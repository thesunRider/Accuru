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
	#endif


%}

%%



[0-9]+		{
				number = atoi(yytext);
				printf("Pnumber %d>",number);
				yylval.no = createTree(number,0,NUM,yytext,NULL,NULL); 
				return NODE_NUM;
			}

"begin"		{printf("Pbegin>");return NODE_BEGIN;}
"end"		{printf("Pend>");return NODE_END;}
"read"		{printf("Pread>");return NODE_READ;}
"write"		{printf("Pwrite>");return NODE_WRITE;}
"="			{printf("Pequals>");return *yytext;}


[a-z]		{
				printf("Pid %s>",yytext);
				yylval.no = createTree(0,0,ID,yytext,NULL,NULL); 
				return NODE_ID;
			}

";"			{return *yytext;}


"+"			{return NODE_PLUS;}
"-"			{return NODE_MINUS;}
"*"			{return NODE_MUL;}
"/"			{return NODE_DIV;}

[\s]		{}
[ \t]		{}
[()]		{return *yytext;}
[\n]		{}
.			{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}

/*

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 1;
}

*/

