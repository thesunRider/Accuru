

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


int evaluate(struct tnode *t,FILE *fp){
		
	int p,q,r,l;

	switch((t->nodetype)){
		case NUM:
			r = getReg();
			fprintf(fp,"MOV R%d , %d\n",r,t->val);
			return r;
			break;


		case EQUALS:
			q = evaluate(t->right,fp);
			printf("LEFT VAR: %s",((t->left)->varname));
			fprintf(fp,"MOV [%d] , R%d ; Storing Operation to %s\n",getvar_addrs(((t->left)->varname)),q,(t->left)->varname);
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


		case ID:
			//this can only be used to retrive the id using a register call the other function to get a writable address
			printf("IDVAR: %s",(t->varname));
			r = getReg();
			fprintf(fp,"MOV R%d , [%d] ;retreiving VAR: %s\n", r, getvar_addrs(t->varname),(t->varname));
			return r;
			break;

		case WRITE:
			p = evaluate(t->left,fp);
			xos_call(fp,"Write",-2,p);
			break;


		case READ:
			r = getReg();
			xos_call(fp,"Read",-1,getvar_addrs((t->left)->varname));
			freeReg();
			break;

		case OP:
			p = evaluate(t->left,fp);
			q = evaluate(t->right,fp);
			switch (*(t->varname)){
				case '+' : 
					fprintf(fp, "ADD R%d , R%d\n",p,q );
					break;

				case '-' : 
					fprintf(fp, "SUB R%d , R%d\n",p,q );
					break;
					
				case '*' : 
					fprintf(fp, "MUL R%d , R%d\n",p,q );
					break;
					
				case '/' : 
					fprintf(fp, "DIV R%d , R%d\n",p,q );	
					break;
				}

			freeReg();
			return p;
		}
}


int getvar_addrs(char* var){
	int variable_address;
	variable_address =  4096 + (int) ((*var - 'a'));
	return variable_address;
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
