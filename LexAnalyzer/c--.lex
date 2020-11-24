D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "ast.h"
#include "c--.tab.h"

void count();
%}

%%
"#"			{comment(); }
"//"		{comment(); }
"int"		{count(); return(INT); }
"bool"		{count(); return(BOOL); }
"if"		{count(); return(IF); }
"else"		{count(); return(ELSE); }
"while"		{count(); return(WHILE); }
"void"		{count(); return(VOID); }
"true"		{count(); return(TRUE); }
"false"		{count(); return(FALSE); }
"return"	{count(); return(RETURN); }
"cin"		{count(); return(CIN); }
"cout"		{count(); return(COUT); }


{L}({L}|{D})*			{ count(); yylval.strings = strdup(yytext); return(check_type()); }
{D}+					{ count(); yylval.intVal = atoi(yytext);return(INTEGER_LITERAL); }
L?\"(\\.|[^\\"])*\"		{ count(); yylval.strings = strdup(yytext); return(STRING_LITERAL); }
0{D}+{IS}?		    	{ count(); yylval.intVal = atoi(yytext); return(CONSTANT); }
{D}+{IS}?		    	{ count(); yylval.intVal = atoi(yytext); return(CONSTANT); }


"{"			{ count(); return(LBRACE); }
"}"			{ count(); return(RBRACE); }
"("			{ count(); return(LBRK); }
")"			{ count(); return(RBRK); }
"["			{ count(); return(LSQBKT); }
"]"			{ count(); return(RSQBKT); }
","			{ count(); return(COMMA); }
"="			{ count(); return(ASSIGN); }
";"			{ count(); return(END_OF_INSTRUCTION);}

"+"			{ count(); return(ADD); }
"-"			{ count(); return(SUBSTRACT); }
"*"			{ count(); return(MULT); }
"/"			{ count(); return(DIV); }
"!"			{ count(); return(NOT);}
"&&"		{ count(); return(AND);}
"||"		{ count(); return(OR);}
"=="		{ count(); return(EQUAL); }
"!="		{ count(); return(NEQUAL); }

"<"			{ count(); return(LESS); }
">"			{ count(); return(GREATER); }
"<="		{ count(); return(LESSEQ); }
">="		{ count(); return(GREATEREQ); }
"<<"		{ count(); return(LEFT); }
">>"		{ count(); return(RIGHT); }


[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

yywrap()
{
	return(1);
}


comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{

	return(IDENTIFIER);
}
