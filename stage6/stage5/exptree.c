#include <stdio.h>
#include <string.h>

/*
	int val;        // value of a number for NUM nodes.
	int type;       //type of variable
	char* varname;  //name of a variable for ID nodes  
	int nodetype;   // information about non-leaf nodes - read/write/connector/+/* etc.  
	
	struct tnode *left,*right;


2 for commands and operators
1 for variable
0 for integers 

*/




int labelCount = -1;

int address_count = -1;
int mem_offset = 4096;

int breaklabel = -1;
int breaklist[10]; //maximum of 10 break_loops can be put in the code,please increase this if necessary


struct tnode* createTree(int val, int type,int nodetype ,char* varname, struct tnode *l, struct tnode *r){
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->val = val;
	temp->type = type;
	temp->left = l;
	temp->right = r;
	temp->varname = varname==NULL?NULL:strdup(varname);
	temp->nodetype = nodetype;
	return temp;

}

/*
struct tnode *copy(tnode *L) {

    tnode *current = L;

    // Assume the list contains at least 1 student.
    tnode *copy = new tnode;
    copy->student = new Student(*current->student);
    copy->next = NULL;

    // Keep track of first element of the copy.
    Listnode *const head = copy;

    // 1st element already copied.
    current = current->next;

    while (current != NULL) {
       // Allocate the next node and advance `copy` to the element being copied.
       copy = copy->next = new Listnode;

       // Copy the node contents; don't share references to students.
       copy->student = new Student(*current->student);

       // No next element (yet).
       copy->next = NULL;

       // Advance 'current' to the next element
       current = current->next;
    }

    // Return pointer to first (not last) element.
    return head;
}
*/


// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
struct Gsymbol* Lookup(Gsymbol **tablelook,char *name){

    struct Gsymbol *temp = *tablelook;

    while (temp != NULL) {

      if (strcmp(temp->name, name) == 0) {
        return temp;
      }

      temp = temp->next;
    }

    return temp;
}

struct tnode* createParamNode(char *varname, int type)
{
	struct tnode *temp ;
	temp = (struct tnode *)malloc(sizeof(struct tnode));
	temp->varname = (char *)malloc(10*sizeof(char));
	strcpy(temp->varname, varname);
	temp->nodetype = type;
	temp->left = NULL;
	temp->right = NULL;
	//createTree(0 ,0,FUNCTION_PARAMETER ,NULL, temp, NULL)
	
	return temp;
}

struct tnode* ParamLookup(struct tnode **headref, char *varname)
{
	struct tnode *temp = *headref;
	while((temp != NULL) && (strcmp(temp->varname, varname) != 0))
	{
		temp = temp->left;
	}
	return temp;
}

void appendParamNode(struct tnode **headref, struct tnode *newNode)
{
	struct tnode *temp = *headref;
	if(temp == NULL)
	{
		*headref = newNode;
		return;
	}
	while(temp->left)
	{
		temp = temp->left;
	}
	temp->left = newNode;
}

void LAppendNode(struct Gsymbol **headref, struct Gsymbol *newNode) // Appends a node to the local symbol table
{
	struct Gsymbol *temp = *headref;
	if(temp == NULL)
	{
		*headref = newNode;
		return;
	}
	while(temp->next)
	{
		if(strcmp(temp->name, newNode->name) == 0)
			return;
		temp = temp->next;
	}
	temp->next = newNode;
}

struct Gsymbol* LInstall(char *name, int type, int binding) // Creates a local symbol entry.
{
	struct Gsymbol *temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	temp->name = (char *)malloc(10*sizeof(char));
	strcpy(temp->name, name);
	temp->type = type;
	temp->binding = binding;
	temp->next = NULL;
	temp->entry = VAR_LOCAL;
	return temp;
}

struct tnode* appendArg(struct tnode **headref, struct tnode **newNode) 
{
	struct tnode *temp = *headref;
	if(temp == NULL)
	{
		*headref = createTree(0 ,0,FUNCTION_ARGLIST ,NULL, *newNode, NULL);
		return *headref;
	}
	else
	{
		while(temp->left)
		{
			temp = temp->left;
		}
		temp->left = *newNode;
		return temp;
	}
}


void printSymbolTable(struct Gsymbol **headref)
{

	printf("\n");
	struct Gsymbol *temp = *headref;
	while(temp)
	{
		printf("%s  ", temp->name);
		switch(temp->type)
		{
			case INT_TYPE : printf("Int  ");
						break;
			case STR_TYPE : printf("String  ");
						break;
			case BOOL_TYPE : printf("Bool  ");
						break;
			default : printf("%d  ", temp->type);
		}
		printf("%d  ", temp->size);
		printf("%d\n", temp->binding);
		temp = temp->next;
	}
	return;
}

void assignType(struct Gsymbol **headref, int type)
{
	struct Gsymbol *temp = *headref;
	while(temp)
	{
		if(temp->type == 0)
		{
			temp->type = type;
		}
		temp = temp->next;
	}
	return;
}


// Creates a symbol table entry.
void Install(char *name, int type, int size,struct tnode *plist){
	Gsymbol *currenTable = Lookup(&globalTable,name);
	if (currenTable != NULL)
	{
	    printf("Variable %s has already been declared, exiting.\n", name);
	    exit(0);
	}

	struct Gsymbol *temp;
	temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->name = strdup(name);
	temp->type = type;
	temp->size = size;
	temp->paramlist = plist==NULL?NULL:plist;
	address_count += size;
	temp->binding = mem_offset + address_count;
	temp->next = NULL;
	temp->entry = VAR_GLOBAL;

	//temp->paramlist = paramlist;
	//bindval = temp->binding;
	struct Gsymbol *symbolTable = globalTable;

    if(symbolTable == NULL)
         symbolTable = temp;
    else
    {
        struct Gsymbol *lastNode = symbolTable;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = temp;
    }


}



const long int var_hash(char *str) {
    unsigned long hash = 5381;  
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}


int evaluate(struct tnode *t,FILE *fp){
		
	int p,q,r,l;
	int lb,extlb;

	switch((t->nodetype)){
		case NUM:
			r = getReg();
			fprintf(fp,"MOV R%d , %d\n",r,t->val);
			return r;
			break;

		case STR:
			printf("Reached str node:val %s",t->varname);
			r = getReg();
			fprintf(fp,"MOV R%d , %s\n",r,t->varname);
			return r;
			break;

		case BREAK:
			//check if something was added in to loop
			if (breaklabel > -1)
			{
				printf("BREAK REACHED FOR: %d",breaklist[breaklabel]);
				fprintf(fp, "JMP :%d\n", breaklist[breaklabel]);
			}
			break;

		case CONTINUE:
			//check if something was added in to loop and return to the top of the loop 
			if (breaklabel > -1)
			{
				printf("CONTINUE REACHED FOR: %d",breaklist[breaklabel]-1);
				fprintf(fp, "JMP :%d\n", breaklist[breaklabel]-1);
			}
			break;
			


		case ASSIGN:
			q = evaluate(t->right,fp);
			printf("LEFT VAR: %s",((t->left)->varname));
			fprintf(fp,"MOV [%d] , R%d ; Storing Operation to %s\n",getvar_addrs(t->left),q,(t->left)->varname);
			break;

		case CONNECT:
			if (t->left != NULL){
				l = evaluate(t->left,fp);
			}
			if (t->right != NULL){
				l = evaluate(t->right,fp);
				
			}
			freeReg();
			return l;
		break;

		case ARRAY_TYPE:
			//$$ = createTree($3->val,temp1->type,ARRAY_TYPE,$1->varname,NULL,NULL);
			r = getReg();
			fprintf(fp,"MOV R%d , [%d] ;retreiving VAR: %s\n", r, getvar_addrs(t),(t->varname));
			return r;
			break;



		case ID:
			//this can only be used to retrive the id using a register call the other function to get a writable address
			printf("IDVAR: %s",(t->varname));
			r = getReg();
			fprintf(fp,"MOV R%d , [%d] ;retreiving VAR: %s\n", r, getvar_addrs(t),(t->varname));
			return r;
			break;

		case WRITE:
			p = evaluate(t->left,fp);
			xos_call(fp,"Write",-2,p);
			break;


		case READ:
			r = getReg();
			xos_call(fp,"Read",-1,getvar_addrs(t->left));
			freeReg();
			break;

		case OP:
			p = evaluate(t->left,fp);
			q = evaluate(t->right,fp);
			switch (var_hash(t->varname)){
				case var_PLUS : 
					fprintf(fp, "ADD R%d , R%d\n",p,q );
					break;

				case var_MINUS : 
					fprintf(fp, "SUB R%d , R%d\n",p,q );
					break;
					
				case var_MUL : 
					fprintf(fp, "MUL R%d , R%d\n",p,q );
					break;
					
				case var_DIV : 
					fprintf(fp, "DIV R%d , R%d\n",p,q );	
					break;
				}

			freeReg();
			return p;
			break;

		case LOGIC_OP:
			p = evaluate(t->left,fp);
			q = evaluate(t->right,fp);
			switch (var_hash(t->varname)){
				case var_GRT : 
					fprintf(fp, "LT R%d, R%d\n", p, q);
					break;

				case var_LES : 
					fprintf(fp, "GT R%d, R%d\n", p, q);
					break;
					
				case var_GEQ : 
					fprintf(fp, "GE R%d, R%d\n", p, q);	
					break;
					
				case var_LEQ : 
					fprintf(fp, "LE R%d, R%d\n", p, q);
					break;

				case var_NEQ : 
					fprintf(fp, "NE R%d, R%d\n", p, q);	
					break;

				case var_EQ : 
					fprintf(fp, "EQ R%d, R%d\n", p, q);	
					break;
				}

			freeReg();
			return p;
			break;

		case IF:
			//we are actually evaluating the expression condition here and check wether type is bool
			if (t->left->type != BOOL_TYPE )
			{
				printf("\nError condition in if statement is not boolean");
				exit(0);
				break;
			}

			p = evaluate(t->left,fp);

			lb =  t->type == IF_DOUBLE?jumplabel():0;
			extlb = jumplabel();

			switch (t->type )
			{
				case IF_SINGLE:
					//write primary condition for single if
					fprintf(fp, "JZ R%d, :%d\n", p, extlb);

					//adding if code
					q = evaluate(t->right,fp);
					
					//exitlabel
					fprintf(fp, ":%d \n",extlb);
					break;

				case IF_DOUBLE:
					//write primary condition for double if,and jump to else
					fprintf(fp, "JZ R%d, :%d\n", p, lb);

					//evaluate if 
					q = evaluate(t->right->left,fp);

					//exitloop
					fprintf(fp, "JMP :%d\n", extlb);

					//add else label
					fprintf(fp, ":%d \n",lb);

					//evaluate else
					q = evaluate(t->right->right,fp);

					//exitlabel
					fprintf(fp, ":%d \n",extlb);
					break;
			}
			return q;
			break;

		case WHILE:

			lb = jumplabel();
			extlb = jumplabel();

			//this is for setting the break statement
			++breaklabel;
			breaklist[breaklabel] = extlb;

			//top label
			fprintf(fp, ":%d \n",lb);

			//we are actually evaluating the expression condition here
			p = evaluate(t->left,fp);

			fprintf(fp, "JZ R%d, :%d\n", p, extlb);

			q = evaluate(t->right,fp);

			//jump to top
			fprintf(fp, "JMP :%d\n", lb);

			//exit from loop
			fprintf(fp, ":%d \n",extlb);

			--breaklabel;

			return q;
			break;

		}
}

int getvar_arrayaddrs(char* var,int ary_indx){
	struct Gsymbol *temp = NULL;
	temp = Lookup(&globalTable,var);
	if (temp)
	{
		if (temp->size < ary_indx)
		{
			printf("\nArray out ouf bound exception");
			exit(0);
		}
		return temp->binding - temp->size + ary_indx;
	}
	else{
		printf("\nUndefined Variable calling");
		exit(0);
		return 0;
	}
}

int getvar_addrs(struct tnode* t){

	char *var = t->varname;
	struct Gsymbol *temp = NULL;


	printf("\n\n name:%s",t->varname);
	printf("\ntype:%d",t->nodetype);

	if (t->nodetype == ARRAY_TYPE)
	{
		return getvar_arrayaddrs(var,t->val);
	}
	if (t->entry == VAR_GLOBAL)
	{
		temp = Lookup(&globalTable,var);	
	}else{
		temp = Lookup(&localTable,var);
	}

	
	if (temp)
	{
		return temp->binding;
	}
	else{
		printf("\nUndefined Variable calling");
		exit(0);
		return 0;
	}
}


int getReg(){
	if(firstreg == 1){
			firstreg = 0;
			return 0;
		}
	return register_index++;
}

void freeReg(){
	if (register_index > 0)
	{
		 --register_index;
	}

}


void xos_call(FILE *fp,char *func_code ,int arg1,int arg2)
{


	//PUSH Function_Code  // Push Function Code 
	//PUSH Argument_1     // Push argument 1 to the stack
	//PUSH Argument_2     // Push argument 2 to the stack
	//PUSH Argument_3     // Push argument 3 to the stack
	//PUSH R0             // Push an empty space for RETURN VALUE
	//CALL 0              // Pass the control to virtual address 0. 
	// (eXpOS loader links the library to virtual address 0)
	
	int r_free = getReg();
	
	//push function code
	fprintf(fp,"MOV R%d, \"%s\"\n",r_free,func_code);
	fprintf(fp,"PUSH R%d\n",r_free);

	//push arg 1
	fprintf(fp,"MOV R%d, %d\n",r_free,arg1);
	fprintf(fp,"PUSH R%d\n",r_free);

	//push arg 2
	if(func_code[0]=='R'){
		fprintf(fp,"MOV R%d, %d\n",r_free,arg2);
		fprintf(fp,"PUSH R%d\n",r_free);
	}
	else{
		fprintf(fp,"PUSH R%d\n",arg2);
	}

	
	//push dummy arg 3
	fprintf(fp,"PUSH R%d\n",r_free);
	fprintf(fp,"PUSH R%d\n",r_free);

	fprintf(fp,"CALL 0\n");

	fprintf(fp,"POP R%d\n",r_free);
	fprintf(fp,"POP R%d\n",r_free);
	fprintf(fp,"POP R%d\n",r_free);
	fprintf(fp,"POP R%d\n",r_free);
	fprintf(fp,"POP R%d\n",r_free);
	freeReg();
}


int jumplabel(){
 return ++labelCount;
}
