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
    NODE_NUM = 258,                /* NODE_NUM  */
    NODE_PLUS = 259,               /* NODE_PLUS  */
    NODE_MINUS = 260,              /* NODE_MINUS  */
    NODE_MUL = 261,                /* NODE_MUL  */
    NODE_DIV = 262,                /* NODE_DIV  */
    NODE_OP = 263,                 /* NODE_OP  */
    NODE_STR = 264,                /* NODE_STR  */
    NODE_GRT = 265,                /* NODE_GRT  */
    NODE_LES = 266,                /* NODE_LES  */
    NODE_GEQ = 267,                /* NODE_GEQ  */
    NODE_LEQ = 268,                /* NODE_LEQ  */
    NODE_NEQUALS = 269,            /* NODE_NEQUALS  */
    NODE_EQUALS = 270,             /* NODE_EQUALS  */
    NODE_ID = 271,                 /* NODE_ID  */
    NODE_CONNECT = 272,            /* NODE_CONNECT  */
    NODE_BEGIN = 273,              /* NODE_BEGIN  */
    NODE_END = 274,                /* NODE_END  */
    NODE_BREAK = 275,              /* NODE_BREAK  */
    NODE_CONTINUE = 276,           /* NODE_CONTINUE  */
    NODE_RETURN = 277,             /* NODE_RETURN  */
    NODE_ENDTYPE = 278,            /* NODE_ENDTYPE  */
    NODE_VARDECL = 279,            /* NODE_VARDECL  */
    NODE_VARENDDECL = 280,         /* NODE_VARENDDECL  */
    NODE_TYPE_INT = 281,           /* NODE_TYPE_INT  */
    NODE_TYPE_STR = 282,           /* NODE_TYPE_STR  */
    NODE_TYPE_BOOL = 283,          /* NODE_TYPE_BOOL  */
    NODE_TYPE = 284,               /* NODE_TYPE  */
    NODE_ENDWHILE = 285,           /* NODE_ENDWHILE  */
    NODE_DO = 286,                 /* NODE_DO  */
    NODE_WHILE = 287,              /* NODE_WHILE  */
    NODE_IF = 288,                 /* NODE_IF  */
    NODE_THEN = 289,               /* NODE_THEN  */
    NODE_ELSE = 290,               /* NODE_ELSE  */
    NODE_ENDIF = 291,              /* NODE_ENDIF  */
    NODE_READ = 292,               /* NODE_READ  */
    NODE_WRITE = 293,              /* NODE_WRITE  */
    NODE_ALLOC = 294,              /* NODE_ALLOC  */
    NODE_FREE = 295,               /* NODE_FREE  */
    NODE_INIT = 296                /* NODE_INIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NODE_NUM 258
#define NODE_PLUS 259
#define NODE_MINUS 260
#define NODE_MUL 261
#define NODE_DIV 262
#define NODE_OP 263
#define NODE_STR 264
#define NODE_GRT 265
#define NODE_LES 266
#define NODE_GEQ 267
#define NODE_LEQ 268
#define NODE_NEQUALS 269
#define NODE_EQUALS 270
#define NODE_ID 271
#define NODE_CONNECT 272
#define NODE_BEGIN 273
#define NODE_END 274
#define NODE_BREAK 275
#define NODE_CONTINUE 276
#define NODE_RETURN 277
#define NODE_ENDTYPE 278
#define NODE_VARDECL 279
#define NODE_VARENDDECL 280
#define NODE_TYPE_INT 281
#define NODE_TYPE_STR 282
#define NODE_TYPE_BOOL 283
#define NODE_TYPE 284
#define NODE_ENDWHILE 285
#define NODE_DO 286
#define NODE_WHILE 287
#define NODE_IF 288
#define NODE_THEN 289
#define NODE_ELSE 290
#define NODE_ENDIF 291
#define NODE_READ 292
#define NODE_WRITE 293
#define NODE_ALLOC 294
#define NODE_FREE 295
#define NODE_INIT 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "exptree.y"

	struct tnode *node;
	int type_node;
	struct Gsymbol *var_node;
	struct PTable *param_node;

#line 156 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
