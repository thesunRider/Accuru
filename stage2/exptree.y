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

%union{
	struct tnode *no;
	
}

%type <no> expr NODE_NUM Program NODE_NODE_END NODE_ID Slist Stmt InputStmt OutputStmt AsgStmt
%token NODE_NUM NODE_PLUS NODE_MINUS NODE_MUL NODE_DIV NODE_NODE_END NODE_NODE_BEGIN NODE_READ NODE_WRITE NODE_EQUALS NODE_OP NODE_ID NODE_CONNECT NODE_BEGIN NODE_END
%left NODE_PLUS NODE_MINUS
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
	| Stmt {$$ = $1;}
	;

Stmt : InputStmt {$$ = $1;}
	| OutputStmt {$$ = $1;}
	| AsgStmt {$$ = $1;}
	;

InputStmt : NODE_READ'('NODE_ID')'';'	{$$ = createTree(0 ,0,READ ,NULL, $3, NULL);}
	;

OutputStmt : NODE_WRITE'('expr')'';' 	{printf("creat");$$ = createTree(0 ,0,WRITE ,NULL, $3, NULL);}
	;

AsgStmt : NODE_ID'='expr';' 			{$$ = createTree(0 ,0,EQUALS ,"=", $1, $3);}
	;

expr : expr NODE_PLUS expr		{$$ = createTree(0 ,0,OP ,"+", $1, $3);}
	 | expr NODE_MINUS expr  	{$$ = createTree(0 ,0,OP ,"-", $1, $3);}
	 | expr NODE_MUL expr		{$$ = createTree(0 ,0,OP ,"*", $1, $3);}
	 | expr NODE_DIV expr		{$$ = createTree(0 ,0,OP ,"/", $1, $3);}
	 | '(' expr ')'				{$$ = $2;}
	 | NODE_ID 					{$$ = $1;}
	 | NODE_NUM					{$$ = $1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 1;
}


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