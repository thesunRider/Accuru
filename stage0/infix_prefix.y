%{

#include<stdio.h>
int yylex(void);
int yyerror(char *s);

%}


%union
{
    char character;
    int integer;

};

%token PLUS MINUS MUL DIV 
%token NUMBER

%type <character> PLUS MINUS MUL DIV 
%type <integer> NUMBER


%left PLUS MINUS
%left MUL DIV


%%

S: expr
    ;

expr: expr PLUS expr { printf("%c %d %d",$<character>2,$<integer>1,$<integer>3); }
    | expr MINUS expr { printf("%c %d %d",$<character>2,$<integer>1,$<integer>3); }
    | expr MUL expr { printf("%c %d %d",$<character>2,$<integer>1,$<integer>3); }
    | expr DIV expr { printf("%c %d %d",$<character>2,$<integer>1,$<integer>3); }
    | NUMBER        { $<integer>$=$<integer>1; }
    ;

%%


int main(){
    yyparse();
}


int yyerror (char *msg) {
    return printf ("error YACC: %s\n", msg);
}

