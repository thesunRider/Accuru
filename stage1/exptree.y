%{
	#include <stdlib.h>
	#include <stdio.h>
	int yylex(void);
	int yyerror(char const *s);
	FILE *code;
	int register_index;

	#include "exptree.h"
	#include "exptree.c"

%}

%union{
	struct tnode *no;
	
}

%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
				$$ = $2;
				evaluate($1,code);
				
				exit(1);
			}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr	{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 1;
}


int main(void) {
	register_index = 0;
	code = fopen("out.txt", "w");
	yyparse();
	
	return 0;
}