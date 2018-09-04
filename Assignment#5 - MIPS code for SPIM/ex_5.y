%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int token_no=2;

char left[100][100];
char right[100][100];

char argument[100][100];
int arg_index=0;

int left_index=0;
int right_index=0;

char global_data[1000];
int newLabel=0;
char lev[10];
int label_no=1;


char variable[100][10];
int var_index=0;

char token[100][10];
int token_index=0;

int stk=0;//stack pointer
char stk_add[10];



void print_str(char str[100])
{
	 printf("la $a0, %s\n",str);
    	 printf("li $v0, 4\n");
    	 printf("syscall\n");
}

void newline()
{
	printf("la $a0,newLine\n");
	printf("li $v0, 4\nsyscall\n");
}
void print_integer(char str[10])
{
	printf("li  $v0, 1\n");
	printf("lw $t0,%s\n",str);
	printf("add $a0, $t0, $zero\n");
	printf("syscall\n");	
}
void stk_to_str(int stkp)
{
	memset(stk_add,'\0',sizeof(stk_add));
	if(stkp>9)
	{
		int two=stkp/10;
		int one=stkp-two*10;
		stk_add[0]=two+'0';
		stk_add[1]=one+'0';
		stk_add[2]='\0';
				
	}
	else
	{
		stk_add[0]=stkp+'0';
		stk_add[1]='\0';
	
	}

}

int duplicate(char str[100])
{
	int i=0;
	for(i=0;i<var_index;i++)
	{
		if(strcmp(variable[i],str)==0)return 1;
	}
	return 0;

}

void substr_match(int len,char sub[10000],char mat[5])
{

	int l=len;
	int i=0,j=0;

	for(i=0;i<l-2;i++)
	{
		if(sub[i]==mat[0] && sub[i+1]==mat[1] && sub[i+2]==mat[2])
		{
			sub[i]=' ';
			sub[i+1]=' ';
			sub[i+2]=' ';	
		}

	}


}


void substr_match_jL0(int len,char sub[10000],char mat[5])
{
	
	int l=len;
	int i=0,j=0;
	
	for(i=0;i<l-3;i++)
	{
		if(sub[i]==mat[0] && sub[i+2]==mat[2] && sub[i+3]==mat[3])
		{
			sub[i]=' ';
			sub[i+2]=' ';
			sub[i+3]=' ';	
		}
	
	}
}



char label_array[100][10]={0};
int label_index=0;
void gen_label(char str1[10])
{
	memset(str1,'\0',sizeof(str1));
	str1[0]='L';
	if(label_no>9)
	{
		int two=label_no/10;
		int one=label_no-two*10;
		str1[1]=two+'0';
		str1[2]=one+'0';
		str1[3]='\0';
		label_no++;
				
	}
	else
	{
		str1[1]=label_no+'0';
		str1[2]='\0';
		label_no++;
	
	}
	strcpy(token[label_index],str1);
	label_index++;
}

void p(char* path)
{
	int i,l;
	l=strlen(path);
	printf("size of total length = %d\n",l);
	for(i=0;i<l;i++)
	{
		if(path[i]==';')
			printf("\n");
		else
			printf("%c",path[i]);
	}
	
	memset(global_data,0,sizeof(global_data));
}

void print_temp(char str2[])
{
	memset(str2,'\0',sizeof(str2));
	str2[0]='t';
	if(token_no>9)
	{
		int two=token_no/10;
		int one=token_no-two*10;
		str2[1]=two+'0';
		str2[2]=one+'0';
		str2[3]='\0';
		token_no++;
				
	}
	else
	{
		str2[1]=token_no+'0';
		str2[2]='\0';
		token_no++;
	
	}
	strcpy(token[token_index],str2);
	token_index++;
}
void print_comma_exprs()
{
	int in=0;
	for(in=0;in<left_index;in++)
	{
	 printf("%s = %s\n",left[in],right[in]);
	}
}
//
char TAC[10000];
int TAC_len=0;

void print_3ac()
{
	int i=0;
	for(i=0;i<TAC_len;i++)
	{
		printf("%c",TAC[i]);
	}
	printf("\n");
}

%}

%union{
	char id[10000];
	struct s
	{
		char true1[10];
		char false1[10];
		char next[10];
		char code[10000];
		char temp[10];
	} st;
	//ETYPE eval; 
};


%token <id> INTEGER REAL ID 
%token <id> PLUS MINUS MUL DIV
%token <id> OPEN CLOSE
%token <id> ASSIGN  SEMICOLON COMMA RETURN
%token <id> TRUE FALSE SOPEN SCLOSE
%token <id> NOT GREATER_EQ GREATER LESS LESS_EQ EQ NOT_EQ OR AND
%token <id> COLON THEN IF FI ELSE DO OD 
%type  <st>  program stmts stmt selection iteration alts alt guard assignment heading body args returnStmt  
%type  <st>  sum term factor subprogram subprogramDecl
%type  <st>  result vars exprs expr disjunction conjunction negation relation


%%

result						: program
							  {
								
								int len=strlen($1.code);
								TAC_len=len;
								memset(TAC,0,sizeof(TAC));
								strcpy(TAC,$1.code);
								
							 }
program 					: stmts 
							{
							
								strcpy($$.code,$1.code);
								
							}
							| 
							{
								printf("empty\n");
							}
							;

stmts 						: stmt 
							{
							
								strcpy($$.code,$1.code);
							
							}
							| stmts SEMICOLON stmt 
							  {
							
								strcat($1.code,$3.code);
								strcpy($$.code,$1.code);
							

							  }
							;
stmt 						: selection 
							  {
								
								strcpy($$.code,$1.code);
								
							  }
							| iteration 
							  {
								strcpy($$.code,$1.code);
								
							  }
							| assignment
							  {
								
								strcpy($$.code,$1.code);
								
							  }
							| subprogramDecl
							  {
								
								strcpy($$.code,"j exit\n");
								strcat($$.code,$1.code);
								
							  }

							;
							
selection 					: IF alts FI
							  {
	
								
								strcpy($$.code,$2.code);
								strcat($$.code,"L0:\n");
	
								
							  }
							;
							
iteration 					: DO alts OD 
							{
								int len=strlen($2.code);
								char str[len+100];
								strcpy(str,$2.code);
								int i=0;
								char mat[5]={0};
								strcpy(mat,$2.false1);
								strcat(mat,":");
								substr_match(len,str,mat);
								memset(mat,0,sizeof(mat));
								strcpy(mat,"j L0");
								substr_match_jL0(len,str,mat);
							
								char lv_begin[10];
								gen_label(lv_begin);

								strcpy($$.code,lv_begin);
								strcat($$.code,":\n");
								strcat($$.code,str);
								strcat($$.code,"j ");
								strcat($$.code,lv_begin);
								strcat($$.code,"\n");
								strcat($$.code,$2.false1);
								strcat($$.code,":\n");
							}
							;


alts 						: alt
							  { 
								
								strcpy($$.code,$1.code);
								strcpy($$.true1,$1.true1);
								strcpy($$.false1,$1.false1);
								
								strcpy($$.temp,$1.temp);
							  }
							| alts COLON alt
							  {
								
								strcat($1.code,$3.code);	
								strcpy($$.code,$1.code);
								strcat($$.code," j L0\n");
								
								strcpy($$.temp,$3.temp);

							}
							;
alt 						: guard THEN stmts
	    					  {
								char lv_t[10]={0};
								memset(lv_t,0,sizeof(lv_t));
								gen_label(lv_t);
		
								char lv_f[10]={0};
								memset(lv_f,0,sizeof(lv_f));
								gen_label(lv_f);
	
								strcpy($$.code,$1.code);
	
								strcat($$.code,"li $t5,1\n");

								strcat($$.code,"beq ");
								strcat($$.code,$1.temp);
								strcat($$.code,",");
								strcat($$.code," $t5 , ");
								strcat($$.code,lv_t);	
								strcat($$.code,"\n");

								strcat($$.code,"j ");
								strcat($$.code,lv_f);
								strcat($$.code,"\n");

								strcat($$.code,lv_t);
								strcat($$.code,":\n");
	
								strcat($$.code,$3.code);	
								strcat($$.code,"\n");

								strcat($$.code,"j L0\n");
	
								strcat($$.code,lv_f);
								strcat($$.code,":\n");	
	
		

								
								strcpy($$.true1,lv_t);
								
								strcpy($$.false1,lv_f);
								

								strcpy($$.temp,$1.temp);
								
							}
							;
		
guard 						: expr
							{

								strcpy($$.code,$1.code);
								strcpy($$.temp,$1.temp);
								
							}
							;
assignment					:  vars ASSIGN exprs 
							{  
								
								strcpy($$.code,$3.code);
								strcat($$.code,"move $t0,");
								strcat($$.code,$3.temp);
								strcat($$.code,"\n");
	
								strcat($$.code,"sw $t0,");
								strcat($$.code,$1.code);
								strcat($$.code,"\n");
								right_index=right_index-1;
								left_index=left_index-1;
							
							}
							| vars ASSIGN subprogram ASSIGN exprs
							{

								strcpy($$.code,"sw $fp,0($sp)\n");
								strcat($$.code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								int ri=right_index;
								int i=ri-1;
								for(;i>=0;i--)
								{
									strcat($$.code,right[i]);
									strcat($$.code,"sw $t0,0($sp)\n");
									strcat($$.code,"addiu $sp,$sp,-4\n");
									stk=stk+4;
								}
								strcat($$.code,"jal ");
								strcat($$.code,$3.code);
								strcat($$.code,"\n");
								
								strcat($$.code,"sw $v1,"); 
								strcat($$.code,$1.code);
								strcat($$.code,"\n");
								
	
	
							}
							
							| ASSIGN subprogram ASSIGN exprs 
							  {
	
								strcpy($$.code,"sw $fp,0($sp)\n");
								strcat($$.code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								int ri=right_index;
								int i=ri-1;
								for(;i>=0;i--)
								{
									strcat($$.code,right[i]);
									strcat($$.code,"sw $t0,0($sp)\n");
									strcat($$.code,"addiu $sp,$sp,-4\n");
									stk=stk+4;
								}
								strcat($$.code,"jal ");
								strcat($$.code,$2.code);
								strcat($$.code,"\n");
	
								right_index=right_index-1;
								
	
							 }
							 
							| vars ASSIGN subprogram ASSIGN
							  { 
								strcpy($$.code,"sw $fp,0($sp)\n");
								strcat($$.code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								strcat($$.code,"jal ");
								strcat($$.code,$3.code);
								strcat($$.code,"\n");
								//return
								strcat($$.code,"sw $v1,"); 
								strcat($$.code,$1.code);
								strcat($$.code,"\n");
								
								right_index=right_index-1;
								left_index=left_index-1;

     						}
						  | ASSIGN subprogram ASSIGN
							{
								strcpy($$.code,"sw $fp,0($sp)\n");
								strcat($$.code,"addiu $sp,$sp,-4\n");
								stk=stk+4;
								strcat($$.code,"jal ");
								strcat($$.code,$2.code);
								strcat($$.code,"\n");
								

							}
							;

vars					: ID 
						  {
							strcpy(left[left_index],$1); 
							left_index++;
							strcpy($$.code,$1);
							strcpy($$.temp,$1);
							int check=duplicate($1);
							if(check==0)
							{
								strcpy(variable[var_index],$1);
								var_index++;	
	
							}

							 
						 }
					   | vars COMMA ID
					     {
							char str[100];

							strcpy(str,"lw $a0,");
							strcat(str,$3);
							strcat(str,"\n"); 	
							strcat(str,"move $s7,$a0\n");
							strcpy(left[left_index],$3); 
							left_index++; 
							strcpy($$.code,str);
							strcpy($$.temp,"$s7");

						
							int check=duplicate($3);
							if(check==0)
							{
								strcpy(variable[var_index],$3);
								var_index++;	
	
							}

						}
						;
subprogram				: ID
						  {
							strcpy($$.code,$1);
						  }
						;

exprs					: expr 
						  { 
							strcpy(right[right_index],$1.code); 
							right_index++;
							strcpy($$.code,$1.code);
							strcpy($$.temp,$1.temp); 
						  }
						| exprs COMMA expr 
  						  { 
							strcpy(right[right_index],$3.code); 
							right_index++;
							strcpy($$.code,$1.code);
							strcpy($$.temp,$3.temp); 
						  }
						;

subprogramDecl			: heading body
						  {
							strcpy($$.code,$1.code);
							strcat($$.code,$2.code);	

						  }

heading					: ID OPEN args CLOSE 
						  {
							strcpy($$.code,$1);
							strcat($$.code,":\n");
							strcat($$.code,"move $fp,$sp\n");
							strcat($$.code,"sw $ra,0($sp)\n");
							strcat($$.code,"addiu $sp,$sp,-4\n");
							stk=stk+4;
							int i=0;
							int ai=arg_index-1;
							int stk_p=4;
							for(i=ai;i>=0;i--)
							{
								stk_to_str(stk_p);
								strcat($$.code,"lw $t0,");
								strcat($$.code,stk_add);
								strcat($$.code,"($fp)\n");
								stk_p=stk_p+4;

								strcat($$.code,"sw $t0,");
								strcat($$.code,argument[i]);
								strcat($$.code,"\n");
							}
		
						 }

						
args					: ID COMMA args
						  {

							strcpy(argument[arg_index],$1); 
							arg_index++;
							strcpy($$.code,$1);

							int check=duplicate($1);
							if(check==0)
							{
								strcpy(variable[var_index],$1);
								var_index++;	
	
							}

						  }
						| ID
						  {


							int check=duplicate($1);
							if(check==0)
							{
								strcpy(variable[var_index],$1);
								var_index++;	
	
							}
							char str[100];

							strcpy(argument[arg_index],$1); 
							arg_index++;
							strcpy($$.code,$1);	
  						  }
						| {}

body					: SOPEN stmts returnStmt SCLOSE 
						  {
							strcpy($$.code,$2.code);
							strcat($$.code,$3.code);	
						  }


returnStmt  			: RETURN exprs
						{
							strcpy($$.code,$2.code);
							strcat($$.code,"lw $ra, 4($sp)\n");
							stk_to_str(stk);
							strcat($$.code,"addi $sp,$sp,");
							strcat($$.code,stk_add);
							strcat($$.code,"\n");
							
							if(left_index>0)
							{
								strcat($$.code,"move $v1,");
								strcat($$.code,$2.temp);
								strcat($$.code,"\n");	
	
							}
							strcat($$.code,"jr $ra\n");
							
							right_index=right_index-1;
							left_index=left_index-1;

						}
						|{}
						
expr					:disjunction 
						{ 

	
							strcpy($$.code,$1.code);
							strcpy($$.temp,$1.temp);
	
							 
						}
						;
disjunction				: conjunction 
						  { 
							strcpy($$.code,$1.code);
							strcpy($$.temp,$1.temp); 

						  }
						| disjunction OR conjunction 
						  { 
							strcpy($$.code,$1.code);
							strcat($$.code,"move $s0,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");

							strcat($$.code,$3.code);
							strcat($$.code,"move $s1,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"or $t3,$s0,$s1\n");

							
							char temp[10];
							
							strcpy(temp,"$s7");
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);

						  }
						;
conjunction				: negation 
						{ 
							strcpy($$.code,$1.code); 
							strcpy($$.temp,$1.temp);
						}
						| conjunction AND negation 
						  { 
							strcpy($$.code,$1.code);
							strcat($$.code,"move $t2,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $t3,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"and $t3,$t2,$t3\n");
	
							char temp[10];

							strcpy(temp,"$s7");
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);
						}

negation				: relation 
   						  { 
							strcpy($$.code,$1.code) ; 
							strcpy($$.temp,$1.temp) ;
						  }
						| NOT relation 
						  { 

							strcpy($$.code,$2.code);
							strcat($$.code,"neg $t4,");
							strcat($$.code,$2.temp);

							char temp[10];	
							strcpy(temp,"$s7");	
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t4\n");
							strcpy($$.temp,temp);

						 }
						;

relation				: sum 
						  { 
							strcpy($$.code,$1.code); 
							strcpy($$.temp,$1.temp); 
						  }
						| sum LESS sum 
						{
							strcpy($$.code,$1.code);
							strcat($$.code,"move $a2,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $a3,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"slt $t3,$a2,$a3\n");
	

							char temp[10];

							strcpy(temp,"$s7");	
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);
	
		
						}

						| sum LESS_EQ sum 
						{

							strcpy($$.code,$1.code);
							strcat($$.code,"move $s6,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $t9,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"sle $t3,$s6,$t9\n");
	
						
							char temp[10];
						
							strcpy(temp,"$s7");
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);

						}
						| sum EQ sum 
						{ 
							strcpy($$.code,$1.code);
							strcat($$.code,"move $t8,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $t9,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"seq $t3,$t8,$t9\n");
	
						
							char temp[10];
						
							strcpy(temp,"$s7");
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);

	
						}
						| sum NOT_EQ sum 
						{ 

							strcpy($$.code,$1.code);
							strcat($$.code,"move $t6,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $t7,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"sne $t3,$t6,$t7\n");
	
						
							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);	

							 
						}
						| sum GREATER_EQ sum 
						{

							strcpy($$.code,$1.code);
							strcat($$.code,"move $t5,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $t6,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"sge $t3,$t5,$t6\n");


							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");	
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);
	
						}
						| sum GREATER sum 
						{ 	
							strcpy($$.code,$1.code);
							strcat($$.code,"move $a2,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $a3,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"sgt $t3,$a2,$a3\n");
	

							char temp[10]={0};
							//print_temp(temp);
							strcpy(temp,"$s7");
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);


						 
						}
						;

sum						: term
						{ 
							strcpy($$.code, $1.code);
							strcpy($$.temp, $1.temp); 
						}		
						| MINUS term 
						{
							strcpy($$.code,$2.code);
							strcat($$.code,"neg $t4,");
							strcat($$.code,$2.temp);

							char temp[10];
							strcpy(temp,"$s7");
							//print_temp(temp);
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t4\n");
							strcpy($$.temp,temp);	
	
	
						}
						| sum PLUS term 
						{ 
							strcpy($$.code,$1.code);
							strcat($$.code,"move $a0,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $a1,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"add $t3,$a0,$a1\n");
	
							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");	
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);



						}
						| sum MINUS term
						{
							strcpy($$.code,$1.code);
							strcat($$.code,"move $s5,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $s6,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"sub $t3,$s5,$s6\n");
	
							
							char temp[10];
							//print_temp(temp);
							strcpy(temp,"$s7");	
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);

						}
						;


term					: factor 
						{ 
							strcpy($$.code, $1.code);
							strcpy($$.temp, $1.temp);
						}
						| term MUL factor 
						{

							strcpy($$.code,$1.code);
							strcat($$.code,"move $s3,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $s4,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"mul $t3,$s3,$s4\n");
	
							
							char temp[10];
							
							strcpy(temp,"$s7");	
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");
							strcpy($$.temp,temp);


	
						}
						| term DIV factor 
						{
							strcpy($$.code,$1.code);
							strcat($$.code,"move $s1,");		
							strcat($$.code,$1.temp);
							strcat($$.code,"\n");
	
							strcat($$.code,$3.code);
							strcat($$.code,"move $s2,");
							strcat($$.code,$3.temp);
							strcat($$.code,"\n");
							strcat($$.code,"div $t3,$s1,$s2\n");
	
							char temp[10];
							
							strcpy(temp,"$s7");	
							strcat($$.code,"move ");
							strcat($$.code,temp);
							strcat($$.code,",$t3\n");

							strcpy($$.temp,temp);
	
						}
						; 

factor					: INTEGER 
						{
							char str[100];
							strcpy(str,"li $t0,");
							strcat(str,$1);
							strcat(str,"\n");

							strcpy($$.code,str);
							strcpy($$.temp,"$t0");	
		
						}
						| ID 
						{ 

							char str[100];
							strcpy(str,"lw $t0,");
							strcat(str,$1);
							strcat(str,"\n");

							strcpy($$.code,str);
							strcpy($$.temp,"$t0");
	
							int check=duplicate($1);
							if(check==0)
							{
								strcpy(variable[var_index],$1);
								var_index++;	
	
							}
							 
						}
						| OPEN expr CLOSE 
						{ 

							char str[100];
							
	
							strcpy($$.code,$2.code);
							strcpy($$.temp,$2.temp);	
							 
						}
						| REAL 
						{ 
							char str[100];
							strcpy(str,"li.s $f0,");
							strcat(str,$1);
							strcat(str,"\n");
							strcpy($$.code,str);
							strcpy($$.temp,"$f0");
		
	
							 
						}
						| TRUE 
						{ 

							char str[100];
							strcpy(str,"li $t0,1\n");
							strcpy($$.code,str);
							strcpy($$.temp,"$t0");		
						}
						| FALSE {
							char str[100];
							strcpy(str,"li $t0,0\n");
							strcpy($$.code,str);
							strcpy($$.temp,"$t0");	
	
		
						}
						;

%%
extern int yylex();
extern int yyparse();
extern FILE *yyin;
main()
{
	FILE *myfile = fopen("input.txt", "r");
	freopen("out.s","w",stdout);
	

	if (!myfile) {
		printf("File error\n");
		return -1;
	}
	yyin = myfile;
	
	do {
		yyparse();
	} while (!feof(yyin));

	printf(".data\n");
	int i=0;
	for(i=0;i<var_index;i++)
	{
		printf("%s:	.word 0\n",variable[i]);
	}
	printf("newLine:	.asciiz \"\n\" ");
	printf("\n\n");
	
	printf(".text\n");
	printf("main:\n");
	print_3ac();
		

	printf("exit:\n");
	for(i=0;i<var_index;i++)
	{
		char str[10];
		strcpy(str,variable[i]);
		//print_str(str);
        newline();
    	print_integer(variable[i]);
		newline();
	
	}
	print_integer("m");

	newline();
	printf("li $v0, 10\nsyscall\n");
	
	

}

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
}
