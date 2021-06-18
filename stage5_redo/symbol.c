struct tableEntry{
	int isLoc;
	struct globalEntry* globalEntry;
	struct localEntry* localEntry;
	struct localTable* localTable;
};

struct globalEntry{
	char *name; //name of the variable or function
	int type; //type of the variable:(Integer / String)
	int size[2]; //size of an array
	int nodetype;
	int binding; //static binding of global variables
	struct tnode *paramlist;//pointer to the head of the formal parameter list
									//in the case of functions
	int flabel; //a label for identifying the starting address of a function's code
	struct globalEntry *next; //points to the next Global Symbol Table entry
}; 


struct localEntry{
	char *name; //name of the variable
	int type; //type of the variable:(Integer / String)
	int nodetype; //just for pointer/var
	int binding; //local binding of the variable
	struct localEntry *next;//points to the next Local Symbol Table entry
}; 


struct localTable{
	char *funcName; //name of the function
	struct localEntry * localEntry; //points to the first param in this function's Local Symbol Table
	struct localTable *next;
};


struct localTable* localTableLookup(char *name){
    struct localTable* current = allLST;  // Initialize current
    while (current != NULL)
    {
        if (strcmp(name,current->funcName)==0){
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct localTable* localTableCreate(char *name){
	
	if(localTableLookup(name) == NULL){
		struct localTable* table = (struct localTable*) malloc(sizeof(struct localTable));
		table->funcName = strdup(name);
		table->next = allLST;
		allLST = table;
		return table;
	} else {
		yyerror("Function already declared\n");	//
		return NULL;
	}
}



void localEntryCreate(char *funcName, char *varName, int type,int nodetype, int binding){

	struct localTable * current = localTableLookup(funcName);  
	
	//check if it already exists in lookup
    if (current != NULL)
    {
        struct localEntry * currParam =  (struct localEntry*) malloc(sizeof(struct localEntry));
        currParam->name = strdup(varName);
        if(nodetype==tPVAR) type+=10;
        currParam->type = type;
        currParam->nodetype = nodetype;
        currParam->binding=binding;
        
        currParam->next = current->localEntry;	//new entry
        current->localEntry =currParam;	//update table
    }
    return NULL;
}

int paramCheck(char * funcName){
	struct globalEntry * gEntry = gLookup(funcName);
	struct localTable * lTable = localTableLookup(funcName);
	
	struct tnode * gParam = gEntry->paramlist;
	struct localEntry * lParam = lTable->localEntry;
	
	
	
	while(gParam!=NULL && lParam!=NULL){
		if ((strcmp(gParam->name,lParam->name)==0) &&(gParam->type==lParam->type)){
            gParam=gParam->middle;
            lParam=lParam->next;
        } else {
        showST();
        	yyerror("Parameter name/type mismatch");
        }
	}
	
	if((gParam!=NULL && lParam==NULL)){
		yyerror("Parameter number mismatch, too many in gparam\n");
		}
	if(gParam==NULL && lParam!=NULL){
		yyerror("Parameter number mismatch, too many in lparam\n");
	}

}



struct localEntry * localEntryLookup(char * funcName, char * varName){
    struct localTable * current = allLST;
    while (current != NULL)
    {
        if (strcmp(funcName,current->funcName)==0){
            break;
    	}
        current = current->next;
    }
    
    if((current != NULL)){
    	 struct localEntry * currEntry = current->localEntry;
    	 while (currEntry != NULL)
			{
				if (strcmp(varName,currEntry->name)==0){
				    return currEntry;
			}
				currEntry = currEntry->next;
			}
    	 
    }
    
    return NULL;
}

struct globalEntry * gLookup(char * name){
    struct globalEntry * current = symtable;
    while (current != NULL)
    {
        if (strcmp(name,current->name)==0){
            return current;}
        current = current->next;
    }
    return NULL;
}


struct tableEntry * lookup(char * name){

	struct tableEntry * entryForVar = (struct tableEntry *)malloc(sizeof(struct tableEntry));
	
	struct localEntry * loc = localEntryLookup(currFunc, name);
	struct globalEntry* glo = gLookup(name);
	
	if(loc!=NULL){
		entryForVar->isLoc =1;
		entryForVar->localEntry = loc;
	} else {
		entryForVar->isLoc =0;
		entryForVar->globalEntry = glo;
	}
	
	if(loc==NULL && glo==NULL)
		return NULL;
	
	return entryForVar;

}

void gInstall(char *name, int type,int nodetype, int size0,int size1, int binding, struct tnode *paramlist,int flabel){


	if(gLookup(name) == NULL){
					struct globalEntry* symEntry = (struct globalEntry*) malloc(sizeof(struct globalEntry));
					symEntry->name = strdup(name);
					symEntry->type = type; 	//str/int
					symEntry->nodetype = nodetype;
					symEntry->size[0]=size0;
					symEntry->size[1]=size1;
					symEntry->binding = binding;
					symEntry->next = symtable;
					
					symEntry->paramlist = paramlist;
					while(paramlist){
						if(paramlist->nodetype==tPVAR){
							paramlist->type+=10;
						}
						paramlist=paramlist->middle;
					}
					symEntry->flabel = flabel;
					symtable = symEntry;
					return;
	} else {
		yyerror("Variable already declared\n");
		return;
	}
	 
}


void gAssignTypeDecl(struct tnode *typeNode, struct tnode *varlist){

	struct globalEntry * t = NULL;
	
	while(varlist!=NULL){
		t = gLookup(varlist->name);
		switch(t->nodetype){	//var, pvar, arr,tfunc
			case tPVAR: t->type = typeNode->type + 10;		///MAGIC NUMBER DON'T REARRANGE HEADER
									//str, int
						break;
			default: t->type = typeNode->type;
						break;
		}
		varlist=varlist->middle;
	}
}


void addIdListToLocal(struct  tnode * typeNode, struct  tnode * idList){
//for each id, make and localEntry in localTable for "currFunc"
	struct localTable * currTable = localTableLookup(currFunc);
	struct localEntry * lookupEntry = localEntryLookup(currFunc,idList->name);
	int pType=typeNode->type;

		
	while(idList!=NULL && lookupEntry==NULL){
		lookupEntry = localEntryLookup(currFunc, idList->name);
		
		if(lookupEntry!=NULL){
			yyerror("Variable name already used\n");
		}
		if(idList->nodetype==tPVAR) {pType=pType+10;}
		localEntryCreate(currFunc, idList->name, pType, idList->nodetype ,getLocalSpace());

		idList=idList->middle;
	}
	return;
}



int getFLabel(){
	return funcLabel++;
}


void showST(){
	struct globalEntry* current = symtable;  // Initialize current
	struct localTable* currLocal = symtable;
	printf("------------Symbol Table-------------------\n");
    while (current != NULL)
    {
        printf("Name:%9.9s Size:%d,%d Type:%d-%s, FLabel:%d ,Nodetype: %d,Binding:%d\n",current->name,current->size[0],current->size[1] ,current->type,typeToString(current->type),(current->flabel), (current->nodetype), current->binding);
        if((current->nodetype)==38){
        	struct tnode* pl = (current->paramlist);
			while(pl!=NULL){
				printf("\tPARAMLIST: %s, %s,%d\n",pl->name, typeToString(pl->type),pl->nodetype);
				pl=pl->middle;
			}
		}
        current = current->next;
    }
    
    currLocal = allLST;
    printf("------------Local Symbol Tables-------------------\n");
    while (currLocal != NULL)
    {	struct localEntry* lv = currLocal->localEntry;
        printf("Name:%9.9s\n", currLocal->funcName);	//params in st's names
        	
			while(lv!=NULL){
				printf("\tLocal vars: %s, %s,%d,%d\n ",lv->name, typeToString(lv->type),lv->nodetype,lv->binding);
				lv=lv->next;
			}
        currLocal = currLocal->next;
    }
    printf("--------------------------------------------------\n\n");
}


char * typeToString(int type){
	switch(type){
		case intType: return "Integer";
			break;
		case stringType: return "String";
			break;
		case pStringType: return "String Pointer";
			break;
		case pIntType: return "Int Pointer";
			break;
		default: return "Void";
			break;
	}
}
