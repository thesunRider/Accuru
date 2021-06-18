%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h> 
	int yylex(void);
	int yyerror(char const *s);
	FILE *code;
	int register_index;
	int firstreg;

	//externs for lex go here
	int inside_function = 0; //0 false 1 true
	int inside_declaration = 0; 
	int inside_type = 0; 


	///counts
	int current_stack_base = 0; //this points out to the base of memory
	int param_count = 0;
	int local_count = 0;

	struct Gsymbol *localsymbolTable = NULL;
	struct Gsymbol *globalsymbolTable = NULL;
	struct PTable *paramTable = NULL;
	struct Fsymbol *funcTable = NULL;
	struct tnode *current_function = NULL; //this is an array storing which function is being parsed now


	#include "exptree.h"
	#include "exptree.c"

%}

%define parse.error verbose

%union{
	struct tnode *node;
	int type_node;
	struct Gsymbol *var_node;
	struct PTable *param_node;
}

//type and structure
%type <node> expr NODE_NUM NODE_STR Program NODE_ID Slist Stmt InputStmt OutputStmt FunctionType
%type <node> AsgStmt BrkStmnt CntStmnt FunctionBlock FunctionList FuncallStmt arglist RetStmnt
%type <type_node> NODE_TYPE_INT NODE_TYPE_STR NODE_TYPE Type CustomType
%type <var_node> VarList 
%type <param_node> Paramlist Decl DeclList Declarations

//operators
%token NODE_NUM NODE_PLUS NODE_MINUS NODE_MUL NODE_DIV NODE_OP NODE_STR
%token NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS 


//core keywords
%token  NODE_ID NODE_CONNECT NODE_BEGIN NODE_END NODE_BREAK NODE_CONTINUE NODE_RETURN
%token NODE_VARDECL NODE_VARENDDECL NODE_TYPE_INT NODE_TYPE_STR NODE_TYPE_BOOL NODE_TYPE

//control flows
%token NODE_ENDWHILE NODE_DO NODE_WHILE NODE_IF NODE_THEN NODE_ELSE NODE_ENDIF
  

//system calls
%token NODE_READ NODE_WRITE 

//associativity
%nonassoc NODE_GRT NODE_LES NODE_GEQ NODE_LEQ NODE_NEQUALS NODE_EQUALS
%left NODE_PLUS NODE_MINUS NODE_END
%left NODE_MUL NODE_DIV

%%


Program : Declarations NODE_BEGIN FunctionList NODE_END {
				printf("\n------------GLobal SymbolTable--------------");
				printSymbolTable(&globalsymbolTable);
				pushglobals(code); //push global variables to code
				$$ = $3;

				struct tnode *temp = NULL;
				temp = $3;

				printf("\n yacc>> ");
				//exit(1);
				evaluate($3,code);
				//printf($2);
				exit(1);}

		| Declarations NODE_BEGIN NODE_END {$$ = NULL;}
		;

FunctionList 	: FunctionList FunctionBlock {$$ = appendTree($1,createTree(0,0,FUNCTION_LIST,NULL,NULL,$2));}
				| FunctionBlock {$$ = createTree(0,0,FUNCTION_LIST,NULL,NULL,$1);}
				;


FunctionBlock	: Type NODE_ID'('Paramlist')' '{' Declarations Slist '}' {
								printf("\nyacc>>function block with paramlist\n");
								struct PTable *temp = NULL;
								temp = $7;

								struct tnode *temp2 = NULL;
								temp2 = $2;

								InstallLocals($7,$2->varname);
								$$ = createTree(0 ,0,FUNCTION_CONNECT ,$2->varname, NULL, $8);
				
				}

				| Type NODE_ID'('')' '{' Declarations Slist '}'	{
								printf("\nyacc>>function block without paramlist\n");
								InstallLocals($6,$2->varname);
								$$ = createTree(0 ,0,FUNCTION_CONNECT ,$2->varname, NULL, $7);
				}

				;

FunctionTypeList 	: FunctionTypeList FunctionType
					| FunctionType 
					;

FunctionType	:	FunctionType','Type NODE_ID'('')'';' { 
												param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc($3,$4->varname,NULL);
											}
										}


				|	Type NODE_ID'('')'';' {
											param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc($1,$2->varname,NULL);
											}
										}

			 	|	FunctionType','Type NODE_ID'('Paramlist')'';' {

											param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc($3,$4->varname,$6);
											}
										}


				|	Type NODE_ID'('Paramlist')'';' {

											param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc($1,$2->varname,$4);
											}
										}
			 	;	

Paramlist	: Paramlist','Type NODE_ID 
							{ 
								struct Gsymbol *temp = NULL;
								temp = Lookup($4->varname);
								if (inside_function){
									if (temp==NULL){
										printf("\n Those variables arent declared");
									}
								}

								if (inside_declaration == 1){
									++param_count;
									Install($4->varname,$3,1);
									Lookup($4->varname)->env_type = 2;
									$$ = InstallParam($1,$4->varname,$3,param_count);
								}else{
									$$ = NULL; //when not declaring we pass param list empty
								}
							}

			| Type NODE_ID {	struct Gsymbol *temp = NULL;
								temp = Lookup($2->varname);
								if (inside_function){
									if (temp==NULL){
										printf("\n Those variables arent declared");
									}
								}
								if (inside_declaration == 1){
									//globally declaring the function
									++param_count;
									Install($2->varname,$1,1);
									Lookup($2->varname)->env_type = 2;
									$$ = createParam($2->varname,$1,param_count);	
								}
								else
								{
									$$ = NULL;
								}
							}
			;

Declarations	: NODE_VARDECL DeclList FunctionTypeList NODE_VARENDDECL';' {$$ = $2;}
				| NODE_VARDECL DeclList NODE_VARENDDECL';' {$$ = $2;}
				| NODE_VARDECL NODE_VARENDDECL';' {$$ = NULL;}
				;

DeclList	: DeclList Decl';' {$$ = InstallDeclType($1,$2);}
			| Decl';'	{$$ = $1;}
			;

Decl 	: Type VarList {
							if (inside_declaration == 1 && inside_function == 0)
							{
								//declared in global section
								assignType(&globalsymbolTable, $1);
								assignType(&$2, $1);
							}else if (inside_declaration == 1 && inside_function == 1){
								//declared inside a function
								assignType(&$2, $1);
							}
							$$ = createDeclType($1,$2);
						}
		;


Type : NODE_TYPE_INT {$$ = INT_TYPE;}
	 | NODE_TYPE_STR {$$ = STR_TYPE;}
	 ;


VarList : VarList','NODE_ID {	struct Gsymbol *temp = NULL;
								temp = Lookup($3->varname);
								if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
								{
									Install($3->varname, 0, 1);
									$$ = Lookup($3->varname);
								}
								else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
								{ //all those declared inside functions goes to local table
									++local_count;
									$$ = appendlocalTable($1,createlocal($3->varname, 0, 1,local_count));
								}
								else
								{
									if (inside_function != 1 && inside_declaration != 0) {
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
							}

		| NODE_ID 	{	struct Gsymbol *temp = NULL;
						temp = Lookup( $1->varname);
						if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
						{
							Install( $1->varname, 0, 1);
							$$ = Lookup( $1->varname);
						}
						else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
								{
									++local_count;
									$$ = createlocal($1->varname, 0,1,local_count);
								}
						else
						{
							if (inside_function != 1 && inside_declaration != 0) {
										printf("Error. Variable declared twice.\n");
										exit(1);
									};
						};
					}

		| VarList','NODE_ID'['NODE_NUM']' { struct Gsymbol *temp = NULL;
									temp = Lookup($3->varname);
									if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
									{
										Install($3->varname, 0, $5->val);
										$$ = Lookup($3->varname);
									}
									else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
									{
										++local_count;
										$$ = appendlocalTable($1,createlocal($3->varname, 0,1,local_count));
									}
									else
									{
										if (inside_function != 1 && inside_declaration != 0) {
											printf("Error. Variable declared twice.\n");
											exit(1);
										}
									}
								}
		| NODE_ID'['NODE_NUM']'			{
									struct Gsymbol *temp = NULL;
									temp = Lookup($1->varname);
									if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
									{	Install( $1->varname, 0, $3->val);
										$$ = Lookup($1->varname);
							
									}
									else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
									{
										
										$$ = createlocal($1->varname, 0,1,local_count);
									}
									else
									{
										if (inside_function != 1 && inside_declaration != 0) {
											printf("Error. Variable declared twice.\n");
											exit(1);
										}
									}
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
	| FuncallStmt {$$ = $1;}
	| RetStmnt {$$ = $1;}
	| NODE_WHILE '('expr')' NODE_DO Slist NODE_ENDWHILE';' {$$ = createTree(0 ,0,WHILE ,NULL,$3, $6);}
	| NODE_IF '('expr')' NODE_THEN Slist NODE_ELSE Slist NODE_ENDIF';' {$$ = createTree(0 ,IF_DOUBLE,IF ,NULL,$3, createTree(0 ,0,CONNECT ,NULL, $6, $8));}
	| NODE_IF '('expr')' NODE_THEN Slist NODE_ENDIF';' {$$ = createTree(0 ,IF_SINGLE,IF ,NULL,$3, $6);}
	;

RetStmnt :	NODE_RETURN FuncallStmt';' {$$ = createTree(0,0,FUNCTION_RETURN,NULL, NULL, $2);}
		 |	NODE_RETURN expr';' 		{$$ = createTree(0,0,FUNCTION_RETURN,NULL, NULL, $2);}
		 |	NODE_RETURN';'			{$$ = createTree(0,0,FUNCTION_RETURN,NULL, NULL, NULL);}
		 ;

CntStmnt : NODE_CONTINUE';' {$$ = createTree(0 ,0,CONTINUE ,NULL, NULL, NULL);}
BrkStmnt : NODE_BREAK';' {$$ = createTree(0 ,0,BREAK ,NULL, NULL, NULL);}
	;

InputStmt : NODE_READ'('expr')'';'	{$$ = createTree(0 ,0,READ ,NULL, $3, NULL);}
	;

OutputStmt : NODE_WRITE'('expr')'';' 	{$$ = createTree(0 ,0,WRITE ,NULL, $3, NULL);}
	;

AsgStmt : NODE_ID'='expr';' 				{
												struct Gsymbol *symb = Lookup($1->varname);
												if(symb != NULL)
													$1->type = symb->type;
												else
													printf("yacc>>Probably some untyped variable\n");
												
												$$ = createTree(0 ,0,ASSIGN ,"=", $1, $3);
											}
		| NODE_ID'['NODE_NUM']''='expr';'	{	
												struct Gsymbol *temp1 = Lookup($1->varname);
			 									if(temp1)
													printf("\nyacc>>Not Null!\n");
												else
													printf("\nyacc>>Null!\n");

												$1->type = temp1->type;
											 	struct tnode *arrNode = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
												$$ = createTree(0 ,0,ASSIGN ,"=", arrNode, $6);
											}
		| NODE_ID'='FuncallStmt			{
												struct Gsymbol *symb = Lookup($1->varname);
												if(symb != NULL)
													$1->type = symb->type;
												else
													printf("yacc>>Probably some untyped variable\n");

												$$ = createTree(0 ,0,ASSIGN ,"=", $1, $3);
											}
		| NODE_ID'['NODE_NUM']''='FuncallStmt	{	
												struct Gsymbol *temp1 = Lookup($1->varname);
			 									if(temp1)
													printf("\nyacc>>Not Null!\n");
												else
													printf("\nyacc>>Null!\n");

												$1->type = temp1->type;
											 	struct tnode *arrNode = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
												$$ = createTree(0 ,0,ASSIGN ,"=", arrNode, $6);
											}
		;

FuncallStmt :	NODE_ID'('arglist')'';' 	{	if (inside_function)
											{
												struct Gsymbol *temp1 = Lookup($1->varname);
			 									if(temp1 == NULL){
													printf("yacc>>Undefined Function\n");
													exit(1);
			 									}
			 									$1->type = temp1->type;
												$$ = createTree(0,0,FUNCTION_CALL,NULL,$3,$1);
											}
											else{
												printf("yacc>>Function cannot be called from outside\n");
												exit(1);
											}
										}
			|	NODE_ID'('')'';'		{ if (inside_function)
											{
												struct Gsymbol *temp1 = Lookup($1->varname);
			 									if(temp1 == NULL){
													printf("yacc>>Undefined Function\n");
													exit(1);
			 									}
			 									$1->type = temp1->type;
			 									$$ = createTree(0,0,FUNCTION_CALL,NULL,NULL,$1);
	 										}else{
	 											printf("yacc>>Function cannot be called from outside\n");
												exit(1);
	 										}

										}
			;

arglist 	: arglist','expr 	{
									$$ = appendTree($1,createTree(0,0,FUNCTION_ARGUMENT_LIST,NULL,NULL,$3));
								}
			| expr {$$ = createTree(0,0,FUNCTION_ARGUMENT_LIST,NULL,NULL,$1);}
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
											printf("yac>>Not Null!\n");
										else
											printf("yacc>>Null!\n");

										$1->type = temp1->type;
										$$ = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
									}
	 | NODE_ID 						{
	 									struct Gsymbol *temp = Lookup($1->varname);
										if(temp){
											printf("\nyacc>>Not Null!\n");
											$1->type = temp->type;
										}
										else
										{
											$1->type = VAR_UNDEF;
											printf("\nyacc>>Null!\n");
										}
										$$ = $1;
									}

	 | NODE_NUM						{$1->type = INT_TYPE;$$ = $1;}
	 | NODE_STR						{$1->type = STR_TYPE;$$ = $1;}
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