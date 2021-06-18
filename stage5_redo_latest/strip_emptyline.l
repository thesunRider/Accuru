%{
#include<stdio.h>
FILE *fp;
%}


%%
^(?:[\t ]*(?:\r?\n|\r))+ {}						
%%


int yywrap()
{
return 1;
}



int main()
{
extern FILE *yyin; 
fp = fopen("out2.txt","w");
yyin=fopen("out.txt","r");
yyout=fp;

yylex();

return 0;
}