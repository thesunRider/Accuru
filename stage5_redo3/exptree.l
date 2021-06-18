%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exptree.h"
	#include <string.h> 
	#include <stdlib.h>
	#include "y.tab.h"
	int yyerror(char const *s);
	int number;


	#if !defined NODE_READ
		#define NODE_NUM 1
		#define NODE_PLUS 2
		#define NODE_MINUS 3
		#define NODE_MUL 4
		#define NODE_DIV 5
		#define NODE_READ 8
		#define NODE_WRITE 9
		#define NODE_EQUALS 10
		#define NODE_OP 11
		#define NODE_ID 12
		#define NODE_CONNECT 13
		#define NODE_BEGIN 14
		#define NODE_END 15
		#define NODE_WHILE 16
		#define NODE_DO 17
		#define NODE_ENDWHILE 18
		#define NODE_IF 19
		#define NODE_THEN 20
		#define NODE_ELSE 21
		#define NODE_ENDIF 22
		#define NODE_GRT 23
		#define NODE_LES 24
		#define NODE_GEQ 25
		#define NODE_LEQ 26
		#define NODE_NEQUALS 27
		#define NODE_STR 28
		#define NODE_BREAK 29
		#define NODE_CONTINUE 30
		#define NODE_VARDECL 31
		#define NODE_VARENDDECL 32
		#define NODE_RETURN 33
		#define NODE_TYPE_STR 34
		#define NODE_TYPE_INT 35
	#endif


%}

%%



[0-9]+		{
				number = atoi(yytext);
				printf("Pnumber %d>",number);
				yylval.node = createTree(number,0,NUM,yytext,NULL,NULL); 
				return NODE_NUM;
			}

\"([^\"]*)\" {
				printf("Pstr %s>",yytext);
				yylval.node = createTree(0,0,STR,strdup(yytext),NULL,NULL); 
				return NODE_STR;
			}

"end"		{printf("Pend>");return NODE_END;}
"endif"		{printf("Pendif>");return NODE_ENDIF;}
"endwhile"	{printf("Pendwhile>");return NODE_ENDWHILE;}

"begin"		{printf("Pbegin>");return NODE_BEGIN;}
"read"		{printf("Pread>");return NODE_READ;}
"write"		{printf("Pwrite>");return NODE_WRITE;}
"do"		{printf("Pdo>");return NODE_DO;}
"while"		{printf("Pwhile>");return NODE_WHILE;}
"if"		{printf("Pif>");return NODE_IF;}
"then"		{printf("Pthen>");return NODE_THEN;}
"else"		{printf("Pelse>");return NODE_ELSE;}
"break"		{printf("Pbrk>");return NODE_BREAK;}
"continue"	{printf("Pbrk>");return NODE_CONTINUE;}
"decl"		{printf("Pdecl>");return NODE_VARDECL;}
"enddecl"	{printf("Pendecl>");return NODE_VARENDDECL;}
"return"	{printf("Preturn>");return NODE_RETURN;}
"str"		{printf("Pstr>");return NODE_TYPE_STR;}
"int"		{printf("Pint>");return NODE_TYPE_INT;}
[a-zA-Z]+	{
				printf("Pid %s>",yytext);
				yylval.node = createTree(0,0,ID,yytext,NULL,NULL); 
				return NODE_ID;
			}





"<="		{return NODE_GEQ;}
">="		{return NODE_LEQ;}
"!="		{return NODE_NEQUALS;}
"=="		{return NODE_EQUALS;}
"<"			{return NODE_GRT;}
">"			{return NODE_LES;}

"+"			{return NODE_PLUS;}
"-"			{return NODE_MINUS;}
"*"			{return NODE_MUL;}
"/"			{return NODE_DIV;}


[{}] 		{return *yytext;}

"," 		{return *yytext;}
"[" 		{return *yytext;}
"]" 		{return *yytext;}
"="			{return *yytext;}
";"			{return *yytext;}

[ \t]		{}
[()] 		{return *yytext;}
[\n]		{}
.			{yyerror("unknown character\n");exit(1);}

%%

int yywrap() {
	return 1;
}

/*
int main(){
extern FILE *yyin; 
FILE *code;


yyin = fopen("factorial", "r");

yylex();
return 0;
}
*/

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 1;
}


