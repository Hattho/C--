#include "SemanticAnalyzer.h"
#include <malloc.h>
#include <string.h>


void createSymbolList(Node* ast, int level, SymTableNode** root, char* contextName) {
	int index = 0;
	if (ast) {

		char* symbolName = NULL;
		char* dataType = NULL;
		int symbolType = NULL;
		IdentifierScope symbolScope = 0;
		char* aux = NULL;
		int samecontext = 0;
		int declared = 0;

		if (strcmp(ast->type, "VariableDeclaration") == 0) {
			

			dataType = ast->links[0]->extraData;
			symbolName = ast->extraData;
			symbolType = 1;
			if (level == 2) {
				symbolScope = Global;

			}
			else {
				symbolScope = Local;
			}
		}
		else if (strcmp(ast->type, "FunctionDefinition") == 0) {

			aux = contextName;
			contextName = ast->extraData;
			dataType = ast->links[0]->extraData;
			symbolName = ast->extraData;
			symbolType = 2;
			if (level == 1) {
				symbolScope = Global;

			}
			else {
				symbolScope = Local;
			}
		}


		if (symbolName != NULL && contextName != NULL) {
			if (aux != NULL) {
				samecontext = SearchNodeContextSymTable(*root, symbolName, aux);
			}
			else {
				samecontext = SearchNodeContextSymTable(*root, symbolName, contextName);
			}
		}

		if (dataType != NULL && symbolName != NULL && samecontext == 0) {
			if (aux != NULL) {
				addEntryToSymbolTable(root, symbolName, dataType, symbolType, symbolScope, aux);
			}
			else {
				addEntryToSymbolTable(root, symbolName, dataType, symbolType, symbolScope, contextName);
			}
		}


		for (index = 0; index < ast->numLinks; index++) {
			createSymbolList(ast->links[index], level + 1, root, contextName);
		}

	}
}

void printSymbolList(SymTableNode* symTableroot) {
	SymTableNode* aux = symTableroot;
	printf("\nBelow we can see the Symbol Table: \n");
	while (aux != NULL) {
		printf("Symbol Name: %s\n", aux->symbolEntry->symbolName);
		printf("Data Type: %s\n", aux->symbolEntry->dataType);
		printf("Symbol Type: %d\n", aux->symbolEntry->symbolType);
		printf("Symbol Scope: %d\n", aux->symbolEntry->symbolScope);
		printf("Context Name: %s\n", aux->symbolEntry->contextName);
		printf("\n");
		if (aux->next != NULL) {
			aux = aux->next;
		}
		else {
			return;
		}
	}
	if (!aux) {
		printf("The Table is Empty!");
	}
}


void addEntryToSymbolTable(SymTableNode** symTableroot, char* symbolName, char* dataType, int symbolType,
	IdentifierScope symbolScope, char* contextName) {

	SymTableEntry* symTableEntry = (SymTableEntry*)malloc(sizeof(SymTableEntry));
	memset(symTableEntry, 0, sizeof(SymTableEntry));
	strcpy(symTableEntry->symbolName, symbolName);
	strcpy(symTableEntry->dataType, dataType);
	symTableEntry->symbolType = symbolType;
	symTableEntry->symbolScope = symbolScope;
	if (contextName != NULL) {
		strcpy(symTableEntry->contextName, contextName);
	}
	else {
		strcpy(symTableEntry->contextName, "Global");
	}

	SymTableNode* newNode = (SymTableNode*)malloc(sizeof(SymTableNode));
	newNode->symbolEntry = symTableEntry;
	newNode->next = NULL;

	if (*symTableroot == NULL) {
		*symTableroot = (SymTableNode*)malloc(sizeof(SymTableNode));
		*symTableroot = newNode;
	}
	else {
		SymTableNode* auxNode = *symTableroot;
		while (auxNode->next != NULL) {
			auxNode = auxNode->next;
		}
		auxNode->next = newNode;
	}

}



int SearchNodeContextSymTable(SymTableNode* SymTableHead, char* symbolName, char* contextname) {
	SymTableNode* auxNode = SymTableHead;

	while (auxNode != NULL) {
		SymTableEntry* auxEntry = auxNode->symbolEntry;
		int found = 0;
		if (symbolName != NULL) {
			if (strcmp(symbolName, auxEntry->symbolName) == 0) {
				found = 1;
			}
		}
		if (found == 1) {
			if (strcmp(contextname, auxEntry->contextName) == 0) {
				printf("\nError: The variable %s has already been declared in the context %s \n\n", symbolName, contextname);
				return 1;
			}
		}
		auxNode = auxNode->next;
	}

	//else {
	//	printf("The SymTable is still Empty! \n");
	//}
	return 0;
}
