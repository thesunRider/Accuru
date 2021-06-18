%{
#include<stdio.h>
int yylex(void);
int yyerror(char *s);
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%

S:  E {printf("\n");}
    ;
E:  E '+' E {printf(" + ");}
    |   E '*' E {printf(" * ");}
    |   E '-' E {printf(" - ");}
    |   E '/' E {printf(" / ");}
    |   '(' E ')'
    |   '-' E {printf(" - ");}
    |   NUM     {printf(" %d ", yylval);}
    ;
%%

int main(){
    yyparse();
}


int yyerror (char *msg) {
    return printf ("error YACC: %s\n", msg);
}