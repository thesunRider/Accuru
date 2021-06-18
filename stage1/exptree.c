

struct tnode* makeLeafNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

int evaluate(struct tnode *t,FILE *fp){
    if(t->op == NULL)
    {
        int r;
        r = getReg();
        fprintf(fp,"MOV R%d , %d\n",r,t->val);
        return r;
    }
    else{
        int p,q;
        p = evaluate(t->left,fp);
        q = evaluate(t->right,fp);
        switch(*(t->op)){
            case '+' : fprintf(fp, "ADD R%d , R%d\n",p,q );
                       break;
            case '-' : fprintf(fp, "SUB R%d , R%d\n",p,q );
                       break;
            case '*' : fprintf(fp, "MUL R%d , R%d\n",p,q );
                       break;
            case '/' : fprintf(fp, "DIV R%d , R%d\n",p,q );
                       break;
        }
        freeReg();
        return p;
    }
}


int getReg(){
    return register_index++;
}

void freeReg(){
    --register_index;
}