// LexAnalyzer.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "symbols.h"
#include <errno.h>

extern FILE* yyin;
extern int yylex(void);
extern int yyparse(void);
extern int yydebug;

char* symbols[] = {
 "END",
 "INT",
 "BOOL",
 "IF",
 "ELSE",
 "WHILE",
 "VOID",
 "TRUE",
 "FALSE",
 "RETURN",
 "CIN",
 "COUT",
 "INTEGER_LITERAL ",
 "STRING_LITERAL",
 "CONSTANT ",
 "LBRACE",
 "RBRACE",
 "LBRK",
 "RBRK",
 "LSQBKT ",
 "RSQBKT ",
 "COMMA",
 "ASSIGN",
 "END_OF_INSTRUCTION",
 "ADD",
 "SUBSTRACT",
 "MULT",
 "DIV",
 "NOT",
 "AND",
 "OR",
 "EQUAL",
 "NEQUAL",
 "LESS",
 "GREATER",
 "LESSEQ",
 "GREATEREQ",
 "LEFT",
 "RIGHT",
 "IDENTIFIER "
};


int main() {
    //int lexUnit = 0;
    yydebug = 1;
    yyin = fopen("input.csrc", "rt");
    if (yyin != NULL) {

        int result = yyparse();
        switch (result)
        {
        case 0:
            printf("Parse Successfull.\n");
            break;

        case 1:
            printf("Invalid input encountered.\n");
            break;

        case 2:
            printf("Out of memory.\n");
            break;

        default:
            break;
        }

        /*while ((lexUnit = yylex()) != END)
        {
            printf(" -> TOKEN %s\n", symbols[lexUnit]);
        }*/

        fclose(yyin);
    }
    else {
        printf("Fisier inexistent/Fisierul nu poate fi deschis. Erorr: %d", errno);
        //printf("Fisierul nu poate fi deschis");


    }
}


