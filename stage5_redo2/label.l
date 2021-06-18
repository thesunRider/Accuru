%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "label.h"
	#include "label.c"
	int instructionCount = 1, i, j;
    struct tnode *t = NULL;
	int parse = 1, addr, flag;
	FILE *fptr;
	FILE *fptr2;
%}

letter [A-Z|a-z]
digit [0-9]
jmp "JMP "
jnz "JNZ "
jz "JZ "
gt "GT "
lt "LT "
eq "EQ "
ge "GE "
le "LE "
ne "NE "
mov "MOV "
call "CALL "
add "ADD "
sub "SUB "
mul "MUL "
div "DIV "
mod "MOD "
push "PUSH "
pop "POP "
brkp "BRKP"
ret "RET"
main "MAIN"
string ["][a-z|A-Z|0-9| ]+["]
quote ["] 
openbrac "["
closebrac "]"
comma ","
space [ ]
hyphen "-"
%%

({digit})+[\n] 	{
					if(parse == 1)
					{
						printf("Number\n");
					}
					else
					{
						printf("Turn 2 Number\n");
						fprintf(fptr2, "%s", yytext);
					}	
				}
{brkp}[\n] 	{
				if(parse == 1)
				{
					printf("BrkpStmt\n");
					instructionCount++;
				}
				else
				{
					printf("Turn 2 Brkp\n");
					fprintf(fptr2, "%s", yytext);
				}
			}
{ret}[\n] 	{
				if(parse == 1)
				{
					printf("RetStmt\n");
					instructionCount++;
				}
				else
				{
					printf("Turn 2 Ret\n");
					fprintf(fptr2, "%s", yytext);
				}
			}			
({mov}|{add}|{gt}|{lt}|{eq}|{ge}|{le}|{ne}|{sub}|{mul}|{div}|{mod})({letter}|{digit}|{openbrac}|{closebrac})+{comma}{space}({letter}|{digit}|{string}|{openbrac}|{closebrac}|{hyphen}|{quote})+[\n] 	{
																																							if(parse == 1)
																																							{
																																								printf("MovTypeStmt\n");
																																								instructionCount++;
																																							}
																																							else
																																							{
																																								printf("Turn 2 MovTypeStmt\n");
																																								fprintf(fptr2, "%s", yytext);
																																							}
																																						}
({jnz}|{jz})({letter}|{digit}|{openbrac}|{closebrac})+{comma}{space}({letter}|{digit}|{openbrac}|{closebrac}|{hyphen}|{quote})+[\n] {
																																		if(parse == 1)
																																		{
																																			printf("JmpCallTypeStmt\n");
																																			instructionCount++;
																																		}
																																		else
																																		{
																																			flag = 0;
																																			char *temp = (char *)malloc(sizeof(100));
																																			for(i = 0; yytext[i]!='L' && yytext[i]!='\0'; i++)
																																			{
																																				temp[i] = yytext[i];
																																			}
																																			temp[i] = '\0';
																																			if(yytext[i]!='\0')
																																			{
																																				flag = 1;
																																				char *label = (char *)malloc(sizeof(10));
																																				j = 0;
																																				for(; yytext[i]!='\n'; i++)
																																				{
																																					label[j++] = yytext[i];
																																				}
																																				label[j] = '\0';
																																				addr = getAddress(&t, label);
																																				char *temp2 = (char *)malloc(sizeof(10));
																																				sprintf(temp2, "%d", addr);
																																				strcat(temp, temp2);
																																			}
																																			printf("Turn 2 JnzTypeStmt\n");
																																			if(flag == 0)
																																				fprintf(fptr2, "%s", temp);
																																			else
																																				fprintf(fptr2, "%s\n", temp);		
																																		}
																																	}
({push}|{pop})({letter}|{digit})+[\n] 	{
											if(parse == 1)
											{
												printf("PushTypeStmt\n");
												instructionCount++;
											}
											else
											{
												printf("Turn 2 PushTypeStmt\n");
												fprintf(fptr2, "%s", yytext);
											}
										}
({jmp}|{call})({letter}|{digit})+[\n] 	{
											if(parse == 1)
											{
												printf("JmpCallTypeStmt\n");
												instructionCount++;
											}
											else
											{
												flag = 0;
												char *temp = (char *)malloc(sizeof(100));
												printf("Yo1\n");
												for(i = 0; ((yytext[i]!='L' && yytext[i]!='F' && yytext[i]!='M') || yytext[i-1]!=' ') && yytext[i]!='\0'; i++)
												{
													temp[i] = yytext[i];
												}
												temp[i] = '\0';
												printf("Yo2\n");
												if(yytext[i]!='\0')
												{
													flag = 1;
													char *label = (char *)malloc(sizeof(10));
													j = 0;
													printf("Yo3\n");
													for(; yytext[i]!='\n'; i++)
													{
														label[j++] = yytext[i];
													}
													label[j] = '\0';
													printf("Yo4\n");
													addr = getAddress(&t, label);
													printf("Yo5\n");
													char *temp2 = (char *)malloc(sizeof(10));
													sprintf(temp2, "%d", addr);
													printf("Yo6\n");
													strcat(temp, temp2);
												}
												printf("Turn 2 JmpCallTypeStmt\n");	
												if(flag == 0)
													fprintf(fptr2, "%s", temp);
												else
													fprintf(fptr2, "%s\n", temp);	
											}
										}

[L|F][0-9]+":"[\n]	{
						if(parse == 1)
						{
							char *temp = (char *)malloc(10);
							for(i = 0; yytext[i]!=':'; i++)
							{
								temp[i] = yytext[i];
							}
							temp[i] = '\0';
							//printf("%s", temp);
							insertNode(&t, temp, (2056 + 2*(instructionCount-1)));
						}
						else
						{
							printf("Turn 2 Chumma\n");
						}
					}

{main}":"[\n]	{
						if(parse == 1)
						{
							char *temp = (char *)malloc(10);
							for(i = 0; yytext[i]!=':'; i++)
							{
								temp[i] = yytext[i];
							}
							temp[i] = '\0';
							//printf("%s", temp);
							insertNode(&t, temp, (2056 + 2*(instructionCount-1)));
						}
						else
						{
							printf("Turn 2 Chumma\n");
						}
				}					

%%

int yywrap()
{
	if(parse == 1)
	{
		parse = 2;
		if(fptr)
		{
			fseek(fptr, 0, SEEK_SET);
		}
		yyin = fptr;
		fptr2 = fopen("codef.xsm", "w");
		return 0;
	}
	else
    	return 1;
}

int main()
{
	//printf("Jellp\n");
	fptr = fopen("target.xsm", "r");
	fptr2 = fopen("codef.xsm", "w");
	yyin = fptr;
	yylex();
	printLabel(&t);
	fclose(fptr2);
	fclose(fptr);
	return 1;
}
