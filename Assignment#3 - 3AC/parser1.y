%{

#include <stdio.h>
#include<string.h>
#define YYSTYPE char*

int idx=1;
void tempGen(char *t)
{

	t[0] = 't';
	sprintf(t+1,"%d",idx++);
	
}

%}


%token INTEGER
%token ADD 
%token SUB 
%token MUL 
%token DIV
%token ABS
%token EOL
%token SEM
%token ASSIGN
%token ID 
%token REAL
%token COMMA
%token OP
%token CP
%token NEG 
%token GT
%token GT_EQ
%token LT
%token LT_EQ
%token EQ 
%token NOT_EQ
%token OR
%token AND
%%

assignment  : vars ASSIGN exprs SEM { 

					if(strstr($1,","))
					{
					
						char *save_ptr1, *save_ptr2 ;
						char *token1, *token2;
						char str_1[100];
						char str_2[100];
		
						//strcpy(,"x,z");
		
						//strcpy(str_2,"~(m&n),(m<b | m<c)");
						 
						token1 = strtok_r($1, ",", &save_ptr1);
						token2 = strtok_r($3, ",", &save_ptr2);

						while(token1 && token2) 
						{

							char temp[100], temp2[100];
							strcpy(temp,token1);
							strcpy(temp2,token2);
							printf("%s = %s\n",temp,temp2);
							token1 = strtok_r(NULL, ",", &save_ptr1);
							token2 = strtok_r(NULL, ",", &save_ptr2);

						}
					
					}
					else
						printf("%s = %s\n", $1, $3);
				}
			;
			
			
vars		: ID 						 { $$ = $1; }
    		| vars COMMA ID 			 { $$ = strdup($1); strcat($$,","); strcat($$, $3);  }
			;
			
			
exprs		: expr						 { $$ = $1 ;}
    		| exprs COMMA expr 			 { $$ = strdup($1); strcat($$,","); strcat($$, $3); }
			;
			
			
expr		: sum 				 		 { $$ = $1 ;}
			; 
		
			
sum			: term 						 { $$ = $1;}
    		| SUB term 					 { char t[10]; tempGen(t); printf("%s = -%s\n",t,$2);         $$ = strdup(t);}
    	    | sum ADD term 				 { char t[10]; tempGen(t); printf("%s = %s + %s\n",t,$1,$3);  $$ = strdup(t);}
    		| sum SUB term 				 { char t[10]; tempGen(t); printf("%s = %s - %s\n",t,$1,$3);  $$ = strdup(t);}
			;
			
			
term		: factor 					 { $$ = $1 ;}
    		| term MUL factor 			 { char t[10];tempGen(t); printf("%s = %s * %s\n",t,$1,$3);   $$ = strdup(t);}					
    		| term DIV factor 			 { char t[10];tempGen(t); printf("%s = %s / %s\n",t,$1,$3);   $$ = strdup(t);}
			;
			
			
factor		: INTEGER					 { $$ = $1; }
    		| REAL 						 { $$ = $1; }
    		| ID 						 { $$ = $1; }
    		| OP expr CP 				 { $$ = $2; }
			;


%%

void yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}

int main(int argc, char **argv)
{
	yyparse();
	return 0;
}

