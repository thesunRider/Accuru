//section for nodetype
#define NUM 1
#define PLUS 2
#define MINUS 3
#define MUL 4
#define DIV 5
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
#define ARRAY_TYPE 6
#define FUNCTION_TYPE 7
#define FUNCTION_ARGLIST 8
#define FUNCTION_PARAMETER 9
#define FUNCTION_ID 10
#define FUNCTION_MAIN 11
#define FUNCTION_ARGLISTNODE 12

//entry variable
#define VAR_LOCAL 1
#define VAR_GLOBAL 2

typedef struct tnode{

 	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	char* varname;	//name of a variable for ID nodes  
	struct tnode *left,*right;
	int entry;		 //define wether this is a global or local variable
 }tnode;

typedef struct Gsymbol {

	char* name;
	int type;
	int size;
	int binding;
	struct tnode *paramlist;
	int flabel;
	int entry;		 //define wether this is a global or local variable
	struct Gsymbol *next;
 }Gsymbol;

struct tnode* appendArg(struct tnode **headref, struct tnode **newNode);

struct tnode* createParamNode(char *varname, int type);
struct tnode* ParamLookup(struct tnode **headref, char *varname);
void appendParamNode(struct tnode **headref, struct tnode *newNode);

void LAppendNode(struct Gsymbol **headref, struct Gsymbol *newNode);
struct Gsymbol* LInstall(char *name, int type, int binding);

struct Gsymbol *Lookup(struct Gsymbol **tablelook,char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void assignType(struct Gsymbol **headref, int type);
void printSymbolTable(struct Gsymbol **headref);
void Install(char *name, int type, int size,struct tnode *plist); // Creates a symbol table entry.


struct tnode* createTree(int val, int type,int nodetype, char* varname, struct tnode *l, struct tnode *r);	
struct tnode* makeLeafIntegerNode(int n);
struct tnode* makeLeafVarNode(char n);	
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);




/*To evaluate an expression tree*/
int evaluate(struct tnode *t,FILE *fp);

int getvar_addrs(struct tnode* t);
int getvar_arrayaddrs(char* var,int ary_indx);

int getReg();

void freeReg();
void xos_call(FILE *fp,char *func_code ,int arg1,int arg2);
const long int var_hash(char *str);

int jumplabel();


int yylex(void);
int yyerror(char const *s);
