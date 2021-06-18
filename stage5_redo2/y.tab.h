/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    TEXT = 259,                    /* TEXT  */
    ID = 260,                      /* ID  */
    PLUS = 261,                    /* PLUS  */
    MINUS = 262,                   /* MINUS  */
    MUL = 263,                     /* MUL  */
    DIV = 264,                     /* DIV  */
    MOD = 265,                     /* MOD  */
    EQ = 266,                      /* EQ  */
    BEGIN1 = 267,                  /* BEGIN1  */
    END = 268,                     /* END  */
    READ = 269,                    /* READ  */
    WRITE = 270,                   /* WRITE  */
    POW = 271,                     /* POW  */
    IF = 272,                      /* IF  */
    ELSE = 273,                    /* ELSE  */
    THEN = 274,                    /* THEN  */
    ENDIF = 275,                   /* ENDIF  */
    WHILE = 276,                   /* WHILE  */
    DO = 277,                      /* DO  */
    ENDWHILE = 278,                /* ENDWHILE  */
    EQEQ = 279,                    /* EQEQ  */
    NOTEQ = 280,                   /* NOTEQ  */
    GREAT = 281,                   /* GREAT  */
    GREATEQ = 282,                 /* GREATEQ  */
    LESS = 283,                    /* LESS  */
    LESSEQ = 284,                  /* LESSEQ  */
    BREAK = 285,                   /* BREAK  */
    CONTINUE = 286,                /* CONTINUE  */
    INT = 287,                     /* INT  */
    STR = 288,                     /* STR  */
    IDec = 289,                    /* IDec  */
    Varlist = 290,                 /* Varlist  */
    LDECL = 291,                   /* LDECL  */
    LENDDECL = 292,                /* LENDDECL  */
    GIDec = 293,                   /* GIDec  */
    MAIN = 294,                    /* MAIN  */
    RET = 295,                     /* RET  */
    PID = 296,                     /* PID  */
    LIDec = 297,                   /* LIDec  */
    IdList = 298,                  /* IdList  */
    GDeclBlock = 299,              /* GDeclBlock  */
    FID = 300,                     /* FID  */
    GDECL = 301,                   /* GDECL  */
    GENDDECL = 302                 /* GENDDECL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define TEXT 259
#define ID 260
#define PLUS 261
#define MINUS 262
#define MUL 263
#define DIV 264
#define MOD 265
#define EQ 266
#define BEGIN1 267
#define END 268
#define READ 269
#define WRITE 270
#define POW 271
#define IF 272
#define ELSE 273
#define THEN 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define EQEQ 279
#define NOTEQ 280
#define GREAT 281
#define GREATEQ 282
#define LESS 283
#define LESSEQ 284
#define BREAK 285
#define CONTINUE 286
#define INT 287
#define STR 288
#define IDec 289
#define Varlist 290
#define LDECL 291
#define LENDDECL 292
#define GIDec 293
#define MAIN 294
#define RET 295
#define PID 296
#define LIDec 297
#define IdList 298
#define GDeclBlock 299
#define FID 300
#define GDECL 301
#define GENDDECL 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "5_1.y"

	struct tnode *no;
	struct Paramstruct *pr;
	struct Gsymbol *gs;
	struct Lsymbol *ls;

#line 168 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
