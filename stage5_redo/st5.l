%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include"y.tab.h"
	int val;
%}
%option noyywrap

single \/\/

%%

begin { 
		return BEG;
		}
end {	
		return END;
	}
	
read	{
		return READ;
		}
write {
		return WRITE;
	}

if {
	return IF;
	}
then {
	return THEN;	
	}
else {
	return ELSE;
	}
endif {
	return ENDIF;
	}

while {
	return WHILE;
	}

do {
	return DO;
}

endwhile {
	return ENDWHILE;
	}

break {
	return BREAK;
}

continue {
	return CONTINUE;
}

decl {
	return DECL;	
}

enddecl {
	return ENDDECL;
}

int {
	return INT;
}

str {
	return STR;
}
breakpoint {
	return BRKP;
}
return {
	return RETURN;
	}

main {
	return MAIN;
	}
{single}.*[\n] ;

"<"	return LT;
">"	return GT;
"<="	return LE;
">="	return GE;
"=="	return EQ;
"!="	return NE;
"+"	return ADD;
"-"	return SUB;
"*"	return MUL;
"/"	return DIV;

[a-zA-Z]+[a-zA-Z0-9]* {
		char * temp = strdup(yytext);
		yylval = createVarNode(temp);
		return ID;}
		
"[" {return *yytext;}
"]" {return *yytext;}
"&" {return *yytext;}

[\"].*[\"] {
		char * temp = strdup(yytext);
		yylval = createLiteralNode(temp);
		return LIT;
	}

[0-9]+ { val = atoi(yytext);
		yylval = createNumNode(val);
		return NUM;}
		
[ \t\n] 	{}

;		{return *yytext;}
		
[()\{\}] {return *yytext;}


[\=] {
		return *yytext;
		}

"," {
		return *yytext;
}
. {	yyerror("unknown character\n");
	exit(1);
	}

%%




