#define tNUM 0
#define tADD 1
#define tSUB 2
#define tMUL 3
#define tDIV 4
#define tREAD 5
#define tWRITE 6
#define tASSIGN 7
#define tVAR 8
#define tCONNECT 9
#define tLT 10
#define tGT 11
#define tLE 12
#define tGE 13
#define tEQ 14
#define tNE 15
#define tIF 16
#define tWHILE 17
#define tBREAK 18
#define tCONTINUE 19
#define tDOWHILE 20
#define intType 21
#define stringType 22
#define boolType 23
#define tREPEAT 24
#define heapBase 4096
#define tDCONNECT 25
#define tDECL 26
#define tVCONNECT 27
#define tLIT 28
#define tARR 29
#define tDARR 30
#define pIntType 31
#define pStringType 32
#define tPVAR 33
#define tBRKP 34
#define tREF 35
#define tDEREF 36

#define tFUNC 38
#define tFCALL 39
#define tRET 40
#define tBODY 41

int tempreg;
int label;
int funcLabel=1;
int tempCount=0;
int memory[26];
struct StackNode* breakstack;
struct StackNode* contstack;
int staticSize = 4096;	//leave space for main's return value and return address?
int localOffset=1;
int argOffset=-3;
char * typeToString(int type);


struct globalEntry * gLookup(char * name);


struct globalEntry * symtable = NULL;
struct localTable * allLST = NULL;
char *currFunc;


// A structure to represent a stack
struct StackNode
{
    int data;
    struct StackNode* next;
};
typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* name;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc. 
	struct tableEntry *entry; //pointerto entry for global variables and functions 
	struct tnode *left,*middle,*right,*arglist;	//left and right branches   
}tnode;

