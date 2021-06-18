
%{
#include<stdio.h>
int yylineno;
int start = 2056;
int size = 2;

static int max_jumps = 10;

int ary[10][2]; //change max labels here too...
int i = -1;

FILE *fp;

int found_val = -1;
int replace_gate = 0; //this will determine wether to start replacing the function names
extern int yylex_destroy(void);
//THERE ARE TWO STAGE SCAN FIRST WE RETRIEVE ALL THE FUNCTIONS 
//THEN WE PLUG VALUES IN
%}

%option yylineno



%%	

(:[0-9]*\n) {if (replace_gate == 1)
				{
					++yytext;
					int loop;
					for(loop = 0; loop <= found_val; loop++){
							if (atoi(yytext) == ary[loop][0]){
							fprintf(fp,"%d\n", ary[loop][1]);
							break;}
						}
				}
			}

(:[0-9]*) {
		if (replace_gate == 0){
			++i;
			++found_val;
			ary[i][0] = atoi(++yytext);
			//found_val is substracted due to linenumbers being deleted it acts like a stack
			ary[i][1] = start + size*(yylineno - found_val+1) ;
			}
		}


[\n]  {
		if (replace_gate == 1)
		{++yylineno;fprintf(fp,"\n");}
	  }
%% 


int yywrap()
{
return 1;
}



int main()
{
extern FILE *yyin; 

yyin=fopen("out.txt","r");

yylex();

printf("\n");

int loop;
printf("Finished mapping \n");
printf("LNME - LNO\n");
for(loop = 0; loop <= found_val; loop++){
	printf("%d - %d \n", ary[loop][0],ary[loop][1]);
}

printf("Starting second gating....\n");
replace_gate = 1;

yylex_destroy();

//second gating started

extern FILE *yyin;
fp = fopen("out2.txt","w"); 
yyin=fopen("out.txt","r");
yyout=fp;
yylex();


return 0;
}