%{ 

#include<stdio.h> 
int lc=0, sc=0, tc=0, ch=0; /*Global variables*/

%} 

/*Rule Section*/
%% 

\n 			return 0; 	//line counter 
([ ])+ 		sc++;	 	//space counter 
\t 			tc++; 		//tab counter 
. 			ch++;	 	//characters counter 

%% 

void main() 
{ 
	// The function that starts the analysis 
	yylex(); 
	
	printf("\nNo. of lines=%d", lc); 
	printf("\nNo. of spaces=%d", sc); 
	printf("\nNo. of tabs=%d", tc); 
	printf("\nNo. of other characters=%d", ch); 
	
} 
