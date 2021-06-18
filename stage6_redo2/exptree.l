%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "exptree.h"
	#include <string.h> 
	#include <stdlib.h>
	#include "y.tab.h"
	#include <signal.h>

	int yyerror(char const *s);
	int number;

	extern int inside_function; //0 false 1 true
	extern int inside_declaration; //0 false 1 true
	extern int inside_type;
	extern int local_count;
	extern int param_count;
	extern int type_count;


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
		#define NODE_THEN 20`
		#define NODE_ELSE 21
		#define NODE_ENDIF 22
		#define NODE_GRT 23
		#define NODE_LES 24
		#define NODE_GEQ 25
		#define NODE_LEQ 26
		#define NODE_NEQUALS 27
	#endif


%}

%option yylineno

%%


"end"		{	printf("Pend>");
				inside_function = 0;
				return NODE_END;
			}
"endif"		{printf("Pendif>");return NODE_ENDIF;}
"endwhile"	{printf("Pendwhile>");return NODE_ENDWHILE;}

"begin"		{	printf("Pbegin>");
				inside_function = 1; 
				//since all decl and endecl that are inside begin are 
				//inside a function we can safely assume this.
				return NODE_BEGIN;
			}

"type"		{
				printf("Ptype>");
				inside_type = 1;
				return NODE_TYPE;
			}

"endtype"	{
				printf("Pendtype>");
				inside_type = 0;
				return NODE_ENDTYPE;
			}
"free"		{printf("Palloc>");return NODE_FREE;}
"initialize" {printf("Palloc>");return NODE_INIT;}
"alloc"		{printf("Palloc>");return NODE_ALLOC;}
"return"	{printf("Preturn>");return NODE_RETURN;}
"read"		{printf("Pread>");return NODE_READ;}
"write"		{printf("Pwrite>");return NODE_WRITE;}
"do"		{printf("Pdo>");return NODE_DO;}
"while"		{printf("Pwhile>");return NODE_WHILE;}
"if"		{printf("Pif>");return NODE_IF;}
"then"		{printf("Pthen>");return NODE_THEN;}
"else"		{printf("Pelse>");return NODE_ELSE;}
"break"		{printf("Pbrk>");return NODE_BREAK;}
"continue"	{printf("Pcont>");return NODE_CONTINUE;}
"decl"		{
				local_count = 0;
				printf("Pdecl>");
				inside_declaration = 1;
				return NODE_VARDECL;

			}
"enddecl"	{
				local_count = 0;
				printf("Pendecl>");
				inside_declaration = 0;
				return NODE_VARENDDECL;
			}
"str"		{printf("Pstr> %s",yytext);return NODE_TYPE_STR;}
"int"		{printf("Pint>");return NODE_TYPE_INT;}
"true"		{printf("Ptrue>");return NODE_TYPE_BOOL;}
"false"		{printf("Ptrue>");return NODE_TYPE_BOOL;}


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

"," 		{return *yytext;}
"[" 		{return *yytext;}
"]" 		{return *yytext;}
"="			{return *yytext;}
";"			{return *yytext;}


[0-9]+		{
				number = atoi(yytext);
				printf("Pnumber %d>",number);
				yylval.node = createTree(number,0,NUM,yytext,NULL,NULL); 
				return NODE_NUM;
			}

[a-zA-Z]*		{
				printf("Pid %s>",yytext);
				yylval.node = createTree(0,0,ID,yytext,NULL,NULL); 
				//raise(SIGINT);
				return NODE_ID;
			}

\"([^\"]*)\"	{
				printf("Pstr %s>",yytext);
				yylval.node = createTree(0,0,STR,strdup(yytext),NULL,NULL); 
				return NODE_STR;
			}


[ \t]		{}
[()] 		{
				param_count = 0; //we are reseting param count ,as all params come under brackets
				return *yytext;
			}
[{] 		{type_count = 1;return *yytext;}
[}]			{type_count = 0;return *yytext;}
[.]			{return *yytext;}

[\n]		{}
.			{yyerror("unknown character\n");exit(1);}

%%

int yywrap() {
	return 1;
}

/*
int main(){

yylex();
return 0;
}

*/

int yyerror(char const *s)
{
	printf("\n yacc>>Error | Line: %d\n%s\n",yylineno,s);
    return 1;
}



