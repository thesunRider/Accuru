int hashCode(int label) {//can change for strings
   return label % SIZE;
}

int search(int label) {
   //get the hash 
   int hashIndex = hashCode(label);  
   
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if(hashArray[hashIndex]->label == label)
         return (hashArray[hashIndex])->address; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return -1;        
}


int fsearch(int label) {
   //get the hash 
   int hashIndex = hashCode(label);  
   
   //move in array until an empty 
   while(funcArray[hashIndex] != NULL) {
	
      if(funcArray[hashIndex]->label == label)
         return (funcArray[hashIndex])->address; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return -1;        
}


void insert(int label,int address) {

   labelItem *item = (labelItem*) malloc(sizeof(labelItem));
   item->address = address;  
   item->label = label;

   //get the hash 
   int hashIndex = hashCode(label);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->label != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
		hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

void finsert(int label,int address) {

   labelItem *item = (labelItem*) malloc(sizeof(labelItem));
   item->address = address;  
   item->label = label;

   //get the hash 
   int hashIndex = hashCode(label);

   //move in array until an empty or deleted cell
   while(funcArray[hashIndex] != NULL && funcArray[hashIndex]->label != -1) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
		hashIndex %= SIZE;
   }
	
   funcArray[hashIndex] = item;
}


void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%d,%d)",hashArray[i]->label,hashArray[i]->address);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}

