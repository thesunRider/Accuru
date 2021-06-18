void insertNode(struct tnode **headref, char *labelval, int addval)
{
    struct tnode *temp = *headref;
    struct tnode *newNode = (struct tnode *)malloc(sizeof(struct tnode));
    newNode->label = (char *)malloc(10);
    strcpy(newNode->label, labelval);
    newNode->address = addval;
    newNode->next = NULL;
    if(temp == NULL)
    {
        *headref = newNode;
        return;
    }
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}
int getAddress(struct tnode **headref, char *labelval)
{
    struct tnode *temp = *headref;
    printf("%s\n", labelval);
     
    int res = -1;
    while((temp != NULL) && (strcmp(temp->label, labelval) != 0))
    {
        temp = temp->next;
    }
     
    if(temp)
    {
        if(strcmp(temp->label, labelval) == 0)
            res = temp->address;
    }        
    return res;
}

void printLabel(struct tnode **headref)
{
    struct tnode *temp = *headref;
    while(temp)
    {
        printf("%s -> %d\n", temp->label, temp->address);
        temp = temp->next;
    }
}
