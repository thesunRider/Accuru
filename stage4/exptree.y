%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h> 
	int yylex(void);
	int yyerror(char const *s);
	FILE *code;
	int register_index;
	int firstreg;

	struct Gsymbol *symbolTable = NULL;

	#include "exptree.h"
	#include "exptree.c"

%}

%define parse.error verbose

%union{
	struct tnode *node;
	int number;
	struct Gsymbol *decl_node;
	
}

//type and structure
%type <node> expr NODE_NUM NODE_STR Program NODE_ID Slist Stmt InputStmt OutputStmt 
%type <node> AsgStmt BrkStmnt CntStmnt
%type <number> NODE_TYPE_INT NODE_TYPE_STR Type
%type <decl_node> VarList

//operators
%token NODE_NUM NODE_PLUS NODE_MINUS NODE_MUL NODE_DIV NODE_OP NODE_STR
%token NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS


//core keywords
%token  NODE_ID NODE_CONNECT NODE_BEGIN NODE_END NODE_BREAK NODE_CONTINUE
%token NODE_VARDECL NODE_VARENDDECL NODE_TYPE_INT NODE_TYPE_STR

//control flows
%token NODE_ENDWHILE NODE_DO NODE_WHILE NODE_IF NODE_THEN NODE_ELSE NODE_ENDIF
  

//system calls
%token NODE_READ NODE_WRITE 

//associativity
%nonassoc NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS
%left NODE_PLUS NODE_MINUS NODE_END
%left NODE_MUL NODE_DIV

%%


Program : Declarations NODE_BEGIN Slist NODE_END {
				printSymbolTable(&symbolTable);
				$$ = $3;
				evaluate($3,code);
				//printf($2);
				exit(1);}

		| Declarations NODE_BEGIN NODE_END {$$ = NULL;}
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


Declarations	: NODE_VARDECL DeclList NODE_VARENDDECL';'
				| NODE_VARDECL NODE_VARENDDECL';'
				;

DeclList	: DeclList Decl 
			| Decl
			;

Decl 	: Type VarList';' {assignType(&symbolTable, $1);}
		;

Type : NODE_TYPE_INT {$$ = INT_TYPE;}
	 | NODE_TYPE_STR {$$ = STR_TYPE;}
	 ;

VarList : VarList','NODE_ID {	struct Gsymbol *temp = NULL;
								temp = Lookup($3->varname);
								if(temp == NULL)
								{
									Install($3->varname, 0, 1);
									$$ = Lookup($3->varname);
								}
								else
								{
									printf("Error. Variable declared twice.\n");
									exit(1);
								}
							}

		| NODE_ID 	{	struct Gsymbol *temp = NULL;
						temp = Lookup( $1->varname);
						if(temp == NULL)
						{
							Install( $1->varname, 0, 1);
							$$ = Lookup( $1->varname);
						}
						else
						{
							printf("Error. Variable declared twice.\n");
							exit(1);
						}
					}

		| VarList','NODE_ID'['NODE_NUM']' { struct Gsymbol *temp = NULL;
									temp = Lookup($3->varname);
									if(temp == NULL)
									{
										Install($3->varname, 0, $5->val);
										$$ = Lookup($3->varname);
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
		| NODE_ID'['NODE_NUM']'			{
									struct Gsymbol *temp = NULL;
									temp = Lookup($1->varname);
									if(temp == NULL){
										Install( $1->varname, 0, $3->val);
										$$ = Lookup($1->varname);
							
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
		;


CntStmnt : NODE_CONTINUE';' {$$ = createTree(0 ,0,CONTINUE ,NULL, NULL, NULL);}
BrkStmnt : NODE_BREAK';' {$$ = createTree(0 ,0,BREAK ,NULL, NULL, NULL);}
	;

InputStmt : NODE_READ'('expr')'';'	{$$ = createTree(0 ,0,READ ,NULL, $3, NULL);}
	;

OutputStmt : NODE_WRITE'('expr')'';' 	{$$ = createTree(0 ,0,WRITE ,NULL, $3, NULL);}
	;

AsgStmt : NODE_ID'='expr';' 				{$$ = createTree(0 ,0,ASSIGN ,"=", $1, $3);}
		| NODE_ID'['NODE_NUM']''='expr';'	{	
												struct Gsymbol *temp1 = Lookup($1->varname);
			 									if(temp1)
													printf("Not Null!\n");
												else
													printf("Null!\n");

												$1->type = temp1->type;
											 	struct tnode *arrNode = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
												$$ = createTree(0 ,0,ASSIGN ,"=", arrNode, $6);
											}
		;



expr : expr NODE_GRT expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<", $1, $3);}
	 | expr NODE_LES expr  			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">", $1, $3);}
	 | expr NODE_GEQ expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<=", $1, $3);}
	 | expr NODE_LEQ expr 			{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">=", $1, $3);}
	 | expr NODE_NEQUALS expr 		{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"!=", $1, $3);}
	 | expr NODE_EQUALS expr 		{$$ = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"==", $1, $3);}
	 | expr NODE_PLUS expr			{$$ = createTree(0 ,0,OP ,"+", $1, $3);}
	 | expr NODE_MINUS expr  		{$$ = createTree(0 ,0,OP ,"-", $1, $3);}
	 | expr NODE_MUL expr			{$$ = createTree(0 ,0,OP ,"*", $1, $3);}
	 | expr NODE_DIV expr			{$$ = createTree(0 ,0,OP ,"/", $1, $3);}
	 | '(' expr ')'					{$$ = $2;}
	 | NODE_ID'['NODE_NUM']' 		{ 	
	 									struct Gsymbol *temp1 = Lookup($1->varname);
	 									if(temp1)
											printf("Not Null!\n");
										else
											printf("Null!\n");

										$1->type = temp1->type;
										$$ = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
									}
	 | NODE_ID 						{	
	 									struct Gsymbol *temp = Lookup($1->varname);
										if(temp)
											printf("Not Null!\n");
										else
											printf("Null!\n");
										$1->type = temp->type;
										$$ = $1;
									}

	 | NODE_NUM						{$$ = $1;}
	 | NODE_STR						{$$ = $1;}
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