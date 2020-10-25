// LexAnalyzer.c : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "symbols.h"
#include <errno.h>

extern FILE* yyin;
extern int yylex(void);

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
    int lexUnit = 0;
    yyin = fopen("input.csrc", "rt");
    if (yyin != NULL) {
        while ((lexUnit = yylex()) != END)
        {
            printf(" -> TOKEN %s\n", symbols[lexUnit]);
        }
        fclose(yyin);
    }
    else {
        printf("Fisierul nu poate fi deschis. Erorr: %d", errno);
        //printf("Fisierul nu poate fi deschis");
    }
}


