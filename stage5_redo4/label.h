typedef struct tnode {
	char* label;	//name of the label  
	int address;  // address value  
	struct tnode *next;	//next node   
}tnode;

void insertNode(struct tnode **headref, char *labelval, int addval);
int getAddress(struct tnode **headref, char *labelval);
