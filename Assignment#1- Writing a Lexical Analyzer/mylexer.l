
%{
#include<stdio.h>
#include<string.h>
int val;
int yylval;


%}


digit     [0-9]
letter    [A-Za-z]
sign[-\+]
signed_number {sign}[1-9]{digit}*|{sign}[1-9]{digit}*
decimal_number {digit}+[\.]{digit}+

%%


(({sign}[0-9]+[.]?[0-9]*)|([0-9]*[.][0-9]+))[eE][+-][0-9]+		{ printf("Scientific number %s\n",yytext);};

0x[0-9A-F]+					    {
									if(yyleng<=6)
										printf("Hex %s\n",yytext);
									else
										printf("Oveflow %s\n",yytext);
								}
								;
[1-9]{digit}*					{				
									val = atoi(yytext);
									if( val>9999 )
										printf("Overflow %d\n",val);
									if( (val%4)==0 && yyleng<5 )
										printf("Div_4* %s\n",yytext);
								}
								;
								
								
\*								{ printf("MultOp %s\n",yytext); };
\=								{ printf("AssignOp %s\n",yytext); };
\+								{ printf("AddOp %s\n",yytext); };

{signed_number}					{ printf("Signed %s\n",yytext); };

{letter}({letter}|{digit})*	    { printf("ID %s\n",yytext); };

{decimal_number}			    { printf("Decimal %s\n",yytext); };

"=="	     					{ printf("RelationOP %s\n",yytext); };
"!=" 	     					{ printf("RelationOP %s\n",yytext); };
"<" 	   					    { printf("RelationOP %s\n",yytext); };
">" 	     					{ printf("RelationOP %s\n",yytext); };
"<=" 	     					{ printf("RelationOP %s\n",yytext); };
">="	     					{ printf("RelationOP %s\n",yytext); };
[ \t]																 ;
.								{printf("Invalid input\n");};
%%
int yywrap()
{
	return 1;
}
int main(int argc,char *argv[]) {
	yyin = freopen(argv[1],"r",stdin);
	yyout = freopen (argv[2],"w",stdout);
    yylex();
    fclose(yyout);
   
    return 0;
}
