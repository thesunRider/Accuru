%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h> 
	#include <signal.h>


	struct Gsymbol *localTable;
	struct Gsymbol *globalTable;
	FILE *code;
	int bindval;
	int register_index;
	int firstreg;

	#include "exptree.h"
	#include "exptree.c"

%}

%define parse.error verbose

%union{
	struct tnode *node,*param_list;
	int number;
	struct Gsymbol *decl_node;
	
}

//type and structure
%type <node> expr NODE_NUM NODE_STR Program NODE_ID Slist Stmt InputStmt OutputStmt 
%type <node> AsgStmt BrkStmnt CntStmnt Body RetStmt ArgList FDefList FDef Param ParamList

%type <number> NODE_TYPE_INT NODE_TYPE_STR Type
%type <decl_node> VarList Varcode LVarList LVarcode

//operators
%token NODE_NUM NODE_PLUS NODE_MINUS NODE_MUL NODE_DIV NODE_OP NODE_STR
%token NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS


//core keywords
%token  NODE_ID NODE_CONNECT NODE_BEGIN NODE_END NODE_BREAK NODE_CONTINUE
%token NODE_VARDECL NODE_VARENDDECL NODE_TYPE_INT NODE_TYPE_STR NODE_RETURN

//control flows
%token NODE_ENDWHILE NODE_DO NODE_WHILE NODE_IF NODE_THEN NODE_ELSE NODE_ENDIF
  

//system calls
%token NODE_READ NODE_WRITE 

//associativity
%nonassoc NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS
%left NODE_PLUS NODE_MINUS NODE_END
%left NODE_MUL NODE_DIV

%%


Program : GDeclarations NODE_BEGIN FDefList NODE_END{
				printSymbolTable(&globalTable);
				$$ = $3;
				evaluate($3,code);
				//printf($2);
				exit(1);}

		| GDeclarations NODE_BEGIN NODE_END {$$ = NULL;}
		;




GDeclarations	: NODE_VARDECL GDeclList NODE_VARENDDECL';'
				| NODE_VARDECL NODE_VARENDDECL';'
				;


GDeclList	: GDeclList GDecl
			| GDecl
			;

GDecl 	: Type VarList';' {assignType(&globalTable, $1);}
		;

FDefList 	: FDefList FDef
			| FDef
			;

FDef	: Type NODE_ID'('ParamList')''{' LDeclarations Body'}' {
																	$$ = createTree(0,0,FUNCTION_MAIN,NULL,$8,$2);
																} 
		;

Body : NODE_BEGIN Slist RetStmt NODE_END 		{
													$$ = createTree(0,0,CONNECT,NULL,$2,$3);
													//returnType = $3->type;
												}

	| NODE_BEGIN RetStmt NODE_END	';'			{
										$$ = $2;
										//returnType = $2->type;
									}
	;


Slist : Slist Stmt {$$ = createTree(0 ,0,CONNECT ,NULL, $1, $2);}
	|	Stmt {$$ = $1;}
	;


Stmt : InputStmt {$$ = $1;}
	| OutputStmt {$$ = $1;}
	| AsgStmt {$$ = $1;}
	| CntStmnt {$$ = $1;}
	| BrkStmnt {$$ = $1;}
	| RetStmt {$$ = $1;}
	| NODE_WHILE '('expr')' NODE_DO Slist NODE_ENDWHILE';' {$$ = createTree(0 ,0,WHILE ,NULL,$3, $6);}
	| NODE_IF '('expr')' NODE_THEN Slist NODE_ELSE Slist NODE_ENDIF';' {$$ = createTree(0 ,IF_DOUBLE,IF ,NULL,$3, createTree(0 ,0,CONNECT ,NULL, $6, $8));}
	| NODE_IF '('expr')' NODE_THEN Slist NODE_ENDIF';' {$$ = createTree(0 ,IF_SINGLE,IF ,NULL,$3, $6);}
	;

LDeclarations	: NODE_VARDECL LDeclList NODE_VARENDDECL';'
				| NODE_VARDECL NODE_VARENDDECL';'
				;


LDeclList	: LDeclList LDecl
			| LDecl
			;

LDecl	: Type LVarList';' {assignType(&localTable, $1);}
		;

LVarList 	: LVarcode','LVarcode 
			| LVarcode
			;

LVarcode 	: NODE_ID 	{	
							struct Gsymbol *temp = Lookup(&localTable, $1->varname);
							if(temp == NULL)	{
							
								--bindval;
								LAppendNode(&localTable, LInstall($1->varname, 0, bindval));
								$$ = Lookup( &localTable ,$1->varname);
							}
							else{

								printf("Error. Variable declared twice.\n");
								exit(1);
							}
				
						}
			;


VarList : VarList','Varcode
		| Varcode
		;




Varcode :  NODE_ID 	{	struct Gsymbol *temp = NULL;
						temp = Lookup(&globalTable ,$1->varname);
						if(temp == NULL)
						{
							Install( $1->varname, 0, 1,NULL);
							$$ = Lookup( &globalTable ,$1->varname);
						}
						else
						{
							printf("Error. Variable declared twice.\n");
							exit(1);
						}
					}

		| NODE_ID'['NODE_NUM']'			{
									struct Gsymbol *temp = NULL;
									temp = Lookup(&globalTable ,$1->varname);
									if(temp == NULL){
										Install( $1->varname, 0, $3->val,NULL);
										$$ = Lookup(&globalTable ,$1->varname);
							
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
		|	NODE_ID'('')'			{	struct Gsymbol *temp = NULL;
											temp = Lookup(&globalTable ,$1->varname);
											if(temp == NULL)
											{
												Install($1->varname, FUNCTION_ID, -1,NULL);
												//raise(SIGINT);
												$$ = Lookup(&globalTable ,$1->varname);

											}else{
												printf("Error. Function name declared twice.\n");
												exit(1);
											}

										}

		|	NODE_ID'('ParamList')'	{
											struct Gsymbol *temp = NULL;
											temp = Lookup(&globalTable ,$1->varname);

											if(temp == NULL)
											{
												Install($1->varname, FUNCTION_ID, -1,$3);
												//raise(SIGINT);
												$$ = Lookup(&globalTable ,$1->varname);
												
											}
											else
											{
												printf("Error. Function name declared twice.\n");
												exit(1);
											}
										}

		;


ParamList : ParamList','Param	{
										struct tnode *temp = NULL;
										if($1 == NULL)
											printf("Null parameter\n");
										else
											printf("Not Null parameter\n");

										temp = ParamLookup(&($1), $3->varname);
										printf("Lookup over\n");
										if(temp == NULL)
										{
											appendParamNode(&($1),$3);
											--bindval;
											LAppendNode(&localTable, LInstall($3->varname, $3->type, bindval));
											$$ = ParamLookup(&($1), $3->varname);
										}
										else
										{
											printf("Error. Parameter name already used in function.\n");
											exit(1);
										}
								}

		| Param				{
										bindval = 0;
										LAppendNode(&localTable, LInstall($1->varname, $1->nodetype, bindval));
										$$ = $1;
							}
		;


Param : Type NODE_ID { struct tnode *temp = createParamNode($2->varname, $1);
						$$ = temp;}
		;



Type : NODE_TYPE_INT {$$ = INT_TYPE;}
	 | NODE_TYPE_STR {$$ = STR_TYPE;}
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
												struct Gsymbol *temp1 = Lookup(&globalTable ,$1->varname);
			 									if(temp1)
													printf("Not Null!\n");
												else
													printf("Null!\n");

												$1->type = temp1->type;
											 	struct tnode *arrNode = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
												$$ = createTree(0 ,0,ASSIGN ,"=", arrNode, $6);
											}
		;


RetStmt : NODE_RETURN expr';' {
								$$ = createTree(0,$2->type,NODE_RETURN,NULL,$2,NULL);
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

	 | NODE_ID'('')' 					{
										struct Gsymbol *temp = Lookup(&globalTable ,$1->varname);
										if(temp == NULL)
										{
											printf("Function not declared.\n");
											exit(1);
										}
										$1->type = temp->type;
										$$ = createTree(0,$1->type,FUNCTION_TYPE,$1->varname,NULL,NULL);
									}

	 | NODE_ID'('ArgList')'				{
										struct Gsymbol *temp = Lookup(&globalTable ,$1->varname);
										if(temp == NULL)
										{
											printf("Function not declared.\n");
											exit(1);
										}
										$1->type = temp->type;
										struct tnode *temp1 = createTree(0,$1->type,FUNCTION_ARGLISTNODE,$1->varname,$3,NULL);
										$$ = temp1;
									}


	 | NODE_ID'['NODE_NUM']' 		{ 	
	 									struct Gsymbol *temp1 = Lookup(&globalTable ,$1->varname);
	 									if(temp1)
											printf("Not Null!\n");
										else
											printf("Null!\n");

										$1->type = temp1->type;
										$$ = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
									}
	 | NODE_ID 						{	
	 									struct Gsymbol *temp = Lookup(&globalTable ,$1->varname);
	 									struct Gsymbol *temp1 = Lookup(&localTable ,$1->varname);
										if(temp ){
											printf("Not Null!\n");
											$1->type = temp->type;
											$1->entry = VAR_GLOBAL;
											$$ = $1;}
										else{
											printf("Null!\n");
										}

										if(temp1 ){
											printf("Not Null!\n");
											$1->type = temp1->type;
											$1->entry = VAR_LOCAL;
											$$ = $1;
										}
										else{
											printf("Null!\n");
										}

										
									}

	 | NODE_NUM						{$$ = $1;}
	 | NODE_STR						{$$ = $1;}
	 ;


ArgList : ArgList','expr	{
								$$ = appendArg(&($1),&($3));
							}

		| expr				{
								$$ = createTree(0 ,0,FUNCTION_ARGLIST ,NULL, ($1), NULL);
							}
		;


%%



int main(void) {
	extern FILE *yyin; 

	register_index = 0;
	firstreg = 1;
	code = fopen("out.txt", "w");

	yyin = fopen("factorial", "r"); 

	if( yyin == NULL)
	{
	     printf("\n Error ! \n");
	} else {
	    printf("parsing started!\n");
	    yyparse();
	}
	
	return 0;
}