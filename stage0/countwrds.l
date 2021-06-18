    
%{ 

int valid_word=0; 

%} 
  
%% 

(["A"]((.)(.))) valid_word++; 
.;

%% 
  
int main() 
{ 
  yylex(); 

  if(valid_word!=0) printf("Valid good characters = %d\n",valid_word); 
  else printf("Nothig recognised\n"); 
  return 0; 
} 