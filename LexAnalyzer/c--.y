%{
#include <stdio.h>
%}

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
%token INTEGER_LITERAL
%token STRING_LITERAL
%token CONSTANT
%token IDENTIFIER
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
 
%expect 36

%start program
%%
 
program
 : program var_declaration
 | program function_declaration
 | 
 ;
var_declaration
 : type id END_OF_INSTRUCTION
 | type id LSQBKT INTEGER_LITERAL RSQBKT END_OF_INSTRUCTION
 ;
type
 : INT
 | BOOL
 | VOID
 ;
function_declaration
 : type id parameters block
 ;
parameters
 : LBRK RBRK
 | LBRK formalsList RBRK
 ;
formalsList
 : formalDecl
 | formalsList COMMA formalDecl
 ;
formalDecl
 : type id
 ;
block
 : LBRACE declList stmtList LBRACE
 ;
declList
 : declList var_declaration
 | 
 ;
stmtList
 : stmtList stmt
 | 
 ;
stmt
 : CIN RIGHT id END_OF_INSTRUCTION
 | CIN RIGHT id LSQBKT exp RSQBKT END_OF_INSTRUCTION
 | COUT LEFT exp END_OF_INSTRUCTION
 | subscriptExpr ASSIGN exp END_OF_INSTRUCTION
 | id ASSIGN exp END_OF_INSTRUCTION
 | IF LBRK exp RBRK block
 | IF LBRK exp RBRK block ELSE block
 | WHILE LBRK exp RBRK block
 | RETURN exp END_OF_INSTRUCTION
 | RETURN END_OF_INSTRUCTION
 | fnCallStmt END_OF_INSTRUCTION
 ;
exp
 : exp ADD exp
 | exp SUBSTRACT exp
 | exp MULT exp
 | exp DIV exp
 | NOT exp
 | exp AND exp
 | exp OR exp
 | exp EQUAL exp
 | exp NEQUAL exp
 | exp LESS exp
 | exp GREATER exp
 | exp LESSEQ exp
 | exp GREATEREQ exp
 | SUBSTRACT atom  %prec NEG 
 | atom
 ;
atom
 : INTEGER_LITERAL
 | STRING_LITERAL
 | TRUE
 | FALSE
 | LBRK exp RBRK
 | fnCallExpr
 | subscriptExpr
 | id
 ;
fnCallExpr
 : id LBRK RBRK
 | id LBRK actualList RBRK
 ;
fnCallStmt
 : id LBRK RBRK
 | id LBRK actualList RBRK
 ;
actualList
 : exp
 | actualList COMMA exp
 ;
subscriptExpr
 : id LSQBKT exp RSQBKT
 ;
id
 : IDENTIFIER
 ;

%%

int yyerror(char *errmsg)
{
     fprintf("%s \n", errmsg);
}