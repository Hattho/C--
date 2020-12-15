#include "SemanticAnalyzer.h"
#include <malloc.h>
#include <string.h>



void createSymbolList(Node* ast, int level, SymTableNode** root) {
	int index = 0;
	if (ast) {

		char* symbolName = NULL;
		char* dataType = NULL;
		int symbolType = NULL;
		IdentifierScope symbolScope = 0;
		char* contextName = NULL;

		if (strcmp(ast->type, "VariableDeclaration") == 0) {


			contextName = ast->type;
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

			contextName = ast->type;
			dataType = ast->links[0]->extraData;
			symbolName = ast->extraData;
			symbolType = 2;
			if (level == 2) {
				symbolScope = Global;
			}
			else {
				symbolScope = Local;
			}
		} 

		if (dataType != NULL && symbolName != NULL) {

			addEntryToSymbolTable(root, symbolName, dataType, symbolType, symbolScope, contextName);
		}



		for (index = 0; index < ast->numLinks; index++) {
			createSymbolList(ast->links[index], level + 1, root);
		}


	}
}

void printSymbolList(SymTableNode* symTableroot) {
	SymTableNode* aux = symTableroot;
	while (aux != NULL) {
		printf("Symbol Name ->  %s\n", aux->symbolEntry->symbolName);
		printf("Data Type ->  %s\n", aux->symbolEntry->dataType);
		printf("Symbol Type ->  %d\n", aux->symbolEntry->symbolType);
		printf("Symbol Scope ->  %d\n", aux->symbolEntry->symbolScope);
		printf("Context Name ->  %s\n", aux->symbolEntry->contextName);
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
	strcpy(symTableEntry->contextName, contextName);

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

