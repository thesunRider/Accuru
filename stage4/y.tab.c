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

	struct Gsymbol *symbolTable = NULL;

	#include "exptree.h"
	#include "exptree.c"


#line 88 "y.tab.c"

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
    NODE_VARDECL = 277,            /* NODE_VARDECL  */
    NODE_VARENDDECL = 278,         /* NODE_VARENDDECL  */
    NODE_TYPE_INT = 279,           /* NODE_TYPE_INT  */
    NODE_TYPE_STR = 280,           /* NODE_TYPE_STR  */
    NODE_ENDWHILE = 281,           /* NODE_ENDWHILE  */
    NODE_DO = 282,                 /* NODE_DO  */
    NODE_WHILE = 283,              /* NODE_WHILE  */
    NODE_IF = 284,                 /* NODE_IF  */
    NODE_THEN = 285,               /* NODE_THEN  */
    NODE_ELSE = 286,               /* NODE_ELSE  */
    NODE_ENDIF = 287,              /* NODE_ENDIF  */
    NODE_READ = 288,               /* NODE_READ  */
    NODE_WRITE = 289               /* NODE_WRITE  */
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
#define NODE_VARDECL 277
#define NODE_VARENDDECL 278
#define NODE_TYPE_INT 279
#define NODE_TYPE_STR 280
#define NODE_ENDWHILE 281
#define NODE_DO 282
#define NODE_WHILE 283
#define NODE_IF 284
#define NODE_THEN 285
#define NODE_ELSE 286
#define NODE_ENDIF 287
#define NODE_READ 288
#define NODE_WRITE 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "exptree.y"

	struct tnode *node;
	int number;
	struct Gsymbol *decl_node;
	

#line 216 "y.tab.c"

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
  YYSYMBOL_NODE_VARDECL = 22,              /* NODE_VARDECL  */
  YYSYMBOL_NODE_VARENDDECL = 23,           /* NODE_VARENDDECL  */
  YYSYMBOL_NODE_TYPE_INT = 24,             /* NODE_TYPE_INT  */
  YYSYMBOL_NODE_TYPE_STR = 25,             /* NODE_TYPE_STR  */
  YYSYMBOL_NODE_ENDWHILE = 26,             /* NODE_ENDWHILE  */
  YYSYMBOL_NODE_DO = 27,                   /* NODE_DO  */
  YYSYMBOL_NODE_WHILE = 28,                /* NODE_WHILE  */
  YYSYMBOL_NODE_IF = 29,                   /* NODE_IF  */
  YYSYMBOL_NODE_THEN = 30,                 /* NODE_THEN  */
  YYSYMBOL_NODE_ELSE = 31,                 /* NODE_ELSE  */
  YYSYMBOL_NODE_ENDIF = 32,                /* NODE_ENDIF  */
  YYSYMBOL_NODE_READ = 33,                 /* NODE_READ  */
  YYSYMBOL_NODE_WRITE = 34,                /* NODE_WRITE  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_Slist = 44,                     /* Slist  */
  YYSYMBOL_Stmt = 45,                      /* Stmt  */
  YYSYMBOL_Declarations = 46,              /* Declarations  */
  YYSYMBOL_DeclList = 47,                  /* DeclList  */
  YYSYMBOL_Decl = 48,                      /* Decl  */
  YYSYMBOL_Type = 49,                      /* Type  */
  YYSYMBOL_VarList = 50,                   /* VarList  */
  YYSYMBOL_CntStmnt = 51,                  /* CntStmnt  */
  YYSYMBOL_BrkStmnt = 52,                  /* BrkStmnt  */
  YYSYMBOL_InputStmt = 53,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 54,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 55,                   /* AsgStmt  */
  YYSYMBOL_expr = 56                       /* expr  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
      35,    36,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    64,    70,    71,    76,    77,    78,    79,
      80,    81,    82,    83,    87,    88,    91,    92,    95,    98,
      99,   102,   116,   130,   143,   160,   161,   164,   167,   170,
     171,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   207,   217,   218
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
  "NODE_BREAK", "NODE_CONTINUE", "NODE_VARDECL", "NODE_VARENDDECL",
  "NODE_TYPE_INT", "NODE_TYPE_STR", "NODE_ENDWHILE", "NODE_DO",
  "NODE_WHILE", "NODE_IF", "NODE_THEN", "NODE_ELSE", "NODE_ENDIF",
  "NODE_READ", "NODE_WRITE", "'('", "')'", "';'", "','", "'['", "']'",
  "'='", "$accept", "Program", "Slist", "Stmt", "Declarations", "DeclList",
  "Decl", "Type", "VarList", "CntStmnt", "BrkStmnt", "InputStmt",
  "OutputStmt", "AsgStmt", "expr", YY_NULLPTR
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
     285,   286,   287,   288,   289,    40,    41,    59,    44,    91,
      93,    61
};
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,   -18,    61,     5,    33,   -41,   -41,    -3,   -41,    49,
     -41,   132,   -41,    34,   -41,    54,    30,    23,   -41,    35,
      63,    66,    67,    92,    94,   143,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   104,   -41,   103,   127,    57,   -41,   -41,
      57,    57,    57,    57,   -41,   -41,    91,    95,    96,   -41,
     -41,    98,    57,     4,    44,    72,    84,    99,   -41,   135,
     101,   136,   111,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,   -41,   122,   120,   117,   118,   116,    57,
     128,   -41,    28,    28,   -41,   -41,   205,   205,   205,   205,
     205,   205,   174,   174,   -41,   -41,   -41,    32,   -41,   153,
     112,   -41,   121,   174,   130,   -41,   164,   -41,   133,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,    19,    20,     0,    17,     0,
       1,     0,    15,     0,    16,    22,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     5,     9,    10,     6,
       7,     8,    14,     0,    18,     0,     0,     0,    26,    25,
       0,     0,     0,     0,     2,     4,     0,    21,     0,    44,
      45,    43,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,    41,    37,    38,    39,    40,    31,    32,    33,    34,
      35,    36,     0,     0,    27,    28,    23,     0,    42,     0,
       0,    30,     0,     0,     0,    11,     0,    13,     0,    12
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,   -40,   -25,   -41,   -41,   150,   -41,   -41,   -41,
     -41,   -41,   -41,   -41,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    25,    26,     3,     7,     8,     9,    16,    27,
      28,    29,    30,    31,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      45,    54,    55,    56,    57,     4,     5,     6,    63,    64,
      65,    66,     1,    62,    67,    68,    69,    70,    71,    72,
      13,     5,     6,    11,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    65,    66,    63,    64,    65,    66,
      97,    73,    67,    68,    69,    70,    71,    72,    63,    64,
      65,    66,    99,   100,    67,    68,    69,    70,    71,    72,
      49,    10,    36,   106,    37,    15,    50,    34,    35,   101,
      12,    32,    38,    51,    45,    45,    63,    64,    65,    66,
      74,    45,    67,    68,    69,    70,    71,    72,    63,    64,
      65,    66,    52,    33,    67,    68,    69,    70,    71,    72,
      39,    40,    41,    63,    64,    65,    66,    46,    75,    67,
      68,    69,    70,    71,    72,    63,    64,    65,    66,    47,
      76,    67,    68,    69,    70,    71,    72,    42,    17,    43,
      48,    58,    19,    20,    59,    77,    60,    61,    78,    80,
      21,    22,    79,   103,   104,    23,    24,    81,    17,    92,
      93,    18,    19,    20,    94,    95,    96,    14,   105,    17,
      21,    22,    44,    19,    20,    23,    24,   107,    98,    17,
     109,    21,    22,    19,    20,     0,    23,    24,     0,   102,
      17,    21,    22,     0,    19,    20,    23,    24,     0,     0,
      17,     0,    21,    22,    19,    20,   108,    23,    24,     0,
       0,     0,    21,    22,     0,     0,     0,    23,    24,    63,
      64,    65,    66,     0,     0,    -1,    -1,    -1,    -1,    -1,
      -1
};

static const yytype_int8 yycheck[] =
{
      25,    40,    41,    42,    43,    23,    24,    25,     4,     5,
       6,     7,    22,    52,    10,    11,    12,    13,    14,    15,
      23,    24,    25,    18,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     6,     7,     4,     5,     6,     7,
      79,    37,    10,    11,    12,    13,    14,    15,     4,     5,
       6,     7,    92,    93,    10,    11,    12,    13,    14,    15,
       3,     0,    39,   103,    41,    16,     9,    37,    38,    37,
      37,    37,    37,    16,    99,   100,     4,     5,     6,     7,
      36,   106,    10,    11,    12,    13,    14,    15,     4,     5,
       6,     7,    35,    39,    10,    11,    12,    13,    14,    15,
      37,    35,    35,     4,     5,     6,     7,     3,    36,    10,
      11,    12,    13,    14,    15,     4,     5,     6,     7,    16,
      36,    10,    11,    12,    13,    14,    15,    35,    16,    35,
       3,    40,    20,    21,    39,    36,    40,    39,     3,     3,
      28,    29,    41,    31,    32,    33,    34,    36,    16,    27,
      30,    19,    20,    21,    37,    37,    40,     7,    37,    16,
      28,    29,    19,    20,    21,    33,    34,    37,    40,    16,
      37,    28,    29,    20,    21,    -1,    33,    34,    -1,    26,
      16,    28,    29,    -1,    20,    21,    33,    34,    -1,    -1,
      16,    -1,    28,    29,    20,    21,    32,    33,    34,    -1,
      -1,    -1,    28,    29,    -1,    -1,    -1,    33,    34,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    13,    14,
      15
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    22,    43,    46,    23,    24,    25,    47,    48,    49,
       0,    18,    37,    23,    48,    16,    50,    16,    19,    20,
      21,    28,    29,    33,    34,    44,    45,    51,    52,    53,
      54,    55,    37,    39,    37,    38,    39,    41,    37,    37,
      35,    35,    35,    35,    19,    45,     3,    16,     3,     3,
       9,    16,    35,    56,    56,    56,    56,    56,    40,    39,
      40,    39,    56,     4,     5,     6,     7,    10,    11,    12,
      13,    14,    15,    37,    36,    36,    36,    36,     3,    41,
       3,    36,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    27,    30,    37,    37,    40,    56,    40,    44,
      44,    37,    26,    31,    32,    37,    44,    37,    32,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    47,    48,    49,
      49,    50,    50,    50,    50,    51,    52,    53,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     1,     1,     1,     1,     1,
       1,     8,    10,     8,     4,     3,     2,     1,     3,     1,
       1,     3,     1,     6,     4,     2,     2,     5,     5,     4,
       7,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     1,     1,     1
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
  case 2: /* Program: Declarations NODE_BEGIN Slist NODE_END  */
#line 57 "exptree.y"
                                                 {
				printSymbolTable(&symbolTable);
				(yyval.node) = (yyvsp[-1].node);
				evaluate((yyvsp[-1].node),code);
				//printf($2);
				exit(1);}
#line 1609 "y.tab.c"
    break;

  case 3: /* Program: Declarations NODE_BEGIN NODE_END  */
#line 64 "exptree.y"
                                                   {(yyval.node) = NULL;}
#line 1615 "y.tab.c"
    break;

  case 4: /* Slist: Slist Stmt  */
#line 70 "exptree.y"
                   {(yyval.node) = createTree(0 ,0,CONNECT ,NULL, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1621 "y.tab.c"
    break;

  case 5: /* Slist: Stmt  */
#line 71 "exptree.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1627 "y.tab.c"
    break;

  case 6: /* Stmt: InputStmt  */
#line 76 "exptree.y"
                 {(yyval.node) = (yyvsp[0].node);}
#line 1633 "y.tab.c"
    break;

  case 7: /* Stmt: OutputStmt  */
#line 77 "exptree.y"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1639 "y.tab.c"
    break;

  case 8: /* Stmt: AsgStmt  */
#line 78 "exptree.y"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1645 "y.tab.c"
    break;

  case 9: /* Stmt: CntStmnt  */
#line 79 "exptree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1651 "y.tab.c"
    break;

  case 10: /* Stmt: BrkStmnt  */
#line 80 "exptree.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1657 "y.tab.c"
    break;

  case 11: /* Stmt: NODE_WHILE '(' expr ')' NODE_DO Slist NODE_ENDWHILE ';'  */
#line 81 "exptree.y"
                                                               {(yyval.node) = createTree(0 ,0,WHILE ,NULL,(yyvsp[-5].node), (yyvsp[-2].node));}
#line 1663 "y.tab.c"
    break;

  case 12: /* Stmt: NODE_IF '(' expr ')' NODE_THEN Slist NODE_ELSE Slist NODE_ENDIF ';'  */
#line 82 "exptree.y"
                                                                           {(yyval.node) = createTree(0 ,IF_DOUBLE,IF ,NULL,(yyvsp[-7].node), createTree(0 ,0,CONNECT ,NULL, (yyvsp[-4].node), (yyvsp[-2].node)));}
#line 1669 "y.tab.c"
    break;

  case 13: /* Stmt: NODE_IF '(' expr ')' NODE_THEN Slist NODE_ENDIF ';'  */
#line 83 "exptree.y"
                                                           {(yyval.node) = createTree(0 ,IF_SINGLE,IF ,NULL,(yyvsp[-5].node), (yyvsp[-2].node));}
#line 1675 "y.tab.c"
    break;

  case 18: /* Decl: Type VarList ';'  */
#line 95 "exptree.y"
                          {assignType(&symbolTable, (yyvsp[-2].number));}
#line 1681 "y.tab.c"
    break;

  case 19: /* Type: NODE_TYPE_INT  */
#line 98 "exptree.y"
                     {(yyval.number) = INT_TYPE;}
#line 1687 "y.tab.c"
    break;

  case 20: /* Type: NODE_TYPE_STR  */
#line 99 "exptree.y"
                         {(yyval.number) = STR_TYPE;}
#line 1693 "y.tab.c"
    break;

  case 21: /* VarList: VarList ',' NODE_ID  */
#line 102 "exptree.y"
                            {	struct Gsymbol *temp = NULL;
								temp = Lookup((yyvsp[0].node)->varname);
								if(temp == NULL)
								{
									Install((yyvsp[0].node)->varname, 0, 1);
									(yyval.decl_node) = Lookup((yyvsp[0].node)->varname);
								}
								else
								{
									printf("Error. Variable declared twice.\n");
									exit(1);
								}
							}
#line 1711 "y.tab.c"
    break;

  case 22: /* VarList: NODE_ID  */
#line 116 "exptree.y"
                                {	struct Gsymbol *temp = NULL;
						temp = Lookup( (yyvsp[0].node)->varname);
						if(temp == NULL)
						{
							Install( (yyvsp[0].node)->varname, 0, 1);
							(yyval.decl_node) = Lookup( (yyvsp[0].node)->varname);
						}
						else
						{
							printf("Error. Variable declared twice.\n");
							exit(1);
						}
					}
#line 1729 "y.tab.c"
    break;

  case 23: /* VarList: VarList ',' NODE_ID '[' NODE_NUM ']'  */
#line 130 "exptree.y"
                                                  { struct Gsymbol *temp = NULL;
									temp = Lookup((yyvsp[-3].node)->varname);
									if(temp == NULL)
									{
										Install((yyvsp[-3].node)->varname, 0, (yyvsp[-1].node)->val);
										(yyval.decl_node) = Lookup((yyvsp[-3].node)->varname);
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
#line 1747 "y.tab.c"
    break;

  case 24: /* VarList: NODE_ID '[' NODE_NUM ']'  */
#line 143 "exptree.y"
                                                        {
									struct Gsymbol *temp = NULL;
									temp = Lookup((yyvsp[-3].node)->varname);
									if(temp == NULL){
										Install( (yyvsp[-3].node)->varname, 0, (yyvsp[-1].node)->val);
										(yyval.decl_node) = Lookup((yyvsp[-3].node)->varname);
							
									}
									else
									{
										printf("Error. Variable declared twice.\n");
										exit(1);
									}
								}
#line 1766 "y.tab.c"
    break;

  case 25: /* CntStmnt: NODE_CONTINUE ';'  */
#line 160 "exptree.y"
                            {(yyval.node) = createTree(0 ,0,CONTINUE ,NULL, NULL, NULL);}
#line 1772 "y.tab.c"
    break;

  case 26: /* BrkStmnt: NODE_BREAK ';'  */
#line 161 "exptree.y"
                         {(yyval.node) = createTree(0 ,0,BREAK ,NULL, NULL, NULL);}
#line 1778 "y.tab.c"
    break;

  case 27: /* InputStmt: NODE_READ '(' expr ')' ';'  */
#line 164 "exptree.y"
                                        {(yyval.node) = createTree(0 ,0,READ ,NULL, (yyvsp[-2].node), NULL);}
#line 1784 "y.tab.c"
    break;

  case 28: /* OutputStmt: NODE_WRITE '(' expr ')' ';'  */
#line 167 "exptree.y"
                                        {(yyval.node) = createTree(0 ,0,WRITE ,NULL, (yyvsp[-2].node), NULL);}
#line 1790 "y.tab.c"
    break;

  case 29: /* AsgStmt: NODE_ID '=' expr ';'  */
#line 170 "exptree.y"
                                                        {(yyval.node) = createTree(0 ,0,ASSIGN ,"=", (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1796 "y.tab.c"
    break;

  case 30: /* AsgStmt: NODE_ID '[' NODE_NUM ']' '=' expr ';'  */
#line 171 "exptree.y"
                                                        {	
												struct Gsymbol *temp1 = Lookup((yyvsp[-6].node)->varname);
			 									if(temp1)
													printf("Not Null!\n");
												else
													printf("Null!\n");

												(yyvsp[-6].node)->type = temp1->type;
											 	struct tnode *arrNode = createTree((yyvsp[-4].node)->val,temp1->type,ARRAY_TYPE,(yyvsp[-6].node)->varname,NULL,NULL);
												(yyval.node) = createTree(0 ,0,ASSIGN ,"=", arrNode, (yyvsp[-1].node));
											}
#line 1812 "y.tab.c"
    break;

  case 31: /* expr: expr NODE_GRT expr  */
#line 186 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1818 "y.tab.c"
    break;

  case 32: /* expr: expr NODE_LES expr  */
#line 187 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1824 "y.tab.c"
    break;

  case 33: /* expr: expr NODE_GEQ expr  */
#line 188 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"<=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1830 "y.tab.c"
    break;

  case 34: /* expr: expr NODE_LEQ expr  */
#line 189 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,">=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1836 "y.tab.c"
    break;

  case 35: /* expr: expr NODE_NEQUALS expr  */
#line 190 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"!=", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1842 "y.tab.c"
    break;

  case 36: /* expr: expr NODE_EQUALS expr  */
#line 191 "exptree.y"
                                                {(yyval.node) = createTree(0 ,BOOL_TYPE,LOGIC_OP ,"==", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1848 "y.tab.c"
    break;

  case 37: /* expr: expr NODE_PLUS expr  */
#line 192 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"+", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1854 "y.tab.c"
    break;

  case 38: /* expr: expr NODE_MINUS expr  */
#line 193 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"-", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1860 "y.tab.c"
    break;

  case 39: /* expr: expr NODE_MUL expr  */
#line 194 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"*", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1866 "y.tab.c"
    break;

  case 40: /* expr: expr NODE_DIV expr  */
#line 195 "exptree.y"
                                                {(yyval.node) = createTree(0 ,0,OP ,"/", (yyvsp[-2].node), (yyvsp[0].node));}
#line 1872 "y.tab.c"
    break;

  case 41: /* expr: '(' expr ')'  */
#line 196 "exptree.y"
                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 1878 "y.tab.c"
    break;

  case 42: /* expr: NODE_ID '[' NODE_NUM ']'  */
#line 197 "exptree.y"
                                                { 	
	 									struct Gsymbol *temp1 = Lookup((yyvsp[-3].node)->varname);
	 									if(temp1)
											printf("Not Null!\n");
										else
											printf("Null!\n");

										(yyvsp[-3].node)->type = temp1->type;
										(yyval.node) = createTree((yyvsp[-1].node)->val,temp1->type,ARRAY_TYPE,(yyvsp[-3].node)->varname,NULL,NULL);
									}
#line 1893 "y.tab.c"
    break;

  case 43: /* expr: NODE_ID  */
#line 207 "exptree.y"
                                                                {	
	 									struct Gsymbol *temp = Lookup((yyvsp[0].node)->varname);
										if(temp)
											printf("Not Null!\n");
										else
											printf("Null!\n");
										(yyvsp[0].node)->type = temp->type;
										(yyval.node) = (yyvsp[0].node);
									}
#line 1907 "y.tab.c"
    break;

  case 44: /* expr: NODE_NUM  */
#line 217 "exptree.y"
                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1913 "y.tab.c"
    break;

  case 45: /* expr: NODE_STR  */
#line 218 "exptree.y"
                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1919 "y.tab.c"
    break;


#line 1923 "y.tab.c"

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

#line 221 "exptree.y"




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
