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
#line 1 "5_1.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "5_1.h"
	#include "5_1.c"
	int yylex(void);

#line 80 "y.tab.c"

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

#line 234 "y.tab.c"

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
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_TEXT = 4,                       /* TEXT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_PLUS = 6,                       /* PLUS  */
  YYSYMBOL_MINUS = 7,                      /* MINUS  */
  YYSYMBOL_MUL = 8,                        /* MUL  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_MOD = 10,                       /* MOD  */
  YYSYMBOL_EQ = 11,                        /* EQ  */
  YYSYMBOL_BEGIN1 = 12,                    /* BEGIN1  */
  YYSYMBOL_END = 13,                       /* END  */
  YYSYMBOL_READ = 14,                      /* READ  */
  YYSYMBOL_WRITE = 15,                     /* WRITE  */
  YYSYMBOL_POW = 16,                       /* POW  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_THEN = 19,                      /* THEN  */
  YYSYMBOL_ENDIF = 20,                     /* ENDIF  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_DO = 22,                        /* DO  */
  YYSYMBOL_ENDWHILE = 23,                  /* ENDWHILE  */
  YYSYMBOL_EQEQ = 24,                      /* EQEQ  */
  YYSYMBOL_NOTEQ = 25,                     /* NOTEQ  */
  YYSYMBOL_GREAT = 26,                     /* GREAT  */
  YYSYMBOL_GREATEQ = 27,                   /* GREATEQ  */
  YYSYMBOL_LESS = 28,                      /* LESS  */
  YYSYMBOL_LESSEQ = 29,                    /* LESSEQ  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 31,                  /* CONTINUE  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_STR = 33,                       /* STR  */
  YYSYMBOL_IDec = 34,                      /* IDec  */
  YYSYMBOL_Varlist = 35,                   /* Varlist  */
  YYSYMBOL_LDECL = 36,                     /* LDECL  */
  YYSYMBOL_LENDDECL = 37,                  /* LENDDECL  */
  YYSYMBOL_GIDec = 38,                     /* GIDec  */
  YYSYMBOL_MAIN = 39,                      /* MAIN  */
  YYSYMBOL_RET = 40,                       /* RET  */
  YYSYMBOL_PID = 41,                       /* PID  */
  YYSYMBOL_LIDec = 42,                     /* LIDec  */
  YYSYMBOL_IdList = 43,                    /* IdList  */
  YYSYMBOL_GDeclBlock = 44,                /* GDeclBlock  */
  YYSYMBOL_FID = 45,                       /* FID  */
  YYSYMBOL_GDECL = 46,                     /* GDECL  */
  YYSYMBOL_GENDDECL = 47,                  /* GENDDECL  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_49_ = 49,                       /* ';'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_Program = 57,                   /* Program  */
  YYSYMBOL_GdeclBlock = 58,                /* GdeclBlock  */
  YYSYMBOL_GdeclList = 59,                 /* GdeclList  */
  YYSYMBOL_GDecl = 60,                     /* GDecl  */
  YYSYMBOL_GidList = 61,                   /* GidList  */
  YYSYMBOL_Gid = 62,                       /* Gid  */
  YYSYMBOL_FdefBlock = 63,                 /* FdefBlock  */
  YYSYMBOL_Fdef = 64,                      /* Fdef  */
  YYSYMBOL_MainBlock = 65,                 /* MainBlock  */
  YYSYMBOL_ParamList = 66,                 /* ParamList  */
  YYSYMBOL_Param = 67,                     /* Param  */
  YYSYMBOL_LdeclBlock = 68,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 69,                  /* LDecList  */
  YYSYMBOL_LDecl = 70,                     /* LDecl  */
  YYSYMBOL_LidList = 71,                   /* LidList  */
  YYSYMBOL_Type = 72,                      /* Type  */
  YYSYMBOL_Body = 73,                      /* Body  */
  YYSYMBOL_Slist = 74,                     /* Slist  */
  YYSYMBOL_stmt = 75,                      /* stmt  */
  YYSYMBOL_input = 76,                     /* input  */
  YYSYMBOL_output = 77,                    /* output  */
  YYSYMBOL_asgn = 78,                      /* asgn  */
  YYSYMBOL_retstmt = 79,                   /* retstmt  */
  YYSYMBOL_ifstmt = 80,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 81,                 /* whilestmt  */
  YYSYMBOL_ArgList = 82,                   /* ArgList  */
  YYSYMBOL_var = 83,                       /* var  */
  YYSYMBOL_expr = 84                       /* expr  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   534

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  233

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      51,    52,     2,     2,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    49,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    36,    37,    39,    40,    42,    42,    44,
      46,    46,    48,    49,    50,    54,    54,    56,   116,   161,
     195,   230,   278,   317,   318,   321,   323,   324,   326,   326,
     328,   330,   330,   332,   333,   338,   339,   342,   343,   345,
     345,   345,   346,   346,   347,   348,   350,   352,   353,   355,
     356,   358,   359,   361,   362,   364,   366,   367,   368,   369,
     370,   371,   373,   374,   375,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   429,   430,   431,   432,   433,   434
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "TEXT", "ID",
  "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "BEGIN1", "END", "READ",
  "WRITE", "POW", "IF", "ELSE", "THEN", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "EQEQ", "NOTEQ", "GREAT", "GREATEQ", "LESS", "LESSEQ", "BREAK",
  "CONTINUE", "INT", "STR", "IDec", "Varlist", "LDECL", "LENDDECL",
  "GIDec", "MAIN", "RET", "PID", "LIDec", "IdList", "GDeclBlock", "FID",
  "GDECL", "GENDDECL", "'['", "';'", "','", "'('", "')'", "'{'", "'}'",
  "']'", "$accept", "Program", "GdeclBlock", "GdeclList", "GDecl",
  "GidList", "Gid", "FdefBlock", "Fdef", "MainBlock", "ParamList", "Param",
  "LdeclBlock", "LDecList", "LDecl", "LidList", "Type", "Body", "Slist",
  "stmt", "input", "output", "asgn", "retstmt", "ifstmt", "whilestmt",
  "ArgList", "var", "expr", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    91,    59,
      44,    40,    41,   123,   125,    93
};
#endif

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      60,  -171,  -171,    -7,    15,    88,  -171,     5,  -171,    66,
    -171,    -1,  -171,    88,  -171,  -171,    56,    24,  -171,  -171,
      46,   133,  -171,  -171,  -171,    49,    84,   -16,  -171,    -1,
       0,    -4,  -171,   150,  -171,   110,  -171,    99,   161,    -2,
      88,  -171,  -171,    -2,   109,   164,    72,   156,   144,  -171,
     156,   147,    -2,  -171,   135,   165,   172,   174,   166,   179,
       9,   164,  -171,   185,   203,   204,   217,   205,   206,    -3,
    -171,   134,  -171,   215,   207,  -171,   216,  -171,   156,   218,
     253,     9,     9,     9,  -171,  -171,  -171,  -171,     9,   385,
     441,  -171,   247,  -171,  -171,  -171,  -171,  -171,  -171,     9,
       9,  -171,  -171,  -171,   143,  -171,  -171,   219,  -171,   132,
     211,   269,   413,   298,   327,   356,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,  -171,    51,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,  -171,  -171,   413,   505,   148,    -5,  -171,   229,
    -171,  -171,  -171,  -171,   262,   260,  -171,   102,   106,   102,
     106,   264,   107,   264,   107,   -10,   268,    11,  -171,   235,
     322,   235,   322,   235,   322,   235,   322,   235,   322,   235,
     322,  -171,   162,   181,   240,   102,   106,   102,   106,   264,
     107,   264,   107,   -10,   268,    11,  -171,   235,   322,   235,
     322,   235,   322,   235,   322,   235,   322,   235,   322,  -171,
    -171,  -171,   479,   479,     9,  -171,     9,  -171,     9,  -171,
     457,   468,   413,   505,   413,   505,   413,   505,   479,  -171,
    -171,   487,  -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    33,    34,     0,     0,     0,     4,     0,     6,     0,
       8,     0,     1,     0,    16,     3,     0,     0,     5,     7,
      12,     0,    11,    15,     2,     0,     0,     0,     9,     0,
       0,     0,    14,     0,    24,     0,    10,     0,     0,     0,
       0,    13,    25,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    29,     0,     0,    22,     0,    20,     0,     0,
       0,     0,     0,     0,    44,    45,   118,   119,     0,     0,
       0,    37,     0,    39,    40,    41,    36,    42,    43,     0,
       0,    26,    28,    32,     0,    21,    18,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    35,    50,    49,     0,     0,    30,     0,
      17,    46,    48,    47,     0,     0,    77,   102,    78,   103,
      79,   104,    80,   105,    81,   106,    82,   107,    83,   113,
      89,   112,    88,   109,    85,   111,    87,   108,    84,   110,
      86,   114,     0,     0,     0,    90,    65,    91,    66,    92,
      67,    93,    68,    94,    69,    95,    70,   101,    76,   100,
      75,    97,    72,    99,    74,    96,    71,    98,    73,    63,
      64,    31,     0,     0,     0,   115,     0,   116,     0,   117,
       0,     0,    60,    61,    56,    58,    57,    59,     0,    54,
      55,     0,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,   278,  -171,   259,  -171,   276,    26,
     261,   263,   -34,  -171,   228,  -171,    48,   266,  -170,   -61,
    -171,  -171,  -171,   239,  -171,  -171,  -171,   -53,     8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     9,    10,    21,    22,    13,    14,     6,
      33,    34,    47,    71,    72,   104,    35,    48,    61,    62,
      63,    64,    65,    66,    67,    68,   182,    69,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      91,   130,   131,   132,   133,   134,   121,    89,    99,    50,
      45,   135,    86,    87,    53,    12,     1,     2,    78,   136,
     137,   138,   139,   140,   141,     1,     2,   109,   110,   112,
     112,    15,     1,     2,    46,   112,    32,    20,   100,    24,
       8,   129,   220,   221,    17,   100,   144,   146,     7,    39,
     210,    11,    37,    16,    86,    87,    53,    11,   231,   100,
      88,    16,   129,   157,   159,   161,   163,   165,   167,   169,
     171,   173,   175,   177,   179,    26,   183,   185,   187,   189,
     191,   193,   195,   197,   199,   201,   203,   205,   207,   111,
     113,   114,     1,     2,    73,    17,   115,    27,     1,     2,
      30,    25,    88,   181,     1,     2,     3,   145,   147,    70,
     118,   119,   120,    18,   132,   133,   134,   134,   121,    73,
       1,     2,   135,   135,   158,   160,   162,   164,   166,   168,
     170,   172,   174,   176,   178,   180,    31,   184,   186,   188,
     190,   192,   194,   196,   198,   200,   202,   204,   206,   208,
     100,    42,    43,   129,   116,   117,   118,   119,   120,    91,
      91,   222,    52,   224,   121,   226,     1,     2,    45,    53,
      91,   101,   122,   123,   124,   125,   126,   127,    54,    55,
     100,    56,    28,    29,   151,    57,    80,   116,   117,   118,
     119,   120,   148,   149,    58,    59,   100,   121,    75,   129,
      40,    77,    41,   209,    60,   122,   123,   124,   125,   126,
     127,    40,   214,    44,   215,    84,    81,   116,   117,   118,
     119,   120,   223,    82,   225,    83,   227,   121,    85,   100,
      96,   216,   129,   217,    93,   122,   123,   124,   125,   126,
     127,   116,   117,   118,   119,   120,   130,   131,   132,   133,
     134,   121,    94,    95,    97,    98,   135,   103,    53,   100,
     143,   105,   129,   152,   136,   137,   138,   139,   140,   141,
     106,   211,   108,   150,   120,   130,   131,   132,   133,   134,
     121,   212,   213,   100,   135,   135,   129,    19,    36,    23,
     218,    38,   219,   136,   137,   138,   139,   140,   141,   102,
      92,     0,     0,    49,   130,   131,   132,   133,   134,    51,
       0,     0,   100,    74,   135,   129,    76,     0,    79,     0,
       0,   153,   136,   137,   138,   139,   140,   141,   130,   131,
     132,   133,   134,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,   135,   107,     0,     0,     0,     0,     0,
     154,   136,   137,   138,   139,   140,   141,     0,     0,     0,
       0,     0,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,   135,     0,     0,     0,     0,     0,     0,   155,
     136,   137,   138,   139,   140,   141,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,   121,     0,     0,     0,     0,     0,     0,   156,   122,
     123,   124,   125,   126,   127,     0,     0,     0,     0,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   100,   128,     0,   129,   122,   123,   124,
     125,   126,   127,     0,     0,     0,     0,   130,   131,   132,
     133,   134,     0,     0,     0,     0,     0,   135,     0,     0,
       0,   100,    53,     0,   129,   136,   137,   138,   139,   140,
     141,    54,    55,    53,    56,   228,     0,   229,    57,     0,
       0,     0,    54,    55,    53,    56,     0,    58,    59,    57,
     142,   230,    53,    54,    55,     0,    56,     0,    58,    59,
      57,    54,    55,     0,    56,     0,     0,   232,    57,    58,
      59,   130,   131,   132,   133,   134,     0,    58,    59,     0,
       0,   135,     0,     0,     0,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   141
};

static const yytype_int16 yycheck[] =
{
      61,     6,     7,     8,     9,    10,    16,    60,    11,    43,
      12,    16,     3,     4,     5,     0,    32,    33,    52,    24,
      25,    26,    27,    28,    29,    32,    33,    80,    81,    82,
      83,     5,    32,    33,    36,    88,    52,    38,    48,    13,
      47,    51,   212,   213,    39,    48,    99,   100,     0,    53,
      55,     3,    52,     5,     3,     4,     5,     9,   228,    48,
      51,    13,    51,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,    51,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    81,
      82,    83,    32,    33,    46,    39,    88,    51,    32,    33,
      51,    45,    51,    52,    32,    33,    46,    99,   100,    37,
       8,     9,    10,    47,     8,     9,    10,    10,    16,    71,
      32,    33,    16,    16,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    52,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      48,    41,    53,    51,     6,     7,     8,     9,    10,   220,
     221,   214,    53,   216,    16,   218,    32,    33,    12,     5,
     231,    37,    24,    25,    26,    27,    28,    29,    14,    15,
      48,    17,    49,    50,    52,    21,    51,     6,     7,     8,
       9,    10,    49,    50,    30,    31,    48,    16,    54,    51,
      50,    54,    52,    55,    40,    24,    25,    26,    27,    28,
      29,    50,    50,    52,    52,    49,    51,     6,     7,     8,
       9,    10,   214,    51,   216,    51,   218,    16,    49,    48,
      13,    50,    51,    52,    49,    24,    25,    26,    27,    28,
      29,     6,     7,     8,     9,    10,     6,     7,     8,     9,
      10,    16,    49,    49,    49,    49,    16,    42,     5,    48,
      13,    54,    51,    52,    24,    25,    26,    27,    28,    29,
      54,    42,    54,    54,    10,     6,     7,     8,     9,    10,
      16,    19,    22,    48,    16,    16,    51,     9,    29,    13,
      50,    30,    52,    24,    25,    26,    27,    28,    29,    71,
      61,    -1,    -1,    40,     6,     7,     8,     9,    10,    43,
      -1,    -1,    48,    47,    16,    51,    50,    -1,    52,    -1,
      -1,    52,    24,    25,    26,    27,    28,    29,     6,     7,
       8,     9,    10,     6,     7,     8,     9,    10,    16,    -1,
      -1,    -1,    -1,    16,    78,    -1,    -1,    -1,    -1,    -1,
      52,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    52,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    48,    49,    -1,    51,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    48,     5,    -1,    51,    24,    25,    26,    27,    28,
      29,    14,    15,     5,    17,    18,    -1,    20,    21,    -1,
      -1,    -1,    14,    15,     5,    17,    -1,    30,    31,    21,
      49,    23,     5,    14,    15,    -1,    17,    -1,    30,    31,
      21,    14,    15,    -1,    17,    -1,    -1,    20,    21,    30,
      31,     6,     7,     8,     9,    10,    -1,    30,    31,    -1,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    33,    46,    57,    58,    65,    72,    47,    59,
      60,    72,     0,    63,    64,    65,    72,    39,    47,    60,
      38,    61,    62,    64,    65,    45,    51,    51,    49,    50,
      51,    52,    52,    66,    67,    72,    62,    52,    66,    53,
      50,    52,    41,    53,    52,    12,    36,    68,    73,    67,
      68,    73,    53,     5,    14,    15,    17,    21,    30,    31,
      40,    74,    75,    76,    77,    78,    79,    80,    81,    83,
      37,    69,    70,    72,    73,    54,    73,    54,    68,    73,
      51,    51,    51,    51,    49,    49,     3,     4,    51,    83,
      84,    75,    79,    49,    49,    49,    13,    49,    49,    11,
      48,    37,    70,    42,    71,    54,    54,    73,    54,    83,
      83,    84,    83,    84,    84,    84,     6,     7,     8,     9,
      10,    16,    24,    25,    26,    27,    28,    29,    49,    51,
       6,     7,     8,     9,    10,    16,    24,    25,    26,    27,
      28,    29,    49,    13,    83,    84,    83,    84,    49,    50,
      54,    52,    52,    52,    52,    52,    52,    83,    84,    83,
      84,    83,    84,    83,    84,    83,    84,    83,    84,    83,
      84,    83,    84,    83,    84,    83,    84,    83,    84,    83,
      84,    52,    82,    83,    84,    83,    84,    83,    84,    83,
      84,    83,    84,    83,    84,    83,    84,    83,    84,    83,
      84,    83,    84,    83,    84,    83,    84,    83,    84,    55,
      55,    42,    19,    22,    50,    52,    50,    52,    50,    52,
      74,    74,    83,    84,    83,    84,    83,    84,    18,    20,
      23,    74,    20
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    57,    57,    58,    58,    59,    59,    60,
      61,    61,    62,    62,    62,    63,    63,    64,    64,    64,
      64,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    82,    82,    82,    82,
      82,    82,    83,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       3,     1,     1,     4,     3,     2,     1,     9,     8,     8,
       7,     8,     7,     3,     1,     2,     3,     2,     2,     1,
       3,     3,     1,     1,     1,     4,     3,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     4,     4,     4,     3,
       3,     3,     3,     9,     7,     7,     3,     3,     3,     3,
       3,     3,     1,     4,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     4,     4,     1,     1
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
  case 2: /* Program: GdeclBlock FdefBlock MainBlock  */
#line 35 "5_1.y"
                                                        {printf("Program done\n");}
#line 1508 "y.tab.c"
    break;

  case 3: /* Program: GdeclBlock MainBlock  */
#line 36 "5_1.y"
                                                                        {printf("Program done\n");}
#line 1514 "y.tab.c"
    break;

  case 4: /* Program: MainBlock  */
#line 37 "5_1.y"
                                                                                {printf("Program done\n");}
#line 1520 "y.tab.c"
    break;

  case 5: /* GdeclBlock: GDECL GdeclList GENDDECL  */
#line 39 "5_1.y"
                                                        {gdisplay();printf("--------------------Global done--------------------\n");(yyval.no)=(yyvsp[-2].no);}
#line 1526 "y.tab.c"
    break;

  case 13: /* Gid: GIDec '(' ParamList ')'  */
#line 49 "5_1.y"
                                                        {(yyval.gs)= Appendgparam((yyvsp[-3].gs),(yyvsp[-1].pr));}
#line 1532 "y.tab.c"
    break;

  case 14: /* Gid: GIDec '(' ')'  */
#line 50 "5_1.y"
                                                                        {(yyval.gs)= Appendgparam((yyvsp[-2].gs),NULL);}
#line 1538 "y.tab.c"
    break;

  case 17: /* Fdef: Type FID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 57 "5_1.y"
                                                                                {	
											struct Paramstruct *p=getparam((yyvsp[-7].no)->text);
											if(!checkparamlist((yyvsp[-5].pr),p)){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=lroot;
											proot=(yyvsp[-5].pr);
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-7].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-7].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel((yyvsp[-7].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											struct Lsymbol *l=(yyvsp[-1].no)->Lentry;
											struct Paramstruct *par=(yyvsp[-5].pr);
											int y=getreg();
											if(par==NULL || l==NULL){
												printf("Parameterlist is NULL\n");
												exit(1);
											}
											else if(par!=NULL && l!=NULL){
												while(p->next!=NULL){
													p=p->next;
													l=l->next;
												}
												if(l->next==NULL){
													printf("Nothing in local declaration block\n");
													exit(1);
												}
												else
													l=l->next;
												while(l->next!=NULL){
													fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
													l=l->next;
												}
												fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++;
											}
											freereg();
											setlocalbinding((yyvsp[-5].pr),(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											printf("-------------------function %s done------------------\n",(yyvsp[-7].no)->text);
										}
#line 1602 "y.tab.c"
    break;

  case 18: /* Fdef: Type FID '(' ')' '{' LdeclBlock Body '}'  */
#line 117 "5_1.y"
                                                                                {
											struct Paramstruct *p=getparam((yyvsp[-6].no)->text);
											if(p!=NULL){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=lroot;
											proot=NULL;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-6].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-6].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel((yyvsp[-6].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											if((yyvsp[-1].no)->Lentry!=NULL){
												struct Lsymbol *l=(yyvsp[-1].no)->Lentry;
												int y=getreg();
												while(l->next!=NULL){
													fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; //empty space
													l=l->next;
												}
												fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
												freereg();
											}
											setlocalbinding(NULL,(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											lvar=0;
											printf("-------------------function %s done------------------\n",(yyvsp[-6].no)->text);
										}
#line 1651 "y.tab.c"
    break;

  case 19: /* Fdef: Type FID '(' ParamList ')' '{' Body '}'  */
#line 162 "5_1.y"
                                                                                {
											struct Paramstruct *p=getparam((yyvsp[-6].no)->text);
											if(!checkparamlist((yyvsp[-4].pr),p)){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=lroot;
											proot=(yyvsp[-4].pr);
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-6].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-6].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel((yyvsp[-6].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											setlocalbinding((yyvsp[-4].pr),(yyvsp[-1].no)->Lentry);
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",(yyvsp[-6].no)->text);
										}
#line 1689 "y.tab.c"
    break;

  case 20: /* Fdef: Type FID '(' ')' '{' Body '}'  */
#line 196 "5_1.y"
                                                                                {
											struct Paramstruct *p=getparam((yyvsp[-5].no)->text);
											if(p!=NULL){
												printf("Function parameters don't match with the declaration\n");
												exit(1);
											}
											(yyvsp[-1].no)->Lentry=NULL;
											proot=NULL;
											fname=(char*)malloc(sizeof(char));
											strcpy(fname,(yyvsp[-5].no)->text);
											strcpy((yyvsp[-1].no)->varname,(yyvsp[-5].no)->text);
											(yyvsp[-1].no)->right->Lentry=lroot;
											ldisplay();
											lroot=NULL;
											(yyval.no)=(yyvsp[-1].no);
											printf("Codegen start\n");
											FILE *fptr = fopen("target.xsm", "a");
											if(beginflag==1){
												fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												fprintf(fptr, "JMP MAIN\n");pos++;
												beginflag=0;
											}
											int f=getflabel((yyvsp[-5].no)->text);
											fprintf(fptr,"F%d:\n",f);
											func[f]=2*pos+2056;
											fprintf(fptr, "PUSH BP\n");pos++;
											fprintf(fptr, "MOV BP, SP\n");pos++;
											codegen((yyvsp[-1].no),fptr);
											fclose(fptr);
											k=-1;
											printf("-------------------function %s done------------------\n",(yyvsp[-5].no)->text);
										}
#line 1726 "y.tab.c"
    break;

  case 21: /* MainBlock: Type MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 231 "5_1.y"
                                                {
                     						 (yyvsp[-1].no)->Lentry=lroot;
                     						 fname=(char*)malloc(sizeof(char));
                     						 strcpy(fname,"main");
                                   			 (yyval.no)=(yyvsp[-1].no);
                                   			 ldisplay();
                                   			 printf("Codegen start\n");
											 FILE *fptr = fopen("target.xsm", "a");
											 if(beginflag==1){
												 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
												 beginflag=0;
											 }
											 fprintf(fptr,"MAIN:\n");
											 mainl=2*pos+2056;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 if((yyvsp[-1].no)->Lentry!=NULL){
											 	struct Lsymbol *l=(yyvsp[-1].no)->Lentry;
											 	int y=getreg();
											 	while(l->next!=NULL){
													 fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; //empty space
												 	l=l->next;
											 	}
											 	fprintf(fptr, "PUSH R%d\n",y);pos++;lvar++; 
											 	freereg();
											 }
											 setlocalbinding(NULL,(yyvsp[-1].no)->Lentry);
											 codegen((yyvsp[-1].no),fptr);
											 fprintf(fptr, "PASS");pos++;
											 fclose(fptr);
											 k=-1;
											 FILE *fptr2 = fopen("array.c", "w");
											 fprintf(fptr2,"int a[100]={");
											 for(int i=0;i<r;i++){
												 if(i==0)
												 	 fprintf(fptr2,"%d",a[i]);
												 else
													 fprintf(fptr2,",%d",a[i]);
											 }
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int f[100]={0");
											 for(int i=1;i<flabel;i++)
												 fprintf(fptr2,",%d",func[i]);
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int mainl=%d;",mainl);
                                   			 printf("--------------------Main done-----------------------\n");
                                		}
#line 1777 "y.tab.c"
    break;

  case 22: /* MainBlock: Type MAIN '(' ')' '{' Body '}'  */
#line 279 "5_1.y"
                                                {
                     						 (yyvsp[-1].no)->Lentry=lroot;
                     						 fname=(char*)malloc(sizeof(char));
                     						 strcpy(fname,"main");
                                   			 (yyval.no)=(yyvsp[-1].no);
                                   			 ldisplay();
                                   			 printf("Codegen start\n");
											 FILE *fptr = fopen("target.xsm", "a");
											 if(beginflag==1){
												 fprintf(fptr, "MOV SP, %d\n", idaddr);pos++;
											 	 beginflag=0;
											 }
											 fprintf(fptr,"MAIN:\n");
											 mainl=2*pos+2056;
											 fprintf(fptr, "MOV BP, SP\n");pos++;
											 codegen((yyvsp[-1].no),fptr);
											 fprintf(fptr, "PASS");pos++;
											 fclose(fptr);
											 k=-1;
											 FILE *fptr2 = fopen("array.c", "w");
											 fprintf(fptr2,"int a[100]={");
											 for(int i=0;i<r;i++){
												 if(i==0)
												 	 fprintf(fptr2,"%d",a[i]);
												 else
													 fprintf(fptr2,",%d",a[i]);
											 }
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int f[100]={0");
											 for(int i=1;i<flabel;i++)
												 fprintf(fptr2,",%d",func[i]);
											 fprintf(fptr2,"};\n");
											 fprintf(fptr2,"int mainl=%d;",mainl);
                                   			 printf("--------------------Main done-----------------------\n");
                                		}
#line 1817 "y.tab.c"
    break;

  case 23: /* ParamList: ParamList ',' Param  */
#line 317 "5_1.y"
                                                        {(yyval.pr) = Appendparam((yyvsp[-2].pr),(yyvsp[0].pr));}
#line 1823 "y.tab.c"
    break;

  case 24: /* ParamList: Param  */
#line 318 "5_1.y"
                                                                                {(yyval.pr) = (yyvsp[0].pr);}
#line 1829 "y.tab.c"
    break;

  case 25: /* Param: Type PID  */
#line 321 "5_1.y"
                                                                        {(yyval.pr)=(yyvsp[0].pr);}
#line 1835 "y.tab.c"
    break;

  case 35: /* Body: BEGIN1 Slist retstmt END  */
#line 338 "5_1.y"
                                        {(yyval.no)=makenode("filledlater",12,-1,NULL,(yyvsp[-2].no),NULL,(yyvsp[-1].no));}
#line 1841 "y.tab.c"
    break;

  case 36: /* Body: BEGIN1 retstmt END  */
#line 339 "5_1.y"
                                                {printf("Nothing inside body\n");exit(1);}
#line 1847 "y.tab.c"
    break;

  case 37: /* Slist: Slist stmt  */
#line 342 "5_1.y"
                                                        {(yyval.no) = makenode("connector",3,-1,NULL,(yyvsp[-1].no),NULL,(yyvsp[0].no));}
#line 1853 "y.tab.c"
    break;

  case 44: /* stmt: BREAK ';'  */
#line 347 "5_1.y"
                                                        {(yyval.no)=(yyvsp[-1].no);}
#line 1859 "y.tab.c"
    break;

  case 45: /* stmt: CONTINUE ';'  */
#line 348 "5_1.y"
                                                {(yyval.no)=(yyvsp[-1].no);}
#line 1865 "y.tab.c"
    break;

  case 46: /* input: READ '(' var ')'  */
#line 350 "5_1.y"
                                        {(yyval.no) = makenode("read",1,-1,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 1871 "y.tab.c"
    break;

  case 47: /* output: WRITE '(' expr ')'  */
#line 352 "5_1.y"
                                        {(yyval.no) = makenode("write",2,-1,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 1877 "y.tab.c"
    break;

  case 48: /* output: WRITE '(' var ')'  */
#line 353 "5_1.y"
                                            {(yyval.no) = makenode("write",2,-1,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 1883 "y.tab.c"
    break;

  case 49: /* asgn: var EQ expr  */
#line 355 "5_1.y"
                                        {(yyval.no) = makenode("=",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1889 "y.tab.c"
    break;

  case 50: /* asgn: var EQ var  */
#line 356 "5_1.y"
                                            {(yyval.no) = makenode("=",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1895 "y.tab.c"
    break;

  case 51: /* retstmt: RET expr ';'  */
#line 358 "5_1.y"
                                    {(yyval.no) = makenode("return",11,2,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 1901 "y.tab.c"
    break;

  case 52: /* retstmt: RET var ';'  */
#line 359 "5_1.y"
                                                        {(yyval.no) = makenode("return",11,2,NULL,(yyvsp[-1].no),NULL,NULL);}
#line 1907 "y.tab.c"
    break;

  case 53: /* ifstmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF  */
#line 361 "5_1.y"
                                                            {(yyval.no)= makenode("ifelse",6,-1,NULL,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 1913 "y.tab.c"
    break;

  case 54: /* ifstmt: IF '(' expr ')' THEN Slist ENDIF  */
#line 362 "5_1.y"
                                                                        {(yyval.no)= makenode("if",6,-1,NULL,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 1919 "y.tab.c"
    break;

  case 55: /* whilestmt: WHILE '(' expr ')' DO Slist ENDWHILE  */
#line 364 "5_1.y"
                                                                {(yyval.no)= makenode("while",5,-1,NULL,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 1925 "y.tab.c"
    break;

  case 56: /* ArgList: var ',' var  */
#line 366 "5_1.y"
                                        {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 1931 "y.tab.c"
    break;

  case 57: /* ArgList: expr ',' var  */
#line 367 "5_1.y"
                                                {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 1937 "y.tab.c"
    break;

  case 58: /* ArgList: var ',' expr  */
#line 368 "5_1.y"
                                                {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 1943 "y.tab.c"
    break;

  case 59: /* ArgList: expr ',' expr  */
#line 369 "5_1.y"
                                                {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 1949 "y.tab.c"
    break;

  case 60: /* ArgList: ArgList ',' var  */
#line 370 "5_1.y"
                                        {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 1955 "y.tab.c"
    break;

  case 61: /* ArgList: ArgList ',' expr  */
#line 371 "5_1.y"
                                        {(yyval.no) = argconnect((yyvsp[-2].no),(yyvsp[0].no));}
#line 1961 "y.tab.c"
    break;

  case 63: /* var: var '[' var ']'  */
#line 374 "5_1.y"
                                                {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,2,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 1967 "y.tab.c"
    break;

  case 64: /* var: var '[' expr ']'  */
#line 375 "5_1.y"
                                    {(yyval.no) = makearraynode((yyvsp[-3].no)->varname,2,(yyvsp[-3].no)->type,(yyvsp[-1].no));}
#line 1973 "y.tab.c"
    break;

  case 65: /* expr: expr PLUS expr  */
#line 377 "5_1.y"
                                        {(yyval.no) = makenode("+",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1979 "y.tab.c"
    break;

  case 66: /* expr: expr MINUS expr  */
#line 378 "5_1.y"
                                                {(yyval.no) = makenode("-",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1985 "y.tab.c"
    break;

  case 67: /* expr: expr MUL expr  */
#line 379 "5_1.y"
                                                {(yyval.no) = makenode("*",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1991 "y.tab.c"
    break;

  case 68: /* expr: expr DIV expr  */
#line 380 "5_1.y"
                                                {(yyval.no) = makenode("/",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 1997 "y.tab.c"
    break;

  case 69: /* expr: expr MOD expr  */
#line 381 "5_1.y"
                                                {(yyval.no) = makenode("%",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2003 "y.tab.c"
    break;

  case 70: /* expr: expr POW expr  */
#line 382 "5_1.y"
                                        {(yyval.no) = makenode("@",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2009 "y.tab.c"
    break;

  case 71: /* expr: expr LESS expr  */
#line 383 "5_1.y"
                                                {(yyval.no) = makenode("<",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2015 "y.tab.c"
    break;

  case 72: /* expr: expr GREAT expr  */
#line 384 "5_1.y"
                                                {(yyval.no) = makenode(">",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2021 "y.tab.c"
    break;

  case 73: /* expr: expr LESSEQ expr  */
#line 385 "5_1.y"
                                                {(yyval.no) = makenode("<=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2027 "y.tab.c"
    break;

  case 74: /* expr: expr GREATEQ expr  */
#line 386 "5_1.y"
                                        {(yyval.no) = makenode(">=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2033 "y.tab.c"
    break;

  case 75: /* expr: expr NOTEQ expr  */
#line 387 "5_1.y"
                                                {(yyval.no) = makenode("!=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2039 "y.tab.c"
    break;

  case 76: /* expr: expr EQEQ expr  */
#line 388 "5_1.y"
                                        {(yyval.no) = makenode("==",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2045 "y.tab.c"
    break;

  case 77: /* expr: '(' expr ')'  */
#line 389 "5_1.y"
                                                {(yyval.no) = (yyvsp[-1].no);}
#line 2051 "y.tab.c"
    break;

  case 78: /* expr: var PLUS expr  */
#line 390 "5_1.y"
                                                {(yyval.no) = makenode("+",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2057 "y.tab.c"
    break;

  case 79: /* expr: var MINUS expr  */
#line 391 "5_1.y"
                                                {(yyval.no) = makenode("-",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2063 "y.tab.c"
    break;

  case 80: /* expr: var MUL expr  */
#line 392 "5_1.y"
                                                {(yyval.no) = makenode("*",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2069 "y.tab.c"
    break;

  case 81: /* expr: var DIV expr  */
#line 393 "5_1.y"
                                                {(yyval.no) = makenode("/",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2075 "y.tab.c"
    break;

  case 82: /* expr: var MOD expr  */
#line 394 "5_1.y"
                                                {(yyval.no) = makenode("%",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2081 "y.tab.c"
    break;

  case 83: /* expr: var POW expr  */
#line 395 "5_1.y"
                                        {(yyval.no) = makenode("@",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2087 "y.tab.c"
    break;

  case 84: /* expr: var LESS expr  */
#line 396 "5_1.y"
                                                {(yyval.no) = makenode("<",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2093 "y.tab.c"
    break;

  case 85: /* expr: var GREAT expr  */
#line 397 "5_1.y"
                                                {(yyval.no) = makenode(">",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2099 "y.tab.c"
    break;

  case 86: /* expr: var LESSEQ expr  */
#line 398 "5_1.y"
                                                {(yyval.no) = makenode("<=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2105 "y.tab.c"
    break;

  case 87: /* expr: var GREATEQ expr  */
#line 399 "5_1.y"
                                        {(yyval.no) = makenode(">=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2111 "y.tab.c"
    break;

  case 88: /* expr: var NOTEQ expr  */
#line 400 "5_1.y"
                                                {(yyval.no) = makenode("!=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2117 "y.tab.c"
    break;

  case 89: /* expr: var EQEQ expr  */
#line 401 "5_1.y"
                                        {(yyval.no) = makenode("==",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2123 "y.tab.c"
    break;

  case 90: /* expr: expr PLUS var  */
#line 403 "5_1.y"
                                                {(yyval.no) = makenode("+",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2129 "y.tab.c"
    break;

  case 91: /* expr: expr MINUS var  */
#line 404 "5_1.y"
                                                {(yyval.no) = makenode("-",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2135 "y.tab.c"
    break;

  case 92: /* expr: expr MUL var  */
#line 405 "5_1.y"
                                                {(yyval.no) = makenode("*",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2141 "y.tab.c"
    break;

  case 93: /* expr: expr DIV var  */
#line 406 "5_1.y"
                                                {(yyval.no) = makenode("/",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2147 "y.tab.c"
    break;

  case 94: /* expr: expr MOD var  */
#line 407 "5_1.y"
                                                {(yyval.no) = makenode("%",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2153 "y.tab.c"
    break;

  case 95: /* expr: expr POW var  */
#line 408 "5_1.y"
                                        {(yyval.no) = makenode("@",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2159 "y.tab.c"
    break;

  case 96: /* expr: expr LESS var  */
#line 409 "5_1.y"
                                                {(yyval.no) = makenode("<",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2165 "y.tab.c"
    break;

  case 97: /* expr: expr GREAT var  */
#line 410 "5_1.y"
                                                {(yyval.no) = makenode(">",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2171 "y.tab.c"
    break;

  case 98: /* expr: expr LESSEQ var  */
#line 411 "5_1.y"
                                                {(yyval.no) = makenode("<=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2177 "y.tab.c"
    break;

  case 99: /* expr: expr GREATEQ var  */
#line 412 "5_1.y"
                                        {(yyval.no) = makenode(">=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2183 "y.tab.c"
    break;

  case 100: /* expr: expr NOTEQ var  */
#line 413 "5_1.y"
                                                {(yyval.no) = makenode("!=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2189 "y.tab.c"
    break;

  case 101: /* expr: expr EQEQ var  */
#line 414 "5_1.y"
                                        {(yyval.no) = makenode("==",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2195 "y.tab.c"
    break;

  case 102: /* expr: var PLUS var  */
#line 416 "5_1.y"
                                                {(yyval.no) = makenode("+",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2201 "y.tab.c"
    break;

  case 103: /* expr: var MINUS var  */
#line 417 "5_1.y"
                                                {(yyval.no) = makenode("-",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2207 "y.tab.c"
    break;

  case 104: /* expr: var MUL var  */
#line 418 "5_1.y"
                                                {(yyval.no) = makenode("*",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2213 "y.tab.c"
    break;

  case 105: /* expr: var DIV var  */
#line 419 "5_1.y"
                                                {(yyval.no) = makenode("/",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2219 "y.tab.c"
    break;

  case 106: /* expr: var MOD var  */
#line 420 "5_1.y"
                                                {(yyval.no) = makenode("%",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2225 "y.tab.c"
    break;

  case 107: /* expr: var POW var  */
#line 421 "5_1.y"
                                        {(yyval.no) = makenode("@",4,2,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2231 "y.tab.c"
    break;

  case 108: /* expr: var LESS var  */
#line 422 "5_1.y"
                                                {(yyval.no) = makenode("<",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2237 "y.tab.c"
    break;

  case 109: /* expr: var GREAT var  */
#line 423 "5_1.y"
                                                {(yyval.no) = makenode(">",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2243 "y.tab.c"
    break;

  case 110: /* expr: var LESSEQ var  */
#line 424 "5_1.y"
                                                {(yyval.no) = makenode("<=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2249 "y.tab.c"
    break;

  case 111: /* expr: var GREATEQ var  */
#line 425 "5_1.y"
                                        {(yyval.no) = makenode(">=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2255 "y.tab.c"
    break;

  case 112: /* expr: var NOTEQ var  */
#line 426 "5_1.y"
                                                {(yyval.no) = makenode("!=",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2261 "y.tab.c"
    break;

  case 113: /* expr: var EQEQ var  */
#line 427 "5_1.y"
                                        {(yyval.no) = makenode("==",4,1,NULL,(yyvsp[-2].no),NULL,(yyvsp[0].no));}
#line 2267 "y.tab.c"
    break;

  case 114: /* expr: var '(' ')'  */
#line 429 "5_1.y"
                                        {(yyval.no) = makenode((yyvsp[-2].no)->varname,10,2,NULL,NULL,NULL,NULL);}
#line 2273 "y.tab.c"
    break;

  case 115: /* expr: var '(' ArgList ')'  */
#line 430 "5_1.y"
                                        {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,2,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2279 "y.tab.c"
    break;

  case 116: /* expr: var '(' var ')'  */
#line 431 "5_1.y"
                                                {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,2,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2285 "y.tab.c"
    break;

  case 117: /* expr: var '(' expr ')'  */
#line 432 "5_1.y"
                                                {(yyval.no) = makenode((yyvsp[-3].no)->varname,10,2,(yyvsp[-1].no),NULL,NULL,NULL);}
#line 2291 "y.tab.c"
    break;

  case 118: /* expr: NUM  */
#line 433 "5_1.y"
                                                        {(yyval.no) = (yyvsp[0].no);}
#line 2297 "y.tab.c"
    break;

  case 119: /* expr: TEXT  */
#line 434 "5_1.y"
                                        {(yyval.no) = (yyvsp[0].no);}
#line 2303 "y.tab.c"
    break;


#line 2307 "y.tab.c"

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

#line 437 "5_1.y"


yyerror(char *s)
{
    printf("yyerror %s\n",s);
}


int main(void) {
	extern FILE *yyin;
  	yyin = fopen("factorial", "r");
  	FILE *fptr = fopen("target.xsm", "w");
  	fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,0,0);
	fprintf(fptr, "BRKP\n");
	fclose(fptr);
	yyparse();	
	return 0;
}

    


