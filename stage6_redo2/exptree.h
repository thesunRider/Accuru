//section for nodetype
#define NUM 1
#define PLUS 2
#define MINUS 3
#define MUL 4
#define DIV 5
#define ARRAY_TYPE 6
#define READ 8
#define WRITE 9
#define ASSIGN 10
#define OP 11
#define ID 12
#define CONNECT 13
#define LOGIC_OP 14
#define IF 15
#define WHILE 16
#define BREAK 17
#define CONTINUE 18
#define STR 19
#define FUNCTION_CONNECT 20
#define FUNCTION_CALL 21
#define FUNCTION_ARGUMENT_LIST 22
#define FUNCTION_LIST 23
#define FUNCTION_RETURN 24
#define USER_TYPE 25
#define MEM_ALLOC 26
#define MEM_INIT 27
#define MEM_FREE 28
#define MEM_ASSIGN 29

//section for varname
#define var_PLUS 177616
#define var_MINUS 177618
#define var_DIV 177620
#define var_MUL 177615

#define var_GRT 177633
#define var_LES 177635
#define var_GEQ 5861950
#define var_LEQ 5862016
#define var_NEQ 5861059
#define var_EQ 5861983

//section for type
#define IF_SINGLE 1
#define IF_DOUBLE 2
#define BOOL_TYPE 3
#define INT_TYPE 4
#define STR_TYPE 5
#define VAR_UNDEF 7
#define FUNCTION_TYPE 8


typedef struct Fsymbol { //global functions symbol table
	char *name; //name of variable
	int type; //type of variable
	int jmp; //function entry
	int jmpext; //function exit
	struct PTable *param_list;
	struct PTable *local_var;
	struct Fsymbol *next;

}Fsymbol;

typedef struct tnode{

 	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	char* varname;	//name of a variable for ID nodes  
	struct tnode *left,*right;


 }tnode;

 typedef struct Ttable{ //typesymboltable

	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	struct PTable *varlist; //members of the type table
	struct Ttable *next; 
 }Ttable;


typedef struct Gsymbol { //global symboltable

	char* name; //name of variable
	int type; //type of variable
	int size;	//size of variable
	int binding;	//binding of variable
	int env_type; //0 for local , 1 for global, 2 for parameter,3 for user type
	char* func_name; //name of the function the variable belongs to
	struct Gsymbol *next; //next value in symbol table
 }Gsymbol;


typedef struct PTable { //Parameters of functions saved here
	int type; //type of variable
	struct Gsymbol *var; //next value in symbol table
	struct PTable *next; //next stuff
 }PTable;

struct Ttable *TypeLookup(char *name);
struct Gsymbol* TypeVarlistLookup(char *varname);
struct Gsymbol *Lookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
struct Gsymbol *LocalLookup(char *name);

struct Gsymbol* appendSymbolTable(struct Gsymbol *headref,struct Gsymbol *main);
struct Gsymbol *searchPtable(char *name,struct PTable **table);
struct Fsymbol *searchFunction(char *name);

struct Ttable* createType(char *typename, struct PTable *varlist);
void assignType(struct Gsymbol **headref, int type);
void printSymbolTable(struct Gsymbol **headref);

void pushglobals(FILE *fp);
void Install(char *name, int type, int size); // Creates a Globalsymbol table entry.
struct Gsymbol*  createSymbol(char *name, int type, int size,int binding);
void InstallLocals(struct PTable *local_list,char* func_name);

struct PTable* createParam(char *name, int type,int bind);
struct PTable* InstallParam(struct PTable *headref,char *name, int type,int bind);

struct PTable* createDeclType(int type, struct Gsymbol *varlist);
struct PTable* InstallDeclType(struct PTable *headref,struct PTable *currenTable);

struct tnode* appendTree(struct tnode *headref,struct tnode *main);
struct tnode* createTree(int val, int type,int nodetype, char* varname, struct tnode *l, struct tnode *r);
struct tnode* makeLeafIntegerNode(int n);
struct tnode* makeLeafVarNode(char n);	
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);


void debug_setcurrentfunction(char *name,int jmp,int jmpex);
void debug_poplastfunction();
struct tnode* debug_getcurrentfunction();

/*To evaluate an expression tree*/
int evaluate(struct tnode *t,FILE *fp);

int get_memadrs_reg(struct tnode *t,FILE *fp);
int getvar_binding_mem(struct tnode* t);
int getvar_arrayaddrs(char* var,int ary_indx);

int getReg();
void freeReg();
int xos_call(FILE *fp,char *func_code ,int arg1,int arg2);
const long int var_hash(char *str);

int jumplabel();


/**
	STACK DIAGRAM:

	GLOBALVAR

	REGISTERS(previous)		| 4096
	Parameters 				|				
	RETURNVAL				|
	RETURNADDRESS			|
	OLDBP					|
	LOCALVAR 				V grows down 

**/