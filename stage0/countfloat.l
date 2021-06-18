    
%{ 

int valid_int=0, valid_float=0; 

%} 
  
%% 
^[-+]?[0-9]* valid_int++; 
^[-+]?[0-9]*[.][0-9]+$ valid_float++; 
.; 
%% 
  
int main() 
{ 
  yylex(); 

  printf("recognised int = %d\n", valid_int);
  printf("recognised float = %d\n", valid_float);

  if(valid_int!=0) printf("Valid Integer number\n"); 
  else if(valid_float!=0) printf("Valid Float number\n"); 
  else printf("Not valid Integer/Float number\n"); 
  return 0; 
} 