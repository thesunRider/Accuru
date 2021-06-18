
%option noyywrap

%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include"y.tab.h"
	#include"label_tr.h"
	#include"label_tr.c"
	extern FILE *yyin;
	FILE* fout,*ftemp,*fin;
	int pass=1;
	int currLine = 2048;
%}

%%

L(.)*:[\n] {
			if(pass==1){
				char t;
				t = yytext[1];
				insert(t-'0',currLine);
			}
			}
F(.)*:[\n] {
			if(pass==1){
				char t;
				t = yytext[1];
				finsert(t-'0',currLine);
			}
		}
			
(MAIN:[\n]) {
			if(pass==1){
					finsert(0,currLine);
			}
	}

(MAIN[\n]) {
	

		if(pass==2){
			fprintf(fout,"%d\n",fsearch(0));
			incLine();
		} else if(pass == 1){
			fstrcpy(ftemp, yytext);
			incLine();
		} 
		
}

(J(.)*[\n]) {	
				
				if(pass == 1){
					fstrcpy(ftemp, yytext);
				} else {
					int i, labelNo;				
					char tempS[50];
					//saves string upto 'L' eg "JMP ", "JZ R4, "
					for(i=0; i<yyleng && yytext[i]!='L' ; i++){
						tempS[i] = yytext[i];
					}
					tempS[i]='\0';
					labelNo = yytext[i+1] - '0';
					fprintf(fout,"%s%d\n",tempS,search(labelNo));
				}
				incLine();
			}

(C(.)*F(.)*[\n]) {
				
				if(pass == 1){
					fstrcpy(ftemp, yytext);
				} else {
					int i,j, labelNo;				
					char tempS[50];
					//i will have the number after 'F'
					for(i=0; i<yyleng && yytext[i]!='F' ; i++){
					}
					i++;
					j=0;
					while(yytext[i]!='\n'){
						tempS[j]=yytext[i];
						i++;
						j++;
					}
					tempS[j]='\0';
					labelNo = atoi(tempS);
					fprintf(fout,"CALL %d\n",fsearch(labelNo));
				}
				incLine();
			}

.*[\n] {	
			if(pass == 1){
					fstrcpy(ftemp, yytext);
				} else if(pass==2){
					fstrcpy(fout, yytext);
				}
				incLine();
		}



%%



/* Auxiliary functions */



void incLine(){
	if(currLine>=2056){
		currLine=currLine+2;
		return;
	} else {
		currLine++;
		return;
	}
}

void fstrcpy(FILE *fp, char* s){
	int i;
	char ch;
	for(i=0;i<strlen(s);i++){
      ch = s[i];
      putc(ch, fp);
   }
   
}

int main(int argc, char* argv[])
{	char c;
	if(argc > 2){
		ftemp =fopen("temp", "w");
		yyin = fopen(argv[1], "r");
	} else {
		printf("\nExpected filename for input and output\n ./a.out <inputfile> <outputfile>\n\n");
		return 0;
	}
	yylex();
	currLine=2048;
	pass=2;
	fclose(ftemp);
	fout = fopen(argv[2], "w");
	fin = fopen("temp", "r");
	yyin = fin;
	
	if (!yyin) {
		printf("Error opening include file: %s\n", yytext);
		return 1;
		}
	yylex();
	printf("success\n");
	return 1;
}
