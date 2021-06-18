
%{
#include<stdio.h>
%}


%%
\;(.*) {};							
%%


int yywrap()
{
return 1;
}



int main()
{
extern FILE *yyin; 

yyin=fopen("out.txt","r");
yyout=fopen("out2.txt","w");

yylex();

return 0;
}