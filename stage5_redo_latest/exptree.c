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
int max_registers = 10;

int address_count = -1;
int mem_offset = 4096; //where memory begins
int func_offset = 2056; //where programming code begins

int breaklabel = -1;
int breaklist[10]; //maximum of 10 break_loops can be put in the code,please increase this if necessary


struct tnode* appendTree(struct tnode *headref,struct tnode *main){
        struct tnode *lastNode = headref;

        while(lastNode->left != NULL)
        {
            lastNode = lastNode->left;
        }

        lastNode->left = main;
    return headref;
}

void InstallFunc(int return_type, char* func_name,struct PTable *param){
	Install(func_name,FUNCTION_TYPE,1); //here the type is NODE_FUNCTION not the return type since we are pushing to global symbol
	struct Fsymbol *temp1;
	temp1 = (struct Fsymbol*)malloc(sizeof(struct Fsymbol));
	temp1->name = strdup(func_name);
	temp1->type = return_type;
	temp1->param_list = param;

	if(funcTable == NULL)
         funcTable = temp1;
    else
    {
        struct Fsymbol *lastNode = funcTable;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = temp1;
    }
}

void pushglobals(FILE *fp){
	struct Gsymbol *temp = globalsymbolTable;
	int ev;
	int r = getReg();
	fprintf(fp, "MOV R%d , 0\n",r );
    while (1) {


      	for (int i = 0; i < temp->size; ++i) //push the variable binding*size time
      	{
      		fprintf(fp, "PUSH R%d\n",r );
      	}
      

      if(temp->next == NULL)
      	break;

      temp = temp->next;

    }

    freeReg(); //releasing r
    fprintf(fp, "JMP :-101\n");
}

void InstallLocals(struct PTable *local_list,char* func_name){
	struct Fsymbol *lastNode = funcTable;

	if (strcmp(lastNode->name,func_name) == 0)
     {
        lastNode->local_var = local_list;
        return;
    }

        while(lastNode->next != NULL)
        {
        	if (strcmp(lastNode->name,func_name) == 0)
        	{
        		break;
        	}
            lastNode = lastNode->next;
        }

        lastNode->local_var = local_list;
}

struct PTable* createDeclType(int type, struct Gsymbol *varlist){

	struct PTable *temp1;
	temp1 = (struct PTable*)malloc(sizeof(struct PTable));
	temp1->var = varlist;
	temp1->type = type;
	temp1->next = NULL;
	return temp1;
}


struct PTable* InstallParam(struct PTable *headref,char *name, int type,int bind){
	struct PTable *temp1;
	temp1 = (struct PTable*)malloc(sizeof(struct PTable));
	temp1 = createParam(name, type,bind);
	struct PTable *lastNode = headref;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = temp1;

	return headref;
}

struct PTable* InstallDeclType(struct PTable *headref,struct PTable *currenTable){
	struct PTable *lastNode = headref;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = currenTable;

	return headref;
}

struct PTable* createParam(char *name, int type,int bind){

	struct Gsymbol *temp;
	temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->name = strdup(name);
	temp->type = type;
	temp->binding = bind;
	temp->next = NULL;

	struct PTable *temp1;
	temp1 = (struct PTable*)malloc(sizeof(struct PTable));
	temp1->var = temp;
	temp1->type = type;
	temp1->next = NULL;
	return temp1;
}






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


// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
struct Gsymbol *Lookup(char *name){

	//first check if the variable is declared locally
	struct Gsymbol *temp1 = NULL;
	temp1 = LocalLookup(name);
	if (temp1 != NULL)
	{
		return temp1;
	}


	//then search for global versions
    struct Gsymbol *temp = globalsymbolTable;

    while (temp != NULL) {

      if (strcmp(temp->name, name) == 0) {
        return temp;
      }

      temp = temp->next;
    }
    if (temp != NULL)
    {
    	return temp;
    }


}

struct Gsymbol *LocalLookup(char *name){

    struct Fsymbol *temp = NULL;
    temp = funcTable;

    struct Gsymbol *retval = NULL;

    if (funcTable != NULL){
	    while(1)
	    {
	    	retval = searchPtable(name,&temp->local_var);
	    	if (retval != NULL) 
	    		return retval;
	    	temp = temp->next;
	    	if (temp==NULL)
	            	break;
	    }
	}

    return NULL;

}


struct Gsymbol *searchPtable(char *name,struct PTable **table)
{
	
 		struct PTable *temp = *table;

 		if (temp != NULL)
 		{
	        while(1)
	        {
		        if (strcmp(temp->var->name,name)==0){
		        		return temp->var;
		        }

	            temp = temp->next;
	            if (temp==NULL)
	            	break;
	        }
 		}

        return NULL;
    
};

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
			case FUNCTION_TYPE : printf("Function  ");
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


//creates local entry
struct Gsymbol* createlocal(char *name, int type, int size,int binding){
	//Gsymbol *currenTable = LocalLookup(name,namefunc);

	struct Gsymbol *temp;
	temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->name = strdup(name);
	temp->type = type;
	temp->size = size;
	temp->env_type = 0;
	temp->binding = binding;
	//temp->func_name = strdup(namefunc);

	//address allocation not set properly for local variables
	//address_count += size;
	//temp->binding = mem_offset + address_count;

	temp->next = NULL;
	return temp;
}

struct Gsymbol* appendlocalTable(struct Gsymbol *headref,struct Gsymbol *main){
        struct Gsymbol *lastNode = headref;

        while(lastNode->next != NULL)
        {
        	if (lastNode->name == main->name){
        		printf("Variable %s has already been declared locally, exiting locl.\n", main->name);
	   			exit(0);
        	}
            lastNode = lastNode->next;

        }

        lastNode->next = main;

    return headref;

}

// Creates a symbol table entry.
void Install(char *name, int type, int size){
	Gsymbol *currenTable = Lookup(name);
	if (currenTable != NULL)
	{
	    printf("Variable %s has already been declared, exiting globl.\n", name);
	    exit(0);
	}

	struct Gsymbol *temp;
	temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->name = strdup(name);
	temp->type = type;
	temp->size = size;
	address_count += size;
	temp->binding = mem_offset + address_count;
	temp->next = NULL;
	temp->env_type = 1;

    if(globalsymbolTable == NULL)
         globalsymbolTable = temp;
    else
    {
        struct Gsymbol *lastNode = globalsymbolTable;

        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        lastNode->next = temp;
    }

	++current_stack_base;
}



const long int var_hash(char *str) {
    unsigned long hash = 5381;  
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

void debug_setcurrentfunction(char *name,int jmp,int jmpex){	
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->varname = strdup(name);
	temp->val = jmp; //here the functions jumpcode is saved
	temp->type = jmpex; //here the functions base code is saved

	if (current_function != NULL)
	{
	    struct tnode *lastNode = current_function;
        while(lastNode->right != NULL)
        {
            lastNode = lastNode->right;
        }

        lastNode->right = temp;
	}
	else{
		current_function = temp;
	}
}

void debug_poplastfunction(){
	struct tnode *curNode = current_function;
	struct tnode *prevnode = NULL;
    while(curNode->right != NULL) {

        if (curNode->right != NULL)
   		{
   				prevnode = curNode;
   				curNode = curNode->right;
   		}else{
   			prevnode->right = NULL;
   			break;
   		}
    }
}

struct tnode* debug_getcurrentfunction(){
	struct tnode *lastNode = current_function;
    while(lastNode->right != NULL) {
            lastNode = lastNode->right;
    }

    return lastNode;
}

struct Fsymbol *searchFunction(char *name){
	struct Fsymbol *temp = funcTable;

	while(1){

		if (strcmp(temp->name,name)==0){
			return temp;
		}

		if (temp->next == NULL){
			break;
		}
		temp = temp->next;
	}
	return NULL;
}

int evaluate(struct tnode *t,FILE *fp){
		
	int p,q,r,l;
	int lb,extlb;


	switch((t->nodetype)){
		case FUNCTION_LIST:
			if (t->left != NULL){
				l = evaluate(t->left,fp);
			}
			if (t->right != NULL){
				l = evaluate(t->right,fp);
				
			}
			break;


		case FUNCTION_RETURN:
			if (t->right != NULL){
				l = evaluate(t->right,fp);
				int ret_reg = getReg();
				fprintf(fp, "MOV R%d , BP\n",ret_reg );
				fprintf(fp, "SUB R%d , 2\n",ret_reg); 
				fprintf(fp, "MOV [R%d], R%d\n",ret_reg,l); 
				freeReg();//free ret_reg
				freeReg(); //freeing up call to evaluate register
			}
			struct tnode *curfunc = debug_getcurrentfunction();		
			fprintf(fp, "JMP :%d\n", curfunc->type); //this refers to the jumping to exit of curfunc
			break;


			

		case FUNCTION_CALL: ;

			//int sp_save = getReg();
			//fprintf(fp, "MOV R%d , BP\n",sp_save);

			//saving registers
			for (int i = 0; i <= max_registers; i++)
			{
				++current_stack_base;
				fprintf(fp, "PUSH R%d ; saving all registers\n",i);
			}

			current_stack_base = 0;
			struct Fsymbol *srchfunc = searchFunction(t->right->varname);

			//save parameters
			if (t->left != NULL)
			{
				if(srchfunc->param_list == NULL)
				{
					printf("yacc>> Function declared has not arguments but still arguments passed!?\n");
					exit(1);
				}
				

				struct PTable *srchprm = srchfunc->param_list;
				//push parameter values
				struct tnode *temp = t->left;
				int i = 0;
				while (1){
						++current_stack_base;

						//params pushed from 1st to last
						if (srchprm->type != temp->right->type){

							struct Gsymbol *srchlcl = searchPtable(t->varname,&srchfunc->local_var); //search for the node with the same name as this one
							if (temp->right->type == VAR_UNDEF &&  srchlcl!= NULL)
							{

								temp->right->type = srchlcl->type; //declaring the variable
								if (srchlcl->type != srchprm->var->type)
								{
									printf("yacc>>Arguments datatype doesnt match functions!\n");
									exit(1);
								}
							}else{
									printf("yacc>> Undefined variable detected ,Either declare it locally or globally\n");
									exit(1);
								}
						}


						l = evaluate(temp->right,fp);
						fprintf(fp, "PUSH R%d;pushing the argument %s\n",l,temp->right->varname);
						freeReg(); //freeing the last reg


						if (temp->right != NULL && srchprm != NULL){
							break;
						}
						else{
							printf("yacc>>Error incorrect number of arguments passed\n");
							exit(1);
						}

						srchprm = srchprm->next;
						temp = temp->left;
				}
				
			}

			//two space for RETVAL RETADDRESS
			r = getReg();
			fprintf(fp, "MOV R%d , 0 \n",r);
			fprintf(fp, "PUSH R%d ;for storing a return value\n",r);
			freeReg();
			//fprintf(fp, "PUSH R%d\n",sp_save); //now sp will point to the address of the base
			//fprintf(fp, "MOV BP , SP\n");
			
			//freeReg(); //free sp_save register
			struct Fsymbol *srchfunc2 = searchFunction(t->right->varname);
			fprintf(fp,"CALL :%d\n",srchfunc2->jmp); //this creates the return address in the stack
			
			int r = getReg();
			fprintf(fp, "POP R%d ;pop return value into register\n", r); //this pops off the return value into the register
			struct Gsymbol *funcsymb = Lookup(t->right->varname);
			fprintf(fp,"MOV [%d] , R%d \n",funcsymb->binding,r);
			freeReg(); //free up r register

			int q = getReg();
			for (int i = 0; i < current_stack_base; ++i)
			{
				fprintf(fp, "POP R%d ;pop all arguments\n",q );
			}
			freeReg();

			//pop registers back
			for (int i = max_registers; i >= 0; i--)
			{
				
					fprintf(fp, "POP R%d ;pop register back%d\n",i );
			}


			r = getReg();
			fprintf(fp, "MOV R%d , [%d] ;returning the register\n",r,funcsymb->binding);

			return r;
			break;

		case FUNCTION_CONNECT: ;

			int jmpz;
			int jmpex;

			//we are now going inside a function
			if (strcmp(t->varname,"main") == 0){
				 jmpz = -101;
				 jmpex = -102;
			}
			else{
				jmpz = jumplabel();
				jmpex = jumplabel();
			}

			
			int register_index_history = register_index;

			debug_setcurrentfunction(t->varname,jmpz,jmpex);
			fprintf(fp, ":%d; function %s \n", jmpz,t->varname);

			fprintf(fp, "PUSH BP 	 	;pushing BP\n"); //push BP to stack (old bp)
			fprintf(fp, "MOV BP , SP 	;now sp and bp are the same\n"); //update bp

			struct Fsymbol *temp = searchFunction(t->varname);
			temp->jmp = jmpz;
			temp->jmpext = jmpex;

			int null_reg = getReg();
			current_stack_base = 0;

			//save all localvariables
			if (temp->local_var != NULL){
				struct PTable *temp1 = temp->local_var;	

				while (1){
					current_stack_base += temp1->var->size;
					//simply pushing 0's for all local variable values (declaration) 
					for (int i = 0; i <  (temp1->var->size); ++i)
					{

						fprintf(fp, "MOV R%d, 0 ;pushing space for local variables\n",null_reg);
						fprintf(fp, "PUSH R0\n");
					} //push as much space as required

					if (temp1->next == NULL){
						break;
					}
					temp1 = temp1->next;
				}
			}

			freeReg(); //free null_reg

			register_index = 0;

			//evaluate contents
			if (t->right != NULL){
				l = evaluate(t->right,fp);	
			}

			//restore_context
			register_index = register_index_history;



			//function exit label
			debug_poplastfunction();

			//fprintf(fp, "JMP :%d\n",jmpex);
			fprintf(fp, ":%d\n",jmpex );


			//pop all the local_vars
			int pop_reg = getReg();
			for (int i = 0; i < current_stack_base; ++i)
			{
				fprintf(fp, "POP R%d ;poping localvar\n",pop_reg);
			}
			freeReg(); //free pop_reg

			//jumps to the last section
			if (strcmp(t->varname,"main")==0)
			{
				fprintf(fp, "JMP :-103;jumping to die\n");
			}
			else{
				fprintf(fp, "POP BP ;poping old bp to the new bp\n");//saving old bp as new bp
				fprintf(fp, "RET ;returning to where sp is\n");

			}

			break;


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
			p = evaluate(t->left,fp);
			q = evaluate(t->right,fp);
			printf("LEFT VAR: %s",((t->left)->varname));
			int rt = t->right->nodetype;
			if (rt == NUM || rt == STR || rt ==  FUNCTION_CALL) //all of these are supposed to return registers
				fprintf(fp,"MOV [R%d] , R%d ; Storing Operation to %s\n",p,q,(t->left)->varname);
			else //all of these are supposed to return memory
				fprintf(fp,"MOV [R%d] , [R%d] ; Storing Operation to %s\n",p,q,(t->left)->varname);
			freeReg();
			freeReg();
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
			fprintf(fp,"MOV R%d , [%d] ;retreiving VAR: %s\n", r, getvar_binding_mem(t),(t->varname));
			return r;
			break;



		case ID:
				printf("IDVAR: %s",(t->varname));
				r =  get_memadrs_reg(t,fp);
				return r;

		case WRITE:
			p = evaluate(t->left,fp);
			q = getReg();
			if (t->left->nodetype == ID)
				fprintf(fp, "MOV R%d , [R%d] ;moving memory to register for reading operations\n",q,p );
			else
				fprintf(fp, "MOV R%d , R%d ;moving memory to register for reading operations\n",q,p );

			xos_call(fp,"Write",-2,q);
			freeReg();
			break;


		case READ:
			r = getReg();
			p = evaluate(t->left,fp);
			xos_call(fp,"Read",-1,p);
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
					fprintf(fp, ":%d\n",extlb);
					break;

				case IF_DOUBLE:
					//write primary condition for double if,and jump to else
					fprintf(fp, "JZ R%d, :%d\n", p, lb);

					//evaluate if 
					q = evaluate(t->right->left,fp);

					//exitloop
					fprintf(fp, "JMP :%d\n", extlb);

					//add else label
					fprintf(fp, ":%d\n",lb);

					//evaluate else
					q = evaluate(t->right->right,fp);

					//exitlabel
					fprintf(fp, ":%d\n",extlb);
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
			fprintf(fp, ":%d\n",lb);

			//we are actually evaluating the expression condition here
			p = evaluate(t->left,fp);

			fprintf(fp, "JZ R%d, :%d\n", p, extlb);

			q = evaluate(t->right,fp);

			//jump to top
			fprintf(fp, "JMP :%d\n", lb);

			//exit from loop
			fprintf(fp, ":%d\n",extlb);

			--breaklabel;

			return q;
			break;

		}
}

int getvar_arrayaddrs(char* var,int ary_indx){
	struct Gsymbol *temp = NULL;
	temp = Lookup(var);
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

int getvar_binding_mem(struct tnode* t){

	char *var = t->varname;
	struct Gsymbol *temp = NULL;


	printf("\n\n name:%s",t->varname);
	printf("\ntype:%d",t->nodetype);

	if (t->nodetype == ARRAY_TYPE)
	{
		return getvar_arrayaddrs(var,t->val);
	}

	temp = Lookup(var);
	if (temp)
	{	if (temp->env_type == 0)
		{
			return temp->binding; //local variable
		}
		else if (temp->env_type == 1) //global variable
		{
			return temp->binding;
		}else if(temp->env_type == 2){

			struct Fsymbol *temp = funcTable;
			struct Gsymbol *srpch = NULL;
			while(1){

				srpch = searchPtable(t->varname,&temp->param_list);

				if (srpch != NULL &&strcmp(srpch->name,t->varname)==0)
				{
					return srpch->binding;
				}
				if (temp->next == NULL ){
					break;
				}
				temp = temp->next;
			}

			printf("yacc>>Undefined parameter");
			exit(1);
		}
	}
	else{
		printf("\nyacc>>Undefined Variable calling");
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
		fprintf(fp,"MOV R%d, R%d\n",r_free,arg2);
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


int get_memadrs_reg(struct tnode *t,FILE *fp){
			int g;
			struct Gsymbol *temp5 = Lookup(t->varname);
			struct Fsymbol *temp2 = searchFunction(debug_getcurrentfunction()->varname);

			if (temp2->param_list != NULL && temp5->env_type == 2)
			{
				//check if parameter of function
				struct Gsymbol *temp3 = searchPtable(t->varname,&temp2->param_list);
				if (temp3 != NULL)
				{
					//this is a parameters 
					int bind = getvar_binding_mem(t);
					struct PTable *temp6 = temp2->param_list;

					//get the last parameter (ie total parameter binding)
					while (temp6->next != NULL){
						temp6 = temp6->next;
					}

					int tparam_size = temp6->var->binding;
					int current_bind = tparam_size - bind + 2; // here there is +2 because of two spaces from bp in stack and +1 because we didnt count 0 in mem address

					g = getReg();
					fprintf(fp, "MOV R%d , 0\n",g);
					fprintf(fp, "SUB R%d , %d\n",g,current_bind);
					fprintf(fp, "ADD R%d, BP ;retrieving parameter\n",g );
					return g;

				}

			}
			//this can only be used to retrive the id using a register call the other function to get a writable address
			
			if (temp5->env_type == 0) //it is undefined type (probably a local variable)
			{
				//check if it is a local variable or parameter if not variable is undeclared

				if (temp2->local_var != NULL)
				{
					struct Gsymbol *temp4 = searchPtable(t->varname,&temp2->local_var);
					if (temp4){
						//this is a local variable
						int bind = getvar_binding_mem(t);
						printf("IDVAR: %s",(t->varname));
						int g;
						g = getReg();
						fprintf(fp, "MOV R%d , 0\n",g);
						fprintf(fp, "ADD R%d , %d\n",g,bind);
						fprintf(fp, "ADD R%d, BP ;retreiving LOCAL VAR\n",g );
						return g;

					}else{
						printf("yacc>> Variable not delcared \n");
						exit(1);
					}
				}else{
					printf("yacc>> No local variables declared for this function\n");
					exit(1);
				}

			}
			else if(temp5->env_type == 1){

				printf("IDVAR: %s",(t->varname));
				g = getReg(); 
				fprintf(fp, "MOV R%d , %d ;retreieving normal var\n",g,getvar_binding_mem(t));
				return g;
			}
			else {
				printf("yacc>>Undeclared variable\n");
				exit(1);
			}
}