
%{
#include <stdio.h>
#include <string.h>
#include <ctype.h>

extern FILE *yyin; 
extern FILE *yyout;

int yylineno;

char *curstr;
int curline;

FILE *fp;
char *trim(char *str);

extern int yylex_destroy(void);
int yyerror(char const *s);
%}

%option yylineno


%%	


^[A-Z].(.*)	{		
					if (yylineno == (curline+1) && curstr != NULL){
						fprintf(fp, "%s #%s#\n",trim(yytext),curstr );
						}
					else{
						fprintf(fp, "%s\n",yytext);}
				}

^(:-*([0-9]*)) { //this section finds standing labels only
				curstr = strdup(yytext);
				curline = yylineno;
				}

[0-9]* {fprintf(fp, "%s\n" ,yytext);}
\n 	{}

%% 

char *trim(char *str)
{
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if( str == NULL ) { return NULL; }
    if( str[0] == '\0' ) { return str; }

    len = strlen(str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
     * characters from each end.
     */
    while( isspace((unsigned char) *frontp) ) { ++frontp; }
    if( endp != frontp )
    {
        while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
    }

    if( frontp != str && endp == frontp )
            *str = '\0';
    else if( str + len - 1 != endp )
            *(endp + 1) = '\0';

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if( frontp != str )
    {
            while( *frontp ) { *endp++ = *frontp++; }
            *endp = '\0';
    }

    return str;
}


int yywrap()
{
	//[a-zA-Z]*.(:-*([0-9]*)) {printf(" STATEMENT WAS MADE>%s\n", yytext);}

return 1;
}



int main()
{

yyin = fopen("out.txt","r");
fp = fopen("striped.txt","w");
yyout = fp;
yylex();

return 0;
}

int yyerror(char const *s)
{
	printf("\n yacc>>Error | Line: %d\n%s\n",yylineno,s);
    return 1;
}

