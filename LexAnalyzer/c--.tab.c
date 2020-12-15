/* A Bison parser, made by GNU Bison 3.7.1.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "c--.y"

#include <stdio.h>
#include "ast.h"

Node* astRoot = NULL;

int yyerror(char * s);
extern int yylex(void);

#line 81 "c--.tab.c"

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

#include "c--.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_BOOL = 4,                       /* BOOL  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_VOID = 8,                       /* VOID  */
  YYSYMBOL_TRUE = 9,                       /* TRUE  */
  YYSYMBOL_FALSE = 10,                     /* FALSE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_CIN = 12,                       /* CIN  */
  YYSYMBOL_COUT = 13,                      /* COUT  */
  YYSYMBOL_INTEGER_LITERAL = 14,           /* INTEGER_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 15,            /* STRING_LITERAL  */
  YYSYMBOL_CONSTANT = 16,                  /* CONSTANT  */
  YYSYMBOL_IDENTIFIER = 17,                /* IDENTIFIER  */
  YYSYMBOL_LBRACE = 18,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 19,                    /* RBRACE  */
  YYSYMBOL_LBRK = 20,                      /* LBRK  */
  YYSYMBOL_RBRK = 21,                      /* RBRK  */
  YYSYMBOL_LSQBKT = 22,                    /* LSQBKT  */
  YYSYMBOL_RSQBKT = 23,                    /* RSQBKT  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_END_OF_INSTRUCTION = 26,        /* END_OF_INSTRUCTION  */
  YYSYMBOL_LEFT = 27,                      /* LEFT  */
  YYSYMBOL_RIGHT = 28,                     /* RIGHT  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_LESS = 31,                      /* LESS  */
  YYSYMBOL_LESSEQ = 32,                    /* LESSEQ  */
  YYSYMBOL_GREATER = 33,                   /* GREATER  */
  YYSYMBOL_GREATEREQ = 34,                 /* GREATEREQ  */
  YYSYMBOL_EQUAL = 35,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 36,                    /* NEQUAL  */
  YYSYMBOL_ADD = 37,                       /* ADD  */
  YYSYMBOL_SUBSTRACT = 38,                 /* SUBSTRACT  */
  YYSYMBOL_MULT = 39,                      /* MULT  */
  YYSYMBOL_DIV = 40,                       /* DIV  */
  YYSYMBOL_NOT = 41,                       /* NOT  */
  YYSYMBOL_NEG = 42,                       /* NEG  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_declaration = 45,               /* declaration  */
  YYSYMBOL_var_declaration = 46,           /* var_declaration  */
  YYSYMBOL_type = 47,                      /* type  */
  YYSYMBOL_function_declaration = 48,      /* function_declaration  */
  YYSYMBOL_parameters = 49,                /* parameters  */
  YYSYMBOL_formalsList = 50,               /* formalsList  */
  YYSYMBOL_formalDecl = 51,                /* formalDecl  */
  YYSYMBOL_block = 52,                     /* block  */
  YYSYMBOL_declList = 53,                  /* declList  */
  YYSYMBOL_stmtList = 54,                  /* stmtList  */
  YYSYMBOL_stmt = 55,                      /* stmt  */
  YYSYMBOL_exp = 56,                       /* exp  */
  YYSYMBOL_atom = 57,                      /* atom  */
  YYSYMBOL_fnCallExpr = 58,                /* fnCallExpr  */
  YYSYMBOL_fnCallStmt = 59,                /* fnCallStmt  */
  YYSYMBOL_actualList = 60,                /* actualList  */
  YYSYMBOL_subscriptExpr = 61              /* subscriptExpr  */
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
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    78,    82,    83,    84,    87,    88,    91,
      92,    93,    96,    99,   100,   103,   104,   110,   113,   116,
     117,   118,   121,   122,   123,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   156,   157,   158,   159,   160,   161,   162,   163,   166,
     167,   170,   171,   174,   175,   178
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "BOOL", "IF",
  "ELSE", "WHILE", "VOID", "TRUE", "FALSE", "RETURN", "CIN", "COUT",
  "INTEGER_LITERAL", "STRING_LITERAL", "CONSTANT", "IDENTIFIER", "LBRACE",
  "RBRACE", "LBRK", "RBRK", "LSQBKT", "RSQBKT", "COMMA", "ASSIGN",
  "END_OF_INSTRUCTION", "LEFT", "RIGHT", "OR", "AND", "LESS", "LESSEQ",
  "GREATER", "GREATEREQ", "EQUAL", "NEQUAL", "ADD", "SUBSTRACT", "MULT",
  "DIV", "NOT", "NEG", "$accept", "program", "declaration",
  "var_declaration", "type", "function_declaration", "parameters",
  "formalsList", "formalDecl", "block", "declList", "stmtList", "stmt",
  "exp", "atom", "fnCallExpr", "fnCallStmt", "actualList", "subscriptExpr", YY_NULLPTR
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
     295,   296,   297
};
#endif

#define YYPACT_NINF (-95)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     126,   -95,   -95,   -95,    52,   -95,   -95,   -12,   -95,   -95,
     -95,    49,     0,    43,   -95,    48,   -95,    59,    88,   -95,
      -8,   126,   -95,   -95,   -95,   126,    67,   -95,    75,   241,
     -95,   -95,    -2,    93,    95,    -3,   103,   106,    14,   -95,
     250,   -95,   127,   142,    69,    69,   -95,   -95,   -95,   -95,
      68,    69,   -95,   274,    69,   158,   -95,   -95,   -95,   134,
      69,    44,    69,    69,   -95,   -95,   -95,    69,    66,    87,
      53,   107,   -95,   -95,   -95,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    11,   173,   -95,
     242,    90,   125,   188,   203,    48,    48,   -95,   111,   -95,
     265,   275,   275,   275,   275,   275,   275,   275,   110,   110,
     -95,   -95,    69,   -95,   -95,   -95,    69,   -95,   -95,   -95,
     146,   -95,   -95,   143,   242,    48,   144,   -95,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     9,    10,    11,     0,     2,     4,     0,     5,     1,
       3,     0,     0,     0,     7,     0,    13,     0,     0,    15,
       0,    21,    12,    17,    14,     0,     0,    20,     0,    24,
      16,     8,     0,     0,     0,     0,     0,     0,     0,    19,
       0,    23,     0,     0,     0,     0,    53,    54,    51,    52,
      58,     0,    34,     0,     0,     0,    50,    56,    57,     0,
       0,     0,     0,     0,    18,    22,    35,     0,     0,     0,
       0,     0,    49,    40,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      63,     0,     0,     0,     0,     0,     0,    59,     0,    55,
      42,    41,    45,    47,    46,    48,    43,    44,    36,    37,
      38,    39,     0,    25,    27,    62,     0,    65,    29,    28,
      30,    32,    60,     0,    64,     0,     0,    31,    26
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   164,    51,     1,   -95,   -95,   -95,   160,   -94,
     -95,   -95,   129,   -35,   118,   -95,   -95,   116,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    15,    18,    19,    22,
      29,    40,    41,    90,    56,    57,    42,    91,    58
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,   120,   121,     1,     2,    11,    46,    47,     3,    68,
      69,    48,    49,    17,    50,    26,    71,    51,    43,    73,
      13,    16,    28,    52,    14,    88,    17,    92,    93,    43,
      28,   127,    94,   112,    61,    53,    62,   113,    54,    63,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     9,    46,    47,     1,     2,    20,    48,    49,
       3,    50,    46,    47,    51,    89,    21,    48,    49,    12,
      50,    13,    27,    51,    97,    14,    23,   123,    46,    47,
      39,   124,    53,    48,    49,    54,    50,    95,    70,    51,
      62,    53,    32,    31,    54,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    53,    96,    24,
      54,   115,    25,    44,   116,    45,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    99,     1,
       2,    59,   122,    60,     3,   116,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,   117,    85,
      86,    87,   125,    66,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,   126,    67,    10,    65,
     128,    72,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    74,    30,    98,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   114,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,   118,     0,     0,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   119,
       0,     0,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     1,     2,    33,     0,    34,     3,
       0,     0,    35,    36,    37,    33,     0,    34,    38,     0,
       0,    35,    36,    37,     0,     0,     0,    38,     0,    64,
       0,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    46,    47,     0,     0,     0,    48,    49,
       0,    50,     0,     0,    51,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86
};

static const yytype_int8 yycheck[] =
{
      35,    95,    96,     3,     4,    17,     9,    10,     8,    44,
      45,    14,    15,    12,    17,    23,    51,    20,    29,    54,
      22,    21,    21,    26,    26,    60,    25,    62,    63,    40,
      29,   125,    67,    22,    20,    38,    22,    26,    41,    25,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     9,    10,     3,     4,    14,    14,    15,
       8,    17,     9,    10,    20,    21,    18,    14,    15,    20,
      17,    22,    21,    20,    21,    26,    17,   112,     9,    10,
      29,   116,    38,    14,    15,    41,    17,    21,    20,    20,
      22,    38,    17,    26,    41,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    38,    21,    21,
      41,    21,    24,    20,    24,    20,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    21,     3,
       4,    28,    21,    27,     8,    24,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    23,    39,
      40,    17,     6,    26,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    23,    25,     4,    40,
      26,    53,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    26,    25,    70,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    11,    12,    13,     5,    -1,     7,    17,    -1,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    -1,    19,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     9,    10,    -1,    -1,    -1,    14,    15,
      -1,    17,    -1,    -1,    20,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     8,    44,    45,    46,    47,    48,     0,
      45,    17,    20,    22,    26,    49,    21,    47,    50,    51,
      14,    18,    52,    17,    21,    24,    23,    46,    47,    53,
      51,    26,    17,     5,     7,    11,    12,    13,    17,    46,
      54,    55,    59,    61,    20,    20,     9,    10,    14,    15,
      17,    20,    26,    38,    41,    56,    57,    58,    61,    28,
      27,    20,    22,    25,    19,    55,    26,    25,    56,    56,
      20,    56,    57,    56,    26,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    17,    56,    21,
      56,    60,    56,    56,    56,    21,    21,    21,    60,    21,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    22,    26,    26,    21,    24,    23,    26,    26,
      52,    52,    21,    56,    56,     6,    23,    52,    26
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    46,    46,    47,
      47,    47,    48,    49,    49,    50,    50,    51,    52,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     0,     3,     6,     1,
       1,     1,     4,     2,     3,     1,     3,     2,     4,     2,
       1,     0,     2,     1,     0,     4,     7,     4,     4,     4,
       5,     7,     5,     3,     2,     2,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       4,     3,     4,     1,     3,     4
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
  case 2: /* program: declaration  */
#line 77 "c--.y"
               { (yyval.node) = createProgramUnitNode((yyvsp[0].node)); astRoot = (yyval.node);}
#line 1244 "c--.tab.c"
    break;

  case 3: /* program: program declaration  */
#line 78 "c--.y"
                       { (yyval.node) = (yyvsp[-1].node);addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1250 "c--.tab.c"
    break;

  case 4: /* declaration: var_declaration  */
#line 82 "c--.y"
                                                    { (yyval.node) = createDeclarationNode((yyvsp[0].node)); }
#line 1256 "c--.tab.c"
    break;

  case 5: /* declaration: function_declaration  */
#line 83 "c--.y"
                                                    { (yyval.node) = createDeclarationNode((yyvsp[0].node)); }
#line 1262 "c--.tab.c"
    break;

  case 6: /* declaration: %empty  */
#line 84 "c--.y"
                                                    { (yyval.node) = NULL;}
#line 1268 "c--.tab.c"
    break;

  case 7: /* var_declaration: type IDENTIFIER END_OF_INSTRUCTION  */
#line 87 "c--.y"
                                                                    { (yyval.node) = createVarDeclaration((yyvsp[-2].node), (yyvsp[-1].strings), 0); }
#line 1274 "c--.tab.c"
    break;

  case 8: /* var_declaration: type IDENTIFIER LSQBKT INTEGER_LITERAL RSQBKT END_OF_INSTRUCTION  */
#line 88 "c--.y"
                                                                    { (yyval.node) = createArrayDeclaration((yyvsp[-5].node), (yyvsp[-4].strings), (yyvsp[-2].intVal)); }
#line 1280 "c--.tab.c"
    break;

  case 9: /* type: INT  */
#line 91 "c--.y"
                    { (yyval.node) = createTypeSpecifier("INT"); }
#line 1286 "c--.tab.c"
    break;

  case 10: /* type: BOOL  */
#line 92 "c--.y"
                    { (yyval.node) = createTypeSpecifier("BOOL"); }
#line 1292 "c--.tab.c"
    break;

  case 11: /* type: VOID  */
#line 93 "c--.y"
                    { (yyval.node) = createTypeSpecifier("VOID"); }
#line 1298 "c--.tab.c"
    break;

  case 12: /* function_declaration: type IDENTIFIER parameters block  */
#line 96 "c--.y"
                                                                    { (yyval.node) = createFunctionDeclarationNode((yyvsp[-3].node), (yyvsp[-2].strings), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1304 "c--.tab.c"
    break;

  case 13: /* parameters: LBRK RBRK  */
#line 99 "c--.y"
                                                            { (yyval.node) = NULL;}
#line 1310 "c--.tab.c"
    break;

  case 14: /* parameters: LBRK formalsList RBRK  */
#line 100 "c--.y"
                                                            { (yyval.node) = createParametersNode((yyvsp[-1].node));}
#line 1316 "c--.tab.c"
    break;

  case 15: /* formalsList: formalDecl  */
#line 103 "c--.y"
                                                            { (yyval.node) = createListNode("FormalsList", (yyvsp[0].node)); }
#line 1322 "c--.tab.c"
    break;

  case 16: /* formalsList: formalsList COMMA formalDecl  */
#line 104 "c--.y"
                                                             {
					(yyval.node) = (yyvsp[-2].node);
					addLinkToList((yyval.node), (yyvsp[0].node));
						}
#line 1331 "c--.tab.c"
    break;

  case 17: /* formalDecl: type IDENTIFIER  */
#line 110 "c--.y"
                                                                    { (yyval.node) = createFormalDecl((yyvsp[-1].node), (yyvsp[0].strings));}
#line 1337 "c--.tab.c"
    break;

  case 18: /* block: LBRACE declList stmtList RBRACE  */
#line 113 "c--.y"
                                                            { (yyval.node) = createBlock((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1343 "c--.tab.c"
    break;

  case 19: /* declList: declList var_declaration  */
#line 116 "c--.y"
                                                            { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1349 "c--.tab.c"
    break;

  case 20: /* declList: var_declaration  */
#line 117 "c--.y"
                                                            { (yyval.node) = createListNode("DecList", (yyvsp[0].node)); }
#line 1355 "c--.tab.c"
    break;

  case 21: /* declList: %empty  */
#line 118 "c--.y"
                                                            { (yyval.node) = NULL;}
#line 1361 "c--.tab.c"
    break;

  case 22: /* stmtList: stmtList stmt  */
#line 121 "c--.y"
                                                            { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1367 "c--.tab.c"
    break;

  case 23: /* stmtList: stmt  */
#line 122 "c--.y"
                                                            { (yyval.node) = createListNode("StatementList", (yyvsp[0].node)); }
#line 1373 "c--.tab.c"
    break;

  case 24: /* stmtList: %empty  */
#line 123 "c--.y"
                                                            { (yyval.node) = NULL;}
#line 1379 "c--.tab.c"
    break;

  case 25: /* stmt: CIN RIGHT IDENTIFIER END_OF_INSTRUCTION  */
#line 126 "c--.y"
                                                                    { (yyval.node) = createCin((yyvsp[-1].strings), NULL);}
#line 1385 "c--.tab.c"
    break;

  case 26: /* stmt: CIN RIGHT IDENTIFIER LSQBKT exp RSQBKT END_OF_INSTRUCTION  */
#line 127 "c--.y"
                                                                    { (yyval.node) = createCin((yyvsp[-4].strings), (yyvsp[-2].node));}
#line 1391 "c--.tab.c"
    break;

  case 27: /* stmt: COUT LEFT exp END_OF_INSTRUCTION  */
#line 128 "c--.y"
                                                            { (yyval.node) = createCout((yyvsp[-1].node));}
#line 1397 "c--.tab.c"
    break;

  case 28: /* stmt: subscriptExpr ASSIGN exp END_OF_INSTRUCTION  */
#line 129 "c--.y"
                                                            { (yyval.node) = createSubscriptExprStatement((yyvsp[-3].node),(yyvsp[-1].node));}
#line 1403 "c--.tab.c"
    break;

  case 29: /* stmt: IDENTIFIER ASSIGN exp END_OF_INSTRUCTION  */
#line 130 "c--.y"
                                                                    { (yyval.node) = createAssignStatement((yyvsp[-3].strings),(yyvsp[-1].node));}
#line 1409 "c--.tab.c"
    break;

  case 30: /* stmt: IF LBRK exp RBRK block  */
#line 131 "c--.y"
                                                            { (yyval.node) = createIfStatement((yyvsp[-2].node), (yyvsp[0].node), NULL);}
#line 1415 "c--.tab.c"
    break;

  case 31: /* stmt: IF LBRK exp RBRK block ELSE block  */
#line 132 "c--.y"
                                                            { (yyval.node) = createIfStatement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1421 "c--.tab.c"
    break;

  case 32: /* stmt: WHILE LBRK exp RBRK block  */
#line 133 "c--.y"
                                                            { (yyval.node) = createWhileStatement((yyvsp[-2].node), (yyvsp[0].node));}
#line 1427 "c--.tab.c"
    break;

  case 33: /* stmt: RETURN exp END_OF_INSTRUCTION  */
#line 134 "c--.y"
                                                            { (yyval.node) = createReturnStatement((yyvsp[-1].node));}
#line 1433 "c--.tab.c"
    break;

  case 34: /* stmt: RETURN END_OF_INSTRUCTION  */
#line 135 "c--.y"
                                                            { (yyval.node) = createReturnStatement(NULL);}
#line 1439 "c--.tab.c"
    break;

  case 35: /* stmt: fnCallStmt END_OF_INSTRUCTION  */
#line 136 "c--.y"
                                                            { (yyval.node) = createFnCallStatement((yyvsp[-1].node));}
#line 1445 "c--.tab.c"
    break;

  case 36: /* exp: exp ADD exp  */
#line 139 "c--.y"
                                { (yyval.node) = createAddExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1451 "c--.tab.c"
    break;

  case 37: /* exp: exp SUBSTRACT exp  */
#line 140 "c--.y"
                                { (yyval.node) = createSubstractExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1457 "c--.tab.c"
    break;

  case 38: /* exp: exp MULT exp  */
#line 141 "c--.y"
                                { (yyval.node) = createMultExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1463 "c--.tab.c"
    break;

  case 39: /* exp: exp DIV exp  */
#line 142 "c--.y"
                                { (yyval.node) = createDivExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1469 "c--.tab.c"
    break;

  case 40: /* exp: NOT exp  */
#line 143 "c--.y"
                                { (yyval.node) = createNotExp((yyvsp[0].node));}
#line 1475 "c--.tab.c"
    break;

  case 41: /* exp: exp AND exp  */
#line 144 "c--.y"
                                { (yyval.node) = createAndExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1481 "c--.tab.c"
    break;

  case 42: /* exp: exp OR exp  */
#line 145 "c--.y"
                                { (yyval.node) = createOrExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1487 "c--.tab.c"
    break;

  case 43: /* exp: exp EQUAL exp  */
#line 146 "c--.y"
                                { (yyval.node) = createEqualExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1493 "c--.tab.c"
    break;

  case 44: /* exp: exp NEQUAL exp  */
#line 147 "c--.y"
                                { (yyval.node) = createNEqualExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1499 "c--.tab.c"
    break;

  case 45: /* exp: exp LESS exp  */
#line 148 "c--.y"
                                { (yyval.node) = createLessExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1505 "c--.tab.c"
    break;

  case 46: /* exp: exp GREATER exp  */
#line 149 "c--.y"
                                { (yyval.node) = createGreaterExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1511 "c--.tab.c"
    break;

  case 47: /* exp: exp LESSEQ exp  */
#line 150 "c--.y"
                                { (yyval.node) = createLesseqExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1517 "c--.tab.c"
    break;

  case 48: /* exp: exp GREATEREQ exp  */
#line 151 "c--.y"
                                { (yyval.node) = createGreatereqExp((yyvsp[-2].node),(yyvsp[0].node));}
#line 1523 "c--.tab.c"
    break;

  case 49: /* exp: SUBSTRACT atom  */
#line 152 "c--.y"
                                { (yyval.node) = createNegativeExp((yyvsp[0].node));}
#line 1529 "c--.tab.c"
    break;

  case 50: /* exp: atom  */
#line 153 "c--.y"
                                { (yyval.node) = createAtomExp((yyvsp[0].node));}
#line 1535 "c--.tab.c"
    break;

  case 51: /* atom: INTEGER_LITERAL  */
#line 156 "c--.y"
                        { (yyval.node) = createIntLiteralNode((yyvsp[0].intVal));;}
#line 1541 "c--.tab.c"
    break;

  case 52: /* atom: STRING_LITERAL  */
#line 157 "c--.y"
                        { (yyval.node) = createStrLiteralNode((yyvsp[0].strings));;}
#line 1547 "c--.tab.c"
    break;

  case 53: /* atom: TRUE  */
#line 158 "c--.y"
                        { (yyval.node) = TRUE;}
#line 1553 "c--.tab.c"
    break;

  case 54: /* atom: FALSE  */
#line 159 "c--.y"
                        { (yyval.node) = FALSE;}
#line 1559 "c--.tab.c"
    break;

  case 55: /* atom: LBRK exp RBRK  */
#line 160 "c--.y"
                        { (yyval.node) = createFuncAtom((yyvsp[-1].node));}
#line 1565 "c--.tab.c"
    break;

  case 56: /* atom: fnCallExpr  */
#line 161 "c--.y"
                        { (yyval.node) = createfnCallAtom((yyvsp[0].node));}
#line 1571 "c--.tab.c"
    break;

  case 57: /* atom: subscriptExpr  */
#line 162 "c--.y"
                        { (yyval.node) = createSubscriptAtom((yyvsp[0].node));}
#line 1577 "c--.tab.c"
    break;

  case 58: /* atom: IDENTIFIER  */
#line 163 "c--.y"
                        { (yyval.node) = createIdentifierNode((yyvsp[0].strings));}
#line 1583 "c--.tab.c"
    break;

  case 59: /* fnCallExpr: IDENTIFIER LBRK RBRK  */
#line 166 "c--.y"
                                        { (yyval.node) = createFnCallExpr((yyvsp[-2].strings),NULL);}
#line 1589 "c--.tab.c"
    break;

  case 60: /* fnCallExpr: IDENTIFIER LBRK actualList RBRK  */
#line 167 "c--.y"
                                        { (yyval.node) = createFnCallExpr((yyvsp[-3].strings),(yyvsp[-1].node));}
#line 1595 "c--.tab.c"
    break;

  case 61: /* fnCallStmt: IDENTIFIER LBRK RBRK  */
#line 170 "c--.y"
                                        { (yyval.node) = createFnCallStmt((yyvsp[-2].strings),NULL);}
#line 1601 "c--.tab.c"
    break;

  case 62: /* fnCallStmt: IDENTIFIER LBRK actualList RBRK  */
#line 171 "c--.y"
                                        { (yyval.node) = createFnCallStmt((yyvsp[-3].strings),(yyvsp[-1].node));}
#line 1607 "c--.tab.c"
    break;

  case 63: /* actualList: exp  */
#line 174 "c--.y"
                                { (yyval.node) = createListNode("ActualList", (yyvsp[0].node)); }
#line 1613 "c--.tab.c"
    break;

  case 64: /* actualList: actualList COMMA exp  */
#line 175 "c--.y"
                                { (yyval.node) = (yyvsp[-2].node); ((yyval.node), (yyvsp[0].node));}
#line 1619 "c--.tab.c"
    break;

  case 65: /* subscriptExpr: IDENTIFIER LSQBKT exp RSQBKT  */
#line 178 "c--.y"
                                        { (yyval.node) = createSubscriptExpr((yyvsp[-3].strings),(yyvsp[-1].node));}
#line 1625 "c--.tab.c"
    break;


#line 1629 "c--.tab.c"

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

#line 181 "c--.y"


int yyerror(char *errmsg)
{
     printf("%s \n", errmsg);
     return 0;
}
