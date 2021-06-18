%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<limits.h>
	#include<string.h>
	#include"st5.h"
	#include"stack.c"
	#include"symbol.c"
	#include"codegen.c"
	#include"ast.c"
	#define YYSTYPE tnode*
	extern FILE *yyin;
	FILE* fout;
%}


%token BEG END READ WRITE NUM ID IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE
%token DECL ENDDECL INT STR LIT BRKP RETURN MAIN
%token LT "<"
%token GT ">"
%token LE "<="
%token GE ">="
%token EQ "=="
%token NE "!="
%token ADD "+"
%token SUB "-"
%token MUL "*"
%token DIV "/"
%left ADD SUB
%left MUL DIV
%nonassoc LT GT LE GE EQ NE

%%

prog : GDeclBlock FDefBlock MainBlock {
	 	showST();
	 	fprintf(fout,"%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,1,0);
	 	codeGen($2,fout);
	 	freeAllReg();
	 	codeGen($3,fout);
	 	fprintf(fout,"INT 10\n");
		printf("\nSuccessfully parsed program with fdecl\n");
		exit(1);
		}
	 |GDeclBlock MainBlock {
	 	showST();
	 	fprintf(fout,"%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP, %d\nMOV BP, %d\n",0,0,0,0,0,1,0,staticSize,staticSize);
	 	codeGen($2,fout);
	 	fprintf(fout,"INT 10\n");
	 	printf("Successfully parsed program\n");
	 	exit(1);
		}
	;


GDeclBlock : DECL GDeclList ENDDECL		{}
		   |	{}
		   ;

GDeclList  : GDeclList GDecl {}
		   | GDecl {}
		   ;

GDecl	  : Type Gidlist ';'	{	
									gAssignTypeDecl($1, $2);
								}
;

Type :	INT					{
								$$=createTypeNode(intType);}
		|STR				{$$=createTypeNode(stringType);}
		;

Gidlist	: Gidlist ',' Gid	{	
								$3->middle=$1;
								$$=$3;
								}
		|Gid				{
								$1->middle=NULL;
								$$=$1;
							} 
;

Gid		:ID		{
				gInstall($1->name,NULL,tVAR,1,0,getStaticSpace(1),NULL,NULL);
				$$=$1;
				}
		|fID '(' newParamList ')'	{
									
									gInstall($1->name,NULL,tFUNC, 0,0,NULL, $3, getFLabel());
									$1->nodetype=tFUNC;
									$$=$1;
									}
		|MUL ID	{
				gInstall($1->name,NULL,tPVAR,1,0,getStaticSpace(1),NULL,NULL);
				$2->nodetype=tPVAR;
				$$=$2;
				}
		|ID '[' NUM ']'{
				gInstall($1->name,NULL,tARR,$3->val,0,getStaticSpace($3->val),NULL,NULL);
				$1->nodetype=tARR;
				$$=$1;
		}
		|ID '[' NUM ']''[' NUM ']'{
				gInstall($1->name,NULL,tDARR,$3->val,$6->val,getStaticSpace(($3->val)*($5->val)),NULL,NULL);
				$1->nodetype=tDARR;
				$$=$1;
		}
		;
		
newParamList	:  newParamList ',' Param  {
						$3->middle=$1;
						$$=$3;
						}
		   	|  Param	{
		   				$$=$1;
					}
			|	{$$=NULL;}
;
		
fID : ID {	currFunc=strdup($1->name);}
;

FDefBlock:	 FDefBlock Fdef {
						$$ = createTree(NULL,NULL, NULL,tCONNECT,NULL, $1,NULL, $2,NULL);
						resetLocalSpace();
						}
			|Fdef {
						$$=$1;
						resetLocalSpace();
						};
			
Fdef:		Type newFID '(' validParamList ')' '{' LdeclBlock Body '}'  {
							//$8 is a (slist+return) statement node
							
							$$ = createFuncDefNode($1->type,$2->name,$8);
							resetLocalSpace();
							}
	;
newFID: ID {
			struct localTable* currTable = gLookup($1->name);
			if(currTable!=NULL){
				localTableCreate($1->name);
				currFunc=strdup($1->name);
			} else {
					yyerror("Did not declare this func\n");
			}
};

validParamList: ParamList {
						//Name Equivalence
						paramCheck(currFunc);
}
;

ParamList	:  ParamList ',' Param  {
						localEntryCreate(currFunc, $3->name, $3->type,$3->nodetype, getArgSpace());
						$3->middle=$1;
						$$=$3;
						}
			|	Param	{
						localEntryCreate(currFunc, $1->name, $1->type,$1->nodetype, getArgSpace());
					}
			|	{
				$$=NULL;}
;

Param		: Type ID {	
						$2->type = $1->type;
						$2->nodetype=tVAR;
						$$=$2;
						}
			| Type MUL ID {
				//+10?
				$3->type = $1->type;
				$3->nodetype=tPVAR;
				$$=$3;
			}
		   ;
				
LdeclBlock: DECL LDecList ENDDECL{} | DECL ENDDECL{}
;
LDecList :LDecList LDecl ';'{}
		| LDecl ';'	{}
;

LDecl: Type IdList {	
						addIdListToLocal($1, $2);
					}
;

IdList: IdList ',' IDVar {
				$3->middle =$1;
				$$=$3;
			}
		| IDVar {$$=$1;}
;
IDVar:	| ID	{
				$1->nodetype=tVAR;
				$$=$1;
			}
		| MUL ID	{
				$2->nodetype=tPVAR;
				$$=$2;
		}
;

Body	: BEG Slist Retstmt END {
				$$ = createFuncBodyNode($2, $3);	//tBODY
			}
;
Retstmt : RETURN Expr';'{
						$$=createRetNode($2);//type checkdone in ast
				}
;



MainBlock : Main '(' ')' '{' LdeclBlock Body '}'
								{
									$$ = createFuncDefNode($1->type,"main",$6);
									resetLocalSpace();
								}
;

Main: INT MAIN {
		currFunc=strdup("main");
		gInstall("main",intType,tFUNC,0,0,0,NULL,NULL);
		localTableCreate("main");
		$$=$1;
	}
;

Slist : Slist Stmt ';' {
		$$ = createTree(NULL,NULL, NULL,tCONNECT,NULL, $1,NULL, $2,NULL);
	}
	| Stmt ';'{
		$$=$1;
	}
	|{$$=NULL;}
	;

Stmt : InputStmt	//defaults to $$=$1
		|OutputStmt
		|AsgStmt 
		|IfStmt 
		|WhileStmt
		|BrkContStmt
		|Breakpoint
;

Breakpoint: BRKP {
	$$ = createTree(NULL,NULL, NULL,tBRKP,NULL, NULL,NULL, NULL,NULL);	
	};

InputStmt: READ '(' Expr ')'		{
										$$= createReadNode($3);
								};

OutputStmt: WRITE '(' Expr ')'	{	$$= createWriteNode($3);};

AsgStmt: Var '=' Expr {
					
					//checks tht exp and id have same type
					$$ = createAsgNode($1, $3);

};
Var: ID 			{	
						
						if(lookup($1->name) != NULL){
							$1->entry = lookup($1->name);
							if($1->entry->isLoc){
								//localEntry has a nodetype for tPVAR now
								$1->nodetype=($1->entry->localEntry)->nodetype;
								$1->type=($1->entry->localEntry)->type;
							} else {
								//_a_=&b
								if((($1->entry->globalEntry)->nodetype!=tVAR) && ($1->entry->globalEntry)->nodetype!=tPVAR){
									yyerror("Type mismatch: Not a variable");
								}
								$1->nodetype=($1->entry->globalEntry)->nodetype;
								$1->type=($1->entry->globalEntry)->type;
							}
						} else {
							yyerror("Variable undeclared\n");
						}
						$$ = $1;
					}
		|MUL ID {		//*p=*p+1 turns to q=*p+1
						if(lookup($2->name) != NULL){
							$2->entry = lookup($2->name);							
							if($2->entry->isLoc){
								if($2->entry->localEntry->nodetype!=tPVAR){
									yyerror("Type mismatch: Not declared as pointer variable\n");
								}
								$2->type=($2->entry->localEntry->type)-10;	//type says not pointer
								
							} else {
								if($2->entry->globalEntry->nodetype!=tPVAR){
								yyerror("Type mismatch: Not declared as pointer variable\n");
								}
								$2->type=($2->entry->globalEntry->type)-10;	//type says not pointer
							}
							$2->nodetype=tPVAR;				//nodetype says pointer
							
														
						} else {
							yyerror("Variable undeclared\n");
						}
						$$ = $2;
		}
		|ID '[' Expr ']' {	if(lookup($1->name) != NULL){
								$1->entry = lookup($1->name);
								//will never be a local variable, not even an argument
								if(($1->entry)->globalEntry->nodetype!=tARR){
									yyerror("Type mismatch: Not declared as array\n");
								}
								
								$1->nodetype=tARR;
								$1->type=($1->entry)->globalEntry->type;
								
								if($3->type==intType){
									if(($3->nodetype==tNUM) && ( $3->val >= $1->entry->globalEntry->size[0])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected interger type as offset\n");
								}
								$1->middle=$3;
							} else {
								yyerror("Variable undeclared\n");
							}				
							$$ = $1;
							}
		| ID '[' Expr ']' '[' Expr ']'{
							if(lookup($1->name) != NULL){
								$1->entry = lookup($1->name);
								//will never be a local variable, not even an argument
								if(($1->entry)->globalEntry->nodetype!=tDARR){
									yyerror("Type mismatch: Not declared as array\n");
								}
								
								$1->nodetype=tDARR;
								$1->type=($1->entry)->globalEntry->type;
								
								if($3->type==intType){
									if(($3->nodetype==tNUM) && ( $3->val >= $1->entry->globalEntry->size[0])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected interger type as offset\n");
								}
							
								if($6->type==intType){
									if(($6->nodetype==tNUM) && ( $6->val >= $1->entry->globalEntry->size[1])){
										yyerror("Array out of bounds\n");
									}
								}
								$1->right=$6;		
								$$ = $1;
							} else {
								yyerror("Variable undeclared\n");
							}	
			
		}
		;

IfStmt: IF '(' Expr ')' THEN Slist ELSE Slist ENDIF {
							
							$$ = createIfNode($3,$6,$8);
						}
		| IF '(' Expr ')' THEN Slist ENDIF {
							$$ = createIfNode($3,$6,NULL);
						}
						;
WhileStmt: WHILE '(' Expr ')' DO Slist ENDWHILE {
							$$ = createWhileNode($3,$6);
							};

BrkContStmt: BREAK { $$=createBreakNode();
					}
			| CONTINUE {
					$$=createContinueNode();
					};
Expr : Expr "+" Expr	{
							$$ = createOpNode(tADD,$1,$3);
						}
						
	| Expr "-" Expr  	{
								$$ = createOpNode(tSUB,$1,$3);
						}
	| Expr "*" Expr		{
								$$ = createOpNode(tMUL,$1,$3);
						}
	| Expr "/" Expr		{
								$$ = createOpNode(tDIV,$1,$3);
						}
	| Expr "<" Expr		{		
								$$ = createOpNode(tLT,$1,$3);
						}
	| Expr ">" Expr		{	
								$$ = createOpNode(tGT,$1,$3);
						}
	| Expr "<=" Expr		{
								$$ = createOpNode(tLE,$1,$3);
						}
	| Expr ">=" Expr		{
								$$ = createOpNode(tGE,$1,$3);
						}
	| Expr "==" Expr	{
							$$ = createOpNode(tEQ,$1,$3);
						}
	| Expr "!=" Expr	{
							$$ = createOpNode(tNE,$1,$3);
						}
	| '(' Expr ')'		{$$ = $2;}
	| NUM				{$$ = $1;}
	| ID				{	
							if(lookup($1->name) != NULL){
								$1->entry = lookup($1->name);
								//lookup creates the entry acc to where it finds the var declared
								if($1->entry->isLoc){
									$1->type=($1->entry->localEntry)->type;
									if(($1->entry->localEntry)->nodetype!=tVAR && ($1->entry->localEntry)->nodetype!=tPVAR){
										printf("%s\n",$1->name);
										yyerror("Type mismatch: Expected Var or PVar \n");
									}
									$1->nodetype=$1->entry->localEntry->nodetype;
								}
								else {
									$1->type=($1->entry->globalEntry)->type;								
									if(($1->entry->globalEntry)->nodetype!=tVAR && ($1->entry->globalEntry)->nodetype!=tPVAR){
										yyerror("Type mismatch: Expected Var \n");
									}
									$1->nodetype=($1->entry->globalEntry)->nodetype;
								}
							} else {
								printf("%s\n:",$1->name);
								yyerror("Variable undeclared\n");
							}
						$$ = $1;
						}
	| MUL ID {		
					if(lookup($2->name) != NULL){
						$2->entry = lookup($2->name);
						if($2->entry->isLoc){						
							if($2->entry->localEntry->nodetype==tPVAR){
								$2->type=($2->entry->localEntry)->type-10;
								$2->nodetype=tDEREF;
								$$=$2;
							} else {
								yyerror("Type mismatch: Expected Pointer\n");
							}
						} else {
							if($2->entry->globalEntry->nodetype==tPVAR){
									$2->type=($2->entry->globalEntry)->type-10;
									$2->nodetype=tDEREF;
									$$=$2;
								} else {
									yyerror("Type mismatch: Expected Pointer\n");
								}
					
							}
					} else {
						yyerror("Variable undeclared\n");
					}
					$$ = $2;
			}	
	| '&' ID {	
				if(lookup($2->name) != NULL){
						$2->entry = lookup($2->name);
						
						if($2->entry->isLoc){						
								if($2->entry->localEntry->nodetype==tVAR){
								$2->type=($2->entry->localEntry)->type+10;
								$2->nodetype=tREF;
								$$=$2;
							} else {
								yyerror("Type mismatch: Expected Variable after &\n");
							}
						} else {
							if($2->entry->globalEntry->nodetype==tVAR){
								$2->type=($2->entry->globalEntry)->type+10;
								$2->nodetype=tREF;
								$$=$2;
							} else {
								yyerror("Type mismatch: Expected Variable after &\n");
							}
						}
					
				} else {
						yyerror("Variable undeclared\n");
					}
				$$ = $2;
			}
	| '&' ID '[' Expr ']' {
					if(lookup($2->name) != NULL){
						$2->entry = lookup($2->name);
						//can't be local
						if($2->entry->globalEntry->nodetype==tARR){
								$2->type=($2->entry->globalEntry)->type+10;
								$2->nodetype=tREF;
								$$=$2;
								if($4->type==intType){
									$2->middle = $4;
									if(($3->nodetype==tNUM) && ( $4->val >= $2->entry->globalEntry->size)){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
						} else {
								yyerror("Type mismatch: Expected Array after &\n");
						}
					} else {
							yyerror("Array undeclared\n");
						}
				$$ = $2;
					
	}
	|ID  '[' Expr ']' {
						if(lookup($1->name) != NULL){
								$1->entry = lookup($1->name);
								//must be global
								$1->type=($1->entry->globalEntry)->type;
								if(($1->entry->globalEntry)->nodetype!=tARR){
									yyerror("Type mismatch: Expected Array\n");
								}
								$1->nodetype=tARR;
								if($3->type==intType){
									$1->middle = $3;
									if(($3->nodetype==tNUM) && ( $3->val >= $1->entry->globalEntry->size)){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
								$$=$1;
							} else {
								yyerror("Variable undeclared\n");
							}
	
	}
	|ID  '[' Expr ']' '[' Expr ']' {
						if(lookup($1->name) != NULL){
								$1->entry = lookup($1->name);
								$1->type=($1->entry->globalEntry)->type;
								if(($1->entry->globalEntry)->nodetype!=tDARR){
									yyerror("Type mismatch: Expected Double Array\n");
								}
								$1->nodetype=tDARR;
								if($3->type==intType){
									$1->middle = $3;
									if(($3->nodetype==tNUM) && ( $3->val >= $1->entry->globalEntry->size[0])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
								if($6->type==intType){
									$1->right = $6;
									if(($6->nodetype==tNUM) && ( $6->val >= $1->entry->globalEntry->size[1])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
								$$=$1;
							} else {
								yyerror("Variable undeclared\n");
							}
	
	}
	
	| LIT {$$ = $1;}
	| ID '(' ArgList ')'  {	char *retFunc = strdup(currFunc);
							currFunc=strdup($1->name);
							$$ = createFuncCallNode($1->name,$3);
							currFunc=retFunc;
							}
;

ArgList: ArgList ',' Expr {	$3->arglist=$1;
							$$=$3;}
		| Expr {$$=$1;}
		|{$$=NULL;}
;



%%

int getStaticSpace(int size){
	//upto 5119
	if(staticSize+size >= 5119){
		yyerror("No space for allocation\n");
		exit(1);
	}
	staticSize+=size;
	return staticSize-size;
}

yyerror(char const *s)
{	showST();
	printf("error: %s\n",s);
	exit(1);
}

int getLocalSpace(){
	return localOffset++;
}

int getArgSpace(){
	return argOffset--;
}

void resetLocalSpace(){
	localOffset=1;
	argOffset=-3;
}
int main(int argc, char* argv[])
{
	
	extern FILE *yyin; 

	tempreg = 0;
	
	yyin = fopen("func", "r");
	fout = fopen("ous.txt", "w");
		

	yyparse();
	return 0;
}

