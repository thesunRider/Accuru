
%{
#include<stdio.h>
%}


%%
\/\/(.*) {};					

\/\*(.*\n)*.*\*\/  {};			
%%


int yywrap()
{
return 1;
}



int main()
{
yyin=fopen("test_code","r");

printf("_______________");
yylex();
printf("_______________");

return 0;
}