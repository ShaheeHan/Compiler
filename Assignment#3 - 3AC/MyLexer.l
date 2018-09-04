%{
	#include "parser1.tab.h"
%}


digit     [0-9]
letter    [A-Za-z]
sign[-\+]
signed_number {sign}[1-9]{digit}*|{sign}[1-9]{digit}*
decimal_number {digit}+[\.]{digit}+

%%

";" 									{ return SEM; }
"+" 									{ return ADD; }
"-" 									{ return SUB; }
"*" 									{ return MUL; }
"/" 									{ return DIV; }
":=" 									{ return ASSIGN; }
"," 									{ return COMMA;}
{digit}+ 								{ yylval = strdup(yytext); return INTEGER; }
[a-zA-Z][0-9a-zA-Z]* 					{ yylval = strdup(yytext); return ID; }
decimal_number							{ yylval = strdup(yytext); return REAL; }
"(" 									{ return OP;}
")" 									{ return CP;}
[ \t\n\r] 
. { printf("Invalid character %c\n", *yytext); }
%%

int yywrap()
{
	return 1;
}
