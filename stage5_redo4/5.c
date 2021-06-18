

void push(int whileStack[], int num)
{
	top++;
	whileStack[top] = num;
	return;
}

void pop(int whileStack[])
{
	top--;
	return;
}

struct tnode* createTree(int val,int type,char* varname,int nodetype,struct Gsymbol *Gentry,struct Lsymbol *Lentry,struct tnode *arglist,struct tnode *l,struct tnode *m,struct tnode *r)
{
    //creating tnode.....
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    //assigning val,type,nodetype
    temp->val = val;
    temp->Gentry = Gentry;
	temp->Lentry = Lentry;
	if(Lentry)
		temp->type = Lentry->type;
	else if(Gentry)
		temp->type = Gentry->type;
	else
		temp->type = type;
    temp->nodetype = nodetype;
    //mallocing for varname
    if(varname != NULL)
    {
    	temp->varname=(char*)malloc(30*sizeof(char));
    	strcpy(temp->varname, varname);
		if((strcmp(varname, "+") == 0) || (strcmp(varname, "-") == 0) || (strcmp(varname, "/") == 0) || (strcmp(varname, "*") == 0))
		{
			if((l->type!=inttype) || (r->type!=inttype))
			{
				fprintf(stderr, "Error : Arithmetic expression type mismatch\n");
				exit(0);
			}
			else
			{
				temp->type = l->type;
			}
		}
	}
    else
    {
    	temp->varname=NULL;
    }
	//assigning arglist, left, middle and right nodes....
    temp->arglist = arglist;
	temp->left = l;
	temp->middle = m;
    temp->right = r;
	if((temp->nodetype == NODE_IF) || (temp->nodetype == NODE_WHILE))
	{
	if(temp->left->type!=booltype)
		{
			fprintf(stderr, "Error : Non-Boolean guard for If or While Statement.\n");
			exit(0);
		}
	}
	if((temp->nodetype == NODE_ARR))
	{
		if(temp->right->type!=inttype)
		{
			fprintf(stderr, "Error : Array indexed by a variable other than int type.\n");
			exit(0);
		}
	}
	if(temp->nodetype == NODE_FUNCTION)
	{
		struct Paramstruct *paramlist = *(&(temp->Gentry->paramlist));
		struct tnode *tempArgList = *(&(temp->left));
		while(paramlist && tempArgList)
		{
			printf("Matching Test for %s:\n", temp->varname);
			if(paramlist->type!=tempArgList->type)
			{
				fprintf(stderr, "Error : mismatch in argument types supplied to function call.\n");
				exit(0);
			}
			paramlist = paramlist->next;
			tempArgList = tempArgList->arglist;
		}
		if((paramlist != NULL) || (tempArgList != NULL))
		{
			if(paramlist)
			{
				fprintf(stderr, "Paramlist not over.\n");
				while(paramlist)
				{
					paramlist = paramlist->next;
				}
			}
			if(tempArgList)
			{
				fprintf(stderr, "tempArgList not over.\n");
				while(tempArgList)
				{
					tempArgList = tempArgList->arglist;
				}
			}
			fprintf(stderr, "Error : mismatch in no. of arguments supplied to function call.\n");
			exit(0);
		}
		printf("Matching Test for %s successfully done.\n", temp->varname);
	}
    return temp;
}

struct Gsymbol* GLookup(struct Gsymbol **headref, char *name)
{
	struct Gsymbol *temp = *headref;
	while((temp != NULL) && (strcmp(temp->name, name) != 0))
	{
		temp = temp->next;
	}
	return temp;
}

void GInstall(struct Gsymbol **headref, char *name, int type, int size, struct Paramstruct *paramlist)
{

	struct Gsymbol *temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
	temp->name = (char *)malloc(10*sizeof(char));
	strcpy(temp->name, name);
	temp->type = type;
	temp->size = size;
	++freeAddress;
	temp->binding = freeAddress;
	if(size != -1)
	{
		freeAddress += size-1;
	}
	else
	{
		++fLabel;
		temp->fLabel = fLabel;
	}
	temp->paramlist = paramlist;
	temp->next = NULL;

	struct Gsymbol *tempHead = *headref;
	if(tempHead == NULL)
	{

		*headref = temp;
		return;
	}

	while(tempHead->next)
	{
		tempHead = tempHead->next;
	}
	tempHead->next = temp;

	return;
}

void printParamList(struct Paramstruct **headref)
{
	struct Paramstruct *temp = *headref;
	while(temp)
	{
		printf("%s ", temp->name);
		printf("%d ", temp->type);
		if(temp->next)
			printf(", ");
		temp = temp->next;
	}
	printf("\n");
}

void printGSymbolTable(struct Gsymbol **headref)
{
	struct Gsymbol *temp = *headref;
	printf("***GLOBAL SYMBOL TABLE***\n");
	while(temp)
	{
		printf("%s  ", temp->name);
		printf("%d ", temp->type);
		printf("%d  ", temp->size);
		printf("%d\n", temp->binding);
		if(temp->paramlist)
		{
			printf("Parameters : ");
			printParamList(&(temp->paramlist));
			printf("\n");
		}
		temp = temp->next;
	}
	return;
}

void GAssignType(struct Gsymbol **headref, int type)
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

struct Paramstruct* createParamNode(char *varname, int type)
{
	struct Paramstruct *temp = (struct Paramstruct *)malloc(sizeof(struct Paramstruct));
	temp->name = (char *)malloc(10*sizeof(char));
	strcpy(temp->name, varname);
	temp->type = type;
	temp->next = NULL;
	return temp;
}

void appendParamNode(struct Paramstruct **headref, struct Paramstruct *newNode)
{
	struct Paramstruct *temp = *headref;
	if(temp == NULL)
	{
		*headref = newNode;
		return;
	}
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}

struct Paramstruct* ParamLookup(struct Paramstruct **headref, char *varname)
{
	struct Paramstruct *temp = *headref;
	while((temp != NULL) && (strcmp(temp->name, varname) != 0))
	{
		temp = temp->next;
	}
	return temp;
}

struct Lsymbol* LLookup(struct Lsymbol **headref, char *name) // Returns a pointer to the local symbol table entry for the variable, returns NULL otherwise.
{
	struct Lsymbol *temp = *headref;
	while((temp != NULL) && (strcmp(temp->name, name) != 0))
	{
		temp = temp->next;
	}
	return temp;
}

struct Lsymbol* LInstall(char *name, int type, int binding) // Creates a local symbol entry.
{
	struct Lsymbol *temp = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	temp->name = (char *)malloc(10*sizeof(char));
	strcpy(temp->name, name);
	temp->type = type;
	temp->binding = binding;
	temp->next = NULL;
	return temp;
}

void LAppendNode(struct Lsymbol **headref, struct Lsymbol *newNode) // Appends a node to the local symbol table
{
	struct Lsymbol *temp = *headref;
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

struct Lsymbol* copyFirstNode(struct Lsymbol **headref)
{
	struct Lsymbol *temp = *headref;
	struct Lsymbol *newNode = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	newNode->name = (char *)malloc(10*sizeof(char));
	strcpy(newNode->name, temp->name);
	newNode->type = temp->type;
	newNode->binding = temp->binding;
	newNode->next = NULL;
	return newNode;
}

void LAppendList(struct Lsymbol **headref, struct Lsymbol *newList) // Appends a list of nodes to the local symbol table
{
	struct Lsymbol *temp, *newNode;
	struct Lsymbol *temp2 = newList;
	while(newList)
	{
		temp = NULL;
		newNode = copyFirstNode(&newList);
		temp = LLookup(headref, newNode->name);
		if(temp != NULL)
		{
			printf("Variable already declared.\n");
			exit(0);
		}
		else
		{
			LAppendNode(headref, newNode);
		}
		newList = newList->next;
	}
	free(temp2);
}

void LAssignType(struct Lsymbol **headref, int type) // Assigns the types to all the remaining variables in a local declaration.
{
	struct Lsymbol *temp = *headref;
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
void printLSymbolTable(struct Lsymbol **headref) // Prints out the local symbol table
{
	struct Lsymbol *temp = *headref;
	printf("***LOCAL SYMBOL TABLE***\n");
	while(temp)
	{
		printf("%s  ", temp->name);
		printf("%d  ", temp->type);
		printf("%d\n", temp->binding);
		temp = temp->next;
	}
	return;
}

void checkNameEqv(struct Gsymbol **headref, struct Paramstruct **paramlist)
{
	struct Paramstruct *temp = (*headref)->paramlist;
	struct Paramstruct *list = *paramlist;
	while(temp && list)
	{
		if((strcmp(temp->name, list->name) != 0) || (temp->type!=list->type))
		{
			printf("Function signature and declaration not same.\n");
			exit(0);
		}
		temp = temp->next;
		list = list->next;
	}
}

void addParametersToLST(struct Lsymbol **headref, struct Paramstruct **paramlist)
{
	struct Paramstruct *list = *paramlist;
	while(list)
	{
		struct Lsymbol *newNode = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
		newNode->name = (char *)malloc(10*sizeof(char));
		strcpy(newNode->name, list->name);
		newNode->type = list->type;
		newNode->binding = 0;
		newNode->next = NULL;
		LAppendNode(headref, newNode);
		list = list->next;
	}
}

void appendArg(struct tnode **headref, struct tnode *newNode) // Appends a new node to the argument list.
{
	struct tnode *temp = *headref;
	if(temp == NULL)
	{
		*headref = newNode;
		return;
	}
	else
	{
		while(temp->arglist)
		{
			temp = temp->arglist;
		}
		temp->arglist = newNode;
	}
}

// struct Typetable* createTypeNode(char *name, int size, struct Fieldlist *fields)
// {
// 	int temp = (int )malloc(sizeof(struct Typetabl));
// 	temp->name = (char *)malloc(20*sizeof(char));
// 	strcpy(temp->name, name);
// 	temp->size = size;
// 	temp->fields = fields;
// 	temp->next = NULL;
// 	return temp;
// }

// void TypeTableCreate(int *headref)
// {
// 	int temp = *headref;
// 	if(temp != NULL)
// 	{
// 		printf("Error. Type table not empty before initialisation.\n");
// 		exit(0);
// 	}
// 	temp = createTypeNode("int", 1, NULL);
// 	*headref = temp;
// 	temp->next = createTypeNode("str", 1, NULL);
// 	temp = temp->next;
// 	temp->next = createTypeNode("bool", 1, NULL);
// 	temp = temp->next;
// 	temp->next = createTypeNode("null", 1, NULL);
// 	temp = temp->next;
// 	temp->next = createTypeNode("void", 1, NULL);
// 	return;
// }

// void printTypeTable(int *headref)
// {
// 	int temp = *headref;
// 	while(temp)
// 	{
// 		printf("%s ", temp->name);
// 		printf("%d ", temp->size);
// 		if(temp->fields)
// 		{
// 			struct Fieldlist *tempfield = temp->fields;
// 			printf("\nFields : \n");
// 			while(tempfield)
// 			{
// 				printf("%s ", tempfield->name);
// 				printf("%d \n", tempfield->fieldIndex);
// 				tempfield = tempfield->next;
// 			}
// 		}
// 		temp = temp->next;
// 		printf("\n");
// 	}
// }

// struct Typetable* TLookup(int *headref, char *name)
// {
// 	int temp = *headref;
// 	while((temp != NULL) && (strcmp(temp->name, name) != 0))
// 	{
// 		temp = temp->next;
// 	}
// 	return temp;
// }
//
// void TInstall(int *headref, char *name, int size, struct Fieldlist *fields)
// {
// 	int newNode = createTypeNode(name, size, fields);
// 	int count = getSize(&newNode);
// 	newNode->size = count;
// 	int temp = *headref;
// 	while(temp->next)
// 	{
// 		temp = temp->next;
// 	}
// 	temp->next = newNode;
// 	return;
// }
//
// struct Fieldlist* FLookup(int *typeref, char *name)
// {
// 	struct Fieldlist *tempfield = (*typeref)->fields;
// 	while((tempfield != NULL) && (strcmp(tempfield->name, name) != 0))
// 	{
// 		tempfield = tempfield->next;
// 	}
// 	return tempfield;
// }

// int getSize(int *typeref)
// {
// 	int count = 0;
// 	struct Fieldlist *tempfield = (*typeref)->fields;
// 	while(tempfield)
// 	{
// 		count++;
// 		tempfield = tempfield->next;
// 	}
// 	return count;
// }

// struct Fieldlist* createFieldNode(char *name, int fieldIndex, int type)
// {
// 	struct Fieldlist *newNode = (struct Fieldlist *)malloc(sizeof(struct Fieldlist));
// 	newNode->name = (char *)malloc(20*sizeof(char));
// 	strcpy(newNode->name, name);
// 	newNode->fieldIndex = fieldIndex;
// 	newNode->type = type;
// 	newNode->next = NULL;
// 	return newNode;
// }

// void FAppendNode(struct Fieldlist **headref, struct Fieldlist *nextNode)
// {
// 	struct Fieldlist *temp = *headref;
// 	if(temp == NULL)
// 	{
// 		*headref = nextNode;
// 		return;
// 	}
// 	while(temp->next)
// 	{
// 		if(strcmp(temp->name, nextNode->name) == 0)
// 		{
// 			fprintf(stderr, "Error. Field name already declared.\n");
// 			exit(0);
// 		}
// 		temp = temp->next;
// 	}
// 	temp->next = nextNode;
// 	return;
// }

/*int evaluate(struct tnode *t){
	if(t->op == NULL)
	{
		return t->val;
	}
	else
	{
		switch(*(t->op))
		{
			case '+' : return evaluate(t->left) + evaluate(t->right);
			break;
			case '-' : return evaluate(t->left) - evaluate(t->right);
			break;
			case '*' : return evaluate(t->left) * evaluate(t->right);
			break;
			case '/' : return evaluate(t->left) / evaluate(t->right);
			break;
		}
	}
}
void printPrefix(struct tnode *t)
{
	if(t != NULL)
	{
		if(t->op == NULL)
		{
			printf("%d ", t->val);
		}
		else
		{
			printf("%c ", *(t->op));
		}
		printPrefix(t->left);
		printPrefix(t->right);
	}
	return;
}
void printPostfix(struct tnode *t)
{
	if(t != NULL)
	{
		printPostfix(t->left);
		printPostfix(t->right);
		if(t->op == NULL)
		{
			printf("%d ", t->val);
		}
		else
		{
			printf("%c ", *(t->op));
		}
	}
	return;
}*/

int getReg()
{
	reg++;
	return reg;
}

void freeReg()
{
	reg--;
	return;
}

int getLabel()
{
	labelCount++;
	return labelCount;
}

void backup_reg(int num)
{
	int p = 0;
	while(p <= num)
	{
		fprintf(xsm_file, "PUSH R%d\n", p);
		p++;
	}
	return;
}

void restore_reg(int num)
{
	int p = num;
	while(p >= 0)
	{
		fprintf(xsm_file, "POP R%d\n", p);
		p--;
	}
	return;
}

void xos_call(char *func, int arg1, int arg2, int p, int flag)
{
	fprintf(xsm_file, "MOV R%d, \"%s\"\n", p, func);
	fprintf(xsm_file, "PUSH R%d\n", p);
	fprintf(xsm_file, "MOV R%d, %d\n", p, arg1);
	fprintf(xsm_file, "PUSH R%d\n", p);
	if(func[0] == 'W')
	{
		fprintf(xsm_file, "MOV R%d, R%d\n", p, arg2);
	}
	else
	{
		if(flag == 0)
			fprintf(xsm_file, "MOV R%d, %d\n", p, arg2);
		else
			fprintf(xsm_file, "MOV R%d, R%d\n", p, arg2);
	}
	fprintf(xsm_file, "PUSH R%d\n", p);
	fprintf(xsm_file, "PUSH R0\n");
	fprintf(xsm_file, "PUSH R0\n");
	fprintf(xsm_file, "CALL 0\n");
	fprintf(xsm_file, "POP R%d\n", p);
	fprintf(xsm_file, "POP R0\n");
	fprintf(xsm_file, "POP R0\n");
	fprintf(xsm_file, "POP R0\n");
	fprintf(xsm_file, "POP R0\n");
	return;
}

reg_index codeGen(struct tnode *t)
{
	int p, q, add;
	int l1, l2, l3;
	//printf("Initial\n");
	switch(t->nodetype)
	{
		case NODE_CONN : 	//printf("Switchconn\n");
					if(t->left)
					{
						p = codeGen(t->left);
					}
					if(t->right)
					{
						p = codeGen(t->right);
					}
					return p;
					break;

		case NODE_CONSTANT : 	//printf("Switchconst\n");
					p = getReg();
					fprintf(xsm_file, "MOV R%d, %d\n", p, t->val);
					return p;
					break;

		case NODE_STRCONSTANT : 	//printf("Switchstrconst\n");
					p = getReg();
					fprintf(xsm_file, "MOV R%d, %s\n", p, t->varname);
					return p;
					break;

		case NODE_VAR :		//printf("Switchvariable\n");
					p = getReg();
					if(t->Lentry)
					{
						add = t->Lentry->binding;
						q = getReg();
						fprintf(xsm_file, "MOV R%d, BP\n", p);
						if(add < 0)
						{
							add = -add;
							fprintf(xsm_file, "MOV R%d, %d\n", q, add);
							fprintf(xsm_file, "SUB R%d, R%d\n", p, q);
						}
						else
						{
							fprintf(xsm_file, "MOV R%d, %d\n", q, add);
							fprintf(xsm_file, "ADD R%d, R%d\n", p, q);
						}
						freeReg();
					}
					else
					{
						add = t->Gentry->binding;
						fprintf(xsm_file, "MOV R%d, %d\n", p, add);
					}
					return p;
					break;

		case NODE_ARR : //printf("Switcharray\n");
					q = codeGen(t->right);
					if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_EX) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_STRCONSTANT))
					{
						fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
					}
					p = getReg();
					add = t->left->Gentry->binding;
					//fprintf(xsm_file, "Heyyo!\n");
					fprintf(xsm_file, "MOV R%d, %d\n", p, add);
					fprintf(xsm_file, "ADD R%d, R%d\n", q, p);
					//printf("Array Base : %d\n", t->left->Gentry->binding);
					//printf("Array Index: %d\n", t->right->val);
					freeReg();
					return q;
					break;

		case NODE_WRITE : 	//printf("Switchwrite\n");
					q = codeGen(t->left);
					p = getReg();
					if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_STRCONSTANT))
					{
						l1 = getReg();
						fprintf(xsm_file, "MOV R%d, [R%d]\n", l1, q);
						q = l1;
						backup_reg(q);
						xos_call("Write", -2, q, p, 1);
						restore_reg(q);
						freeReg();
						freeReg();
					}
					else
					{
						backup_reg(q);
						xos_call("Write", -2, q, p, 1);
						restore_reg(q);
						freeReg();
					}
					freeReg();
					return p;
					break;

		case NODE_READ : 	//printf("Switchread\n");
					//printf("ReadBeg\n");
					q = codeGen(t->left);
					backup_reg(q);
					p = getReg();
					xos_call("Read", -1, q, p, 1);
					/*if(t->left->nodetype == NODE_ARR)
					{
						//printf("Nodearray\n");
						q = codeGen(t->left);
						backup_reg(p);
						xos_call("Read", -1, q, p, 1);
					}
					else
					{
						//printf("Normal\n");
						//q = t->left->Gentry->binding;
						backup_reg(p);
						xos_call("Read", -1, q, p, 0);
					}*/
					freeReg();
					restore_reg(q);
					freeReg();
					return q;
					break;

		case NODE_ASSGN :	//printf("Switchassgn\n");
					/*if(t->left->nodetype != NODE_ARR)
					{
						add = t->left->Gentry->binding;
						q = codeGen(t->right);
						if(t->right->nodetype == NODE_ARR)
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
						}
						fprintf(xsm_file, "MOV [%d], R%d\n", add, q);
					}
					else
					{
						p = codeGen(t->left);
						q = codeGen(t->right);
						if(t->right->nodetype == NODE_ARR)
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
						}
						fprintf(xsm_file, "MOV [R%d], R%d\n", p, q);
					}*/
					p = codeGen(t->left);
					q = codeGen(t->right);
					if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_EX) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_STRCONSTANT))
					{
						fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
					}
					fprintf(xsm_file, "MOV [R%d], R%d\n", p, q);
					freeReg();
					freeReg();
					return p;
					break;

		case NODE_EX :	//printf("Switchexpr\n");
					p = codeGen(t->left);
					q = codeGen(t->right);
					if(strcmp(t->varname, "!=") == 0)
					{
						if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
						}
						if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
						}
						fprintf(xsm_file, "NE R%d, R%d\n", p, q);
					}
					else if(strcmp(t->varname, "==") == 0)
					{
						if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
						}
						if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
						}
						fprintf(xsm_file, "EQ R%d, R%d\n", p, q);
					}
					else if(strcmp(t->varname, ">=") == 0)
					{
						if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
						}
						if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
						}
						fprintf(xsm_file, "GE R%d, R%d\n", p, q);
					}
					else if(strcmp(t->varname, "<=") == 0)
					{
						if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
						}
						if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION))
						{
							fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
						}
						fprintf(xsm_file, "LE R%d, R%d\n", p, q);
					}
					else if(strcmp(t->varname, "&&") == 0)
					{
						fprintf(xsm_file, "ADD R%d, R%d\n", p, q);
						fprintf(xsm_file, "MOV R%d, 2\n", q);
						fprintf(xsm_file, "GE R%d, R%d\n", p, q);
					}
					else
					{
						switch(*(t->varname))
						{
							case '+' :
									if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
									}
									if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
									}
									fprintf(xsm_file, "ADD R%d, R%d\n", p, q);
									break;
							case '-' :
									if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
									}
									if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
									}
									fprintf(xsm_file, "SUB R%d, R%d\n", p, q);
									break;
							case '*' :
									if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
									}
									if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
									}
									fprintf(xsm_file, "MUL R%d, R%d\n", p, q);
									break;
							case '/' :
									if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
									}
									if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
									}
									fprintf(xsm_file, "DIV R%d, R%d\n", p, q);
									break;
							case '%' :
									if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
									}
									if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
									}
									fprintf(xsm_file, "MOD R%d, R%d\n", p, q);
									break;
							case '>' :
									if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
									}
									if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
									}
									fprintf(xsm_file, "GT R%d, R%d\n", p, q);
									break;
							case '<' :
									if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
									}
									if((t->right->nodetype != NODE_CONSTANT) && (t->right->nodetype != NODE_FUNCTION) && (t->right->nodetype != NODE_EX))
									{
										fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
									}
									fprintf(xsm_file, "LT R%d, R%d\n", p, q);
									break;
						}
					}
					freeReg();
					return p;
					break;

		case NODE_WHILE : //printf("Switchwhile\n");
					l1 = getLabel();
					l2 = getLabel();
					push(whileStack, l1);
					push(whileStack, l2);
					fprintf(xsm_file, "L%d:\n", l1);
					p = codeGen(t->left);
					fprintf(xsm_file, "JZ R%d, L%d\n", p, l2);
					freeReg();
					q = codeGen(t->right);
					fprintf(xsm_file, "JMP L%d\n", l1);
					fprintf(xsm_file, "L%d:\n", l2);
					pop(whileStack);
					pop(whileStack);
					return q;
					break;

		case NODE_IF : //printf("Switchif\n");
					l1 = getLabel();
					p = codeGen(t->left);
					fprintf(xsm_file, "JZ R%d, L%d\n", p, l1);
					freeReg();
					q = codeGen(t->middle);
					if(t->right)
					{
						l2 = getLabel();
						fprintf(xsm_file, "JMP L%d\n", l2);
					}
					fprintf(xsm_file, "L%d:\n", l1);
					if(t->right)
					{
						q = codeGen(t->right);
						fprintf(xsm_file, "L%d:\n", l2);
					}
					return q;
					break;

		case NODE_BREAK :
					if(top != -1)
					{
						l1 = whileStack[top];
						fprintf(xsm_file, "JMP L%d\n", l1);
					}
					return 1;
					break;

		case NODE_CONTINUE :
					if(top != -1)
					{
						l2 = whileStack[top-1];
						fprintf(xsm_file, "JMP L%d\n", l2);
					}
					return 1;
					break;

		case NODE_REPUNTIL :
					l1 = getLabel();
					l2 = getLabel();
					l3 = getLabel();
					push(whileStack, l2);
					push(whileStack, l3);
					fprintf(xsm_file, "L%d:\n", l1);
					p = codeGen(t->left);
					fprintf(xsm_file, "L%d:\n", l2);
					q = codeGen(t->right);
					fprintf(xsm_file, "JZ R%d, L%d\n", q, l1);
					fprintf(xsm_file, "L%d:\n", l3);
					return p;
					break;

		case NODE_DOWHILE :
					l1 = getLabel();
					l2 = getLabel();
					l3 = getLabel();
					push(whileStack, l2);
					push(whileStack, l3);
					fprintf(xsm_file, "L%d:\n", l1);
					p = codeGen(t->left);
					fprintf(xsm_file, "L%d:\n", l2);
					q = codeGen(t->right);
					fprintf(xsm_file, "JNZ R%d, L%d\n", q, l1);
					fprintf(xsm_file, "L%d:\n", l3);
					return p;
					break;

		case NODE_FUNCTION :
					p = getReg();
					backup_reg(p-1);
					freeReg();
					l1 = t->Gentry->fLabel;
					t = t->left;
					l2 = countArg(&t);
					reversePushArg(t);
					/*while(t)
					{
						q = codeGen(t);
						fprintf(xsm_file, "PUSH R%d\n", q);
						l2++;
						t = t->arglist;
					}*/
					fprintf(xsm_file, "PUSH R0\n");
					fprintf(xsm_file, "CALL F%d\n", l1);
					fprintf(xsm_file, "POP R0\n");
					l3 = l2;
					while(l2--)
					{
						fprintf(xsm_file, "POP R0\n");
					}
					p = getReg();
					q = getReg();
					fprintf(xsm_file, "MOV R%d, SP\n", p);
					fprintf(xsm_file, "MOV R%d, %d\n", q, l3+1);
					fprintf(xsm_file, "ADD R%d, R%d\n", p, q);
					fprintf(xsm_file, "MOV R%d, [R%d]\n", p, p);
					restore_reg(p-1);
					freeReg();
					return p;
					break;

		case NODE_RETURN :
					add = codeGen(t->left);
					if((t->left->nodetype != NODE_CONSTANT) && (t->left->nodetype != NODE_FUNCTION) && (t->left->nodetype != NODE_EX))
					{
						fprintf(xsm_file, "MOV R%d, [R%d]\n", add, add);
					}
					p = getReg();
					q = getReg();
					fprintf(xsm_file, "MOV R%d, BP\n", p);
					fprintf(xsm_file, "MOV R%d, 2\n", q);
					fprintf(xsm_file, "SUB R%d, R%d\n", p, q);
					fprintf(xsm_file, "MOV [R%d], R%d\n", p, add);
					freeReg();
					freeReg();
					freeReg();
					return p;
					break;
	}
}

int countArg(struct tnode **rootref)
{
	int count = 0;
	struct tnode *temp = *rootref;
	while(temp)
	{
		count++;
		temp = temp->arglist;
	}
	return count;
}

void reversePushArg(struct tnode *root)
{
	int q;
	if(root->arglist == NULL)
	{
		q = codeGen(root);
		if((root->nodetype != NODE_CONSTANT) && (root->nodetype != NODE_EX) && (root->nodetype != NODE_FUNCTION))
		{
			fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
		}
		fprintf(xsm_file, "PUSH R%d\n", q);
		freeReg();
		return;
	}
	else
	{
		reversePushArg(root->arglist);
		q = codeGen(root);
		if((root->nodetype != NODE_CONSTANT) && (root->nodetype != NODE_EX) && (root->nodetype != NODE_FUNCTION))
		{
			fprintf(xsm_file, "MOV R%d, [R%d]\n", q, q);
		}
		fprintf(xsm_file, "PUSH R%d\n", q);
		freeReg();
		return;
	}
}

void initFuncCode(int label, struct Lsymbol **headref)	// Allocating space for local variables when calling the function
{
	if(label == -1)
		fprintf(xsm_file, "MAIN:\n");
	else
		fprintf(xsm_file, "F%d:\n", label);
	fprintf(xsm_file, "PUSH BP\n");
	fprintf(xsm_file, "MOV BP, SP\n");
	struct Lsymbol *temp = *headref;
	while(temp) // allocating space for local variables
	{
		if(temp->binding > 0)
			fprintf(xsm_file, "PUSH R0\n");
		temp = temp->next;
	}
}

void endFuncCode(struct Lsymbol **headref)	// Deallocating space for local variables before returning from the function
{
	struct Lsymbol *temp = *headref;
	while(temp)
	{
		if(temp->binding > 0)
			fprintf(xsm_file, "POP R0\n");
		temp = temp->next;
	}
	fprintf(xsm_file, "MOV BP, [SP]\n");
	fprintf(xsm_file, "POP R0\n");
	fprintf(xsm_file, "RET\n");
}

/*int codeGen(struct tnode *t, FILE *target_file)
{
	if((t->left == NULL) && (t->right == NULL))
	{
		int p = getReg();
		fprintf(target_file, "MOV R%d, %d\n", p, t->val);
		return p;
	}
	else
	{
		int i = codeGen(t->left, target_file);
		int j = codeGen(t->right, target_file);
		if(*(t->op) == '+')
		{
			fprintf(target_file, "ADD R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
		if(*(t->op) == '-')
		{
			fprintf(target_file, "SUB R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
		if(*(t->op) == '/')
		{
			fprintf(target_file, "DIV R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
		if(*(t->op) == '*')
		{
			fprintf(target_file, "MUL R%d, R%d\n", i, j);
			freeReg();
			return i;
		}
	}
}*/

void tnode_print(struct tnode *t)
{
	printf("\n[");
	printf("val %d\n",t->val);
	printf("type %d\n",t->type);
	printf("nodetype %d\n",t->nodetype);
	switch(t->nodetype)
	{
			case 1:
	    		printf("EXPR\n");
	    		break;
	    	case 2:
	    		printf("ASSGN\n");
	    		break;
	    	case 3:
				printf("CONN\n");
				break;
	    	case 4:
	    		printf("CONSTANT\n");
	    		break;
	    	case 5:
	    		printf("READ\n");
	    		break;
	    	case 6:
	   			printf("VAR\n");
	    		break;
	    	case 7:
	    		printf("WRITE\n");
	    		break;
			case 8 :
				printf("IF\n");
				break;
			case 9 :
				printf("WHILE\n");
				break;
			case 10 :
				printf("BREAK\n");
				break;
			case 11 :
				printf("CONTINUE\n");
				break;
			case 12 :
				printf("REPEAT-UNTIL\n");
				break;
			case 13 :
				printf("DO-WHILE\n");
				break;
			case 14 :
				printf("ARRAY\n");
				break;
			case 15 :
				printf("STRCONSTANT\n");
				break;
			case 16 :
				printf("FUNCTION\n");
				break;
			case 17 :
				printf("RETURN\n");
				break;
	}

  	if(t->varname!=NULL)
  		printf("varname %s\n",t->varname);
 	printf("]\n");
}

void inorder(struct tnode *t)
{ //printf("inside inorder");
	if(t==NULL)
		return;
	inorder(t->left);
	tnode_print(t);
	inorder(t->middle);
	inorder(t->right);
}

void print_header()
{
	fprintf(xsm_file, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(xsm_file, "BRKP\n");
	fprintf(xsm_file, "MOV SP, %d\n", freeAddress);
	fprintf(xsm_file, "MOV BP, %d\n", freeAddress+1);
	fprintf(xsm_file, "PUSH R0\n");
	fprintf(xsm_file, "CALL MAIN\n");
	return;
}

void store_answer()
{
	//fprintf(xsm_file, "PUSH R%d\n",p);
	xos_call("Exit", 0, 0, 0, 0);
	return;
}

/*int evaluate(struct tnode *t)
{
	int temp, lval, mval, rval;
	switch(t->nodetype)
	{
		case NODE_CONSTANT : return t->val;
					break;
		case NODE_VAR : temp = *(t->varname) - 'a';
				printf("%c value is : %d\n", *(t->varname), regarr[temp]);
				return regarr[temp];
				break;
		case NODE_ARR : break;
		case NODE_READ : temp = *(t->left->varname) - 'a';
				printf("Gonna read now.\n");
				fscanf(infile, "%d\n", &regarr[temp]);
				printf("Value Read ; %d\n", regarr[temp]);
				return regarr[temp];
				break;
		case NODE_WRITE : lval = evaluate(t->left);
				fprintf(outfile, "%d\n", lval);
				printf("Just printed.\n");
				printf("Value printed : %d\n", lval);
				return lval;
				break;
		case NODE_EX :
			if(strcmp(t->varname, "<=") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval <= rval)
					return 1;
				else
					return 0;
			}
			else if(strcmp(t->varname, ">=") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval >= rval)
					return 1;
				else
					return 0;
			}
			else if(strcmp(t->varname, "!=") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval != rval)
					return 1;
				else
					return 0;
			}
			else if(strcmp(t->varname, "==") == 0)
			{
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				if(lval == rval)
					return 1;
				else
					return 0;
			}
			switch(*(t->varname))
			{
				case '+' : return evaluate(t->left) + evaluate(t->right);
						break;
				case '-' : return evaluate(t->left) - evaluate(t->right);
						break;
				case '*' : return evaluate(t->left) * evaluate(t->right);
						break;
				case '/' : return evaluate(t->left) / evaluate(t->right);
						break;
				case '<' : lval = evaluate(t->left);
						rval = evaluate(t->right);
						if(lval < rval)
							return 1;
						else
							return 0;
						break;
				case '>' : lval = evaluate(t->left);
						rval = evaluate(t->right);
						if(lval > rval)
							return 1;
						else
							return 0;
						break;
			}
			break;
		case NODE_ASSGN : temp = *(t->left->varname) - 'a';
					rval = evaluate(t->right);
					regarr[temp] = rval;
					return regarr[temp];
					break;
		case NODE_CONN : if(t->left)
					lval = evaluate(t->left);
					if(t->middle)
						mval = evaluate(t->middle);
					if(t->right)
						rval = evaluate(t->right);
					return rval;
					break;
		case NODE_IF : lval = evaluate(t->left);
				if(lval == 1)
				{
					mval = evaluate(t->middle);
					return mval;
				}
				else
				{
					if(t->right)
					{
						rval = evaluate(t->right);
						return rval;
					}
				}
				break;
		case NODE_WHILE :
				lval = evaluate(t->left);
				printf("lval = %d\n", lval);
				while(lval == 1)
				{
					rval = evaluate(t->right);
					lval = evaluate(t->left);
					printf("lval = %d\n", lval);
				}
				return rval;
				break;
		case NODE_BREAK :
				break;
		case NODE_CONTINUE :
				break;
		case NODE_REPUNTIL :
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				printf("rval = %d\n", rval);
				while(rval == 0)
				{
					lval = evaluate(t->left);
					rval = evaluate(t->right);
					printf("rval = %d\n", rval);
				}
				break;
		case NODE_DOWHILE :
				lval = evaluate(t->left);
				rval = evaluate(t->right);
				printf("rval = %d\n", rval);
				while(rval == 1)
				{
					lval = evaluate(t->left);
					rval = evaluate(t->right);
					printf("rval = %d\n", rval);
				}
				break;
	}
}*/

    
