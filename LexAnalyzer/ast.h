#ifndef __AST_H
#define __AST_H

#define MAX_NODE_TYPE 50
#define MAX_EXTRA_DATA 50

typedef struct node {
	char type[MAX_NODE_TYPE];
	int numLinks;
	char extraData[MAX_EXTRA_DATA];
	struct node** links;
}Node;

Node* createTypeSpecifier(const char* typeName);
Node* createProgramUnitNode(Node* declaration);
Node* createDeclarationNode(Node* varFunDeclaration);
Node* createFunctionDeclarationNode(Node* typeSpecifier, const char* functionName, Node* paramsList, Node* compoundStatement);
Node* createVarDeclaration(Node* typeSpecifier, const char* varName, int value); 
Node* createBlock(Node* localDeclList, Node* instructionsList);
Node* createIfStatement(Node* expression, Node* thenStatement, Node* elseStatement);
Node* createArrayDeclaration(Node* typeSpecifier, const char* varName, int size);
Node* createParametersNode(Node* formalsList);
Node* createFormalDecl(Node* type, const char* varName);
Node* createCin(const char* identifierName, Node* expression);
Node* createCout(Node* expression);
Node* createSubscriptExprStatement(Node* subscriptexpr, Node* expression);
Node* createAssignStatement(const char* identifierName, Node* expression);
Node* createWhileStatement(Node* expression, Node* block);
Node* createReturnStatement(Node* expression);
Node* createFnCallStatement(Node* fnCallSttm);
Node* createAddExp(Node* lexp, Node* rexp);
Node* createSubstractExp(Node* lexp, Node* rexp);
Node* createMultExp(Node* lexp, Node* rexp);
Node* createDivExp(Node* lexp, Node* rexp);
Node* createNotExp(Node* exp);
Node* createAndExp(Node* lexp, Node* rexp);
Node* createOrExp(Node* lexp, Node* rexp);
Node* createEqualExp(Node* lexp, Node* rexp);
Node* createNEqualExp(Node* lexp, Node* rexp);
Node* createLessExp(Node* lexp, Node* rexp);
Node* createGreaterExp(Node* lexp, Node* rexp);
Node* createLesseqExp(Node* lexp, Node* rexp);
Node* createGreatereqExp(Node* lexp, Node* rexp);
Node* createNegativeExp(Node* atom);
Node* createAtomExp(Node* atom);
Node* createFuncAtom(Node* exp);
Node* createfnCallAtom(Node* fnCallExpr);
Node* createSubscriptAtom(Node* subscriptExpr);
Node* createFnCallExpr(const char* identifierName, Node* actualList);
Node* createFnCallStmt(const char* identifierName, Node* actualList);
Node* createSubscriptExpr(const char* identifierName, Node* expr);
Node* createStrLiteralNode(const char* stringLiteral);
Node* createIntLiteralNode(int intLiteral);
Node* createIdentifierNode(const char* identifier);

Node* createDefaultNode(const char* nodeName, unsigned int linksCount);
Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize);
Node* createListNode(const char* listName, Node* firstLink);
void addLinkToList(Node* listNode, Node* linkToAdd);
void printAst(Node* ast, int level);
#endif
