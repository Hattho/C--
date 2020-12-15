#include "ast.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
Node* createDefaultNode(const char* nodeName, unsigned int linksCount)
{
	Node* retNode = (Node*)malloc(sizeof(Node));
	if (retNode)
	{
		memset(retNode, 0, sizeof(Node));
		if (nodeName)
		{
			strcpy(retNode->type, nodeName);
		}
		retNode->numLinks = linksCount;
		if (linksCount > 0)
		{
			retNode->links = (Node**)malloc(linksCount * sizeof(Node*));
		}
	}
	return retNode;
}

Node* resizeNodeLinks(Node* nodeToResize, unsigned int newSize)
{
	if (nodeToResize->numLinks == 0)
	{
		nodeToResize->links = (Node**)malloc(newSize * sizeof(Node*));
	}
	else
	{
		nodeToResize->links = (Node**)realloc(nodeToResize->links, newSize * sizeof(Node*));
	}
	nodeToResize->numLinks = newSize;
	return nodeToResize;
}

Node* createListNode(const char* listName, Node* firstLink)
{
	Node* retNode = createDefaultNode(listName, 1);
	retNode->links[0] = firstLink;
	return retNode;
}
void addLinkToList(Node* listNode, Node* linkToAdd)
{
	unsigned int numLinks = listNode->numLinks;
	resizeNodeLinks(listNode, numLinks + 1);
	listNode->links[numLinks] = linkToAdd;
}

Node* createProgramUnitNode(Node* declaration)
{
	Node* retNode = createDefaultNode("ProgramUnit", 1);
	if (retNode)
	{
		retNode->links[0] = declaration;
	}

	return retNode;

}

Node* createDeclarationNode(Node* varFunDeclaration)
{
	Node* retNode = createDefaultNode("Declaration", 1);
	if (retNode)
	{
		retNode->links[0] = varFunDeclaration;
	}
	return retNode;
}

Node* createFunctionDeclarationNode(Node* typeSpecifier, const char* functionName, Node* paramsList, Node* block)
{

	Node* retNode = createDefaultNode("FunctionDefinition", 3);

	if (retNode)
	{
		retNode->links[0] = typeSpecifier;
		retNode->links[1] = paramsList;
		retNode->links[2] = block;
		if (functionName)
			strcpy(retNode->extraData, functionName);
	}
	

	return retNode;
}

Node* createVarDeclaration(Node* typeSpecifier, const char* varName, int value)
{
	Node* retNode = createDefaultNode("VariableDeclaration", 2);

	if (retNode)
	{
		retNode->links[0] = typeSpecifier;
		if (varName)
			sprintf(retNode->extraData, "%s", varName);
		retNode->links[1] = createDefaultNode("Value", 0);
		sprintf(retNode->links[1]->extraData, "%d", value);
	}

	return retNode;

}

Node* createArrayDeclaration(Node* typeSpecifier, const char* varName, int size)
{
	Node* retNode = createDefaultNode("VariableDeclaration", 2);

	if (retNode)
	{
		retNode->links[0] = typeSpecifier;
		if (varName)
			sprintf(retNode->extraData, "%s", varName);
		retNode->links[1] = createDefaultNode("Array", 0);
		sprintf(retNode->links[1]->extraData, "%d", size);
	}

	return retNode;

}

Node* createParametersNode(Node* formalsList)
{
	Node* retNode = createDefaultNode("Parameters", 1);
	retNode->links[0] = formalsList;
	return retNode;
}

Node* createFormalDecl(Node* type, const char* varName)
{
	Node* retNode = createDefaultNode("Parameters", 1);
	retNode->links[0] = type;
	if (varName)
		sprintf(retNode->extraData, "%s", varName);
	return retNode;
}

Node* createBlock(Node* localDeclList, Node* instructionsList)
{
	Node* retNode = createDefaultNode("Block", 2);
	retNode->links[0] = localDeclList;
	retNode->links[1] = instructionsList;
	return retNode;
}

Node* createIfStatement(Node* expression, Node* thenStatement, Node* elseStatement)
{

	Node* retNode = createDefaultNode("IfStatement", 3);
	retNode->links[0] = expression;
	retNode->links[1] = thenStatement;
	retNode->links[2] = elseStatement;

	return retNode;
}

Node* createTypeSpecifier(const char* typeName)
{
	Node* retVal = createDefaultNode("TypeSpecifier", 0);
	if (typeName)
		sprintf(retVal->extraData, "%s", typeName);
	return retVal;
}

Node* createCin(const char* identifierName, Node* expression)
{
	if (!expression) {
		Node* retNode = createDefaultNode("Cin", 0);
		if (identifierName)
			sprintf(retNode->extraData, "%s", identifierName);
		return retNode;
	}
	Node* retNode = createDefaultNode("Cin", 1);
	retNode->links[0] = expression;
	if (identifierName)
		sprintf(retNode->extraData, "%s", identifierName);
	return retNode;
}

Node* createCout(Node* expression)
{

	Node* retNode = createDefaultNode("Cout", 1);
	retNode->links[0] = expression;
	return retNode;	
}

Node* createSubscriptExprStatement(Node* subscriptexpr, Node* expression)
{

	Node* retNode = createDefaultNode("SubscriptExprStatement", 2);
	retNode->links[0] = subscriptexpr;
	retNode->links[1] = expression;
	return retNode;
}

Node* createAssignStatement(const char* identifierName, Node* expression)
{
	Node* retNode = createDefaultNode("AssignStatement", 1);
	retNode->links[0] = expression;
	if (identifierName)
		sprintf(retNode->extraData, "%s", identifierName);
	return retNode;
}

Node* createWhileStatement(Node* expression, Node* block)
{

	Node* retNode = createDefaultNode("WhileStatement", 2);
	retNode->links[0] = expression;
	retNode->links[1] = block;

	return retNode;
}

Node* createReturnStatement( Node* expression)
{
	if (!expression) {
		Node* retNode = createDefaultNode("Return", 0);
		return retNode;
	}
	Node* retNode = createDefaultNode("Return", 1);
	retNode->links[0] = expression;
	return retNode;
}

Node* createFnCallStatement(Node* fnCallSttm)
{

	Node* retNode = createDefaultNode("FnCallStatement", 1);
	retNode->links[0] = fnCallSttm;
	return retNode;
}

Node* createAddExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Add", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createSubstractExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Sub", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createMultExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Mult", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createDivExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Div", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createNotExp(Node* exp)
{

	Node* retNode = createDefaultNode("Not", 1);
	retNode->links[0] = exp;
	return retNode;
}

Node* createAndExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("AND",2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createOrExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("OR", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createEqualExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Equal", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createNEqualExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("NEqual", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createLessExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Less", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createGreaterExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Greater", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createLesseqExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Lesseq", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createGreatereqExp(Node* lexp, Node* rexp)
{

	Node* retNode = createDefaultNode("Greatereq", 2);
	retNode->links[0] = lexp;
	retNode->links[1] = rexp;

	return retNode;
}

Node* createNegativeExp(Node* atom)
{

	Node* retNode = createDefaultNode("NegativeExp", 1);
	retNode->links[0] = atom;
	return retNode;
}

Node* createAtomExp(Node* atom)
{

	Node* retNode = createDefaultNode("AtomExp", 1);
	retNode->links[0] = atom;
	return retNode;
}

Node* createFuncAtom(Node* exp)
{

	Node* retNode = createDefaultNode("FuncAtom", 1);
	retNode->links[0] = exp;
	return retNode;
}

Node* createfnCallAtom(Node* fnCallExpr)
{

	Node* retNode = createDefaultNode("fnCallAtom", 1);
	retNode->links[0] = fnCallExpr;
	return retNode;
}

Node* createSubscriptAtom(Node* subscriptExpr)
{

	Node* retNode = createDefaultNode("SubscriptAtom", 1);
	retNode->links[0] = subscriptExpr;
	return retNode;
}

Node* createFnCallExpr(const char* identifierName, Node* actualList)
{
	if (!actualList) {
		Node* retNode = createDefaultNode("FnCallExpr", 0);
		if (identifierName)
			sprintf(retNode->extraData, "%s", identifierName);
		return retNode;
	}
	Node* retNode = createDefaultNode("FnCallExpr", 1);
	retNode->links[0] = actualList;
	if (identifierName)
		sprintf(retNode->extraData, "%s", identifierName);
	return retNode;


}

Node* createFnCallStmt(const char* identifierName, Node* actualList)
{
	if (!actualList) {
		Node* retNode = createDefaultNode("FnCallStmt", 0);
		if (identifierName)
			sprintf(retNode->extraData, "%s", identifierName);
		return retNode;
	}
	Node* retNode = createDefaultNode("FnCallStmt", 1);
	retNode->links[0] = actualList;
	if (identifierName)
		sprintf(retNode->extraData, "%s", identifierName);
	return retNode;


}

Node* createSubscriptExpr(const char* identifierName, Node* expr)
{
	Node* retNode = createDefaultNode("SubscriptExpr", 1);
	retNode->links[0] = expr;
	if (identifierName)
		sprintf(retNode->extraData, "%s", identifierName);
	return retNode;

}

Node* createStrLiteralNode(const char* stringLiteral)
{
	Node* retNode = createDefaultNode("StringLiteralNode", 0);
	sprintf(retNode->extraData, "%s", stringLiteral);
	return retNode;
}

Node* createIntLiteralNode(int intLiteral)
{
	Node* retNode = createDefaultNode("IntLiteralNode", 0);
	sprintf(retNode->extraData, "%d", intLiteral);
	return retNode;
}

Node* createIdentifierNode(const char* identifier)
{
	Node* retNode = createDefaultNode("IdentifierNode", 0);
	sprintf(retNode->extraData, "%s", identifier);
	return retNode;
}

void printAst(Node* ast, int level)
{
	int idx = 0;
	if (ast)
	{
		for (idx = 0; idx < level; idx++)
		{
			printf(" ");
		}
		if (ast->type)
		{
			printf("%s ", ast->type);
		}
		if (ast->numLinks)
		{
			printf(" - %d - %s\n", ast->numLinks, ast->extraData);
		}
		else
		{
			printf(" - %s\n", ast->extraData);
		}
		for (idx = 0; idx < ast->numLinks; idx++)
		{

			printAst(ast->links[idx], level + 1);
		}
	}
}
