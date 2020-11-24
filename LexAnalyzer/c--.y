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
%type <node> id

%expect 36

%start program
%%
 
 program
 : declaration { $$ = createProgramUnitNode($1); astRoot = $$;}
 | program declaration { $$ = $1;addLinkToList($$, $2);}
 ;

declaration
 : var_declaration                                  { $$ = createDeclarationNode($1); }
 | function_declaration                             { $$ = createDeclarationNode($1); }
 |                                                  { $$ = NULL}
 ;
var_declaration
 : type id END_OF_INSTRUCTION                               { $$ = createVarDeclaration($1, $2, 0); }
 | type id LSQBKT INTEGER_LITERAL RSQBKT END_OF_INSTRUCTION { $$ = createVarDeclaration($1, $2, $4); }
 ;
type
 : INT              { $$ = createTypeSpecifier("INT"); }
 | BOOL             { $$ = createTypeSpecifier("BOOL"); }
 | VOID             { $$ = createTypeSpecifier("VOID"); }
 ;
function_declaration
 : type id parameters block                                 { $$ = createFunctionDeclarationNode($1, $2, $3, $4); }
 ;
parameters
 : LBRK RBRK                                                { $$ = NULL}
 | LBRK formalsList RBRK                                    { $$ = createParametersNode($2);}
 ;
formalsList
 : formalDecl                                               { $$ = createFormalsList(NULL, $1);}
 | formalsList COMMA formalDecl                             { $$ = createFormalsList($1, $3);}
 ;
formalDecl
 : type id                                                  { $$ = createFormalDecl($1, $2);}
 ;
block
 : LBRACE declList stmtList RBRACE                          { $$ = createBlock($2, $3);}
 ;
declList
 : declList var_declaration                                 { $$ = createDecList($1, $2);}
 |                                                          { $$ = NULL}
 ;
stmtList
 : stmtList stmt                                            { $$ = createStmtList($1, $2);}
 |                                                          { $$ = NULL}
 ;
stmt
 : CIN RIGHT id END_OF_INSTRUCTION                          { $$ = createCin($3, NULL);}
 | CIN RIGHT id LSQBKT exp RSQBKT END_OF_INSTRUCTION        { $$ = createCin($3, $5);}
 | COUT LEFT exp END_OF_INSTRUCTION                         { $$ = createCout($3);}
 | subscriptExpr ASSIGN exp END_OF_INSTRUCTION              { $$ = createSubscriptExprStatement($1,$3);}
 | id ASSIGN exp END_OF_INSTRUCTION                         { $$ = createAssignStatement($1,$3);}
 | IF LBRK exp RBRK block                                   { $$ = createIfStatement($3, $4, NULL);}
 | IF LBRK exp RBRK block ELSE block                        { $$ = createIfStatement($3, $4, $6);}
 | WHILE LBRK exp RBRK block                                { $$ = createWhileStatement($3, $5);}
 | RETURN exp END_OF_INSTRUCTION                            { $$ = createReturnStatement($2);}
 | RETURN END_OF_INSTRUCTION                                { $$ = createReturnStatement(NULL);}
 | fnCallStmt END_OF_INSTRUCTION                            { $$ = createFnCallStatement($1);}
 ;
exp
 : exp ADD exp                  { $$ = createExp($1,$3);}
 | exp SUBSTRACT exp            { $$ = createExp($1,$3);}
 | exp MULT exp                 { $$ = createExp($1,$3);}
 | exp DIV exp                  { $$ = createExp($1,$3);}
 | NOT exp                      { $$ = createExp(NULL,$2);}
 | exp AND exp                  { $$ = createExp($1,$3);}
 | exp OR exp                   { $$ = createExp($1,$3);}
 | exp EQUAL exp                { $$ = createExp($1,$3);}
 | exp NEQUAL exp               { $$ = createExp($1,$3);}
 | exp LESS exp                 { $$ = createExp($1,$3);}
 | exp GREATER exp              { $$ = createExp($1,$3);}
 | exp LESSEQ exp               { $$ = createExp($1,$3);}
 | exp GREATEREQ exp            { $$ = createExp($1,$3);}
 | SUBSTRACT atom  %prec NEG    { $$ = createExp(NULL,$2);}
 | atom                         { $$ = createExp($1,NULL);}
 ;
atom
 : INTEGER_LITERAL      { $$ = INTEGER_LITERAL}
 | STRING_LITERAL       { $$ = STRING_LITERAL}
 | TRUE                 { $$ = TRUE}
 | FALSE                { $$ = FALSE}
 | LBRK exp RBRK        { $$ = createAtom($2);}
 | fnCallExpr           { $$ = createAtom($1);}
 | subscriptExpr        { $$ = createAtom($1);}
 | id                   { $$ = createAtom($1);}
 ;  
fnCallExpr
 : id LBRK RBRK                 { $$ = createFnCallExpr($1,NULL);}
 | id LBRK actualList RBRK      { $$ = createFnCallExpr($1,$3);}
 ;
fnCallStmt
 : id LBRK RBRK                 { $$ = createFnCallStmt($1,NULL);}
 | id LBRK actualList RBRK      { $$ = createFnCallStmt($1,$3);}
 ;
actualList
 : exp                          { $$ = createActualList($1,NULL);}
 | actualList COMMA exp         { $$ = createActualList($1,$3);}
 ;
subscriptExpr
 : id LSQBKT exp RSQBKT         { $$ = createSubscriptExpr($1,$3);}
 ;
id
 : IDENTIFIER                   { $$ = IDENTIFIER}
 ;

%%

int yyerror(char *errmsg)
{
     printf("%s \n", errmsg);
     return 0;
}