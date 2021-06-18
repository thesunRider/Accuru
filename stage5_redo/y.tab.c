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
#line 1 "st5.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<limits.h>
	#include<string.h>
	#include"st5.h"
	#include"stack.c"
	#include"symbol.c"
	#include"codegen.c"
	#include"ast.c"
	#define YYSTYPE tnode*
	extern FILE *yyin;
	FILE* fout;

#line 86 "y.tab.c"

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
    BEG = 258,                     /* BEG  */
    END = 259,                     /* END  */
    READ = 260,                    /* READ  */
    WRITE = 261,                   /* WRITE  */
    NUM = 262,                     /* NUM  */
    ID = 263,                      /* ID  */
    IF = 264,                      /* IF  */
    THEN = 265,                    /* THEN  */
    ELSE = 266,                    /* ELSE  */
    ENDIF = 267,                   /* ENDIF  */
    WHILE = 268,                   /* WHILE  */
    DO = 269,                      /* DO  */
    ENDWHILE = 270,                /* ENDWHILE  */
    BREAK = 271,                   /* BREAK  */
    CONTINUE = 272,                /* CONTINUE  */
    DECL = 273,                    /* DECL  */
    ENDDECL = 274,                 /* ENDDECL  */
    INT = 275,                     /* INT  */
    STR = 276,                     /* STR  */
    LIT = 277,                     /* LIT  */
    BRKP = 278,                    /* BRKP  */
    RETURN = 279,                  /* RETURN  */
    MAIN = 280,                    /* MAIN  */
    LT = 281,                      /* "<"  */
    GT = 282,                      /* ">"  */
    LE = 283,                      /* "<="  */
    GE = 284,                      /* ">="  */
    EQ = 285,                      /* "=="  */
    NE = 286,                      /* "!="  */
    ADD = 287,                     /* "+"  */
    SUB = 288,                     /* "-"  */
    MUL = 289,                     /* "*"  */
    DIV = 290                      /* "/"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BEG 258
#define END 259
#define READ 260
#define WRITE 261
#define NUM 262
#define ID 263
#define IF 264
#define THEN 265
#define ELSE 266
#define ENDIF 267
#define WHILE 268
#define DO 269
#define ENDWHILE 270
#define BREAK 271
#define CONTINUE 272
#define DECL 273
#define ENDDECL 274
#define INT 275
#define STR 276
#define LIT 277
#define BRKP 278
#define RETURN 279
#define MAIN 280
#define LT 281
#define GT 282
#define LE 283
#define GE 284
#define EQ 285
#define NE 286
#define ADD 287
#define SUB 288
#define MUL 289
#define DIV 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_BEG = 3,                        /* BEG  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_WRITE = 6,                      /* WRITE  */
  YYSYMBOL_NUM = 7,                        /* NUM  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_THEN = 10,                      /* THEN  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_ENDIF = 12,                     /* ENDIF  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_DO = 14,                        /* DO  */
  YYSYMBOL_ENDWHILE = 15,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 16,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 17,                  /* CONTINUE  */
  YYSYMBOL_DECL = 18,                      /* DECL  */
  YYSYMBOL_ENDDECL = 19,                   /* ENDDECL  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_STR = 21,                       /* STR  */
  YYSYMBOL_LIT = 22,                       /* LIT  */
  YYSYMBOL_BRKP = 23,                      /* BRKP  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_MAIN = 25,                      /* MAIN  */
  YYSYMBOL_LT = 26,                        /* "<"  */
  YYSYMBOL_GT = 27,                        /* ">"  */
  YYSYMBOL_LE = 28,                        /* "<="  */
  YYSYMBOL_GE = 29,                        /* ">="  */
  YYSYMBOL_EQ = 30,                        /* "=="  */
  YYSYMBOL_NE = 31,                        /* "!="  */
  YYSYMBOL_ADD = 32,                       /* "+"  */
  YYSYMBOL_SUB = 33,                       /* "-"  */
  YYSYMBOL_MUL = 34,                       /* "*"  */
  YYSYMBOL_DIV = 35,                       /* "/"  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* '='  */
  YYSYMBOL_45_ = 45,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_prog = 47,                      /* prog  */
  YYSYMBOL_GDeclBlock = 48,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 49,                 /* GDeclList  */
  YYSYMBOL_GDecl = 50,                     /* GDecl  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_Gidlist = 52,                   /* Gidlist  */
  YYSYMBOL_Gid = 53,                       /* Gid  */
  YYSYMBOL_newParamList = 54,              /* newParamList  */
  YYSYMBOL_fID = 55,                       /* fID  */
  YYSYMBOL_FDefBlock = 56,                 /* FDefBlock  */
  YYSYMBOL_Fdef = 57,                      /* Fdef  */
  YYSYMBOL_newFID = 58,                    /* newFID  */
  YYSYMBOL_validParamList = 59,            /* validParamList  */
  YYSYMBOL_ParamList = 60,                 /* ParamList  */
  YYSYMBOL_Param = 61,                     /* Param  */
  YYSYMBOL_LdeclBlock = 62,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 63,                  /* LDecList  */
  YYSYMBOL_LDecl = 64,                     /* LDecl  */
  YYSYMBOL_IdList = 65,                    /* IdList  */
  YYSYMBOL_IDVar = 66,                     /* IDVar  */
  YYSYMBOL_Body = 67,                      /* Body  */
  YYSYMBOL_Retstmt = 68,                   /* Retstmt  */
  YYSYMBOL_MainBlock = 69,                 /* MainBlock  */
  YYSYMBOL_Main = 70,                      /* Main  */
  YYSYMBOL_Slist = 71,                     /* Slist  */
  YYSYMBOL_Stmt = 72,                      /* Stmt  */
  YYSYMBOL_Breakpoint = 73,                /* Breakpoint  */
  YYSYMBOL_InputStmt = 74,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 75,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 76,                   /* AsgStmt  */
  YYSYMBOL_Var = 77,                       /* Var  */
  YYSYMBOL_IfStmt = 78,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 79,                 /* WhileStmt  */
  YYSYMBOL_BrkContStmt = 80,               /* BrkContStmt  */
  YYSYMBOL_Expr = 81,                      /* Expr  */
  YYSYMBOL_ArgList = 82                    /* ArgList  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   348

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      38,    39,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    45,    56,    57,    60,    61,    64,    69,
      71,    74,    78,    84,    88,    94,    99,   104,   111,   115,
     118,   121,   124,   128,   133,   140,   150,   156,   161,   164,
     168,   173,   181,   181,   183,   184,   187,   192,   196,   198,
     198,   202,   208,   212,   219,   226,   234,   237,   240,   243,
     244,   245,   246,   247,   248,   249,   252,   256,   260,   262,
     268,   289,   312,   335,   368,   372,   376,   380,   382,   385,
     389,   392,   395,   398,   401,   404,   407,   410,   413,   416,
     417,   418,   443,   469,   496,   521,   544,   575,   576,   583,
     585,   586
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BEG", "END", "READ",
  "WRITE", "NUM", "ID", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO",
  "ENDWHILE", "BREAK", "CONTINUE", "DECL", "ENDDECL", "INT", "STR", "LIT",
  "BRKP", "RETURN", "MAIN", "\"<\"", "\">\"", "\"<=\"", "\">=\"", "\"==\"",
  "\"!=\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "';'", "','", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "'='", "'&'", "$accept", "prog",
  "GDeclBlock", "GDeclList", "GDecl", "Type", "Gidlist", "Gid",
  "newParamList", "fID", "FDefBlock", "Fdef", "newFID", "validParamList",
  "ParamList", "Param", "LdeclBlock", "LDecList", "LDecl", "IdList",
  "IDVar", "Body", "Retstmt", "MainBlock", "Main", "Slist", "Stmt",
  "Breakpoint", "InputStmt", "OutputStmt", "AsgStmt", "Var", "IfStmt",
  "WhileStmt", "BrkContStmt", "Expr", "ArgList", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,    59,    44,    40,    41,
      91,    93,   123,   125,    61,    38
};
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,    -5,    19,    38,  -153,  -153,    31,  -153,    10,  -153,
       2,    15,    38,  -153,  -153,     5,  -153,  -153,   -33,    54,
      46,  -153,    28,  -153,  -153,    40,  -153,  -153,    47,    80,
    -153,  -153,    10,    -5,    -5,    48,    53,  -153,    13,   -13,
    -153,    62,    70,  -153,    94,    74,  -153,   110,    -5,  -153,
      77,    -5,    35,   117,   115,  -153,  -153,    94,  -153,  -153,
      14,    51,    90,   132,    86,    89,   117,  -153,   125,   102,
    -153,  -153,   107,  -153,   106,   108,   111,   109,   112,  -153,
    -153,  -153,   144,    87,   118,  -153,  -153,  -153,  -153,   123,
    -153,  -153,  -153,  -153,  -153,   126,  -153,    14,  -153,    23,
      23,    23,    23,    23,  -153,    23,   164,   134,  -153,    23,
    -153,  -153,  -153,    25,  -153,   174,    23,   175,   210,   224,
     130,   238,   252,   280,  -153,  -153,   291,    23,    23,  -153,
     266,   145,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    23,  -153,  -153,   158,   176,   170,  -153,   291,    60,
     146,  -153,    23,   311,   311,   311,   311,   311,   311,   301,
     301,   317,   317,    23,   132,   132,    23,  -153,   159,   162,
     178,    68,   100,   291,    23,  -153,  -153,   132,  -153,  -153,
     194,   119,  -153,  -153
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,     9,    10,     0,     7,     0,     1,
       9,     0,     0,    23,     3,     0,     4,     6,    13,     0,
       0,    12,     0,    45,    25,     0,    22,     2,     0,     0,
      15,     8,     0,    20,    29,     0,     0,    11,     0,     0,
      19,     0,    26,    28,     0,    16,    30,     0,     0,    14,
       0,     0,     0,     0,     0,    31,    18,     0,    27,    33,
      39,     0,     0,    48,     0,     0,     0,    40,     0,    36,
      38,    32,     0,    35,     0,     0,    60,     0,     0,    67,
      68,    56,     0,     0,     0,    55,    49,    50,    51,     0,
      52,    53,    54,    44,    17,     0,    41,    39,    34,     0,
       0,     0,     0,     0,    61,     0,     0,     0,    47,     0,
      24,    37,    80,    81,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    46,    59,    91,     0,    82,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,    58,    62,     0,     0,    43,    90,     0,
       0,    79,     0,    73,    74,    75,    76,    77,    78,    69,
      70,    71,    72,     0,    48,    48,     0,    88,    85,     0,
       0,     0,     0,    89,     0,    84,    63,    48,    65,    66,
       0,     0,    86,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,  -153,   195,     8,  -153,   168,  -153,  -153,
    -153,   190,  -153,  -153,  -153,    -2,   157,  -153,   154,  -153,
     120,   150,  -153,   206,  -153,  -152,   -83,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,   -99,  -153
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     7,    38,    20,    21,    39,    22,
      12,    13,    25,    41,    42,    40,    53,    61,    62,    69,
      70,    64,   106,    14,    15,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   118,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   119,   120,   121,   122,   -21,   123,    29,     1,     8,
     126,    11,   171,   172,     8,     4,     5,   130,    18,     9,
      11,    46,    67,    24,    48,   181,    49,    23,   148,   150,
     112,   113,    43,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,    28,    19,   114,    56,    47,    68,    58,
      16,     4,     5,   169,    59,     4,     5,   115,    10,     5,
      60,   116,    30,   127,   170,   128,    33,   173,   117,    60,
      71,     4,     5,    74,    75,   180,    76,    77,    34,   177,
     178,    78,    31,    32,    79,    80,    35,    36,   107,   107,
      44,    81,    74,    75,    45,    76,    77,   166,   107,   167,
      78,    50,    82,    79,    80,    74,    75,    51,    76,    77,
      81,   105,    52,    78,    54,   179,    79,    80,    55,    57,
      63,    82,    65,    81,    74,    75,    73,    76,    77,    93,
      94,   183,    78,    96,    82,    79,    80,    74,    75,    97,
      76,    77,    81,    98,    99,    78,   100,   102,    79,    80,
     103,   101,   104,    82,   108,    81,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    82,   109,   124,   110,
     125,   144,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   129,   131,   165,   152,   164,   168,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   163,   174,
      37,    17,    26,   175,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    66,    72,    95,   111,    27,   176,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,   182,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,     0,   142,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,   143,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,   145,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,   146,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   151,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   147,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   132,   133,   134,
     135,   136,   137,     0,     0,   140,   141,   -22,   -22,   -22,
     -22,   -22,   -22,   132,   133,   134,   135,   136,   137
};

static const yytype_int16 yycheck[] =
{
      83,   100,   101,   102,   103,    38,   105,    40,    18,     1,
     109,     3,   164,   165,     6,    20,    21,   116,     8,     0,
      12,     8,     8,     8,    37,   177,    39,    25,   127,   128,
       7,     8,    34,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    38,    34,    22,    48,    34,    34,    51,
      19,    20,    21,   152,    19,    20,    21,    34,    20,    21,
      52,    38,     8,    38,   163,    40,    38,   166,    45,    61,
      19,    20,    21,     5,     6,   174,     8,     9,    38,    11,
      12,    13,    36,    37,    16,    17,    39,     7,   171,   172,
      42,    23,     5,     6,    41,     8,     9,    37,   181,    39,
      13,    39,    34,    16,    17,     5,     6,    37,     8,     9,
      23,    24,    18,    13,    40,    15,    16,    17,     8,    42,
       3,    34,     7,    23,     5,     6,    36,     8,     9,    43,
      41,    12,    13,     8,    34,    16,    17,     5,     6,    37,
       8,     9,    23,    36,    38,    13,    38,    38,    16,    17,
      38,    40,     8,    34,    36,    23,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    34,    44,     4,    43,
      36,    41,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     8,     8,    14,    40,    10,    41,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    40,    40,
      32,     6,    12,    41,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    57,    61,    66,    97,    12,    41,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    41,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    -1,    -1,    39,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    39,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    -1,    -1,    -1,    39,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    39,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,    35,    26,    27,    28,
      29,    30,    31,    26,    27,    28,    29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    47,    48,    20,    21,    49,    50,    51,     0,
      20,    51,    56,    57,    69,    70,    19,    50,     8,    34,
      52,    53,    55,    25,     8,    58,    57,    69,    38,    40,
       8,    36,    37,    38,    38,    39,     7,    53,    51,    54,
      61,    59,    60,    61,    42,    41,     8,    34,    37,    39,
      39,    37,    18,    62,    40,     8,    61,    42,    61,    19,
      51,    63,    64,     3,    67,     7,    62,     8,    34,    65,
      66,    19,    64,    36,     5,     6,     8,     9,    13,    16,
      17,    23,    34,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    43,    41,    67,     8,    37,    36,    38,
      38,    40,    38,    38,     8,    24,    68,    72,    36,    44,
      43,    66,     7,     8,    22,    34,    38,    45,    81,    81,
      81,    81,    81,    81,     4,    36,    81,    38,    40,     8,
      81,     8,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    39,    39,    41,    39,    39,    36,    81,    82,
      81,    39,    40,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    40,    10,    14,    37,    39,    41,    81,
      81,    71,    71,    81,    40,    41,    41,    11,    12,    15,
      81,    71,    41,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    47,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    54,    54,
      54,    55,    56,    56,    57,    58,    59,    60,    60,    60,
      61,    61,    62,    62,    63,    63,    64,    65,    65,    66,
      66,    66,    67,    68,    69,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    73,    74,    75,    76,
      77,    77,    77,    77,    78,    78,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     0,     2,     1,     3,     1,
       1,     3,     1,     1,     4,     2,     4,     7,     3,     1,
       0,     1,     2,     1,     9,     1,     1,     3,     1,     0,
       2,     3,     3,     2,     3,     2,     2,     3,     1,     0,
       1,     2,     4,     3,     7,     2,     3,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     3,
       1,     2,     4,     7,     9,     7,     7,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     2,     2,     5,     4,     7,     1,     4,     3,
       1,     0
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
  case 2: /* prog: GDeclBlock FDefBlock MainBlock  */
#line 35 "st5.y"
                                      {
	 	showST();
	 	fprintf(fout,"%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\n",0,0,0,0,0,1,0);
	 	codeGen(yyvsp[-1],fout);
	 	freeAllReg();
	 	codeGen(yyvsp[0],fout);
	 	fprintf(fout,"INT 10\n");
		printf("\nSuccessfully parsed program with fdecl\n");
		exit(1);
		}
#line 1426 "y.tab.c"
    break;

  case 3: /* prog: GDeclBlock MainBlock  */
#line 45 "st5.y"
                               {
	 	showST();
	 	fprintf(fout,"%d\nMAIN\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP, %d\nMOV BP, %d\n",0,0,0,0,0,1,0,staticSize,staticSize);
	 	codeGen(yyvsp[0],fout);
	 	fprintf(fout,"INT 10\n");
	 	printf("Successfully parsed program\n");
	 	exit(1);
		}
#line 1439 "y.tab.c"
    break;

  case 4: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 56 "st5.y"
                                                {}
#line 1445 "y.tab.c"
    break;

  case 5: /* GDeclBlock: %empty  */
#line 57 "st5.y"
                        {}
#line 1451 "y.tab.c"
    break;

  case 6: /* GDeclList: GDeclList GDecl  */
#line 60 "st5.y"
                             {}
#line 1457 "y.tab.c"
    break;

  case 7: /* GDeclList: GDecl  */
#line 61 "st5.y"
                           {}
#line 1463 "y.tab.c"
    break;

  case 8: /* GDecl: Type Gidlist ';'  */
#line 64 "st5.y"
                                {	
									gAssignTypeDecl(yyvsp[-2], yyvsp[-1]);
								}
#line 1471 "y.tab.c"
    break;

  case 9: /* Type: INT  */
#line 69 "st5.y"
                                                {
								yyval=createTypeNode(intType);}
#line 1478 "y.tab.c"
    break;

  case 10: /* Type: STR  */
#line 71 "st5.y"
                                                {yyval=createTypeNode(stringType);}
#line 1484 "y.tab.c"
    break;

  case 11: /* Gidlist: Gidlist ',' Gid  */
#line 74 "st5.y"
                                {	
								yyvsp[0]->middle=yyvsp[-2];
								yyval=yyvsp[0];
								}
#line 1493 "y.tab.c"
    break;

  case 12: /* Gidlist: Gid  */
#line 78 "st5.y"
                                                {
								yyvsp[0]->middle=NULL;
								yyval=yyvsp[0];
							}
#line 1502 "y.tab.c"
    break;

  case 13: /* Gid: ID  */
#line 84 "st5.y"
                                {
				gInstall(yyvsp[0]->name,NULL,tVAR,1,0,getStaticSpace(1),NULL,NULL);
				yyval=yyvsp[0];
				}
#line 1511 "y.tab.c"
    break;

  case 14: /* Gid: fID '(' newParamList ')'  */
#line 88 "st5.y"
                                                {
									
									gInstall(yyvsp[-3]->name,NULL,tFUNC, 0,0,NULL, yyvsp[-1], getFLabel());
									yyvsp[-3]->nodetype=tFUNC;
									yyval=yyvsp[-3];
									}
#line 1522 "y.tab.c"
    break;

  case 15: /* Gid: "*" ID  */
#line 94 "st5.y"
                        {
				gInstall(yyvsp[-1]->name,NULL,tPVAR,1,0,getStaticSpace(1),NULL,NULL);
				yyvsp[0]->nodetype=tPVAR;
				yyval=yyvsp[0];
				}
#line 1532 "y.tab.c"
    break;

  case 16: /* Gid: ID '[' NUM ']'  */
#line 99 "st5.y"
                               {
				gInstall(yyvsp[-3]->name,NULL,tARR,yyvsp[-1]->val,0,getStaticSpace(yyvsp[-1]->val),NULL,NULL);
				yyvsp[-3]->nodetype=tARR;
				yyval=yyvsp[-3];
		}
#line 1542 "y.tab.c"
    break;

  case 17: /* Gid: ID '[' NUM ']' '[' NUM ']'  */
#line 104 "st5.y"
                                          {
				gInstall(yyvsp[-6]->name,NULL,tDARR,yyvsp[-4]->val,yyvsp[-1]->val,getStaticSpace((yyvsp[-4]->val)*(yyvsp[-2]->val)),NULL,NULL);
				yyvsp[-6]->nodetype=tDARR;
				yyval=yyvsp[-6];
		}
#line 1552 "y.tab.c"
    break;

  case 18: /* newParamList: newParamList ',' Param  */
#line 111 "st5.y"
                                           {
						yyvsp[0]->middle=yyvsp[-2];
						yyval=yyvsp[0];
						}
#line 1561 "y.tab.c"
    break;

  case 19: /* newParamList: Param  */
#line 115 "st5.y"
                                        {
		   				yyval=yyvsp[0];
					}
#line 1569 "y.tab.c"
    break;

  case 20: /* newParamList: %empty  */
#line 118 "st5.y"
                                {yyval=NULL;}
#line 1575 "y.tab.c"
    break;

  case 21: /* fID: ID  */
#line 121 "st5.y"
         {	currFunc=strdup(yyvsp[0]->name);}
#line 1581 "y.tab.c"
    break;

  case 22: /* FDefBlock: FDefBlock Fdef  */
#line 124 "st5.y"
                                {
						yyval = createTree(NULL,NULL, NULL,tCONNECT,NULL, yyvsp[-1],NULL, yyvsp[0],NULL);
						resetLocalSpace();
						}
#line 1590 "y.tab.c"
    break;

  case 23: /* FDefBlock: Fdef  */
#line 128 "st5.y"
                              {
						yyval=yyvsp[0];
						resetLocalSpace();
						}
#line 1599 "y.tab.c"
    break;

  case 24: /* Fdef: Type newFID '(' validParamList ')' '{' LdeclBlock Body '}'  */
#line 133 "st5.y"
                                                                            {
							//$8 is a (slist+return) statement node
							
							yyval = createFuncDefNode(yyvsp[-8]->type,yyvsp[-7]->name,yyvsp[-1]);
							resetLocalSpace();
							}
#line 1610 "y.tab.c"
    break;

  case 25: /* newFID: ID  */
#line 140 "st5.y"
           {
			struct localTable* currTable = gLookup(yyvsp[0]->name);
			if(currTable!=NULL){
				localTableCreate(yyvsp[0]->name);
				currFunc=strdup(yyvsp[0]->name);
			} else {
					yyerror("Did not declare this func\n");
			}
}
#line 1624 "y.tab.c"
    break;

  case 26: /* validParamList: ParamList  */
#line 150 "st5.y"
                          {
						//Name Equivalence
						paramCheck(currFunc);
}
#line 1633 "y.tab.c"
    break;

  case 27: /* ParamList: ParamList ',' Param  */
#line 156 "st5.y"
                                        {
						localEntryCreate(currFunc, yyvsp[0]->name, yyvsp[0]->type,yyvsp[0]->nodetype, getArgSpace());
						yyvsp[0]->middle=yyvsp[-2];
						yyval=yyvsp[0];
						}
#line 1643 "y.tab.c"
    break;

  case 28: /* ParamList: Param  */
#line 161 "st5.y"
                                        {
						localEntryCreate(currFunc, yyvsp[0]->name, yyvsp[0]->type,yyvsp[0]->nodetype, getArgSpace());
					}
#line 1651 "y.tab.c"
    break;

  case 29: /* ParamList: %empty  */
#line 164 "st5.y"
                                {
				yyval=NULL;}
#line 1658 "y.tab.c"
    break;

  case 30: /* Param: Type ID  */
#line 168 "st5.y"
                          {	
						yyvsp[0]->type = yyvsp[-1]->type;
						yyvsp[0]->nodetype=tVAR;
						yyval=yyvsp[0];
						}
#line 1668 "y.tab.c"
    break;

  case 31: /* Param: Type "*" ID  */
#line 173 "st5.y"
                                      {
				//+10?
				yyvsp[0]->type = yyvsp[-2]->type;
				yyvsp[0]->nodetype=tPVAR;
				yyval=yyvsp[0];
			}
#line 1679 "y.tab.c"
    break;

  case 32: /* LdeclBlock: DECL LDecList ENDDECL  */
#line 181 "st5.y"
                                 {}
#line 1685 "y.tab.c"
    break;

  case 33: /* LdeclBlock: DECL ENDDECL  */
#line 181 "st5.y"
                                                  {}
#line 1691 "y.tab.c"
    break;

  case 34: /* LDecList: LDecList LDecl ';'  */
#line 183 "st5.y"
                            {}
#line 1697 "y.tab.c"
    break;

  case 35: /* LDecList: LDecl ';'  */
#line 184 "st5.y"
                                {}
#line 1703 "y.tab.c"
    break;

  case 36: /* LDecl: Type IdList  */
#line 187 "st5.y"
                   {	
						addIdListToLocal(yyvsp[-1], yyvsp[0]);
					}
#line 1711 "y.tab.c"
    break;

  case 37: /* IdList: IdList ',' IDVar  */
#line 192 "st5.y"
                         {
				yyvsp[0]->middle =yyvsp[-2];
				yyval=yyvsp[0];
			}
#line 1720 "y.tab.c"
    break;

  case 38: /* IdList: IDVar  */
#line 196 "st5.y"
                        {yyval=yyvsp[0];}
#line 1726 "y.tab.c"
    break;

  case 40: /* IDVar: ID  */
#line 198 "st5.y"
                {
				yyvsp[0]->nodetype=tVAR;
				yyval=yyvsp[0];
			}
#line 1735 "y.tab.c"
    break;

  case 41: /* IDVar: "*" ID  */
#line 202 "st5.y"
                                {
				yyvsp[0]->nodetype=tPVAR;
				yyval=yyvsp[0];
		}
#line 1744 "y.tab.c"
    break;

  case 42: /* Body: BEG Slist Retstmt END  */
#line 208 "st5.y"
                                {
				yyval = createFuncBodyNode(yyvsp[-2], yyvsp[-1]);	//tBODY
			}
#line 1752 "y.tab.c"
    break;

  case 43: /* Retstmt: RETURN Expr ';'  */
#line 212 "st5.y"
                        {
						yyval=createRetNode(yyvsp[-1]);//type checkdone in ast
				}
#line 1760 "y.tab.c"
    break;

  case 44: /* MainBlock: Main '(' ')' '{' LdeclBlock Body '}'  */
#line 220 "st5.y"
                                                                {
									yyval = createFuncDefNode(yyvsp[-6]->type,"main",yyvsp[-1]);
									resetLocalSpace();
								}
#line 1769 "y.tab.c"
    break;

  case 45: /* Main: INT MAIN  */
#line 226 "st5.y"
               {
		currFunc=strdup("main");
		gInstall("main",intType,tFUNC,0,0,0,NULL,NULL);
		localTableCreate("main");
		yyval=yyvsp[-1];
	}
#line 1780 "y.tab.c"
    break;

  case 46: /* Slist: Slist Stmt ';'  */
#line 234 "st5.y"
                       {
		yyval = createTree(NULL,NULL, NULL,tCONNECT,NULL, yyvsp[-2],NULL, yyvsp[-1],NULL);
	}
#line 1788 "y.tab.c"
    break;

  case 47: /* Slist: Stmt ';'  */
#line 237 "st5.y"
                  {
		yyval=yyvsp[-1];
	}
#line 1796 "y.tab.c"
    break;

  case 48: /* Slist: %empty  */
#line 240 "st5.y"
         {yyval=NULL;}
#line 1802 "y.tab.c"
    break;

  case 56: /* Breakpoint: BRKP  */
#line 252 "st5.y"
                 {
	yyval = createTree(NULL,NULL, NULL,tBRKP,NULL, NULL,NULL, NULL,NULL);	
	}
#line 1810 "y.tab.c"
    break;

  case 57: /* InputStmt: READ '(' Expr ')'  */
#line 256 "st5.y"
                                        {
										yyval= createReadNode(yyvsp[-1]);
								}
#line 1818 "y.tab.c"
    break;

  case 58: /* OutputStmt: WRITE '(' Expr ')'  */
#line 260 "st5.y"
                                {	yyval= createWriteNode(yyvsp[-1]);}
#line 1824 "y.tab.c"
    break;

  case 59: /* AsgStmt: Var '=' Expr  */
#line 262 "st5.y"
                      {
					
					//checks tht exp and id have same type
					yyval = createAsgNode(yyvsp[-2], yyvsp[0]);

}
#line 1835 "y.tab.c"
    break;

  case 60: /* Var: ID  */
#line 268 "st5.y"
                                {	
						
						if(lookup(yyvsp[0]->name) != NULL){
							yyvsp[0]->entry = lookup(yyvsp[0]->name);
							if(yyvsp[0]->entry->isLoc){
								//localEntry has a nodetype for tPVAR now
								yyvsp[0]->nodetype=(yyvsp[0]->entry->localEntry)->nodetype;
								yyvsp[0]->type=(yyvsp[0]->entry->localEntry)->type;
							} else {
								//_a_=&b
								if(((yyvsp[0]->entry->globalEntry)->nodetype!=tVAR) && (yyvsp[0]->entry->globalEntry)->nodetype!=tPVAR){
									yyerror("Type mismatch: Not a variable");
								}
								yyvsp[0]->nodetype=(yyvsp[0]->entry->globalEntry)->nodetype;
								yyvsp[0]->type=(yyvsp[0]->entry->globalEntry)->type;
							}
						} else {
							yyerror("Variable undeclared\n");
						}
						yyval = yyvsp[0];
					}
#line 1861 "y.tab.c"
    break;

  case 61: /* Var: "*" ID  */
#line 289 "st5.y"
                        {		//*p=*p+1 turns to q=*p+1
						if(lookup(yyvsp[0]->name) != NULL){
							yyvsp[0]->entry = lookup(yyvsp[0]->name);							
							if(yyvsp[0]->entry->isLoc){
								if(yyvsp[0]->entry->localEntry->nodetype!=tPVAR){
									yyerror("Type mismatch: Not declared as pointer variable\n");
								}
								yyvsp[0]->type=(yyvsp[0]->entry->localEntry->type)-10;	//type says not pointer
								
							} else {
								if(yyvsp[0]->entry->globalEntry->nodetype!=tPVAR){
								yyerror("Type mismatch: Not declared as pointer variable\n");
								}
								yyvsp[0]->type=(yyvsp[0]->entry->globalEntry->type)-10;	//type says not pointer
							}
							yyvsp[0]->nodetype=tPVAR;				//nodetype says pointer
							
														
						} else {
							yyerror("Variable undeclared\n");
						}
						yyval = yyvsp[0];
		}
#line 1889 "y.tab.c"
    break;

  case 62: /* Var: ID '[' Expr ']'  */
#line 312 "st5.y"
                                 {	if(lookup(yyvsp[-3]->name) != NULL){
								yyvsp[-3]->entry = lookup(yyvsp[-3]->name);
								//will never be a local variable, not even an argument
								if((yyvsp[-3]->entry)->globalEntry->nodetype!=tARR){
									yyerror("Type mismatch: Not declared as array\n");
								}
								
								yyvsp[-3]->nodetype=tARR;
								yyvsp[-3]->type=(yyvsp[-3]->entry)->globalEntry->type;
								
								if(yyvsp[-1]->type==intType){
									if((yyvsp[-1]->nodetype==tNUM) && ( yyvsp[-1]->val >= yyvsp[-3]->entry->globalEntry->size[0])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected interger type as offset\n");
								}
								yyvsp[-3]->middle=yyvsp[-1];
							} else {
								yyerror("Variable undeclared\n");
							}				
							yyval = yyvsp[-3];
							}
#line 1917 "y.tab.c"
    break;

  case 63: /* Var: ID '[' Expr ']' '[' Expr ']'  */
#line 335 "st5.y"
                                              {
							if(lookup(yyvsp[-6]->name) != NULL){
								yyvsp[-6]->entry = lookup(yyvsp[-6]->name);
								//will never be a local variable, not even an argument
								if((yyvsp[-6]->entry)->globalEntry->nodetype!=tDARR){
									yyerror("Type mismatch: Not declared as array\n");
								}
								
								yyvsp[-6]->nodetype=tDARR;
								yyvsp[-6]->type=(yyvsp[-6]->entry)->globalEntry->type;
								
								if(yyvsp[-4]->type==intType){
									if((yyvsp[-4]->nodetype==tNUM) && ( yyvsp[-4]->val >= yyvsp[-6]->entry->globalEntry->size[0])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected interger type as offset\n");
								}
							
								if(yyvsp[-1]->type==intType){
									if((yyvsp[-1]->nodetype==tNUM) && ( yyvsp[-1]->val >= yyvsp[-6]->entry->globalEntry->size[1])){
										yyerror("Array out of bounds\n");
									}
								}
								yyvsp[-6]->right=yyvsp[-1];		
								yyval = yyvsp[-6];
							} else {
								yyerror("Variable undeclared\n");
							}	
			
		}
#line 1953 "y.tab.c"
    break;

  case 64: /* IfStmt: IF '(' Expr ')' THEN Slist ELSE Slist ENDIF  */
#line 368 "st5.y"
                                                    {
							
							yyval = createIfNode(yyvsp[-6],yyvsp[-3],yyvsp[-1]);
						}
#line 1962 "y.tab.c"
    break;

  case 65: /* IfStmt: IF '(' Expr ')' THEN Slist ENDIF  */
#line 372 "st5.y"
                                                   {
							yyval = createIfNode(yyvsp[-4],yyvsp[-1],NULL);
						}
#line 1970 "y.tab.c"
    break;

  case 66: /* WhileStmt: WHILE '(' Expr ')' DO Slist ENDWHILE  */
#line 376 "st5.y"
                                                {
							yyval = createWhileNode(yyvsp[-4],yyvsp[-1]);
							}
#line 1978 "y.tab.c"
    break;

  case 67: /* BrkContStmt: BREAK  */
#line 380 "st5.y"
                   { yyval=createBreakNode();
					}
#line 1985 "y.tab.c"
    break;

  case 68: /* BrkContStmt: CONTINUE  */
#line 382 "st5.y"
                                   {
					yyval=createContinueNode();
					}
#line 1993 "y.tab.c"
    break;

  case 69: /* Expr: Expr "+" Expr  */
#line 385 "st5.y"
                        {
							yyval = createOpNode(tADD,yyvsp[-2],yyvsp[0]);
						}
#line 2001 "y.tab.c"
    break;

  case 70: /* Expr: Expr "-" Expr  */
#line 389 "st5.y"
                                {
								yyval = createOpNode(tSUB,yyvsp[-2],yyvsp[0]);
						}
#line 2009 "y.tab.c"
    break;

  case 71: /* Expr: Expr "*" Expr  */
#line 392 "st5.y"
                                {
								yyval = createOpNode(tMUL,yyvsp[-2],yyvsp[0]);
						}
#line 2017 "y.tab.c"
    break;

  case 72: /* Expr: Expr "/" Expr  */
#line 395 "st5.y"
                                {
								yyval = createOpNode(tDIV,yyvsp[-2],yyvsp[0]);
						}
#line 2025 "y.tab.c"
    break;

  case 73: /* Expr: Expr "<" Expr  */
#line 398 "st5.y"
                                {		
								yyval = createOpNode(tLT,yyvsp[-2],yyvsp[0]);
						}
#line 2033 "y.tab.c"
    break;

  case 74: /* Expr: Expr ">" Expr  */
#line 401 "st5.y"
                                {	
								yyval = createOpNode(tGT,yyvsp[-2],yyvsp[0]);
						}
#line 2041 "y.tab.c"
    break;

  case 75: /* Expr: Expr "<=" Expr  */
#line 404 "st5.y"
                                        {
								yyval = createOpNode(tLE,yyvsp[-2],yyvsp[0]);
						}
#line 2049 "y.tab.c"
    break;

  case 76: /* Expr: Expr ">=" Expr  */
#line 407 "st5.y"
                                        {
								yyval = createOpNode(tGE,yyvsp[-2],yyvsp[0]);
						}
#line 2057 "y.tab.c"
    break;

  case 77: /* Expr: Expr "==" Expr  */
#line 410 "st5.y"
                                {
							yyval = createOpNode(tEQ,yyvsp[-2],yyvsp[0]);
						}
#line 2065 "y.tab.c"
    break;

  case 78: /* Expr: Expr "!=" Expr  */
#line 413 "st5.y"
                                {
							yyval = createOpNode(tNE,yyvsp[-2],yyvsp[0]);
						}
#line 2073 "y.tab.c"
    break;

  case 79: /* Expr: '(' Expr ')'  */
#line 416 "st5.y"
                                {yyval = yyvsp[-1];}
#line 2079 "y.tab.c"
    break;

  case 80: /* Expr: NUM  */
#line 417 "st5.y"
                                        {yyval = yyvsp[0];}
#line 2085 "y.tab.c"
    break;

  case 81: /* Expr: ID  */
#line 418 "st5.y"
                                        {	
							if(lookup(yyvsp[0]->name) != NULL){
								yyvsp[0]->entry = lookup(yyvsp[0]->name);
								//lookup creates the entry acc to where it finds the var declared
								if(yyvsp[0]->entry->isLoc){
									yyvsp[0]->type=(yyvsp[0]->entry->localEntry)->type;
									if((yyvsp[0]->entry->localEntry)->nodetype!=tVAR && (yyvsp[0]->entry->localEntry)->nodetype!=tPVAR){
										printf("%s\n",yyvsp[0]->name);
										yyerror("Type mismatch: Expected Var or PVar \n");
									}
									yyvsp[0]->nodetype=yyvsp[0]->entry->localEntry->nodetype;
								}
								else {
									yyvsp[0]->type=(yyvsp[0]->entry->globalEntry)->type;								
									if((yyvsp[0]->entry->globalEntry)->nodetype!=tVAR && (yyvsp[0]->entry->globalEntry)->nodetype!=tPVAR){
										yyerror("Type mismatch: Expected Var \n");
									}
									yyvsp[0]->nodetype=(yyvsp[0]->entry->globalEntry)->nodetype;
								}
							} else {
								printf("%s\n:",yyvsp[0]->name);
								yyerror("Variable undeclared\n");
							}
						yyval = yyvsp[0];
						}
#line 2115 "y.tab.c"
    break;

  case 82: /* Expr: "*" ID  */
#line 443 "st5.y"
                 {		
					if(lookup(yyvsp[0]->name) != NULL){
						yyvsp[0]->entry = lookup(yyvsp[0]->name);
						if(yyvsp[0]->entry->isLoc){						
							if(yyvsp[0]->entry->localEntry->nodetype==tPVAR){
								yyvsp[0]->type=(yyvsp[0]->entry->localEntry)->type-10;
								yyvsp[0]->nodetype=tDEREF;
								yyval=yyvsp[0];
							} else {
								yyerror("Type mismatch: Expected Pointer\n");
							}
						} else {
							if(yyvsp[0]->entry->globalEntry->nodetype==tPVAR){
									yyvsp[0]->type=(yyvsp[0]->entry->globalEntry)->type-10;
									yyvsp[0]->nodetype=tDEREF;
									yyval=yyvsp[0];
								} else {
									yyerror("Type mismatch: Expected Pointer\n");
								}
					
							}
					} else {
						yyerror("Variable undeclared\n");
					}
					yyval = yyvsp[0];
			}
#line 2146 "y.tab.c"
    break;

  case 83: /* Expr: '&' ID  */
#line 469 "st5.y"
                 {	
				if(lookup(yyvsp[0]->name) != NULL){
						yyvsp[0]->entry = lookup(yyvsp[0]->name);
						
						if(yyvsp[0]->entry->isLoc){						
								if(yyvsp[0]->entry->localEntry->nodetype==tVAR){
								yyvsp[0]->type=(yyvsp[0]->entry->localEntry)->type+10;
								yyvsp[0]->nodetype=tREF;
								yyval=yyvsp[0];
							} else {
								yyerror("Type mismatch: Expected Variable after &\n");
							}
						} else {
							if(yyvsp[0]->entry->globalEntry->nodetype==tVAR){
								yyvsp[0]->type=(yyvsp[0]->entry->globalEntry)->type+10;
								yyvsp[0]->nodetype=tREF;
								yyval=yyvsp[0];
							} else {
								yyerror("Type mismatch: Expected Variable after &\n");
							}
						}
					
				} else {
						yyerror("Variable undeclared\n");
					}
				yyval = yyvsp[0];
			}
#line 2178 "y.tab.c"
    break;

  case 84: /* Expr: '&' ID '[' Expr ']'  */
#line 496 "st5.y"
                              {
					if(lookup(yyvsp[-3]->name) != NULL){
						yyvsp[-3]->entry = lookup(yyvsp[-3]->name);
						//can't be local
						if(yyvsp[-3]->entry->globalEntry->nodetype==tARR){
								yyvsp[-3]->type=(yyvsp[-3]->entry->globalEntry)->type+10;
								yyvsp[-3]->nodetype=tREF;
								yyval=yyvsp[-3];
								if(yyvsp[-1]->type==intType){
									yyvsp[-3]->middle = yyvsp[-1];
									if((yyvsp[-2]->nodetype==tNUM) && ( yyvsp[-1]->val >= yyvsp[-3]->entry->globalEntry->size)){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
						} else {
								yyerror("Type mismatch: Expected Array after &\n");
						}
					} else {
							yyerror("Array undeclared\n");
						}
				yyval = yyvsp[-3];
					
	}
#line 2208 "y.tab.c"
    break;

  case 85: /* Expr: ID '[' Expr ']'  */
#line 521 "st5.y"
                          {
						if(lookup(yyvsp[-3]->name) != NULL){
								yyvsp[-3]->entry = lookup(yyvsp[-3]->name);
								//must be global
								yyvsp[-3]->type=(yyvsp[-3]->entry->globalEntry)->type;
								if((yyvsp[-3]->entry->globalEntry)->nodetype!=tARR){
									yyerror("Type mismatch: Expected Array\n");
								}
								yyvsp[-3]->nodetype=tARR;
								if(yyvsp[-1]->type==intType){
									yyvsp[-3]->middle = yyvsp[-1];
									if((yyvsp[-1]->nodetype==tNUM) && ( yyvsp[-1]->val >= yyvsp[-3]->entry->globalEntry->size)){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
								yyval=yyvsp[-3];
							} else {
								yyerror("Variable undeclared\n");
							}
	
	}
#line 2236 "y.tab.c"
    break;

  case 86: /* Expr: ID '[' Expr ']' '[' Expr ']'  */
#line 544 "st5.y"
                                       {
						if(lookup(yyvsp[-6]->name) != NULL){
								yyvsp[-6]->entry = lookup(yyvsp[-6]->name);
								yyvsp[-6]->type=(yyvsp[-6]->entry->globalEntry)->type;
								if((yyvsp[-6]->entry->globalEntry)->nodetype!=tDARR){
									yyerror("Type mismatch: Expected Double Array\n");
								}
								yyvsp[-6]->nodetype=tDARR;
								if(yyvsp[-4]->type==intType){
									yyvsp[-6]->middle = yyvsp[-4];
									if((yyvsp[-4]->nodetype==tNUM) && ( yyvsp[-4]->val >= yyvsp[-6]->entry->globalEntry->size[0])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
								if(yyvsp[-1]->type==intType){
									yyvsp[-6]->right = yyvsp[-1];
									if((yyvsp[-1]->nodetype==tNUM) && ( yyvsp[-1]->val >= yyvsp[-6]->entry->globalEntry->size[1])){
										yyerror("Array out of bounds\n");
									}
								} else {
									yyerror("Expected integer type for array offset\n");
								}
								yyval=yyvsp[-6];
							} else {
								yyerror("Variable undeclared\n");
							}
	
	}
#line 2271 "y.tab.c"
    break;

  case 87: /* Expr: LIT  */
#line 575 "st5.y"
              {yyval = yyvsp[0];}
#line 2277 "y.tab.c"
    break;

  case 88: /* Expr: ID '(' ArgList ')'  */
#line 576 "st5.y"
                              {	char *retFunc = strdup(currFunc);
							currFunc=strdup(yyvsp[-3]->name);
							yyval = createFuncCallNode(yyvsp[-3]->name,yyvsp[-1]);
							currFunc=retFunc;
							}
#line 2287 "y.tab.c"
    break;

  case 89: /* ArgList: ArgList ',' Expr  */
#line 583 "st5.y"
                          {	yyvsp[0]->arglist=yyvsp[-2];
							yyval=yyvsp[0];}
#line 2294 "y.tab.c"
    break;

  case 90: /* ArgList: Expr  */
#line 585 "st5.y"
                       {yyval=yyvsp[0];}
#line 2300 "y.tab.c"
    break;

  case 91: /* ArgList: %empty  */
#line 586 "st5.y"
                 {yyval=NULL;}
#line 2306 "y.tab.c"
    break;


#line 2310 "y.tab.c"

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
      yyerror (YY_("syntax error"));
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


#if !defined yyoverflow
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

  return yyresult;
}

#line 591 "st5.y"


int getStaticSpace(int size){
	//upto 5119
	if(staticSize+size >= 5119){
		yyerror("No space for allocation\n");
		exit(1);
	}
	staticSize+=size;
	return staticSize-size;
}

yyerror(char const *s)
{	showST();
	printf("error: %s\n",s);
	exit(1);
}

int getLocalSpace(){
	return localOffset++;
}

int getArgSpace(){
	return argOffset--;
}

void resetLocalSpace(){
	localOffset=1;
	argOffset=-3;
}
int main(int argc, char* argv[])
{
	
	extern FILE *yyin; 

	tempreg = 0;
	
	yyin = fopen("func", "r");
	fout = fopen("ous.txt", "w");
		

	yyparse();
	return 0;
}

