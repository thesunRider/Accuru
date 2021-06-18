

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

//ask mam wether the opcode JZ is standar,it should work on the zero flag but is it like in other machines too?

int labelCount = -1;

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


int jumplabel(){
 return ++labelCount;
}
