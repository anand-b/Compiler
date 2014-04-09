/* A Bison parser, made by GNU Bison 2.7.1.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "c.y"

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<ctype.h>
#include "y.tab.h"
extern FILE *yyin;
extern int line;
//variables
int top=-1;
int result=1;
int startLoop,endLoop;

struct list
{
	struct node *link;
	int count;
}*lis;
struct node
{
    struct node *link;
    char *name;
    int *addr;
};
typedef struct list l;
typedef struct node n;

int if_stack[20];
int if_top=-1;
void if_push();
int if_pop();
int* getAddr(l *,char *);
int getVal(l *,char *);
void freeList(l *);
void freeListUtil(n *);
void printUtil(l *,int);
void insert(l *,char *);
void removeUtil(l *,char *);
n* createNode(char *,int *);
int hashUtil(char *);

/* Line 371 of yacc.c  */
#line 111 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     NUMBER = 259,
     PLUS = 260,
     BMINUS = 261,
     MULTIPLY = 262,
     OP = 263,
     CP = 264,
     AND = 265,
     OR = 266,
     DO = 267,
     COMMA = 268,
     DIVIDE = 269,
     MOD = 270,
     VAR = 271,
     FUNC_NAME = 272,
     PERIOD = 273,
     EQ = 274,
     FOR = 275,
     THEN = 276,
     IF = 277,
     FI = 278,
     RETURN = 279,
     MAIN = 280,
     END = 281,
     BREAK = 282,
     CONTINUE = 283,
     SRIGHT = 284,
     SLEFT = 285,
     BAND = 286,
     BOR = 287,
     BXOR = 288,
     BITCOMPLEMENT = 289,
     LE = 290,
     GE = 291,
     L = 292,
     G = 293,
     NOT = 294,
     NE = 295,
     EE = 296,
     ELSE = 297,
     DEC = 298,
     INC = 299,
     UMINUS = 300,
     OUT = 301,
     IN = 302,
     STRING = 303,
     LOOP = 304,
     TILL = 305,
     WITH = 306
   };
#endif
/* Tokens.  */
#define INT 258
#define NUMBER 259
#define PLUS 260
#define BMINUS 261
#define MULTIPLY 262
#define OP 263
#define CP 264
#define AND 265
#define OR 266
#define DO 267
#define COMMA 268
#define DIVIDE 269
#define MOD 270
#define VAR 271
#define FUNC_NAME 272
#define PERIOD 273
#define EQ 274
#define FOR 275
#define THEN 276
#define IF 277
#define FI 278
#define RETURN 279
#define MAIN 280
#define END 281
#define BREAK 282
#define CONTINUE 283
#define SRIGHT 284
#define SLEFT 285
#define BAND 286
#define BOR 287
#define BXOR 288
#define BITCOMPLEMENT 289
#define LE 290
#define GE 291
#define L 292
#define G 293
#define NOT 294
#define NE 295
#define EE 296
#define ELSE 297
#define DEC 298
#define INC 299
#define UMINUS 300
#define OUT 301
#define IN 302
#define STRING 303
#define LOOP 304
#define TILL 305
#define WITH 306



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 44 "c.y"

	int number;
	char *var_name;


/* Line 387 of yacc.c  */
#line 262 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 290 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  179

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    14,    15,    19,    20,
      26,    27,    33,    34,    40,    41,    45,    48,    52,    56,
      62,    66,    68,    71,    74,    77,    80,    83,    86,    88,
      90,    92,    94,    96,    99,   101,   103,   104,   107,   111,
     115,   116,   121,   124,   128,   132,   135,   138,   141,   144,
     147,   150,   152,   154,   156,   158,   160,   163,   165,   167,
     171,   175,   176,   181,   184,   188,   196,   206,   215,   219,
     223,   225,   229,   233,   237,   241,   245,   249,   251,   255,
     259,   263,   265,   269,   273,   275,   279,   283,   285,   289,
     293,   297,   299,   302,   305,   308,   311,   313,   317,   319,
     322,   325,   327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    25,    54,    -1,    26,    -1,    60,    54,
      -1,    69,    54,    -1,    -1,    55,    78,    54,    -1,    -1,
      46,    48,    56,    18,    54,    -1,    -1,    46,    80,    18,
      57,    54,    -1,    -1,    47,    16,    18,    58,    54,    -1,
      -1,    59,    79,    54,    -1,    18,    54,    -1,     3,    61,
      18,    -1,    16,    13,    61,    -1,    16,    19,    80,    13,
      61,    -1,    16,    19,    80,    -1,    16,    -1,    69,    62,
      -1,    63,    62,    -1,    79,    62,    -1,    67,    62,    -1,
      66,    62,    -1,    65,    62,    -1,    69,    -1,    66,    -1,
      67,    -1,    65,    -1,    63,    -1,    18,    62,    -1,    18,
      -1,    79,    -1,    -1,    64,    78,    -1,    47,    16,    18,
      -1,    46,    80,    18,    -1,    -1,    46,    48,    68,    18,
      -1,    70,    18,    -1,    70,    13,    69,    -1,    16,    19,
      80,    -1,    76,    71,    -1,    63,    71,    -1,    79,    62,
      -1,    74,    71,    -1,    72,    71,    -1,    73,    71,    -1,
      76,    -1,    72,    -1,    74,    -1,    73,    -1,    63,    -1,
      18,    71,    -1,    18,    -1,    79,    -1,    46,    80,    18,
      -1,    47,    16,    18,    -1,    -1,    46,    48,    75,    18,
      -1,    77,    18,    -1,    16,    19,    80,    -1,    22,     8,
      80,     9,    21,    62,    23,    -1,    22,     8,    80,     9,
      21,    62,    42,    71,    23,    -1,    49,    50,    80,    12,
      62,    51,    80,    18,    -1,    80,    10,    81,    -1,    80,
      11,    81,    -1,    81,    -1,    81,    36,    82,    -1,    81,
      35,    82,    -1,    81,    38,    82,    -1,    81,    37,    82,
      -1,    81,    40,    82,    -1,    81,    41,    82,    -1,    82,
      -1,    82,    31,    83,    -1,    82,    32,    83,    -1,    82,
      33,    83,    -1,    83,    -1,    83,    29,    84,    -1,    83,
      30,    84,    -1,    84,    -1,    84,     5,    85,    -1,    84,
       6,    85,    -1,    85,    -1,    86,     7,    85,    -1,    86,
      14,    85,    -1,    86,    15,    85,    -1,    86,    -1,    44,
      86,    -1,    43,    86,    -1,    39,    86,    -1,    34,    86,
      -1,    87,    -1,     8,    80,     9,    -1,    88,    -1,    88,
      44,    -1,    88,    43,    -1,     4,    -1,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    86,    87,    88,    89,    89,    91,    90,
      96,    95,   101,   100,   108,   108,   109,   111,   115,   119,
     132,   141,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   161,   161,   162,   172,
     179,   178,   185,   188,   190,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   217,
     223,   234,   233,   240,   244,   257,   266,   283,   289,   290,
     291,   293,   301,   309,   317,   325,   333,   341,   343,   344,
     345,   346,   348,   349,   350,   352,   353,   354,   356,   357,
     358,   359,   361,   362,   363,   364,   365,   367,   368,   370,
     371,   372,   373
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "NUMBER", "PLUS", "BMINUS",
  "MULTIPLY", "OP", "CP", "AND", "OR", "DO", "COMMA", "DIVIDE", "MOD",
  "VAR", "FUNC_NAME", "PERIOD", "EQ", "FOR", "THEN", "IF", "FI", "RETURN",
  "MAIN", "END", "BREAK", "CONTINUE", "SRIGHT", "SLEFT", "BAND", "BOR",
  "BXOR", "BITCOMPLEMENT", "LE", "GE", "L", "G", "NOT", "NE", "EE", "ELSE",
  "DEC", "INC", "UMINUS", "OUT", "IN", "STRING", "LOOP", "TILL", "WITH",
  "$accept", "st", "statement", "$@1", "$@2", "$@3", "$@4", "$@5",
  "declaration", "list", "block", "ifcondition", "$@6", "input1",
  "varprint1", "strprint1", "$@7", "init", "initlist", "else_block",
  "varprint0", "input0", "strprint0", "$@8", "else_init", "else_initlist",
  "ifcond", "loop", "logical", "compare", "bitwise", "shifts", "expr",
  "term", "pre", "factor", "post", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    54,    55,    54,    56,    54,
      57,    54,    58,    54,    59,    54,    54,    60,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    64,    63,    65,    66,
      68,    67,    69,    69,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      73,    75,    74,    76,    77,    78,    78,    79,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    83,    83,    83,    84,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    86,    86,    87,    87,    88,
      88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     0,     3,     0,     5,
       0,     5,     0,     5,     0,     3,     2,     3,     3,     5,
       3,     1,     2,     2,     2,     2,     2,     2,     1,     1,
       1,     1,     1,     2,     1,     1,     0,     2,     3,     3,
       0,     4,     2,     3,     3,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     2,     1,     1,     3,
       3,     0,     4,     2,     3,     7,     9,     8,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     2,     2,     1,     3,     1,     2,
       2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     0,     0,     0,     6,     3,     0,     0,     2,
       0,     0,     6,     6,     0,     1,    21,     0,     0,    16,
     101,     0,   102,     0,     0,     0,     0,     8,     0,    70,
      77,    81,    84,    87,    91,    96,    98,     0,     0,     6,
       0,     6,     4,     5,     0,    42,     0,     0,    17,    44,
       0,    95,    94,    93,    92,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,    99,    12,     0,     7,
       0,    15,    43,    18,    20,    97,     6,    68,    69,     6,
      72,    71,    74,    73,    75,    76,    78,    79,    80,    82,
      83,    85,    86,    88,    89,    90,     6,     0,     0,     0,
       9,    11,    13,     0,    36,    19,    36,    34,     0,     0,
       0,    32,     0,    31,    29,    30,    28,    35,     0,    33,
      40,     0,     0,     0,    23,    37,    27,    26,    25,    22,
      24,    65,    36,     0,    39,    38,     0,     0,    36,     0,
       0,    36,     0,    36,    36,    36,    36,     0,    36,    41,
      67,     0,    56,    61,     0,     0,    46,    66,    49,    50,
      48,    45,    63,    47,    64,     0,    59,    60,    62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    10,    55,    89,   106,    11,    12,    17,
     120,   121,   122,   123,   124,   125,   143,   126,    14,   152,
     153,   154,   155,   175,   156,   157,    39,   127,    28,    29,
      30,    31,    32,    33,    34,    35,    36
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int16 yypact[] =
{
     -23,     5,    11,    -2,    10,     5,   -43,    14,    17,   -43,
      15,    -9,     5,     5,    -3,   -43,    36,    24,   116,   -43,
     -43,   116,   -43,   116,   116,   116,   116,   -43,     9,   187,
     151,    -5,    65,   -43,    21,   -43,    61,    29,    42,     5,
       6,     5,   -43,   -43,    43,   -43,    -2,   116,   -43,   125,
     138,   -43,   -43,   -43,   -43,    48,   116,   116,   -43,   116,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   -43,   -43,   -43,   116,   -43,
     116,   -43,   -43,   -43,   115,   -43,     5,   187,   187,     5,
     151,   151,   151,   151,   151,   151,    -5,    -5,    -5,    65,
      65,   -43,   -43,   -43,   -43,   -43,     5,   252,   254,    -2,
     -43,   -43,   -43,    54,   172,   -43,   172,   105,    30,    67,
      26,   105,    15,   105,   105,   105,   105,   105,   -16,   -43,
     -43,    50,    73,   116,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   198,    81,   -43,   -43,    90,    66,   140,    68,
      93,   146,    94,   150,   154,   158,   162,    95,   194,   -43,
     -43,   116,   -43,   -43,   104,   101,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   125,   112,   -43,   -43,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -43,   -43,     4,   -43,   -43,   -43,   -43,   -43,   -43,   -42,
     -29,    78,   -43,   -43,   -43,   -43,   -43,     0,   -43,    98,
     -43,   -43,   -43,   -43,   -43,   -43,    19,   -11,   -15,    82,
     196,   202,   203,   165,    56,   -43,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -59
static const yytype_int16 yytable[] =
{
      41,    13,     1,    49,    83,    13,    50,   141,     3,    19,
      44,    15,    13,    13,    16,    45,    42,    43,    20,    56,
      57,     4,    21,     5,    68,    69,   142,    58,    72,    18,
      22,     6,    84,    37,    20,    73,    74,    38,    21,    13,
      40,    13,    48,    79,    82,    81,    22,    77,    23,    46,
      78,     7,     8,    24,   -14,    47,    80,    25,    26,     4,
      56,    57,    27,   107,    23,   108,    86,   115,   144,    24,
      70,    71,    20,    25,    26,   116,    21,   133,   130,    51,
      52,    53,    54,   132,    22,   161,    13,   128,   129,    13,
     110,   145,   134,   111,   136,   137,   138,   139,   140,   159,
      56,    57,    23,   131,    75,    76,    13,    24,   160,   165,
     112,    25,    26,   172,    56,    57,   163,   167,   146,   177,
      20,     4,   176,   117,    21,    56,    57,   -36,   109,   173,
     178,   158,    22,     0,   164,    56,    57,   158,    87,    88,
     158,   135,   158,   158,   158,   158,   174,    85,    56,    57,
      23,   118,   119,     0,    40,    24,   147,     0,   148,    25,
      26,     0,   147,   -57,   148,     0,   147,     0,   148,   -55,
     147,     0,   148,   -52,   147,     0,   148,   -54,   147,     0,
     148,   -53,    65,    66,    67,   -51,   149,   150,     4,    40,
     117,     0,   149,   150,     0,    40,   149,   150,     0,    40,
     149,   150,     0,    40,   149,   150,     0,    40,   149,   150,
       4,    40,   117,     0,   147,     0,   148,   -58,   118,   119,
     151,    40,    59,    60,    61,    62,   151,    63,    64,   151,
       0,   151,   151,   151,   151,   101,   102,   103,   104,   105,
     118,   119,     0,    40,   149,   150,   162,    40,     0,   166,
       0,   168,   169,   170,   171,    90,    91,    92,    93,    94,
      95,   113,    56,    57,    56,    57,   114,    96,    97,    98,
       0,    99,   100
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-43)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      11,     1,    25,    18,    46,     5,    21,    23,     3,     5,
      13,     0,    12,    13,    16,    18,    12,    13,     4,    10,
      11,    16,     8,    18,    29,    30,    42,    18,     7,    19,
      16,    26,    47,    16,     4,    14,    15,    22,     8,    39,
      49,    41,    18,    39,    44,    41,    16,    18,    34,    13,
       8,    46,    47,    39,    49,    19,    50,    43,    44,    16,
      10,    11,    48,    78,    34,    80,    18,   109,    18,    39,
       5,     6,     4,    43,    44,    21,     8,    51,    48,    23,
      24,    25,    26,    16,    16,    19,    86,   116,   117,    89,
      86,    18,   121,    89,   123,   124,   125,   126,   127,    18,
      10,    11,    34,   118,    43,    44,   106,    39,    18,    16,
     106,    43,    44,    18,    10,    11,    48,    23,   133,    18,
       4,    16,    18,    18,     8,    10,    11,    22,    13,   158,
      18,   142,    16,    -1,   149,    10,    11,   148,    56,    57,
     151,   122,   153,   154,   155,   156,   161,     9,    10,    11,
      34,    46,    47,    -1,    49,    39,    16,    -1,    18,    43,
      44,    -1,    16,    23,    18,    -1,    16,    -1,    18,    23,
      16,    -1,    18,    23,    16,    -1,    18,    23,    16,    -1,
      18,    23,    31,    32,    33,    23,    46,    47,    16,    49,
      18,    -1,    46,    47,    -1,    49,    46,    47,    -1,    49,
      46,    47,    -1,    49,    46,    47,    -1,    49,    46,    47,
      16,    49,    18,    -1,    16,    -1,    18,    23,    46,    47,
     142,    49,    35,    36,    37,    38,   148,    40,    41,   151,
      -1,   153,   154,   155,   156,    70,    71,    72,    73,    74,
      46,    47,    -1,    49,    46,    47,   148,    49,    -1,   151,
      -1,   153,   154,   155,   156,    59,    60,    61,    62,    63,
      64,     9,    10,    11,    10,    11,    12,    65,    66,    67,
      -1,    68,    69
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    53,     3,    16,    18,    26,    46,    47,    54,
      55,    59,    60,    69,    70,     0,    16,    61,    19,    54,
       4,     8,    16,    34,    39,    43,    44,    48,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    16,    22,    78,
      49,    79,    54,    54,    13,    18,    13,    19,    18,    80,
      80,    86,    86,    86,    86,    56,    10,    11,    18,    35,
      36,    37,    38,    40,    41,    31,    32,    33,    29,    30,
       5,     6,     7,    14,    15,    43,    44,    18,     8,    54,
      50,    54,    69,    61,    80,     9,    18,    81,    81,    57,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    58,    80,    80,    13,
      54,    54,    54,     9,    12,    61,    21,    18,    46,    47,
      62,    63,    64,    65,    66,    67,    69,    79,    62,    62,
      48,    80,    16,    51,    62,    78,    62,    62,    62,    62,
      62,    23,    42,    68,    18,    18,    80,    16,    18,    46,
      47,    63,    71,    72,    73,    74,    76,    77,    79,    18,
      18,    19,    71,    48,    80,    16,    71,    23,    71,    71,
      71,    71,    18,    62,    80,    75,    18,    18,    18
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 84 "c.y"
    {printf("\n---------------------------------------------\nProgram terminated with return value %d\n",(yyvsp[(2) - (2)].number));exit(0);}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 86 "c.y"
    {(yyval.number)=0;}
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 87 "c.y"
    {}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 88 "c.y"
    {}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 89 "c.y"
    {if_push();}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 89 "c.y"
    {}
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 91 "c.y"
    {
				printf("%s\n",(yyvsp[(2) - (2)].var_name));
			}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 94 "c.y"
    {}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 96 "c.y"
    {
				printf("%d\n",(yyvsp[(2) - (3)].number));
			}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 99 "c.y"
    {}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 101 "c.y"
    {
				int *p=getAddr(lis,(yyvsp[(2) - (3)].var_name));
				int tmp;
				scanf("%d",&tmp);
				*p=tmp;
			}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 107 "c.y"
    {}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 108 "c.y"
    {printf("%d\n",ftell(yyin));}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 108 "c.y"
    {}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 109 "c.y"
    {}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 112 "c.y"
    {
			}
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 116 "c.y"
    {
				insert(lis,(yyvsp[(1) - (3)].var_name));
			}
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 120 "c.y"
    {
				//printf("%s %d\n",$1,$3);
				insert(lis,(yyvsp[(1) - (5)].var_name));
				int *p;
				p=getAddr(lis,(yyvsp[(1) - (5)].var_name));
				*getAddr(lis,(yyvsp[(1) - (5)].var_name))=(yyvsp[(3) - (5)].number);
				//printf("list 1: %s\n",$1);
				int a=getVal(lis,(yyvsp[(1) - (5)].var_name));
				//printf("%d\n",a);
				(yyval.number)=a;
				//printUtil(lis,hashUtil($1));
			}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 133 "c.y"
    {
				//printf("%s %d\n",$1,$3);
				insert(lis,(yyvsp[(1) - (3)].var_name));
				*getAddr(lis,(yyvsp[(1) - (3)].var_name))=(yyvsp[(3) - (3)].number);
				//printf("list 2: %s\n",$1);
				int a=getVal(lis,(yyvsp[(1) - (3)].var_name));
				//printf("%d\n",a);
			}
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 142 "c.y"
    {
				insert(lis,(yyvsp[(1) - (1)].var_name));
			}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 146 "c.y"
    {(yyval.number)=(yyvsp[(1) - (2)].number);}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 147 "c.y"
    {}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 148 "c.y"
    {}
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 149 "c.y"
    {}
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 150 "c.y"
    {}
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 151 "c.y"
    {}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 152 "c.y"
    {}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 153 "c.y"
    {}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 154 "c.y"
    {}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 155 "c.y"
    {}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 156 "c.y"
    {}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 157 "c.y"
    {}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 158 "c.y"
    {}
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 161 "c.y"
    {if_push();}
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 161 "c.y"
    {}
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 163 "c.y"
    {
				if(result==1){
				int *p=getAddr(lis,(yyvsp[(2) - (3)].var_name));
				int tmp;
				scanf("%d",&tmp);
				*p=tmp;
				}
			}
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 173 "c.y"
    {
				if(result==1)
					printf("%d\n",(yyvsp[(2) - (3)].number));
			}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 179 "c.y"
    {
				if(result==1)
					printf("%s\n",(yyvsp[(2) - (2)].var_name));
			}
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 183 "c.y"
    {}
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 186 "c.y"
    {
			}
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 188 "c.y"
    {}
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 191 "c.y"
    {
				if(result==1)
				{
					//printf("Decl: %s\n",$1);
					int *a=getAddr(lis,(yyvsp[(1) - (3)].var_name));
					*a=(yyvsp[(3) - (3)].number);
					(yyval.number)=*a;
					//printf("%d\n",*a);
				}
			}
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 202 "c.y"
    {(yyval.number)=(yyvsp[(1) - (2)].number);}
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 203 "c.y"
    {}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 204 "c.y"
    {}
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 205 "c.y"
    {}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 206 "c.y"
    {}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 207 "c.y"
    {}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 208 "c.y"
    {}
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 209 "c.y"
    {}
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 210 "c.y"
    {}
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 211 "c.y"
    {}
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 212 "c.y"
    {}
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 213 "c.y"
    {}
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 214 "c.y"
    {}
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 215 "c.y"
    {}
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 218 "c.y"
    {
				if(result==0)
					printf("%d\n",(yyvsp[(2) - (3)].number));
			}
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 224 "c.y"
    {
				if(result==0){
				int *p=getAddr(lis,(yyvsp[(2) - (3)].var_name));
				int tmp;
				scanf("%d",&tmp);
				*p=tmp;
				}
			}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 234 "c.y"
    {
				if(result==0)
					printf("%s\n",(yyvsp[(2) - (2)].var_name));
			}
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 238 "c.y"
    {}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 241 "c.y"
    {
			}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 245 "c.y"
    {
				if(result==0)
				{
					//printf("Decl: %s\n",$1);
					int *a=getAddr(lis,(yyvsp[(1) - (3)].var_name));
					*a=(yyvsp[(3) - (3)].number);
					(yyval.number)=*a;
					//printf("%d\n",*a);
				}
			}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 258 "c.y"
    {
				if((yyvsp[(3) - (7)].number)==1)
				{
					//$$=$7;
					//printf("IF statement\n");
				}
				result=if_pop();
			 }
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 267 "c.y"
    {
				//printf("condition: %d\n",$3);
				if((yyvsp[(3) - (9)].number)==1)
				{
					//$$=$6;
					//printf("%d\n",$3);
					//printf("IF statement\n");
				}
				else
				{
					//$$=$9;
					//printf("ELSE statement\n");
				}
				result=if_pop();
			 }
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 284 "c.y"
    {
					printf("Loop\n");
					
				}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 289 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)&&(yyvsp[(3) - (3)].number);result=(yyval.number);}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 290 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)||(yyvsp[(3) - (3)].number);result=(yyval.number);}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 291 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 294 "c.y"
    {
				if((yyvsp[(1) - (3)].number) >= (yyvsp[(3) - (3)].number))
					(yyval.number)=1;
				else
					(yyval.number)=0;
				result=(yyval.number);	
			 }
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 302 "c.y"
    {
				if((yyvsp[(1) - (3)].number) <= (yyvsp[(3) - (3)].number))
					(yyval.number)=1;
				else
					(yyval.number)=0;
				result=(yyval.number);
			 }
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 310 "c.y"
    {
				if((yyvsp[(1) - (3)].number) > (yyvsp[(3) - (3)].number))
					(yyval.number)=1;
				else
					(yyval.number)=0;
				result=(yyval.number);
			 }
    break;

  case 74:
/* Line 1787 of yacc.c  */
#line 318 "c.y"
    {
				if((yyvsp[(1) - (3)].number) < (yyvsp[(3) - (3)].number))
					(yyval.number)=1;
				else
					(yyval.number)=0;
				result=(yyval.number);
			 }
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 326 "c.y"
    {
				if((yyvsp[(1) - (3)].number) != (yyvsp[(3) - (3)].number))
					(yyval.number)=1;
				else
					(yyval.number)=0;
				result=(yyval.number);
			 }
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 334 "c.y"
    {
				if((yyvsp[(1) - (3)].number) == (yyvsp[(3) - (3)].number))
					(yyval.number)=1;
				else
					(yyval.number)=0;
				result=(yyval.number);
			 }
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 341 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 78:
/* Line 1787 of yacc.c  */
#line 343 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)&(yyvsp[(3) - (3)].number);}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 344 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)|(yyvsp[(3) - (3)].number);}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 345 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)^(yyvsp[(3) - (3)].number);}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 346 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 348 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)>>(yyvsp[(3) - (3)].number);}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 349 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)<<(yyvsp[(3) - (3)].number);}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 350 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 352 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)+(yyvsp[(3) - (3)].number);}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 353 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)-(yyvsp[(3) - (3)].number);}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 354 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 356 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)*(yyvsp[(3) - (3)].number);}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 357 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)/(yyvsp[(3) - (3)].number);}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 358 "c.y"
    {(yyval.number)=(yyvsp[(1) - (3)].number)%(yyvsp[(3) - (3)].number);}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 359 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 361 "c.y"
    {(yyval.number)=++(yyvsp[(2) - (2)].number);}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 362 "c.y"
    {(yyval.number)=--(yyvsp[(2) - (2)].number);}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 363 "c.y"
    {(yyval.number)=!(yyvsp[(2) - (2)].number);}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 364 "c.y"
    {(yyval.number)=~(yyvsp[(2) - (2)].number);}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 365 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 367 "c.y"
    {(yyval.number)=(yyvsp[(2) - (3)].number);}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 368 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 370 "c.y"
    {(yyval.number)=(yyvsp[(1) - (2)].number)++;}
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 371 "c.y"
    {(yyval.number)=(yyvsp[(1) - (2)].number)--;}
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 372 "c.y"
    {(yyval.number)=(yyvsp[(1) - (1)].number);}
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 373 "c.y"
    {
								//printf("%s\n",$1);
								int *p=getAddr(lis,(yyvsp[(1) - (1)].var_name));
								(yyval.number)=*p;
								}
    break;


/* Line 1787 of yacc.c  */
#line 2410 "y.tab.c"
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 379 "c.y"

int yywrap()
{
	return 1;
}
int yyerror(char *err)
{
	printf("Error: ");
	printf("Program terminated with return value %d\n",err);
}
int hashUtil(char *name)
{
    int addition=0,i;
    for(i=0;name[i]!='\0';i++)
        addition+=(int)name[i];
    return addition%200;
}
n* createNode(char *name,int *addr)
{
	n *temp=(n*)malloc(sizeof(n));
	temp->link=NULL;
	temp->name=name;
	temp->addr=addr;
	return temp;
}
// 1 success 0 fail
void insert(l *list,char *name)
{
	int *a=(int *) malloc(sizeof(int));
    int index=hashUtil(name);
	//printf("Inside insert\n");
    list[index].count++;
    if(list[index].link==NULL)
    {
		//printf("Inside insert link NLL\n");
    	list[index].link=createNode(name,a);
    }
    else
    {
        n *temp=list[index].link,*prev=list[index].link;
		//printf("Inside insert insde else\n");
        while(temp!=NULL && strcmp(temp->name,name))
        {
			//printf("%d\n",strcmp(temp->name,name));
			//printf("Inside insert while\n");
        	prev=temp;
            temp=temp->link;
        }
        if(!strcmp(temp->name,name))
        {
        	printf("Oops: Duplicate variable declaration!\n");
			exit(0);
        }
		else{
			//printf("Inside insert\n");
			prev->link=createNode(name,a);
		}
    }
	//printf("Inside insert end\n");
}
void removeUtil(l *list,char *name)
{
    int index=hashUtil(name);
    n *temp,*prev;
    if(list[index].count==1)
    {
    	temp=list[index].link;
    	free(temp);    	
        list[index].link=NULL;
    }
    else
    {
    	if(list[index].link->name==name)
    	{
    		temp=list[index].link;
    		list[index].link=list[index].link->link;
    		free(temp);
    		
    	}
    	else
    	{
	        temp=list[index].link->link;
			prev=list[index].link;
	        while(temp!=NULL  && temp->name!=name)
	        {
	            prev=temp;
	            temp=temp->link;
	        }
	        prev->link=temp->link;
	        free(temp);
	    }
    }
    list[index].count--;
}
void printUtil(l *list,int index)
{
	n *temp=list[index].link;
	while(temp!=NULL)
	{
		printf("%d \n",*temp->addr);
		temp=temp->link;
	}
	printf("\n");
}
void freeListUtil(n *node)
{
	if(node==NULL)
		return;
	else
	{
		freeListUtil(node->link);
	}
	n *temp=node;
	free(temp);	
}
void freeList(l *list)
{
	int i;
	for(i=0;i<200;i++)
	{
		freeListUtil(list[i].link);
		list[i].link=NULL;
	}
}
int* getAddr(l *list,char *name)
{
	//printf("%s\n",name);
	//printf("Inside getAddr\n");
	int index=hashUtil(name);
	n *temp=list[index].link;
	//printf("Inside getAddr\n");
	while(temp!=NULL && strcmp(temp->name,name) )
	{
		//printf("Inside getAddr while\n");
		temp=temp->link;
	}
	if(temp==NULL)
	{
		printf("Error: No such variable declared\n");
		exit(0);
	}
	else
	{
		//printf("Inside getAddr\n");
		return temp->addr;
	}
}
int getVal(l *list,char *name)
{
	int index=hashUtil(name);
	n *temp=list[index].link;
	while(temp->name!=name)
	{
		temp=temp->link;
	}
	return *(temp->addr);
}
void if_push()
{
	if_stack[++if_top]=result;	
}
int if_pop()
{
	return if_stack[if_top--];
}
int main(int argc,char *argv[])
{
	int i;
	int a,b,c;
	yyin=fopen(argv[1],"r");
	lis=(l*)malloc(sizeof(l)*200);
	l *lis2=(l*)malloc(sizeof(l)*200);
	for(i=0;i<200;i++)
	{
	lis[i].link=NULL;
	lis[i].count=0;
	}
	yyparse();	
	fclose(yyin);
	return 0;
}