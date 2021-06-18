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




typedef struct tnode{

 	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	char* varname;	//name of a variable for ID nodes  
	struct tnode *left,*right;


 }tnode;

struct tnode* createTree(int val, int type,int nodetype, char* varname, struct tnode *l, struct tnode *r);
	
struct tnode* makeLeafIntegerNode(int n);
struct tnode* makeLeafVarNode(char n);	

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
	
/*To evaluate an expression tree*/
int evaluate(struct tnode *t,FILE *fp);

int getvar_addrs(char* var);

int getReg();
void freeReg();
void xos_call(FILE *fp,char *func_code ,int arg1,int arg2);
const long int var_hash(char *str);

int jumplabel();