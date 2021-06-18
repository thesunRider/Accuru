/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "exptree.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h> 
	int yylex(void);
	int yyerror(char const *s);
	FILE *code;
	int register_index;
	int firstreg;

	//externs for lex go here
	int inside_function = 0; //0 false 1 true
	int inside_declaration = 0; 
	int inside_type = 0; 


	///counts
	int current_stack_base = 0; //this points out to the base of memory
	int param_count = 0;
	int local_count = 0;

	struct Gsymbol *localsymbolTable = NULL;
	struct Gsymbol *globalsymbolTable = NULL;
	struct PTable *paramTable = NULL;
	struct Fsymbol *funcTable = NULL;
	struct tnode *current_function = NULL; //this is an array storing which function is being parsed now


	#include "exptree.h"
	#include "exptree.c"


#line 104 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    NODE_VARDECL = 278,            /* NODE_VARDECL  */
    NODE_VARENDDECL = 279,         /* NODE_VARENDDECL  */
    NODE_TYPE_INT = 280,           /* NODE_TYPE_INT  */
    NODE_TYPE_STR = 281,           /* NODE_TYPE_STR  */
    NODE_TYPE_BOOL = 282,          /* NODE_TYPE_BOOL  */
    NODE_TYPE = 283,               /* NODE_TYPE  */
    NODE_ENDWHILE = 284,           /* NODE_ENDWHILE  */
    NODE_DO = 285,                 /* NODE_DO  */
    NODE_WHILE = 286,              /* NODE_WHILE  */
    NODE_IF = 287,                 /* NODE_IF  */
    NODE_THEN = 288,               /* NODE_THEN  */
    NODE_ELSE = 289,               /* NODE_ELSE  */
    NODE_ENDIF = 290,              /* NODE_ENDIF  */
    NODE_READ = 291,               /* NODE_READ  */
    NODE_WRITE = 292               /* NODE_WRITE  */
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
#define NODE_VARDECL 278
#define NODE_VARENDDECL 279
#define NODE_TYPE_INT 280
#define NODE_TYPE_STR 281
#define NODE_TYPE_BOOL 282
#define NODE_TYPE 283
#define NODE_ENDWHILE 284
#define NODE_DO 285
#define NODE_WHILE 286
#define NODE_IF 287
#define NODE_THEN 288
#define NODE_ELSE 289
#define NODE_ENDIF 290
#define NODE_READ 291
#define NODE_WRITE 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 36 "exptree.y"

	struct tnode *node;
	int type_node;
	struct Gsymbol *var_node;
	struct PTable *param_node;

#line 238 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NODE_NUM = 3,                   /* NODE_NUM  */
  YYSYMBOL_NODE_PLUS = 4,                  /* NODE_PLUS  */
  YYSYMBOL_NODE_MINUS = 5,                 /* NODE_MINUS  */
  YYSYMBOL_NODE_MUL = 6,                   /* NODE_MUL  */
  YYSYMBOL_NODE_DIV = 7,                   /* NODE_DIV  */
  YYSYMBOL_NODE_OP = 8,                    /* NODE_OP  */
  YYSYMBOL_NODE_STR = 9,                   /* NODE_STR  */
  YYSYMBOL_NODE_GRT = 10,                  /* NODE_GRT  */
  YYSYMBOL_NODE_LES = 11,                  /* NODE_LES  */
  YYSYMBOL_NODE_GEQ = 12,                  /* NODE_GEQ  */
  YYSYMBOL_NODE_LEQ = 13,                  /* NODE_LEQ  */
  YYSYMBOL_NODE_NEQUALS = 14,              /* NODE_NEQUALS  */
  YYSYMBOL_NODE_EQUALS = 15,               /* NODE_EQUALS  */
  YYSYMBOL_NODE_ID = 16,                   /* NODE_ID  */
  YYSYMBOL_NODE_CONNECT = 17,              /* NODE_CONNECT  */
  YYSYMBOL_NODE_BEGIN = 18,                /* NODE_BEGIN  */
  YYSYMBOL_NODE_END = 19,                  /* NODE_END  */
  YYSYMBOL_NODE_BREAK = 20,                /* NODE_BREAK  */
  YYSYMBOL_NODE_CONTINUE = 21,             /* NODE_CONTINUE  */
  YYSYMBOL_NODE_RETURN = 22,               /* NODE_RETURN  */
  YYSYMBOL_NODE_VARDECL = 23,              /* NODE_VARDECL  */
  YYSYMBOL_NODE_VARENDDECL = 24,           /* NODE_VARENDDECL  */
  YYSYMBOL_NODE_TYPE_INT = 25,             /* NODE_TYPE_INT  */
  YYSYMBOL_NODE_TYPE_STR = 26,             /* NODE_TYPE_STR  */
  YYSYMBOL_NODE_TYPE_BOOL = 27,            /* NODE_TYPE_BOOL  */
  YYSYMBOL_NODE_TYPE = 28,                 /* NODE_TYPE  */
  YYSYMBOL_NODE_ENDWHILE = 29,             /* NODE_ENDWHILE  */
  YYSYMBOL_NODE_DO = 30,                   /* NODE_DO  */
  YYSYMBOL_NODE_WHILE = 31,                /* NODE_WHILE  */
  YYSYMBOL_NODE_IF = 32,                   /* NODE_IF  */
  YYSYMBOL_NODE_THEN = 33,                 /* NODE_THEN  */
  YYSYMBOL_NODE_ELSE = 34,                 /* NODE_ELSE  */
  YYSYMBOL_NODE_ENDIF = 35,                /* NODE_ENDIF  */
  YYSYMBOL_NODE_READ = 36,                 /* NODE_READ  */
  YYSYMBOL_NODE_WRITE = 37,                /* NODE_WRITE  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '{'  */
  YYSYMBOL_41_ = 41,                       /* '}'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_Program = 48,                   /* Program  */
  YYSYMBOL_FunctionList = 49,              /* FunctionList  */
  YYSYMBOL_FunctionBlock = 50,             /* FunctionBlock  */
  YYSYMBOL_FunctionTypeList = 51,          /* FunctionTypeList  */
  YYSYMBOL_FunctionType = 52,              /* FunctionType  */
  YYSYMBOL_Paramlist = 53,                 /* Paramlist  */
  YYSYMBOL_Declarations = 54,              /* Declarations  */
  YYSYMBOL_DeclList = 55,                  /* DeclList  */
  YYSYMBOL_Decl = 56,                      /* Decl  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_VarList = 58,                   /* VarList  */
  YYSYMBOL_Slist = 59,                     /* Slist  */
  YYSYMBOL_Stmt = 60,                      /* Stmt  */
  YYSYMBOL_RetStmnt = 61,                  /* RetStmnt  */
  YYSYMBOL_CntStmnt = 62,                  /* CntStmnt  */
  YYSYMBOL_BrkStmnt = 63,                  /* BrkStmnt  */
  YYSYMBOL_InputStmt = 64,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 65,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 66,                   /* AsgStmt  */
  YYSYMBOL_FuncallStmt = 67,               /* FuncallStmt  */
  YYSYMBOL_arglist = 68,                   /* arglist  */
  YYSYMBOL_expr = 69                       /* expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   329

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      38,    39,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    89,    92,    93,    97,   110,   118,   119,
     122,   130,   137,   146,   155,   175,   196,   197,   198,   201,
     202,   205,   220,   221,   225,   246,   267,   287,   310,   311,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     326,   327,   328,   331,   332,   335,   338,   341,   350,   361,
     370,   383,   398,   415,   418,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   443,   457,   458
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NODE_NUM",
  "NODE_PLUS", "NODE_MINUS", "NODE_MUL", "NODE_DIV", "NODE_OP", "NODE_STR",
  "NODE_GRT", "NODE_LES", "NODE_GEQ", "NODE_LEQ", "NODE_NEQUALS",
  "NODE_EQUALS", "NODE_ID", "NODE_CONNECT", "NODE_BEGIN", "NODE_END",
  "NODE_BREAK", "NODE_CONTINUE", "NODE_RETURN", "NODE_VARDECL",
  "NODE_VARENDDECL", "NODE_TYPE_INT", "NODE_TYPE_STR", "NODE_TYPE_BOOL",
  "NODE_TYPE", "NODE_ENDWHILE", "NODE_DO", "NODE_WHILE", "NODE_IF",
  "NODE_THEN", "NODE_ELSE", "NODE_ENDIF", "NODE_READ", "NODE_WRITE", "'('",
  "')'", "'{'", "'}'", "','", "';'", "'['", "']'", "'='", "$accept",
  "Program", "FunctionList", "FunctionBlock", "FunctionTypeList",
  "FunctionType", "Paramlist", "Declarations", "DeclList", "Decl", "Type",
  "VarList", "Slist", "Stmt", "RetStmnt", "CntStmnt", "BrkStmnt",
  "InputStmt", "OutputStmt", "AsgStmt", "FuncallStmt", "arglist", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,    40,    41,
     123,   125,    44,    59,    91,    93,    61
};
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,    66,     6,    10,    14,   -87,   -87,   135,    34,     9,
     -87,    53,   -87,    60,   162,    72,    79,   110,   -87,   104,
     124,   -87,    57,   -87,   175,   -87,   153,    72,   189,   131,
     -87,   -14,   201,   190,   -87,   -87,   169,   -87,   172,   195,
     -18,   133,   173,   -16,   178,   179,     4,   202,   -87,   222,
     186,     5,   -13,   -87,   191,   131,   -87,   187,   -19,   198,
     196,    88,   -87,   228,   -87,   268,   -19,   -87,   203,   -87,
       7,   204,   205,    11,   207,   211,   212,   213,   192,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   268,   -87,    86,
     251,    77,   -87,   -87,   -87,   -87,    18,   120,   -87,   217,
      54,   120,   120,   120,   120,   -87,   -87,   199,   225,   218,
      89,   302,   226,   -87,    94,   267,   128,   -87,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   -87,   140,
     158,   170,   188,   -87,   -87,   230,   120,   239,   -87,   231,
     -87,   183,   183,   -87,   -87,   314,   314,   314,   314,   314,
     314,   256,   254,   248,   249,   -87,   302,    77,   -87,   268,
     268,   -87,   -87,   -87,   106,   243,   221,   -87,   250,   268,
     252,   -87,   246,   -87,   253,   -87
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       1,     0,    18,     0,     0,     9,     0,     0,    20,    25,
      21,     3,     0,     5,     0,    17,     0,     8,     0,     0,
      19,    25,     0,     0,     2,     4,     0,    16,     0,     0,
       0,     0,    24,     0,     0,     0,     0,     0,    27,     0,
       0,     0,     0,    11,     0,     0,    15,     0,     0,     0,
       0,     0,    13,     0,    26,     0,     0,    10,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      36,    33,    34,    30,    31,    32,    35,     0,    12,     0,
       0,     0,    44,    43,    68,    69,    67,     0,    42,     0,
       0,     0,     0,     0,     0,     7,    28,     0,    67,     0,
       0,    54,     0,    49,     0,     0,     0,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     6,    52,     0,     0,     0,    47,     0,
      65,    61,    62,    63,    64,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,    51,    53,     0,    66,     0,
       0,    45,    46,    50,     0,     0,     0,    48,     0,     0,
       0,    37,     0,    39,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   -87,   272,   -87,   283,   -21,    15,   -87,   291,
      41,   -87,   -85,   -78,   -87,   -87,   -87,   -87,   -87,   -87,
     -72,   -87,   -86
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    22,    23,    14,    15,    46,     3,     7,     8,
      47,    20,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   110,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,    99,   107,   111,     1,   114,    10,     5,     6,     5,
       6,   116,     5,     6,    94,   129,   130,   131,   132,   113,
      95,    45,    51,    50,    40,    19,    60,    96,    11,   106,
      32,    61,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,     9,    54,    59,    89,    55,    55,    17,    97,
     156,    90,    24,    91,    98,    28,    89,    12,   118,   119,
     120,   121,   115,    24,   122,   123,   124,   125,   126,   127,
      39,   164,    21,    65,   165,   166,    34,    18,     5,     6,
      94,    87,     5,     6,   172,   163,    95,   106,   106,    94,
       4,     5,     6,    96,   106,    95,    63,   128,   118,   119,
     120,   121,   108,    25,   122,   123,   124,   125,   126,   127,
     118,   119,   120,   121,    29,    97,   122,   123,   124,   125,
     126,   127,    30,    94,    97,   109,    31,    68,   135,    95,
      55,   136,   118,   119,   120,   121,   108,   138,   122,   123,
     124,   125,   126,   127,   118,   119,   120,   121,    32,   167,
     122,   123,   124,   125,   126,   127,     5,     6,    97,    13,
       5,     6,   118,   119,   120,   121,    33,   140,   122,   123,
     124,   125,   126,   127,   118,   119,   120,   121,    48,   151,
     122,   123,   124,   125,   126,   127,    26,     5,     6,   120,
     121,    36,   118,   119,   120,   121,    37,   152,   122,   123,
     124,   125,   126,   127,    41,    38,    42,    43,    70,   153,
      40,    44,    71,    72,    73,    70,    52,    49,    56,    71,
      72,    73,    53,    74,    75,    57,    58,   154,    76,    77,
      74,    75,    64,   105,    62,    76,    77,    70,    66,    67,
     133,    71,    72,    73,    69,   101,    88,    92,    93,   102,
     103,   104,    74,    75,   112,   169,   170,    76,    77,    70,
     117,   134,    70,    71,    72,    73,    71,    72,    73,   115,
     139,   137,   168,   155,    74,    75,   158,    74,    75,    76,
      77,   174,    76,    77,    70,   157,   159,   160,    71,    72,
      73,   161,   162,   171,    35,   173,   175,    27,    16,    74,
      75,     0,     0,     0,    76,    77,   118,   119,   120,   121,
       0,     0,   122,   123,   124,   125,   126,   127,   118,   119,
     120,   121,     0,     0,    -1,    -1,    -1,    -1,    -1,    -1
};

static const yytype_int16 yycheck[] =
{
      78,    73,    87,    89,    23,    91,     0,    25,    26,    25,
      26,    97,    25,    26,     3,   101,   102,   103,   104,    91,
       9,    39,    43,    39,    38,    16,    39,    16,    18,   107,
      44,    52,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     1,    39,    39,    38,    42,    42,     7,    38,
     136,    44,    11,    46,    43,    14,    38,    43,     4,     5,
       6,     7,    44,    22,    10,    11,    12,    13,    14,    15,
      29,   157,    19,    58,   159,   160,    19,    43,    25,    26,
       3,    66,    25,    26,   169,   157,     9,   165,   166,     3,
      24,    25,    26,    16,   172,     9,    55,    43,     4,     5,
       6,     7,    16,    43,    10,    11,    12,    13,    14,    15,
       4,     5,     6,     7,    42,    38,    10,    11,    12,    13,
      14,    15,    43,     3,    38,    39,    16,    39,    39,     9,
      42,    42,     4,     5,     6,     7,    16,    43,    10,    11,
      12,    13,    14,    15,     4,     5,     6,     7,    44,    43,
      10,    11,    12,    13,    14,    15,    25,    26,    38,    24,
      25,    26,     4,     5,     6,     7,    42,    39,    10,    11,
      12,    13,    14,    15,     4,     5,     6,     7,    45,    39,
      10,    11,    12,    13,    14,    15,    24,    25,    26,     6,
       7,    16,     4,     5,     6,     7,    43,    39,    10,    11,
      12,    13,    14,    15,     3,    16,    16,    38,    16,    39,
      38,    16,    20,    21,    22,    16,    38,    44,    16,    20,
      21,    22,    43,    31,    32,     3,    40,    39,    36,    37,
      31,    32,    45,    41,    43,    36,    37,    16,    40,    43,
      41,    20,    21,    22,    16,    38,    43,    43,    43,    38,
      38,    38,    31,    32,     3,    34,    35,    36,    37,    16,
      43,    43,    16,    20,    21,    22,    20,    21,    22,    44,
       3,    45,    29,    43,    31,    32,    45,    31,    32,    36,
      37,    35,    36,    37,    16,    46,    30,    33,    20,    21,
      22,    43,    43,    43,    22,    43,    43,    14,     7,    31,
      32,    -1,    -1,    -1,    36,    37,     4,     5,     6,     7,
      -1,    -1,    10,    11,    12,    13,    14,    15,     4,     5,
       6,     7,    -1,    -1,    10,    11,    12,    13,    14,    15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    48,    54,    24,    25,    26,    55,    56,    57,
       0,    18,    43,    24,    51,    52,    56,    57,    43,    16,
      58,    19,    49,    50,    57,    43,    24,    52,    57,    42,
      43,    16,    44,    42,    19,    50,    16,    43,    16,    57,
      38,     3,    16,    38,    16,    39,    53,    57,    45,    44,
      39,    53,    38,    43,    39,    42,    16,     3,    40,    39,
      39,    53,    43,    57,    45,    54,    40,    43,    39,    16,
      16,    20,    21,    22,    31,    32,    36,    37,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    54,    43,    38,
      44,    46,    43,    43,     3,     9,    16,    38,    43,    67,
      69,    38,    38,    38,    38,    41,    60,    59,    16,    39,
      68,    69,     3,    67,    69,    44,    69,    43,     4,     5,
       6,     7,    10,    11,    12,    13,    14,    15,    43,    69,
      69,    69,    69,    41,    43,    39,    42,    45,    43,     3,
      39,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    39,    39,    39,    39,    43,    69,    46,    45,    30,
      33,    43,    43,    67,    69,    59,    59,    43,    29,    34,
      35,    43,    59,    43,    35,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    53,    53,    54,    54,    54,    55,
      55,    56,    57,    57,    58,    58,    58,    58,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    62,    63,    64,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     9,     8,     2,     1,
       7,     5,     8,     6,     4,     2,     5,     4,     3,     3,
       2,     2,     1,     1,     3,     1,     6,     4,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     8,    10,     8,
       3,     3,     2,     2,     2,     5,     5,     4,     7,     3,
       6,     5,     4,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Declarations NODE_BEGIN FunctionList NODE_END  */
#line 74 "exptree.y"
                                                        {
				printf("\n------------GLobal SymbolTable--------------");
				printSymbolTable(&globalsymbolTable);
				pushglobals(code); //push global variables to code
				(yyval.node) = (yyvsp[-1].node);

				struct tnode *temp = NULL;
				temp = (yyvsp[-1].node);

				printf("\n yacc>> ");
				//exit(1);
				evaluate((yyvsp[-1].node),code);
				//printf($2);
				exit(1);}
#line 1704 "y.tab.c"
    break;

  case 3: /* Program: Declarations NODE_BEGIN NODE_END  */
#line 89 "exptree.y"
                                                   {(yyval.node) = NULL;}
#line 1710 "y.tab.c"
    break;

  case 4: /* FunctionList: FunctionList FunctionBlock  */
#line 92 "exptree.y"
                                             {(yyval.node) = appendTree((yyvsp[-1].node),createTree(0,0,FUNCTION_LIST,NULL,NULL,(yyvsp[0].node)));}
#line 1716 "y.tab.c"
    break;

  case 5: /* FunctionList: FunctionBlock  */
#line 93 "exptree.y"
                                                {(yyval.node) = createTree(0,0,FUNCTION_LIST,NULL,NULL,(yyvsp[0].node));}
#line 1722 "y.tab.c"
    break;

  case 6: /* FunctionBlock: Type NODE_ID '(' Paramlist ')' '{' Declarations Slist '}'  */
#line 97 "exptree.y"
                                                                         {
								printf("\nyacc>>function block with paramlist\n");
								struct PTable *temp = NULL;
								temp = (yyvsp[-2].param_node);

								struct tnode *temp2 = NULL;
								temp2 = (yyvsp[-7].node);

								InstallLocals((yyvsp[-2].param_node),(yyvsp[-7].node)->varname);
								(yyval.node) = createTree(0 ,0,FUNCTION_CONNECT ,(yyvsp[-7].node)->varname, NULL, (yyvsp[-1].node));
				
				}
#line 1739 "y.tab.c"
    break;

  case 7: /* FunctionBlock: Type NODE_ID '(' ')' '{' Declarations Slist '}'  */
#line 110 "exptree.y"
                                                                                {
								printf("\nyacc>>function block without paramlist\n");
								InstallLocals((yyvsp[-2].param_node),(yyvsp[-6].node)->varname);
								(yyval.node) = createTree(0 ,0,FUNCTION_CONNECT ,(yyvsp[-6].node)->varname, NULL, (yyvsp[-1].node));
				}
#line 1749 "y.tab.c"
    break;

  case 10: /* FunctionType: FunctionType ',' Type NODE_ID '(' ')' ';'  */
#line 122 "exptree.y"
                                                             { 
												param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc((yyvsp[-4].type_node),(yyvsp[-3].node)->varname,NULL);
											}
										}
#line 1760 "y.tab.c"
    break;

  case 11: /* FunctionType: Type NODE_ID '(' ')' ';'  */
#line 130 "exptree.y"
                                                              {
											param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc((yyvsp[-4].type_node),(yyvsp[-3].node)->varname,NULL);
											}
										}
#line 1771 "y.tab.c"
    break;

  case 12: /* FunctionType: FunctionType ',' Type NODE_ID '(' Paramlist ')' ';'  */
#line 137 "exptree.y"
                                                                                      {

											param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc((yyvsp[-5].type_node),(yyvsp[-4].node)->varname,(yyvsp[-2].param_node));
											}
										}
#line 1783 "y.tab.c"
    break;

  case 13: /* FunctionType: Type NODE_ID '(' Paramlist ')' ';'  */
#line 146 "exptree.y"
                                                                       {

											param_count = 0;
											if (inside_declaration == 1&&inside_function == 0){
												InstallFunc((yyvsp[-5].type_node),(yyvsp[-4].node)->varname,(yyvsp[-2].param_node));
											}
										}
#line 1795 "y.tab.c"
    break;

  case 14: /* Paramlist: Paramlist ',' Type NODE_ID  */
#line 156 "exptree.y"
                                                        { 
								struct Gsymbol *temp = NULL;
								temp = Lookup((yyvsp[0].node)->varname);
								if (inside_function){
									if (temp==NULL){
										printf("\n Those variables arent declared");
									}
								}

								if (inside_declaration == 1){
									++param_count;
									Install((yyvsp[0].node)->varname,(yyvsp[-1].type_node),1);
									Lookup((yyvsp[0].node)->varname)->env_type = 2;
									(yyval.param_node) = InstallParam((yyvsp[-3].param_node),(yyvsp[0].node)->varname,(yyvsp[-1].type_node),param_count);
								}else{
									(yyval.param_node) = NULL; //when not declaring we pass param list empty
								}
							}
#line 1818 "y.tab.c"
    break;

  case 15: /* Paramlist: Type NODE_ID  */
#line 175 "exptree.y"
                                       {	struct Gsymbol *temp = NULL;
								temp = Lookup((yyvsp[0].node)->varname);
								if (inside_function){
									if (temp==NULL){
										printf("\n Those variables arent declared");
									}
								}
								if (inside_declaration == 1){
									//globally declaring the function
									++param_count;
									Install((yyvsp[0].node)->varname,(yyvsp[-1].type_node),1);
									Lookup((yyvsp[0].node)->varname)->env_type = 2;
									(yyval.param_node) = createParam((yyvsp[0].node)->varname,(yyvsp[-1].type_node),param_count);	
								}
								else
								{
									(yyval.param_node) = NULL;
								}
							}
#line 1842 "y.tab.c"
    break;

  case 16: /* Declarations: NODE_VARDECL DeclList FunctionTypeList NODE_VARENDDECL ';'  */
#line 196 "exptree.y"
                                                                            {(yyval.param_node) = (yyvsp[-3].param_node);}
#line 1848 "y.tab.c"
    break;

  case 17: /* Declarations: NODE_VARDECL DeclList NODE_VARENDDECL ';'  */
#line 197 "exptree.y"
                                                                           {(yyval.param_node) = (yyvsp[-2].param_node);}
#line 1854 "y.tab.c"
    break;

  case 18: /* Declarations: NODE_VARDECL NODE_VARENDDECL ';'  */
#line 198 "exptree.y"
                                                                  {(yyval.param_node) = NULL;}
#line 1860 "y.tab.c"
    break;

  case 19: /* DeclList: DeclList Decl ';'  */
#line 201 "exptree.y"
                                   {(yyval.param_node) = InstallDeclType((yyvsp[-2].param_node),(yyvsp[-1].param_node));}
#line 1866 "y.tab.c"
    break;

  case 20: /* DeclList: Decl ';'  */
#line 202 "exptree.y"
                                        {(yyval.param_node) = (yyvsp[-1].param_node);}
#line 1872 "y.tab.c"
    break;

  case 21: /* Decl: Type VarList  */
#line 205 "exptree.y"
                       {
							if (inside_declaration == 1 && inside_function == 0)
							{
								//declared in global section
								assignType(&globalsymbolTable, (yyvsp[-1].type_node));
								assignType(&(yyvsp[0].var_node), (yyvsp[-1].type_node));
							}else if (inside_declaration == 1 && inside_function == 1){
								//declared inside a function
								assignType(&(yyvsp[0].var_node), (yyvsp[-1].type_node));
							}
							(yyval.param_node) = createDeclType((yyvsp[-1].type_node),(yyvsp[0].var_node));
						}
#line 1889 "y.tab.c"
    break;

  case 22: /* Type: NODE_TYPE_INT  */
#line 220 "exptree.y"
                     {(yyval.type_node) = INT_TYPE;}
#line 1895 "y.tab.c"
    break;

  case 23: /* Type: NODE_TYPE_STR  */
#line 221 "exptree.y"
                         {(yyval.type_node) = STR_TYPE;}
#line 1901 "y.tab.c"
    break;

  case 24: /* VarList: VarList ',' NODE_ID  */
#line 225 "exptree.y"
                            {	struct Gsymbol *temp = NULL;
								temp = Lookup((yyvsp[0].node)->varname);
								if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
								{
									Install((yyvsp[0].node)->varname, 0, 1);
									(yyval.var_node) = Lookup((yyvsp[0].node)->varname);
								}
								else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
								{ //all those declared inside functions goes to local table
									++local_count;
									(yyval.var_node) = appendlocalTable((yyvsp[-2].var_node),createlocal((yyvsp[0].node)->varname, 0, 1,local_count));
								}
								else
								{
									if (inside_function != 1 && inside_declaration != 0) {
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
							}
#line 1926 "y.tab.c"
    break;

  case 25: /* VarList: NODE_ID  */
#line 246 "exptree.y"
                                {	struct Gsymbol *temp = NULL;
						temp = Lookup( (yyvsp[0].node)->varname);
						if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
						{
							Install( (yyvsp[0].node)->varname, 0, 1);
							(yyval.var_node) = Lookup( (yyvsp[0].node)->varname);
						}
						else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
								{
									++local_count;
									(yyval.var_node) = createlocal((yyvsp[0].node)->varname, 0,1,local_count);
								}
						else
						{
							if (inside_function != 1 && inside_declaration != 0) {
										printf("Error. Variable declared twice.\n");
										exit(1);
									};
						};
					}
#line 1951 "y.tab.c"
    break;

  case 26: /* VarList: VarList ',' NODE_ID '[' NODE_NUM ']'  */
#line 267 "exptree.y"
                                                  { struct Gsymbol *temp = NULL;
									temp = Lookup((yyvsp[-3].node)->varname);
									if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
									{
										Install((yyvsp[-3].node)->varname, 0, (yyvsp[-1].node)->val);
										(yyval.var_node) = Lookup((yyvsp[-3].node)->varname);
									}
									else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
									{
										++local_count;
										(yyval.var_node) = appendlocalTable((yyvsp[-5].var_node),createlocal((yyvsp[-3].node)->varname, 0,1,local_count));
									}
									else
									{
										if (inside_function != 1 && inside_declaration != 0) {
											printf("Error. Variable declared twice.\n");
											exit(1);
										}
									}
								}
#line 1976 "y.tab.c"
    break;

  case 27: /* VarList: NODE_ID '[' NODE_NUM ']'  */
#line 287 "exptree.y"
                                                        {
									struct Gsymbol *temp = NULL;
									temp = Lookup((yyvsp[-3].node)->varname);
									if(temp == NULL &&  inside_declaration == 1 && inside_function == 0)
									{	Install( (yyvsp[-3].node)->varname, 0, (yyvsp[-1].node)->val);
										(yyval.var_node) = Lookup((yyvsp[-3].node)->varname);
							
									}
									else if (temp == NULL && inside_function == 1 &&inside_declaration == 1)
									{
										
										(yyval.var_node) = createlocal((yyvsp[-3].node)->varname, 0,1,local_count);
									}
									else
									{
										if (inside_function != 1 && inside_declaration != 0) {
											printf("Error. Variable declared twice.\n");
											exit(1);
										}
									}
								}
#line 2002 "y.tab.c"
    break;

  case 28: /* Slist: Slist Stmt  */
#line 310 "exptree.y"
                   {(yyval.node) = createTree(0 ,0,CONNECT ,NULL, (yyvsp[-1].node), (yyvsp[0].node));}
#line 2008 "y.tab.c"
    break;

  case 29: /* Slist: Stmt  */
#line 311 "exptree.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2014 "y.tab.c"
    break;

  case 30: /* Stmt: InputStmt  */
#line 314 "exptree.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 2020 "y.tab.c"
    break;

  case 31: /* Stmt: OutputStmt  */
#line 315 "exptree.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 2026 "y.tab.c"
    break;

  case 32: /* Stmt: AsgStmt  */
#line 316 "exptree.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 2032 "y.tab.c"
    break;

  case 33: /* Stmt: CntStmnt  */
#line 317 "exptree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2038 "y.tab.c"
    break;

  case 34: /* Stmt: BrkStmnt  */
#line 318 "exptree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2044 "y.tab.c"
    break;

  case 35: /* Stmt: FuncallStmt  */
#line 319 "exptree.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2050 "y.tab.c"
    break;

  case 36: /* Stmt: RetStmnt  */
#line 320 "exptree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2056 "y.tab.c"
    break;

  case 37: /* Stmt: NODE_WHILE '(' expr ')' NODE_DO Slist NODE_ENDWHILE ';'  */
#line 321 "exptree.y"
                                                               {(yyval.node) = createTree(0 ,0,WHILE ,NULL,(yyvsp[-5].node), (yyvsp[-2].node));}
#line 2062 "y.tab.c"
    break;

  case 38: /* Stmt: NODE_IF '(' expr ')' NODE_THEN Slist NODE_ELSE Slist NODE_ENDIF ';'  */
#line 322 "exptree.y"
                                                                           {(yyval.node) = createTree(0 ,IF_DOUBLE,IF ,NULL,(yyvsp[-7].node), createTree(0 ,0,CONNECT ,NULL, (yyvsp[-4].node), (yyvsp[-2].node)));}
#line 2068 "y.tab.c"
    break;

  case 39: /* Stmt: NODE_IF '(' expr ')' NODE_THEN Slist NODE_ENDIF ';'  */
#line 323 "exptree.y"
                                                           {(yyval.node) = createTree(0 ,IF_SINGLE,IF ,NULL,(yyvsp[-5].node), (yyvsp[-2].node));}
#line 2074 "y.tab.c"
    break;

  case 40: /* RetStmnt: NODE_RETURN FuncallStmt ';'  */
#line 326 "exptree.y"
                                           {(yyval.node) = createTree(0,0,FUNCTION_RETURN,NULL, NULL, (yyvsp[-1].node));}
#line 2080 "y.tab.c"
    break;

  case 41: /* RetStmnt: NODE_RETURN expr ';'  */
#line 327 "exptree.y"
                                                        {(yyval.node) = createTree(0,0,FUNCTION_RETURN,NULL, NULL, (yyvsp[-1].node));}
#line 2086 "y.tab.c"
    break;

  case 42: /* RetStmnt: NODE_RETURN ';'  */
#line 328 "exptree.y"
                                                        {(yyval.node) = createTree(0,0,FUNCTION_RETURN,NULL, NULL, NULL);}
#line 2092 "y.tab.c"
    break;

  case 43: /* CntStmnt: NODE_CONTINUE ';'  */
#line 331 "exptree.y"
                            {(yyval.node) = createTree(0 ,0,CONTINUE ,NULL, NULL, NULL);}
#line 2098 "y.tab.c"
    break;

  case 44: /* BrkStmnt: NODE_BREAK ';'  */
#line 332 "exptree.y"
                         {(yyval.node) = createTree(0 ,0,BREAK ,NULL, NULL, NULL);}
#line 2104 "y.tab.c"
    break;

  case 45: /* InputStmt: NODE_READ '(' expr ')' ';'  */
#line 335 "exptree.y"
                                        {(yyval.node) = createTree(0 ,0,READ ,NULL, (yyvsp[-2].node), NULL);}
#line 2110 "y.tab.c"
    break;

  case 46: /* OutputStmt: NODE_WRITE '(' expr ')' ';'  */
#line 338 "exptree.y"
                                        {(yyval.node) = createTree(0 ,0,WRITE ,NULL, (yyvsp[-2].node), NULL);}
#line 2116 "y.tab.c"
    break;

  case 47: /* AsgStmt: NODE_ID '=' expr ';'  */
#line 341 "exptree.y"
                                                        {
												struct Gsymbol *symb = Lookup((yyvsp[-3].node)->varname);
												if(symb != NULL)
													(yyvsp[-3].node)->type = symb->type;
												else
													printf("yacc>>Probably some untyped variable\n");
												
												(yyval.node) = createTree(0 ,0,ASSIGN ,"=", (yyvsp[-3].node), (yyvsp[-1].node));
											}
#line 2130 "y.tab.c"
    break;

  case 48: /* AsgStmt: NODE_ID '[' NODE_NUM ']' '=' expr ';'  */
#line 350 "exptree.y"
                                                        {	
												struct Gsymbol *temp1 = Lookup((yyvsp[-6].node)->varname);
			 									if(temp1)
													printf("\nyacc>>Not Null!\n");
												else
													printf("\nyacc>>Null!\n");

												(yyvsp[-6].node)->type = temp1->type;
											 	struct tnode *arrNode = createTree((yyvsp[-4].node)->val,temp1->type,ARRAY_TYPE,(yyvsp[-6].node)->varname,NULL,NULL);
												(yyval.node) = createTree(0 ,0,ASSIGN ,"=", arrNode, (yyvsp[-1].node));
											}
#line 2146 "y.tab.c"
    break;

  case 49: /* AsgStmt: NODE_ID '=' FuncallStmt  */
#line 361 "exptree.y"
                                                        {
												struct Gsymbol *symb = Lookup((yyvsp[-2].node)->varname);
												if(symb != NULL)
													(yyvsp[-2].node)->type = symb->type;
												else
													printf("yacc>>Probably some untyped variable\n");

												(yyval.node) = createTree(0 ,0,ASSIGN ,"=", (yyvsp[-2].node), (yyvsp[0].node));
											}
#line 2160 "y.tab.c"
    break;

  case 50: /* AsgStmt: NODE_ID '[' NODE_NUM ']' '=' FuncallStmt  */
#line 370 "exptree.y"
                                                        {	
												struct Gsymbol *temp1 = Lookup((yyvsp[-5].node)->varname);
			 									if(temp1)
													printf("\nyacc>>Not Null!\n");
												else
													printf("\nyacc>>Null!\n");

												(yyvsp[-5].node)->type = temp1->type;
											 	struct tnode *arrNode = createTree((yyvsp[-3].node)->val,temp1->type,ARRAY_TYPE,(yyvsp[-5].node)->varname,NULL,NULL);
												(yyval.node) = createTree(0 ,0,ASSIGN ,"=", arrNode, (yyvsp[0].node));
											}
#line 2176 "y.tab.c"
    break;

  case 51: /* FuncallStmt: NODE_ID '(' arglist ')' ';'  */
#line 383 "exptree.y"
                                                {	if (inside_function)
											{
												struct Gsymbol *temp1 = Lookup((yyvsp[-4].node)->varname);
			 									if(temp1 == NULL){
													printf("yacc>>Undefined Function\n");
													exit(1);
			 									}
			 									(yyvsp[-4].node)->type = temp1->type;
												(yyval.node) = createTree(0,0,FUNCTION_CALL,NULL,(yyvsp[-2].node),(yyvsp[-4].node));
											}
											else{
												printf("yacc>>Function cannot be called from outside\n");
												exit(1);
											}
										}
#line 2196 "y.tab.c"
    break;

  case 52: /* FuncallStmt: NODE_ID '(' ')' ';'  */
#line 398 "exptree.y"
                                                                { if (inside_function)
											{
												struct Gsymbol *temp1 = Lookup((yyvsp[-3].node)->varname);
			 									if(temp1 == NULL){
													printf("yacc>>Undefined Function\n");
													exit(1);
			 									}
			 									(yyvsp[-3].node)->type = temp1->type;
			 									(yyval.node) = createTree(0,0,FUNCTION_CALL,NULL,NULL,(yyvsp[-3].node));
	 										}else{
	 											printf("yacc>>Function cannot be called from outside\n");
												exit(1);
	 										}

										}
#line 2216 "y.tab.c"
    break;

  case 53: /* arglist: arglist ',' expr  */
#line 415 "exptree.y"
                                        {
									(yyval.node) = appendTree((yyvsp[-2].node),createTree(0,0,FUNCTION_ARGUMENT_LIST,NULL,NULL,(yyvsp[0].node)));
								}
#line 2224 "y.tab.c"
    break;

  case 54: /* arglist: expr  */
#line 418 "exptree.y"
                               {(yyval.node) = createTree(0,0,FUNCTION_ARGUMENT_LIST,NULL,NULL,(yyvsp[0].node));}
#line 2230 "y.tab.c"
    break;

  case 55: /* expr: expr NODE_GRT expr  */
#line 422 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2236 "y.tab.c"
    break;

  case 56: /* expr: expr NODE_LES expr  */
#line 423 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2242 "y.tab.c"
    break;

  case 57: /* expr: expr NODE_GEQ expr  */
#line 424 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2248 "y.tab.c"
    break;

  case 58: /* expr: expr NODE_LEQ expr  */
#line 425 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2254 "y.tab.c"
    break;

  case 59: /* expr: expr NODE_NEQUALS expr  */
#line 426 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"!=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2260 "y.tab.c"
    break;

  case 60: /* expr: expr NODE_EQUALS expr  */
#line 427 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"==", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2266 "y.tab.c"
    break;

  case 61: /* expr: expr NODE_PLUS expr  */
#line 428 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"+", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2272 "y.tab.c"
    break;

  case 62: /* expr: expr NODE_MINUS expr  */
#line 429 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"-", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2278 "y.tab.c"
    break;

  case 63: /* expr: expr NODE_MUL expr  */
#line 430 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"*", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2284 "y.tab.c"
    break;

  case 64: /* expr: expr NODE_DIV expr  */
#line 431 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"/", (yyvsp[-2].node), (yyvsp[0].node));}
#line 2290 "y.tab.c"
    break;

  case 65: /* expr: '(' expr ')'  */
#line 432 "exptree.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2296 "y.tab.c"
    break;

  case 66: /* expr: NODE_ID '[' NODE_NUM ']'  */
#line 433 "exptree.y"
                                                { 	
	 									struct Gsymbol *temp1 = Lookup((yyvsp[-3].node)->varname);
	 									if(temp1)
											printf("yac>>Not Null!\n");
										else
											printf("yacc>>Null!\n");

										(yyvsp[-3].node)->type = temp1->type;
										(yyval.node) = createTree((yyvsp[-1].node)->val,temp1->type,ARRAY_TYPE,(yyvsp[-3].node)->varname,NULL,NULL);
									}
#line 2311 "y.tab.c"
    break;

  case 67: /* expr: NODE_ID  */
#line 443 "exptree.y"
                                                                {
	 									struct Gsymbol *temp = Lookup((yyvsp[0].node)->varname);
										if(temp){
											printf("\nyacc>>Not Null!\n");
											(yyvsp[0].node)->type = temp->type;
										}
										else
										{
											(yyvsp[0].node)->type = VAR_UNDEF;
											printf("\nyacc>>Null!\n");
										}
										(yyval.node) = (yyvsp[0].node);
									}
#line 2329 "y.tab.c"
    break;

  case 68: /* expr: NODE_NUM  */
#line 457 "exptree.y"
                                                                {(yyvsp[0].node)->type = INT_TYPE;(yyval.node) = (yyvsp[0].node);}
#line 2335 "y.tab.c"
    break;

  case 69: /* expr: NODE_STR  */
#line 458 "exptree.y"
                                                                {(yyvsp[0].node)->type = STR_TYPE;(yyval.node) = (yyvsp[0].node);}
#line 2341 "y.tab.c"
    break;


#line 2345 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 461 "exptree.y"




int main(void) {
	extern FILE *yyin; 

	register_index = 0;
	firstreg = 1;
	code = fopen("out.txt", "w");

	yyin = fopen("inp.txt", "r"); 

	if( yyin == NULL)
	{
	     printf("\n Error ! \n");
	} else {
	    printf("parsing started!\n");
	    yyparse();
	}
	
	return 0;
}
