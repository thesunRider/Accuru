#define NODE_EX 1
#define NODE_ASSGN 2
#define NODE_CONN 3
#define NODE_CONSTANT 4
#define NODE_READ 5
#define NODE_VAR 6
#define NODE_WRITE 7
#define NODE_IF 8
#define NODE_WHILE 9
#define NODE_BREAK 10
#define NODE_CONTINUE 11
#define NODE_REPUNTIL 12
#define NODE_DOWHILE 13
#define NODE_ARR 14
#define NODE_STRCONSTANT 15
#define NODE_FUNCTION 16
#define NODE_RETURN 17
#define reg_index int
#define inttype 1
#define booltype 2
#define stringtype 3

static int reg = -1;
static int labelCount = -1;
static int whileStack[50];
static int top = -1;
static int freeAddress = 4095;
static int fLabel = -1;

typedef struct tnode {
	int val;	//value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes
	int nodetype;  //information about non-leaf nodes - read/write/connector/+/* etc.
	struct Gsymbol *Gentry;	//pointer to GST entry for global variables and functions
	struct Lsymbol *Lentry; //pointer to the function's LST for local variables and arguements
	struct tnode *arglist; //pointer to the expression list given as arguments to a function call
	struct tnode *left,*middle,*right;	//left and right branches
}tnode;

typedef struct Gsymbol {
	char* name;	// name of the variable
	int type;	// type of the variable
	int size;	// size of the type of the variable
	int binding;	// stores the static memory address allocated to the variable
	struct Paramstruct *paramlist;	//pointer to the head of the formal parameter list
	int fLabel;	  //a label for identifying the starting address of a function's code
	struct Gsymbol *next;	 //points to the next Global Symbol Table entry
}Gsymbol;

typedef struct Lsymbol {
	char *name;	//name of the variable
	int type;	// type of the variable
	int binding;	//local binding of the variable
	struct Lsymbol *next;	//points to the next Local Symbol Table entry
}Lsymbol;

typedef struct Paramstruct {
	char *name;
	int type;
	struct Paramstruct *next;
}Paramstruct;

// typedef struct Typetable {
//     char *name;                 //type name
//     int size;                   //size of the type
//     struct Fieldlist *fields;   //pointer to the head of fields list
// 	int next;     // pointer to the next type table entry
// }Typetable;

// typedef struct Fieldlist {
// 	char *name;              //name of the field
// 	int fieldIndex;          //the position of the field in the field list
// 	int type;  //pointer to type table entry of the field's type
// 	struct Fieldlist *next;  //pointer to the next field
// }Fieldlist;



FILE *yyin;
FILE *xsm_file;
FILE *infile;
FILE *outfile;

struct tnode* createTree(int val,int type,char* varname,int nodetype,struct Gsymbol *Gentry,struct Lsymbol *Lentry,struct tnode *arglist,struct tnode *l,struct tnode *m,struct tnode *r);

int getReg();

void freeReg();

void backup_reg(int num);

void restore_reg(int num);

void xos_call(char *func, int arg1, int arg2, int tempreg, int flag);

reg_index codeGen(struct tnode *t);

void print_header();

void store_answer();

struct Gsymbol* GLookup(struct Gsymbol **headref, char *name); // Returns a pointer to the global symbol table entry for the variable, returns NULL otherwise.

void GInstall(struct Gsymbol **headref, char *name, int type, int size, struct Paramstruct *paramlist); // Creates a global symbol table entry.

void printGSymbolTable(struct Gsymbol **headref); // Prints out the global symbol table

void printParamList(struct Paramstruct **headref); // Prints out the parameters

void GAssignType(struct Gsymbol **headref, int type); // Assigns the types to all the remaining variables in a global declaration.

struct Paramstruct* createParamNode(char *varname, int type); // Creates a parameter in the parameter list.

void appendParamNode(struct Paramstruct **headref, struct Paramstruct *newNode); // Append a new parameter to the parameter list.

struct Paramstruct* ParamLookup(struct Paramstruct **headref, char *varname); // For checking if parameter name already exists in the list.

struct Lsymbol* LLookup(struct Lsymbol **headref, char *name); // Returns a pointer to the local symbol table entry for the variable, returns NULL otherwise.

struct Lsymbol* LInstall(char *name, int type, int binding); // Creates a local symbol entry.

void LAppendNode(struct Lsymbol **headref, struct Lsymbol *newNode); // Appends a node to the local symbol table

void LAppendList(struct Lsymbol **headref, struct Lsymbol *newList); // Appends a list of nodes to the local symbol table

void LAssignType(struct Lsymbol **headref, int type); // Assigns the types to all the remaining variables in a local declaration.

void printLSymbolTable(struct Lsymbol **headref); // Prints out the local symbol table

void checkNameEqv(struct Gsymbol **headref, struct Paramstruct **paramlist); // Checks name equivalence of the formal parameters in the function declaration and definition.

void addParametersToLST(struct Lsymbol **headref, struct Paramstruct **paramlist); // Adds parameters to the LST

void appendArg(struct tnode **headref, struct tnode *newNode); // Appends a new node to the argument list.

void initFuncCode(int label, struct Lsymbol **headref); // Allocating space for local variables when calling the function

void endFuncCode(struct Lsymbol **headref);	// Deallocating space for local variables before returning from the function

int countArg(struct tnode **rootref); // Counting the number of arguments.

void reversePushArg(struct tnode *root); // Pushing the arguments in the stack in the reverse order.

// void TypeTableCreate(int *headref); // initialising the type table with primitive datatypes

// struct Typetable* TLookup(int *headref, char *name); // Search through the type table and return pointer to type table entry of type 'name'. Returns NULL if entry is not found.

// struct Typetable* createTypeNode(char *name, int size, struct Fieldlist *fields); // creates and returns a type table node

// void TInstall(int *headref, char *name, int size, struct Fieldlist *fields); // creates a type table entry in the type table

// struct Fieldlist* FLookup(int *typeref, char *name); // Searches for a field of given 'name' in the 'fieldlist' of the given user-defined type and returns a pointer to the field entry

int getSize(int *typeref); // Returns the amount of memory words required to store a variable of the given type

/*Create a node tnode*/
//struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);

	/*Make a leaf tnode and set the value of val field*/
//struct tnode* makeLeafNode(int n);

	/*Make a tnode with opertor, left and right branches set*/
//struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

	/*To evaluate an expression tree*/
//int evaluate(struct tnode *t);
