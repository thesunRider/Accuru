
%{
#include <stdio.h>
#include <string.h>

int yylineno;

int mem_offest = 2038;
int op_size = 2;

int scan = 1;

//2098

typedef struct lb_rf
{
	char *label_name;
	int lineno;
	struct lb_rf *next;
} lb_rf;

extern FILE *yyin;
extern FILE *yyout;

FILE *fp;
lb_rf label_ref;

void appendlabel(char *name, int lineno);
char* subString (const char* input, int offset, int len, char* dest);

extern int yylex_destroy(void);
int yyerror(char const *s);
int getlineno(char *name);
%}

%option yylineno


%%	

(\#(:-*([0-9]*))+\#) {
						char dest[strlen(yytext)];
						bzero(dest, strlen(yytext));  
						subString (yytext, 1, strlen(yytext)-2, dest);
						appendlabel(strdup(dest),yylineno);
					}

(:-*([0-9]*)) {
					if(scan == 2){
						printf("addingc\n");
						fprintf(yyout, "%d", mem_offest + op_size*getlineno(yytext));
						}else{
							fprintf(fp, "%s",yytext );
						}
					}

\n 					{fprintf(yyout, "\n" );}

%% 



char* subString (const char* input, int offset, int len, char* dest)
{
  int input_len = strlen (input);

  if (offset + len > input_len)
  {
     return NULL;
  }

  strncpy (dest, input + offset, len);
  return dest;
}

int getlineno(char *name){
	struct lb_rf *temp = &label_ref;
	temp = temp->next ;//first is empty

	 while(temp->next != NULL){
	 	if (strcmp(temp->label_name,name)==0)
	 	{
	 		return temp->lineno;
	 	}
	 	temp = temp->next;
	 }
	 return 0;
}

void appendlabel(char *name, int lineno){
	 struct lb_rf *temp = &label_ref;


	 while(temp->next != NULL){
	 	temp = temp->next;
	 }

	 struct lb_rf *temp2;
	 temp2 = (struct lb_rf*)malloc(sizeof(struct lb_rf));

	 if (temp == NULL)
	 {
	 	temp = temp2;
	 	return;
	 }else{
		temp2->label_name = strdup(name);
	 	temp2->lineno = lineno;
	 	temp->next = temp2;
	 }

}


int yywrap()
{
	//[a-zA-Z]*.(:-*([0-9]*)) {printf(" STATEMENT WAS MADE>%s\n", yytext);}

return 1;
}



int main()
{

yyin = fopen("striped.txt","r");
fp =  fopen("striped2.txt", "w");
yyout = fp;
//fp =  fopen("out.txt", "w");

yylex();
printf("First scan completed\n");
++scan;
fclose(fp);

yylex_destroy();


yyin = fopen("striped2.txt","r");
fp =  fopen("striped3.txt", "w");
yyout = fp;

yylex();

return 0;
}

int yyerror(char const *s)
{
	printf("\n yacc>>Error | Line: %d\n%s\n",yylineno,s);
    return 1;
}

