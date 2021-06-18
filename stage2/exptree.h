//TOKEN DECLARATION
#define NUM 1
#define PLUS 2
#define MINUS 3
#define MUL 4
#define DIV 5
#define READ 8
#define WRITE 9
#define EQUALS 10
#define OP 11
#define ID 12
#define CONNECT 13

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