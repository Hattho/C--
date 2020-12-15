%{
#include <stdio.h>
#include "ast.h"

Node* astRoot = NULL;

int yyerror(char * s);
extern int yylex(void);
%}

%union{
    Node *node;
    char* strings;
    int intVal;
}

%token INT
%token BOOL
%token IF
%token ELSE
%token WHILE
%token VOID
%token TRUE
%token FALSE
%token RETURN
%token CIN
%token COUT
%token <intVal> INTEGER_LITERAL
%token <strings> STRING_LITERAL
%token <intVal> CONSTANT
%token <strings> IDENTIFIER
%token LBRACE
%token RBRACE
%token LBRK
%token RBRK
%token LSQBKT
%token RSQBKT
%token COMMA
%token ASSIGN
%token END_OF_INSTRUCTION
%token LEFT
%token RIGHT

%left OR
%left AND
%precedence LESS LESSEQ GREATER GREATEREQ EQUAL NEQUAL
%left ADD SUBSTRACT
%left MULT DIV
%left NOT
%precedence NEG
 
%type <node> program
%type <node> declaration
%type <node> var_declaration
%type <node> type
%type <node> function_declaration
%type <node> parameters
%type <node> formalsList
%type <node> formalDecl
%type <node> block
%type <node> declList
%type <node> stmtList
%type <node> stmt
%type <node> exp
%type <node> atom
%type <node> fnCallExpr
%type <node> fnCallStmt
%type <node> actualList
%type <node> subscriptExpr

%expect 52

%start program
%%
 
 program
 : declaration { $$ = createProgramUnitNode($1); astRoot = $$;}
 | program declaration { $$ = $1;addLinkToList($$, $2);}
 ;

declaration
 : var_declaration                                  { $$ = createDeclarationNode($1); }
 | function_declaration                             { $$ = createDeclarationNode($1); }
 |                                                  { $$ = NULL;}
 ;
var_declaration 
 : type IDENTIFIER END_OF_INSTRUCTION                               { $$ = createVarDeclaration($1, $2, 0); }
 | type IDENTIFIER LSQBKT INTEGER_LITERAL RSQBKT END_OF_INSTRUCTION { $$ = createArrayDeclaration($1, $2, $4); }
 ;
type
 : INT              { $$ = createTypeSpecifier("INT"); }
 | BOOL             { $$ = createTypeSpecifier("BOOL"); }
 | VOID             { $$ = createTypeSpecifier("VOID"); }
 ;
function_declaration
 : type IDENTIFIER parameters block                                 { $$ = createFunctionDeclarationNode($1, $2, $3, $4); }
 ;
parameters
 : LBRK RBRK                                                { $$ = NULL;}
 | LBRK formalsList RBRK                                    { $$ = createParametersNode($2);}
 ;
formalsList
 : formalDecl                                               { $$ = createListNode("FormalsList", $1); }
 | formalsList COMMA formalDecl                              {
					$$ = $1;
					addLinkToList($$, $3);
						}
 ;
formalDecl
 : type IDENTIFIER                                                  { $$ = createFormalDecl($1, $2);}
 ;
block
 : LBRACE declList stmtList RBRACE                          { $$ = createBlock($2, $3);}
 ;
declList
 : declList var_declaration                                 { $$ = $1; addLinkToList($$, $2);}
 | var_declaration                                          { $$ = createListNode("DecList", $1); }
 |                                                          { $$ = NULL;}
 ;
stmtList
 : stmtList stmt                                            { $$ = $1; addLinkToList($$, $2);}
 | stmt                                                     { $$ = createListNode("StatementList", $1); }
 |                                                          { $$ = NULL;}
 ;
stmt
 : CIN RIGHT IDENTIFIER END_OF_INSTRUCTION                          { $$ = createCin($3, NULL);}
 | CIN RIGHT IDENTIFIER LSQBKT exp RSQBKT END_OF_INSTRUCTION        { $$ = createCin($3, $5);}
 | COUT LEFT exp END_OF_INSTRUCTION                         { $$ = createCout($3);}
 | subscriptExpr ASSIGN exp END_OF_INSTRUCTION              { $$ = createSubscriptExprStatement($1,$3);}
 | IDENTIFIER ASSIGN exp END_OF_INSTRUCTION                         { $$ = createAssignStatement($1,$3);}
 | IF LBRK exp RBRK block                                   { $$ = createIfStatement($3, $5, NULL);}
 | IF LBRK exp RBRK block ELSE block                        { $$ = createIfStatement($3, $5, $7);}
 | WHILE LBRK exp RBRK block                                { $$ = createWhileStatement($3, $5);}
 | RETURN exp END_OF_INSTRUCTION                            { $$ = createReturnStatement($2);}
 | RETURN END_OF_INSTRUCTION                                { $$ = createReturnStatement(NULL);}
 | fnCallStmt END_OF_INSTRUCTION                            { $$ = createFnCallStatement($1);}
 ;
exp
 : exp ADD exp                  { $$ = createAddExp($1,$3);}
 | exp SUBSTRACT exp            { $$ = createSubstractExp($1,$3);}
 | exp MULT exp                 { $$ = createMultExp($1,$3);}
 | exp DIV exp                  { $$ = createDivExp($1,$3);}
 | NOT exp                      { $$ = createNotExp($2);}
 | exp AND exp                  { $$ = createAndExp($1,$3);}
 | exp OR exp                   { $$ = createOrExp($1,$3);}
 | exp EQUAL exp                { $$ = createEqualExp($1,$3);}
 | exp NEQUAL exp               { $$ = createNEqualExp($1,$3);}
 | exp LESS exp                 { $$ = createLessExp($1,$3);}
 | exp GREATER exp              { $$ = createGreaterExp($1,$3);}
 | exp LESSEQ exp               { $$ = createLesseqExp($1,$3);}
 | exp GREATEREQ exp            { $$ = createGreatereqExp($1,$3);}
 | SUBSTRACT atom  %prec NEG    { $$ = createNegativeExp($2);}
 | atom                         { $$ = createAtomExp($1);}
 ;
atom
 : INTEGER_LITERAL      { $$ = createIntLiteralNode($1);;}
 | STRING_LITERAL       { $$ = createStrLiteralNode($1);;}
 | TRUE                 { $$ = TRUE;}
 | FALSE                { $$ = FALSE;}
 | LBRK exp RBRK        { $$ = createFuncAtom($2);}
 | fnCallExpr           { $$ = createfnCallAtom($1);}
 | subscriptExpr        { $$ = createSubscriptAtom($1);}
 | IDENTIFIER           { $$ = createIdentifierNode($1);}
 ;  
fnCallExpr
 : IDENTIFIER LBRK RBRK                 { $$ = createFnCallExpr($1,NULL);}
 | IDENTIFIER LBRK actualList RBRK      { $$ = createFnCallExpr($1,$3);}
 ;
fnCallStmt
 : IDENTIFIER LBRK RBRK                 { $$ = createFnCallStmt($1,NULL);}
 | IDENTIFIER LBRK actualList RBRK      { $$ = createFnCallStmt($1,$3);}
 ;
actualList
 : exp                          { $$ = createListNode("ActualList", $1); }
 | actualList COMMA exp         { $$ = $1; ($$, $3);}
 ;
subscriptExpr
 : IDENTIFIER LSQBKT exp RSQBKT         { $$ = createSubscriptExpr($1,$3);}
 ;

%%

int yyerror(char *errmsg)
{
     printf("%s \n", errmsg);
     return 0;
}