#ifndef __SEMANTICANALYZER_H
#define __SEMANTICANALYZER_H


#include "ast.h"
#include <stdio.h>


#define MAX_SYMBOL_NAME 350
#define MAX_DATATYPE_NAME 250

typedef enum IdentifierScope { Local = 0, Global } IdentifierScope;
struct symbolTableNode;
struct SymTableEntry;

typedef struct SymTableEntry {

	char symbolName[MAX_SYMBOL_NAME];
	char dataType[MAX_DATATYPE_NAME];
	int symbolType;
	IdentifierScope symbolScope;
	char contextName[MAX_SYMBOL_NAME];

}SymTableEntry;

typedef struct symbolTableNode {
	struct SymTableEntry* symbolEntry;
	struct SymTableNode* next;
}SymTableNode;


void createSymbolList(Node* ast, int level, SymTableNode** symTableroot);
void printSymbolList(SymTableNode* symTableroot);
void addEntryToSymbolTable(SymTableNode** symTableroot, char* symbolName, char* dataType, int symbolType,
	IdentifierScope symbolScope, char* contextName);

#endif

