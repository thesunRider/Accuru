%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h> 
	int yylex(void);
	int yyerror(char const *s);
	FILE *code;
	int register_index;
	int firstreg;

	#include "exptree.h"
	#include "exptree.c"

%}

%define parse.error verbose

%union{
	struct tnode *no;
	
}

//type and structure
%type <no> expr NODE_NUM Program NODE_ID Slist Stmt InputStmt OutputStmt AsgStmt BrkStmnt CntStmnt


//operators
%token NODE_NUM NODE_PLUS NODE_MINUS NODE_MUL NODE_DIV NODE_OP
%token NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS


//core keywords
%token  NODE_ID NODE_CONNECT NODE_BEGIN NODE_END NODE_BREAK NODE_CONTINUE

//control flows
%token NODE_ENDWHILE NODE_DO NODE_WHILE NODE_IF NODE_THEN NODE_ELSE NODE_ENDIF
  

//system calls
%token NODE_READ NODE_WRITE 

//associativity
%nonassoc NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS
%left NODE_PLUS NODE_MINUS NODE_END
%left NODE_MUL NODE_DIV

%%


Program : NODE_BEGIN Slist NODE_END {
				$$ = $2;
				evaluate($2,code);
				//printf($2);
				exit(0);}

		| NODE_BEGIN NODE_END {$$ = NULL;}
		;




Slist : Slist Stmt {$$ = createTree(0 ,0,CONNECT ,NULL, $1, $2);}
	|	Stmt {$$ = $1;}
	;



Stmt : InputStmt {$$ = $1;}
	| OutputStmt {$$ = $1;}
	| AsgStmt {$$ = $1;}
	| CntStmnt {$$ = $1;}
	| BrkStmnt {$$ = $1;}
	| NODE_WHILE '('expr')' NODE_DO Slist NODE_ENDWHILE';' {$$ = createTree(0 ,0,WHILE ,NULL,$3, $6);}
	| NODE_IF '('expr')' NODE_THEN Slist NODE_ELSE Slist NODE_ENDIF';' {$$ = createTree(0 ,IF_DOUBLE,IF ,NULL,$3, createTree(0 ,0,CONNECT ,NULL, $6, $8));}
	| NODE_IF '('expr')' NODE_THEN Slist NODE_ENDIF';' {$$ = createTree(0 ,IF_SINGLE,IF ,NULL,$3, $6);}
	;




CntStmnt : NODE_CONTINUE';' {$$ = createTree(0 ,0,CONTINUE ,NULL, NULL, NULL);}
BrkStmnt : NODE_BREAK';' {$$ = createTree(0 ,0,BREAK ,NULL, NULL, NULL);}
	;

InputStmt : NODE_READ'('NODE_ID')'';'	{$$ = createTree(0 ,0,READ ,NULL, $3, NULL);}
	;

OutputStmt : NODE_WRITE'('expr')'';' 	{$$ = createTree(0 ,0,WRITE ,NULL, $3, NULL);}
	;

AsgStmt : NODE_ID'='expr';' 			{$$ = createTree(0 ,0,ASSIGN ,"=", $1, $3);}
	;



expr : expr NODE_GRT expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<", $1, $3);}
	 | expr NODE_LES expr  			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">", $1, $3);}
	 | expr NODE_GEQ expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<=", $1, $3);}
	 | expr NODE_LEQ expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">=", $1, $3);}
	 | expr NODE_NEQUALS expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"!=", $1, $3);}
	 | expr NODE_EQUALS expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"==", $1, $3);}
	 | expr NODE_PLUS expr		{$$ = createTree(0 ,0,OP ,"+", $1, $3);}
	 | expr NODE_MINUS expr  	{$$ = createTree(0 ,0,OP ,"-", $1, $3);}
	 | expr NODE_MUL expr		{$$ = createTree(0 ,0,OP ,"*", $1, $3);}
	 | expr NODE_DIV expr		{$$ = createTree(0 ,0,OP ,"/", $1, $3);}
	 | '(' expr ')'				{$$ = $2;}
	 | NODE_ID 					{$$ = $1;}
	 | NODE_NUM					{$$ = $1;}
	 ;

%%



int main(void) {
	extern FILE *yyin; 

	register_index = 0;
	firstreg = 1;
	code = fopen("out.txt", "w");

	yyin = fopen("inp.txt", "r"); 

	if( yyin == NULL)
	{
	     printf("\n Error ! \n");
	} else {
	    printf("parsing started!\n");
	    yyparse();
	}
	
	return 0;
}