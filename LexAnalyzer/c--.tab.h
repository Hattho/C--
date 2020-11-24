/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_C_TAB_H_INCLUDED
# define YY_YY_C_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT = 258,                     /* INT  */
    BOOL = 259,                    /* BOOL  */
    IF = 260,                      /* IF  */
    ELSE = 261,                    /* ELSE  */
    WHILE = 262,                   /* WHILE  */
    VOID = 263,                    /* VOID  */
    TRUE = 264,                    /* TRUE  */
    FALSE = 265,                   /* FALSE  */
    RETURN = 266,                  /* RETURN  */
    CIN = 267,                     /* CIN  */
    COUT = 268,                    /* COUT  */
    INTEGER_LITERAL = 269,         /* INTEGER_LITERAL  */
    STRING_LITERAL = 270,          /* STRING_LITERAL  */
    CONSTANT = 271,                /* CONSTANT  */
    IDENTIFIER = 272,              /* IDENTIFIER  */
    LBRACE = 273,                  /* LBRACE  */
    RBRACE = 274,                  /* RBRACE  */
    LBRK = 275,                    /* LBRK  */
    RBRK = 276,                    /* RBRK  */
    LSQBKT = 277,                  /* LSQBKT  */
    RSQBKT = 278,                  /* RSQBKT  */
    COMMA = 279,                   /* COMMA  */
    ASSIGN = 280,                  /* ASSIGN  */
    END_OF_INSTRUCTION = 281,      /* END_OF_INSTRUCTION  */
    LEFT = 282,                    /* LEFT  */
    RIGHT = 283,                   /* RIGHT  */
    OR = 284,                      /* OR  */
    AND = 285,                     /* AND  */
    LESS = 286,                    /* LESS  */
    LESSEQ = 287,                  /* LESSEQ  */
    GREATER = 288,                 /* GREATER  */
    GREATEREQ = 289,               /* GREATEREQ  */
    EQUAL = 290,                   /* EQUAL  */
    NEQUAL = 291,                  /* NEQUAL  */
    ADD = 292,                     /* ADD  */
    SUBSTRACT = 293,               /* SUBSTRACT  */
    MULT = 294,                    /* MULT  */
    DIV = 295,                     /* DIV  */
    NOT = 296,                     /* NOT  */
    NEG = 297                      /* NEG  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "c--.y"

    Node *node;
    char* strings;
    int intVal;

#line 112 "c--.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_TAB_H_INCLUDED  */
