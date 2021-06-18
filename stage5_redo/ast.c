struct tnode* createTree(int val,int type, char* c, int nodetype, struct tableEntry * st, struct tnode *l,struct tnode *m, struct tnode *r, struct tnode *arglist){
	struct tnode* t = (struct tnode*)malloc(sizeof(struct tnode));
	t->val = val;
	t->type = type;
	t->name = c;
	t->nodetype= nodetype;
	t->entry=st;
	t->arglist=arglist;
	t->left = l;
	t->middle = m;
	t->right = r;
	return t;
}

struct tnode* createVarNode(char* c){
		return createTree(NULL,NULL, c, NULL, NULL,NULL, NULL ,NULL,NULL);
		
}

struct tnode* createLiteralNode(char* c){
		return createTree(NULL,stringType, c, tLIT, NULL,NULL, NULL ,NULL,NULL);
		
}

struct tnode * createTypeNode(int type){
	return createTree(NULL,type, NULL,NULL,NULL,NULL,NULL,NULL,NULL);
}


struct tnode * createRetNode(struct tnode* expr){
	struct globalEntry* gentry = gLookup(currFunc);
	if(expr->type==gentry->type){
		return createTree(NULL,expr->type, NULL,tRET,NULL,NULL,expr,NULL,NULL);
	} else {
		yyerror("Return type mismatch\n");
	}
}

struct tnode * createFuncBodyNode(struct tnode* slist, struct tnode* ret){
	return createTree(NULL,ret->type, NULL, tBODY, NULL,slist, NULL ,ret,NULL);
}

struct tnode * createFuncDefNode(int retType, char *funcName, struct tnode* body){
	struct globalEntry* gentry = gLookup(funcName);
	struct localTable* lentry = localTableLookup(funcName);
	struct tableEntry* entry = (struct tableEntry*) malloc(sizeof(struct tableEntry));
		entry->globalEntry= gentry;
		entry->localTable=lentry;
		entry->isLoc=2;
	
	
	if(retType==body->type){
		return createTree(NULL,retType, funcName, tFUNC, entry ,NULL, body ,NULL,NULL);
	}

}


struct tnode * createFuncCallNode(char * funcName, struct tnode * arglist){
	
	struct tableEntry * entry = (struct tableEntry *) malloc (sizeof(struct tableEntry));
	struct globalEntry* gtemp = gLookup(funcName);
	struct tnode* paramlist,*arg;
	
	arg = arglist;
	
	if(gtemp == NULL){
					yyerror("Yacc : Undeclared function");
		}
	
	paramlist = gtemp->paramlist;
	while(paramlist!=NULL && arglist!=NULL){
		if(paramlist->type!=arglist->type){
			printf("%d,%d",paramlist->type,arglist->type);
			yyerror("Arguments call type mismatch\n");
		}
		paramlist=paramlist->middle;
		arglist=arglist->arglist;
	}
	if((paramlist!=NULL && arglist==NULL) || (paramlist==NULL && arglist!=NULL)){
		if(arglist==NULL) {printf("not enough arguments\n");}
		else printf("too many arguments\n");
		yyerror("Parameter-argument number mismatch\n");
		
	}
	
	
	entry->isLoc=0;
	entry->globalEntry=gtemp;
	//using middle for first arg in arglist.
	return createTree(NULL,gtemp->type, funcName, tFCALL, entry ,NULL, arg ,NULL,NULL);
	
}




//int/str *p,*c
//int/str q, a
//TODO learn all this perfectly//refactor to be better
//p=&q
//p=c
//pvar = deref + num
//*p = *p+1
//q = *p
//q = a
struct tnode* createAsgNode(struct tnode *l, struct tnode *r){

	if(	l->nodetype==tPVAR &&
		(r->nodetype==tREF || r->nodetype==tPVAR) && //ref(treated as a pvar) both addresses
		(l->type == r->type)
		){
			return createTree(NULL,NULL, NULL,tASSIGN,NULL, l, NULL,r,NULL);
		}
	else if((l->nodetype==tVAR||  l->nodetype==tARR || l->nodetype==tDARR || l->nodetype == tPVAR) && //expr should be value. not pointer
			(r->nodetype!= tREF && r->nodetype != tPVAR) &&
			//can be defer(trated as a var), or a var/arr/darr- all just values, not addresses  
			(l->type == r->type)){
		return createTree(NULL,NULL, NULL,tASSIGN,NULL, l, NULL,r,NULL);
	}else{
		printf("%s:%d,%d\n,%d,%d",l->name,	l->nodetype,	l->type,	r->nodetype,	r->type);
		yyerror("Type mismatch - cannot assign \n");
		}
		
}



struct tnode* createNumNode(int val){
	return createTree(val,intType, NULL,tNUM, NULL,NULL,NULL,NULL,NULL);
}

struct tnode* createOpNode(int nodetype, struct tnode *l, struct tnode *r){
	if ((l->type == intType) && (r->type==intType)){
		switch(nodetype){
			case tADD:
			case tSUB:
			case tMUL:
			case tDIV:
					return createTree(NULL, intType, NULL,nodetype,NULL, l, NULL, r,NULL);
					break;
			case tLT:
			case tGT:
			case tLE:
			case tGE:
			case tEQ:
			case tNE:
					return createTree(NULL, boolType, NULL,nodetype,NULL, l, NULL, r,NULL);
					break;
			}
		}
	else{	showST();
			printf("Type mismatch %d,%d %d,%d\n",l->nodetype,l->type,r->nodetype,r->type);
			exit(1);
		}
}


struct tnode* createReadNode(struct tnode *r){
	if(r->nodetype==tVAR || r->nodetype==tARR|| r->nodetype==tDARR || r->nodetype==tDEREF){
		return createTree(NULL, NULL ,NULL, tREAD,NULL, NULL, NULL, r,NULL);
	} else {
		yyerror("Expected variable for Read\n");
	}
	
}

struct tnode* createWriteNode(struct tnode *r){
	if(((r->type) == intType) || ((r->type) == stringType)){
		return createTree(NULL,NULL, NULL, tWRITE,NULL, NULL, NULL, r,NULL);
	}else {
		yyerror("Type mismatch- can't write\n");
		}
}

struct tnode* createIfNode(struct tnode *l, struct tnode *m, struct tnode *r){
	if((l->type) == boolType)
		return createTree(NULL,NULL, NULL, tIF,NULL, l, m, r,NULL);
	else{
		yyerror("Type mismatch - guard of if must be a conditional\n");
		}
}

struct tnode* createWhileNode(struct tnode *l, struct tnode *r){
	if((l->type) == boolType){
		return createTree(NULL,NULL, NULL,tWHILE,NULL, l, NULL,r,NULL);
	}else{
		yyerror("Type mismatch - guard of while must be a conditional\n");
		}
}

struct tnode* createBreakNode(){
	return createTree(NULL, NULL ,NULL, tBREAK,NULL, NULL, NULL, NULL,NULL);
}
struct tnode* createContinueNode(){
	return createTree(NULL, NULL ,NULL, tCONTINUE,NULL, NULL, NULL, NULL,NULL);
}



