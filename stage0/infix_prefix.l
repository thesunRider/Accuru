%{
#include"y.tab.h"
int yyerror(char *s);
%}


%%

[0-9]+  {yylval.integer=atoi(yytext); return NUMBER;}
"+"	{yylval.character=*strdup(yytext);return PLUS;}
"-"	{yylval.character=*strdup(yytext);return MINUS;}
"*"	{yylval.character=*strdup(yytext);return MUL;}
"/"	{yylval.character=*strdup(yytext);return DIV;}
\n      return 0;
.       return *yytext;

%%

int yywrap(){
    return 1;
}