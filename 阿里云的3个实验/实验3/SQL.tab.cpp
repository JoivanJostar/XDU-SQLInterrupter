/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

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
#line 1 "SQL.y"

	#include"Operate.h"
	#include "calculate.h"
	#include<iostream>
	using namespace std;
	extern int yylex(void);
	int yyerror(char * msg);
	bool exitflag;

/* Line 371 of yacc.c  */
#line 78 "SQL.tab.cpp"

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
   by #include "SQL.tab.h".  */
#ifndef YY_YY_SQL_TAB_H_INCLUDED
# define YY_YY_SQL_TAB_H_INCLUDED
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
     CREATE = 259,
     DROP = 260,
     USE = 261,
     SELECT = 262,
     INSERT = 263,
     DELETE = 264,
     UPDATE = 265,
     FROM = 266,
     WHERE = 267,
     INTO = 268,
     VALUES = 269,
     SET = 270,
     DATABASE = 271,
     DATABASES = 272,
     TABLE = 273,
     PRIMARY = 274,
     KEY = 275,
     null = 276,
     ORDER = 277,
     GROUP = 278,
     BY = 279,
     LIKE = 280,
     ALTER = 281,
     HAVING = 282,
     IN = 283,
     EXISTS = 284,
     TABLES = 285,
     ASC = 286,
     DESC = 287,
     ADD = 288,
     COLUMN = 289,
     VIEW = 290,
     INDEX = 291,
     DOUBLE = 292,
     SHOW = 293,
     FOREIGN = 294,
     REFERENCES = 295,
     RESTRICT = 296,
     CASCADE = 297,
     EXIT = 298,
     BYE = 299,
     VARCHAR = 300,
     LRU = 301,
     ID = 302,
     STRING = 303,
     INTNUMBER = 304,
     DOUBLENUMBER = 305,
     STRINGS = 306,
     OR = 307,
     AND = 308,
     NOT = 309
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 12 "SQL.y"

	/* ID和变量类型 */
	struct values value;

	/* createtable类型 */
	struct colname* colname;
	struct coltype* coltype;
	struct colconf* colconf;
	struct cols* cols;
	struct tableconf* tableconf;
	struct createsql* createsql;

	/* select类型 */
	struct comparator* comparator;
	struct condition* condition;
	struct tablecolconfs* tablecolconfs;
	struct selectsql* selectsql;
	int comp_op;
	/* insert类型 */
	struct dataformat* dataformat;
	struct insertsql* insertsql;

	/* update类型 */
	struct setconf* setconf;
	struct updatesql* updatesql;
	/* delete类型 */
	struct deletesql* deletesql;

	struct calvalue* calvalue;


/* Line 387 of yacc.c  */
#line 207 "SQL.tab.cpp"
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

#endif /* !YY_YY_SQL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 235 "SQL.tab.cpp"

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNRULES -- Number of states.  */
#define YYNSTATES  237

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    68,     2,     2,     2,    67,     2,     2,
      49,    50,    65,    63,    47,    64,    51,    66,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    48,
      58,    57,    59,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    52,    53,    54,    55,    56,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    41,
      46,    51,    53,    57,    61,    65,    74,    82,    84,    86,
      88,    91,    96,    98,   101,   111,   113,   117,   121,   123,
     127,   129,   133,   136,   138,   140,   142,   147,   150,   153,
     156,   164,   169,   175,   181,   187,   194,   201,   208,   210,
     212,   214,   218,   220,   224,   226,   228,   230,   234,   237,
     239,   243,   247,   250,   254,   259,   265,   271,   278,   282,
     284,   286,   288,   290,   292,   295,   298,   300,   303,   307,
     312,   315,   319,   321,   325,   327,   330,   333,   340,   346,
     350,   355,   357,   359,   363,   365,   367,   371,   375,   379,
     383,   386,   390,   392,   394,   401,   407,   409,   413,   417,
     423,   428,   434,   435,   437
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,    71,    -1,    70,    71,    -1,    79,    -1,
      92,    -1,   108,    -1,   114,    -1,   117,    -1,   118,    -1,
      72,    -1,    77,    -1,    73,    -1,    76,    -1,    74,    -1,
      78,    -1,    43,    -1,    44,    -1,     4,    16,    75,    48,
      -1,     5,    16,    75,    48,    -1,     6,    16,    75,    48,
      -1,    52,    -1,    38,    17,    48,    -1,    38,    30,    48,
      -1,    38,    46,    48,    -1,     4,    18,    80,    49,    87,
      81,    50,    48,    -1,     4,    18,    80,    49,    87,    50,
      48,    -1,    52,    -1,    82,    -1,    83,    -1,    81,    81,
      -1,    47,    19,    20,    85,    -1,    84,    -1,    83,    84,
      -1,    47,    39,    20,    85,    40,    80,    49,    86,    50,
      -1,    89,    -1,    49,    86,    50,    -1,    86,    47,    89,
      -1,    89,    -1,    87,    47,    88,    -1,    88,    -1,    89,
      90,    91,    -1,    89,    90,    -1,    52,    -1,     3,    -1,
      37,    -1,    45,    49,    54,    50,    -1,    62,    21,    -1,
      19,    20,    -1,    93,    48,    -1,     7,    94,    11,    97,
      98,   103,   105,    -1,     7,    94,    11,    97,    -1,     7,
      94,    11,    97,    98,    -1,     7,    94,    11,    97,   103,
      -1,     7,    94,    11,    97,   105,    -1,     7,    94,    11,
      97,    98,   103,    -1,     7,    94,    11,    97,    98,   105,
      -1,     7,    94,    11,    97,   103,   105,    -1,    65,    -1,
      95,    -1,    96,    -1,    95,    47,    96,    -1,    89,    -1,
      80,    51,    89,    -1,    53,    -1,    56,    -1,    80,    -1,
      97,    47,    80,    -1,    12,    99,    -1,   100,    -1,    99,
      61,    99,    -1,    99,    60,    99,    -1,    62,    99,    -1,
      49,    99,    50,    -1,    29,    49,    93,    50,    -1,   101,
     102,    49,    93,    50,    -1,   101,    28,    49,    93,    50,
      -1,   101,    62,    28,    49,    93,    50,    -1,   101,   102,
     101,    -1,   113,    -1,    53,    -1,    96,    -1,    58,    -1,
      59,    -1,    58,    57,    -1,    59,    57,    -1,    57,    -1,
      68,    57,    -1,    23,    24,    95,    -1,    23,    24,    95,
     104,    -1,    27,    99,    -1,    22,    24,   106,    -1,   107,
      -1,   106,    47,   107,    -1,    96,    -1,    96,    31,    -1,
      96,    32,    -1,     8,    13,    80,   109,   110,    48,    -1,
       8,    13,    80,   110,    48,    -1,    49,    86,    50,    -1,
      14,    49,   111,    50,    -1,    92,    -1,   112,    -1,   111,
      47,   112,    -1,    53,    -1,   113,    -1,   113,    63,   113,
      -1,   113,    64,   113,    -1,   113,    65,   113,    -1,   113,
      66,   113,    -1,    64,   113,    -1,    49,   113,    50,    -1,
      54,    -1,    55,    -1,    10,    80,    15,   115,    98,    48,
      -1,    10,    80,    15,   115,    48,    -1,   116,    -1,   115,
      47,   116,    -1,    89,    57,   112,    -1,     9,    11,    80,
      98,    48,    -1,     9,    11,    80,    48,    -1,     5,    18,
      80,   119,    48,    -1,    -1,    41,    -1,    42,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    85,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   105,   108,
     111,   114,   122,   125,   128,   131,   139,   150,   161,   162,
     163,   168,   178,   179,   181,   190,   191,   194,   195,   198,
     199,   202,   212,   225,   237,   238,   239,   244,   245,   248,
     251,   252,   259,   266,   267,   268,   269,   270,   274,   275,
     277,   278,   280,   281,   282,   291,   303,   304,   307,   314,
     315,   323,   331,   338,   339,   340,   341,   342,   346,   358,
     386,   395,   412,   413,   414,   415,   416,   417,   420,   421,
     424,   427,   429,   430,   432,   433,   434,   437,   443,   451,
     454,   455,   458,   459,   463,   472,   498,   505,   512,   519,
     526,   534,   535,   541,   551,   557,   565,   566,   568,   571,
     572,   575,   578,   579,   580
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CREATE", "DROP", "USE", "SELECT",
  "INSERT", "DELETE", "UPDATE", "FROM", "WHERE", "INTO", "VALUES", "SET",
  "DATABASE", "DATABASES", "TABLE", "PRIMARY", "KEY", "null", "ORDER",
  "GROUP", "BY", "LIKE", "ALTER", "HAVING", "IN", "EXISTS", "TABLES",
  "ASC", "DESC", "ADD", "COLUMN", "VIEW", "INDEX", "DOUBLE", "SHOW",
  "FOREIGN", "REFERENCES", "RESTRICT", "CASCADE", "EXIT", "BYE", "VARCHAR",
  "LRU", "','", "';'", "'('", "')'", "'.'", "ID", "STRING", "INTNUMBER",
  "DOUBLENUMBER", "STRINGS", "'='", "'<'", "'>'", "OR", "AND", "NOT",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept", "statements",
  "statement", "createdb", "dropdb", "usedb", "dbname", "showdb",
  "showtable", "showlru", "createsql", "tablename", "tableconf",
  "primarykeyconf", "foreignkeyconfs", "foreignkeyconf", "colnameconf",
  "colnames", "cols", "col", "colname", "coltype", "colconf", "selectsql",
  "select", "tablecolconf", "tablecols", "tablecol", "tables", "whereconf",
  "conditions", "condition", "comparator", "comp_op", "groupconf",
  "having", "orderconf", "ordercols", "ordercol", "insertsql",
  "insertcolname", "valuesargs", "values", "value", "cal", "updatesql",
  "setconfs", "setconf", "deletesql", "dropsql", "droptableconf", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,    44,    59,    40,
      41,    46,   302,   303,   304,   305,   306,    61,    60,    62,
     307,   308,   309,    43,    45,    42,    47,    37,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    79,    80,    81,    81,
      81,    82,    83,    83,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    90,    90,    90,    91,    91,    92,
      93,    93,    93,    93,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    96,    96,    96,    97,    97,    98,    99,
      99,    99,    99,    99,    99,    99,    99,    99,   100,   101,
     101,   101,   102,   102,   102,   102,   102,   102,   103,   103,
     104,   105,   106,   106,   107,   107,   107,   108,   108,   109,
     110,   110,   111,   111,   112,   112,   113,   113,   113,   113,
     113,   113,   113,   113,   114,   114,   115,   115,   116,   117,
     117,   118,   119,   119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     1,     3,     3,     3,     8,     7,     1,     1,     1,
       2,     4,     1,     2,     9,     1,     3,     3,     1,     3,
       1,     3,     2,     1,     1,     1,     4,     2,     2,     2,
       7,     4,     5,     5,     5,     6,     6,     6,     1,     1,
       1,     3,     1,     3,     1,     1,     1,     3,     2,     1,
       3,     3,     2,     3,     4,     5,     5,     6,     3,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     3,     4,
       2,     3,     1,     3,     1,     2,     2,     6,     5,     3,
       4,     1,     1,     3,     1,     1,     3,     3,     3,     3,
       2,     3,     1,     1,     6,     5,     1,     3,     3,     5,
       4,     5,     0,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,     0,     2,    10,    12,    14,    13,    11,    15,     4,
       5,     0,     6,     7,     8,     9,     0,     0,     0,     0,
       0,    43,    64,    65,    58,     0,    62,     0,    59,    60,
       0,     0,    27,     0,     0,     0,     0,     1,     3,    49,
      21,     0,     0,     0,   122,     0,     0,     0,     0,     0,
       0,     0,    22,    23,    24,    18,     0,    19,   123,   124,
       0,    20,    43,    63,    66,    51,    61,     0,     0,   101,
       0,     0,     0,   120,     0,     0,     0,   116,     0,    40,
       0,   121,     0,     0,     0,    52,    53,    54,     0,     0,
      38,     0,    98,     0,     0,    64,   112,   113,     0,     0,
      81,    68,    69,     0,    79,   119,     0,     0,   115,     0,
       0,     0,     0,    28,    29,    32,    44,    45,     0,    42,
       0,     0,    67,    55,    56,    57,     0,   104,     0,   102,
     105,     0,    99,    97,     0,     0,    79,    72,   110,     0,
       0,     0,    86,    82,    83,     0,     0,     0,     0,     0,
       0,     0,   118,   117,   114,     0,     0,    39,    26,     0,
       0,    30,     0,    33,     0,     0,     0,    41,    94,    91,
      92,    88,    50,     0,     0,   100,    37,     0,    73,   111,
      71,    70,     0,    84,    85,     0,    87,     0,    78,   106,
     107,   108,   109,     0,     0,    25,     0,    48,    47,    95,
      96,     0,     0,    89,   103,    74,     0,     0,     0,     0,
      31,    35,     0,    46,    93,    90,    76,     0,    75,     0,
       0,    77,    36,     0,     0,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    51,    16,    17,    18,
      19,    35,   171,   123,   124,   125,   220,    99,    88,    89,
      36,   129,   177,    20,    21,    37,    38,   110,    75,    84,
     111,   112,   113,   157,    96,   213,    97,   179,   180,    22,
      80,    81,   138,   139,   114,    23,    86,    87,    24,    25,
      70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -197
static const yytype_int16 yypact[] =
{
      93,   141,   157,    24,   130,    72,   103,    56,    59,  -197,
    -197,    86,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,    92,  -197,  -197,  -197,  -197,   113,    56,   113,    56,
     113,    70,  -197,  -197,  -197,   129,  -197,   163,   137,  -197,
      56,    56,  -197,   175,   146,   152,   153,  -197,  -197,  -197,
    -197,   154,   155,   158,   107,   159,   151,    56,   -37,     0,
      18,   151,  -197,  -197,  -197,  -197,   151,  -197,  -197,  -197,
     162,  -197,  -197,  -197,  -197,    23,  -197,   156,   151,  -197,
      30,   164,    90,  -197,   165,   160,    14,  -197,    -8,  -197,
       6,  -197,   185,   187,    56,    49,   192,  -197,   123,    73,
    -197,   168,  -197,   166,    90,  -197,  -197,  -197,    90,    20,
    -197,   132,  -197,    54,    69,  -197,   123,   151,  -197,   170,
       2,   171,    91,  -197,   173,  -197,  -197,  -197,   172,    -2,
     -37,   -37,  -197,   192,  -197,  -197,    20,  -197,   106,  -197,
      69,   151,  -197,  -197,   215,    65,    97,  -197,   131,    90,
      90,   176,  -197,   169,   174,   196,   177,   115,    20,    20,
      20,    20,  -197,  -197,  -197,   207,   208,  -197,  -197,    44,
     181,   183,   193,  -197,   179,   216,   214,  -197,   167,   190,
    -197,   -15,  -197,    97,   123,  -197,  -197,   188,  -197,  -197,
     178,  -197,   215,  -197,  -197,   191,  -197,     4,  -197,   131,
     131,  -197,  -197,    57,    57,  -197,   194,  -197,  -197,  -197,
    -197,   -37,    90,  -197,  -197,  -197,   195,   215,   197,   151,
    -197,  -197,   201,  -197,  -197,   132,  -197,   198,  -197,   108,
      56,  -197,  -197,   200,   151,   138,  -197
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,   231,  -197,  -197,  -197,   161,  -197,  -197,  -197,
    -197,    -7,   180,  -197,  -197,   119,    42,  -196,  -197,   133,
     -53,  -197,  -197,   -49,  -140,  -197,   120,    -3,  -197,    32,
    -102,  -197,    95,  -197,   182,  -197,   -68,  -197,    39,  -197,
    -197,   184,  -197,  -111,   -80,  -197,  -197,   139,  -197,  -197,
    -197
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -28
static const yytype_int16 yytable[] =
{
      43,    39,   145,    73,   187,   162,   147,     4,    85,   126,
      79,     4,   212,    90,    77,    31,    32,   175,   140,    33,
      52,   165,    54,   229,   146,   100,    82,   134,   135,   148,
      82,    79,    58,    59,    60,    82,   140,     4,   235,   120,
      30,   166,   121,   127,    77,    92,    93,   190,   191,    78,
      74,   128,   216,   136,    72,    76,   183,   218,   106,   107,
     176,   117,   118,   165,    85,   182,    83,    90,   109,   136,
      94,    92,    93,   214,   106,   107,    44,   227,   199,   200,
     201,   202,   151,   166,   109,    40,    47,   132,   186,    45,
       1,     2,     3,     4,     5,     6,     7,     1,     2,     3,
       4,     5,     6,     7,   140,    46,   219,    95,    42,    72,
     225,   152,   153,   154,    41,   188,   155,   183,   119,   103,
     141,   -27,   156,   142,     8,   149,   150,   178,    39,     9,
      10,     8,   158,   159,   160,   161,     9,    10,   169,   104,
      49,   170,    31,   105,   106,   107,    33,   189,    68,    69,
     221,   221,   108,   184,   109,   141,   185,    26,   232,    27,
     158,   159,   160,   161,   197,    50,   100,    31,   105,   106,
     107,    33,   136,    28,    57,    29,   137,   106,   107,   109,
      56,   100,    31,    32,    58,   141,    33,   109,   236,    53,
      61,    55,   149,   150,    62,    34,   160,   161,   209,   210,
      63,    64,    65,    72,    66,    98,    67,    71,   178,   130,
      91,   131,   102,   115,    92,   144,   143,   116,   164,   168,
     172,   174,     4,   233,   195,   192,   193,   203,   204,   205,
     169,   194,   166,   206,   196,   208,   207,   211,   215,   150,
     217,   230,    48,   173,   223,   226,   222,   228,   231,   234,
     224,   181,   198,   167,     0,     0,   163,     0,     0,     0,
       0,     0,     0,     0,   101,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   133
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-197)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       7,     4,   104,    56,   144,   116,   108,     7,    61,     3,
      59,     7,    27,    66,    14,    52,    53,    19,    98,    56,
      27,    19,    29,   219,   104,    78,    12,    95,    96,   109,
      12,    80,    47,    40,    41,    12,   116,     7,   234,    47,
      16,    39,    50,    37,    14,    22,    23,   149,   150,    49,
      57,    45,   192,    49,    52,    58,   136,   197,    54,    55,
      62,    47,    48,    19,   117,   133,    48,   120,    64,    49,
      47,    22,    23,   184,    54,    55,    17,   217,   158,   159,
     160,   161,    28,    39,    64,    13,     0,    94,   141,    30,
       4,     5,     6,     7,     8,     9,    10,     4,     5,     6,
       7,     8,     9,    10,   184,    46,    49,    75,    52,    52,
     212,    57,    58,    59,    11,    50,    62,   197,    86,    29,
      47,    51,    68,    50,    38,    60,    61,   130,   131,    43,
      44,    38,    63,    64,    65,    66,    43,    44,    47,    49,
      48,    50,    52,    53,    54,    55,    56,    50,    41,    42,
     203,   204,    62,    47,    64,    47,    50,    16,    50,    18,
      63,    64,    65,    66,    49,    52,   219,    52,    53,    54,
      55,    56,    49,    16,    11,    18,    53,    54,    55,    64,
      51,   234,    52,    53,    47,    47,    56,    64,    50,    28,
      15,    30,    60,    61,    48,    65,    65,    66,    31,    32,
      48,    48,    48,    52,    49,    49,    48,    48,   211,    24,
      48,    24,    48,    48,    22,    49,    48,    57,    48,    48,
      47,    49,     7,   230,    28,    49,    57,    20,    20,    48,
      47,    57,    39,    54,    57,    21,    20,    47,    50,    61,
      49,    40,    11,   124,    50,    50,   204,    50,    50,    49,
     211,   131,   157,   120,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,     7,     8,     9,    10,    38,    43,
      44,    70,    71,    72,    73,    74,    76,    77,    78,    79,
      92,    93,   108,   114,   117,   118,    16,    18,    16,    18,
      16,    52,    53,    56,    65,    80,    89,    94,    95,    96,
      13,    11,    52,    80,    17,    30,    46,     0,    71,    48,
      52,    75,    80,    75,    80,    75,    51,    11,    47,    80,
      80,    15,    48,    48,    48,    48,    49,    48,    41,    42,
     119,    48,    52,    89,    80,    97,    96,    14,    49,    92,
     109,   110,    12,    48,    98,    89,   115,   116,    87,    88,
      89,    48,    22,    23,    47,    98,   103,   105,    49,    86,
      89,   110,    48,    29,    49,    53,    54,    55,    62,    64,
      96,    99,   100,   101,   113,    48,    57,    47,    48,    98,
      47,    50,    81,    82,    83,    84,     3,    37,    45,    90,
      24,    24,    80,   103,   105,   105,    49,    53,   111,   112,
     113,    47,    50,    48,    49,    99,   113,    99,   113,    60,
      61,    28,    57,    58,    59,    62,    68,   102,    63,    64,
      65,    66,   112,   116,    48,    19,    39,    88,    48,    47,
      50,    81,    47,    84,    49,    19,    62,    91,    96,   106,
     107,    95,   105,   113,    47,    50,    89,    93,    50,    50,
      99,    99,    49,    57,    57,    28,    57,    49,   101,   113,
     113,   113,   113,    20,    20,    48,    54,    20,    21,    31,
      32,    47,    27,   104,   112,    50,    93,    49,    93,    49,
      85,    89,    85,    50,   107,    99,    50,    93,    50,    86,
      40,    50,    50,    80,    49,    86,    50
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
  switch (yytype)
    {
      default:
        break;
    }
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

  switch (yytype)
    {

      default:
        break;
    }
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
/* Line 1792 of yacc.c  */
#line 84 "SQL.y"
    {return 0;}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 85 "SQL.y"
    {return 0;}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 88 "SQL.y"
    {createtable((yyvsp[(1) - (1)].createsql));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 89 "SQL.y"
    {selecttable((yyvsp[(1) - (1)].selectsql));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 90 "SQL.y"
    {inserttable((yyvsp[(1) - (1)].insertsql));}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 91 "SQL.y"
    {updatetable((yyvsp[(1) - (1)].updatesql));}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 92 "SQL.y"
    {deletetable((yyvsp[(1) - (1)].deletesql));}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 100 "SQL.y"
    {exitflag=true;return 0;}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 101 "SQL.y"
    {exitflag=true;return 0;}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 105 "SQL.y"
    {createdb((yyvsp[(3) - (4)].value).name);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 108 "SQL.y"
    {dropdb((yyvsp[(3) - (4)].value).name);}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 111 "SQL.y"
    {usedb((yyvsp[(3) - (4)].value).name);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 115 "SQL.y"
    {
		(yyval.value).length = (yyvsp[(1) - (1)].value).length;
		(yyval.value).name = (char *)malloc((yyvsp[(1) - (1)].value).length+1);
		strcpy_s((yyval.value).name,(yyvsp[(1) - (1)].value).length+1, (yyvsp[(1) - (1)].value).name);
	}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 122 "SQL.y"
    {showdb();}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 125 "SQL.y"
    {showtable();}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 128 "SQL.y"
    {showLRUlist();}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 132 "SQL.y"
    {
		  (yyval.createsql) = new struct createsql;
		  (yyval.createsql)->tablename = (char *)malloc((yyvsp[(3) - (8)].colname)->tablelength+1);
		  strcpy_s((yyval.createsql)->tablename, (yyvsp[(3) - (8)].colname)->tablelength+1, (yyvsp[(3) - (8)].colname)->tablename);
		  (yyval.createsql)->cols = (yyvsp[(5) - (8)].cols);
		  (yyval.createsql)->tableconf = (yyvsp[(6) - (8)].tableconf);
	      }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 140 "SQL.y"
    {
		 (yyval.createsql) = new struct createsql;
		  (yyval.createsql)->tablename = (char *)malloc((yyvsp[(3) - (7)].colname)->tablelength+1);
		  strcpy_s((yyval.createsql)->tablename, (yyvsp[(3) - (7)].colname)->tablelength+1, (yyvsp[(3) - (7)].colname)->tablename);
		  (yyval.createsql)->cols = (yyvsp[(5) - (7)].cols);
		  (yyval.createsql)->tableconf = NULL;
		 }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 151 "SQL.y"
    {
		(yyval.colname) = new struct colname;
		(yyval.colname)->tablelength = (yyvsp[(1) - (1)].value).length;
		(yyval.colname)->tablename = (char *)malloc((yyvsp[(1) - (1)].value).length+1);
		strcpy_s((yyval.colname)->tablename,(yyvsp[(1) - (1)].value).length+1, (yyvsp[(1) - (1)].value).name);
		(yyval.colname)->next=NULL;
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 161 "SQL.y"
    {(yyval.tableconf) = (yyvsp[(1) - (1)].tableconf);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 162 "SQL.y"
    {(yyval.tableconf) = (yyvsp[(1) - (1)].tableconf);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 163 "SQL.y"
    {(yyval.tableconf)=(yyvsp[(1) - (2)].tableconf); while((yyvsp[(1) - (2)].tableconf)->next!=NULL)(yyvsp[(1) - (2)].tableconf) = (yyvsp[(1) - (2)].tableconf)->next; (yyvsp[(1) - (2)].tableconf)->next = (yyvsp[(2) - (2)].tableconf);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 169 "SQL.y"
    {
					(yyval.tableconf) = new struct tableconf;
					(yyval.tableconf)->con = 1;
					(yyval.tableconf)->colnames = (yyvsp[(4) - (4)].colname);
					(yyval.tableconf)->next = NULL;
			   }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 178 "SQL.y"
    {(yyval.tableconf) = (yyvsp[(1) - (1)].tableconf);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 179 "SQL.y"
    {(yyval.tableconf)=(yyvsp[(1) - (2)].tableconf); while((yyvsp[(1) - (2)].tableconf)->next!=NULL)(yyvsp[(1) - (2)].tableconf) = (yyvsp[(1) - (2)].tableconf)->next; (yyvsp[(1) - (2)].tableconf)->next = (yyvsp[(2) - (2)].tableconf); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 181 "SQL.y"
    {
                                                                                 (yyval.tableconf) = new struct tableconf;
																				 (yyval.tableconf)->con = 3; 
																				 (yyval.tableconf)->colnames = (yyvsp[(4) - (9)].colname); 
																				 (yyval.tableconf)->refertable = (yyvsp[(6) - (9)].colname)->tablename;
																				 (yyval.tableconf)->refercol = (yyvsp[(8) - (9)].colname)->name;
																				 (yyval.tableconf)->next = NULL;}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 190 "SQL.y"
    {(yyval.colname) = (yyvsp[(1) - (1)].colname);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 191 "SQL.y"
    {(yyval.colname) = (yyvsp[(2) - (3)].colname);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 194 "SQL.y"
    {(yyval.colname) = (yyvsp[(1) - (3)].colname);while((yyvsp[(1) - (3)].colname)->next!=NULL)(yyvsp[(1) - (3)].colname) = (yyvsp[(1) - (3)].colname)->next; (yyvsp[(1) - (3)].colname)->next = (yyvsp[(3) - (3)].colname);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 195 "SQL.y"
    {(yyval.colname) = (yyvsp[(1) - (1)].colname);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 198 "SQL.y"
    {(yyval.cols) = (yyvsp[(1) - (3)].cols);while((yyvsp[(1) - (3)].cols)->next!=NULL)(yyvsp[(1) - (3)].cols) = (yyvsp[(1) - (3)].cols)->next; (yyvsp[(1) - (3)].cols)->next = (yyvsp[(3) - (3)].cols);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 199 "SQL.y"
    {(yyval.cols) = (yyvsp[(1) - (1)].cols);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 203 "SQL.y"
    {
		(yyval.cols) = new struct cols;
		(yyval.cols)->colname = (char *)malloc((yyvsp[(1) - (3)].colname)->columelength+1);
		strcpy_s((yyval.cols)->colname, (yyvsp[(1) - (3)].colname)->columelength+1, (yyvsp[(1) - (3)].colname)->name);
		(yyval.cols)->coltype = (yyvsp[(2) - (3)].coltype)->type;
		(yyval.cols)->length = (yyvsp[(2) - (3)].coltype)->length;
		(yyval.cols)->colconf = (yyvsp[(3) - (3)].colconf);
		(yyval.cols)->next = NULL;
	}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 213 "SQL.y"
    {
		(yyval.cols) = new struct cols;
		(yyval.cols)->colname = (char *)malloc((yyvsp[(1) - (2)].colname)->columelength+1);
		strcpy_s((yyval.cols)->colname, (yyvsp[(1) - (2)].colname)->columelength+1, (yyvsp[(1) - (2)].colname)->name);
		(yyval.cols)->coltype = (yyvsp[(2) - (2)].coltype)->type;
		(yyval.cols)->length = (yyvsp[(2) - (2)].coltype)->length;
		(yyval.cols)->colconf = NULL;
		(yyval.cols)->next = NULL;
   }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 226 "SQL.y"
    {
		(yyval.colname) = new struct colname;
		(yyval.colname)->columelength = (yyvsp[(1) - (1)].value).length;
		(yyval.colname)->name = (char *)malloc((yyvsp[(1) - (1)].value).length+1);
		strcpy_s((yyval.colname)->name, (yyvsp[(1) - (1)].value).length+1, (yyvsp[(1) - (1)].value).name);
		(yyval.colname)->name[(yyvsp[(1) - (1)].value).length]='\0';
		(yyval.colname)->exist = 1;
		(yyval.colname)->next = NULL;
	}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 237 "SQL.y"
    {(yyval.coltype) = new struct coltype; (yyval.coltype)->type = 1; (yyval.coltype)->length = 4;}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 238 "SQL.y"
    {(yyval.coltype) = new struct coltype;(yyval.coltype)->type = 2; (yyval.coltype)->length = 8;}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 239 "SQL.y"
    {(yyval.coltype) = new struct coltype;(yyval.coltype)->type = 3; (yyval.coltype)->length = (yyvsp[(3) - (4)].value).intnum;}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 244 "SQL.y"
    {(yyval.colconf) = new struct colconf;(yyval.colconf)->con = 2;(yyval.colconf)->next = NULL;}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 245 "SQL.y"
    {(yyval.colconf) = new struct colconf;(yyval.colconf)->con = 1;(yyval.colconf)->next = NULL;}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 248 "SQL.y"
    {(yyval.selectsql) = (yyvsp[(1) - (2)].selectsql);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 252 "SQL.y"
    {
	                                     (yyval.selectsql) = new struct selectsql;
										 (yyval.selectsql)->isall = (yyvsp[(2) - (4)].tablecolconfs)->isall;
										 (yyval.selectsql)->colnames = (yyvsp[(2) - (4)].tablecolconfs)->colnames;
										 (yyval.selectsql)->tablenames = (yyvsp[(4) - (4)].colname);
										 (yyval.selectsql)->condition_tree = NULL;
	                                     }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 259 "SQL.y"
    {
	                                                (yyval.selectsql) = new struct selectsql;
										            (yyval.selectsql)->isall = (yyvsp[(2) - (5)].tablecolconfs)->isall;
										            (yyval.selectsql)->colnames = (yyvsp[(2) - (5)].tablecolconfs)->colnames;
										            (yyval.selectsql)->tablenames = (yyvsp[(4) - (5)].colname);
										            (yyval.selectsql)->condition_tree = (yyvsp[(5) - (5)].condition);
													}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 274 "SQL.y"
    {(yyval.tablecolconfs) = new struct tablecolconfs; (yyval.tablecolconfs)->isall = 1;(yyval.tablecolconfs)->colnames = NULL;}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 275 "SQL.y"
    {(yyval.tablecolconfs) = new struct tablecolconfs; (yyval.tablecolconfs)->isall = 0;(yyval.tablecolconfs)->colnames = (yyvsp[(1) - (1)].colname);}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 277 "SQL.y"
    {(yyval.colname) = (yyvsp[(1) - (1)].colname); (yyval.colname)->num = 1;}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 278 "SQL.y"
    { (yyval.colname) = (yyvsp[(1) - (3)].colname);while((yyvsp[(1) - (3)].colname)->next!=NULL)(yyvsp[(1) - (3)].colname) = (yyvsp[(1) - (3)].colname)->next; (yyvsp[(1) - (3)].colname)->next = (yyvsp[(3) - (3)].colname); (yyval.colname)->num++;}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 280 "SQL.y"
    {(yyval.colname) = new struct colname;(yyval.colname)->exist = 1; (yyval.colname)->tablename =NULL; (yyval.colname)->name = new char[(yyvsp[(1) - (1)].colname)->columelength+1]; strcpy_s((yyval.colname)->name,(yyvsp[(1) - (1)].colname)->columelength+1,(yyvsp[(1) - (1)].colname)->name);(yyval.colname)->name[(yyvsp[(1) - (1)].colname)->columelength]='\0';(yyval.colname)->next = NULL;}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 281 "SQL.y"
    {(yyval.colname) = new struct colname; (yyval.colname)->exist = 1;(yyval.colname)->tablename =new char[(yyvsp[(1) - (3)].colname)->tablelength+1]; strcpy_s((yyval.colname)->tablename,(yyvsp[(1) - (3)].colname)->tablelength+1,(yyvsp[(1) - (3)].colname)->tablename);(yyval.colname)->tablename[(yyvsp[(1) - (3)].colname)->tablelength]='\0'; (yyval.colname)->name = new char[(yyvsp[(3) - (3)].colname)->columelength+1]; strcpy_s((yyval.colname)->name,(yyvsp[(3) - (3)].colname)->columelength+1,(yyvsp[(3) - (3)].colname)->name);(yyval.colname)->name[(yyvsp[(3) - (3)].colname)->columelength]='\0';(yyval.colname)->next = NULL;}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 282 "SQL.y"
    {(yyval.colname) = new struct colname;
		          (yyval.colname)->tablename = NULL;
                  (yyval.colname)->exist = 2;
				  (yyval.colname)->name = (char *)malloc((yyvsp[(1) - (1)].value).length-1);
                  strcpy_s((yyval.colname)->name,(yyvsp[(1) - (1)].value).length-2+1,(yyvsp[(1) - (1)].value).name+1);
			      (yyval.colname)->name[(yyvsp[(1) - (1)].value).length-3]='\0';
			      (yyval.colname)->columelength = (yyvsp[(1) - (1)].value).length-2;
                  (yyval.colname)->next = NULL;
		          }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 291 "SQL.y"
    {(yyval.colname) = new struct colname;
		          (yyval.colname)->tablename = NULL;
                  (yyval.colname)->exist = 2;
				  (yyval.colname)->name = (char *)malloc((yyvsp[(1) - (1)].value).length-1);
                  strcpy_s((yyval.colname)->name,(yyvsp[(1) - (1)].value).length-2+1,(yyvsp[(1) - (1)].value).name+1);
			      (yyval.colname)->name[(yyvsp[(1) - (1)].value).length-3]='\0';
			      (yyval.colname)->columelength = (yyvsp[(1) - (1)].value).length-2;
                  (yyval.colname)->next = NULL;
		          }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 303 "SQL.y"
    {(yyval.colname) = (yyvsp[(1) - (1)].colname);(yyval.colname)->num = 1;}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 304 "SQL.y"
    { (yyval.colname) = (yyvsp[(1) - (3)].colname);while((yyvsp[(1) - (3)].colname)->next!=NULL)(yyvsp[(1) - (3)].colname) = (yyvsp[(1) - (3)].colname)->next; (yyvsp[(1) - (3)].colname)->next = (yyvsp[(3) - (3)].colname); (yyval.colname)->num++;}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 307 "SQL.y"
    {(yyval.condition) = new struct condition;
                             (yyval.condition)->left_type = 5;
							 (yyval.condition)->left_cond = (yyvsp[(2) - (2)].condition);
							 (yyval.condition)->right_type = 0;
							 }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 314 "SQL.y"
    {(yyval.condition) = (yyvsp[(1) - (1)].condition);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 315 "SQL.y"
    {(yyval.condition) = new struct condition;
		                              (yyval.condition)->left_type = 5;
									  (yyval.condition)->left_cond = (yyvsp[(1) - (3)].condition);
									  (yyval.condition)->right_type = 5;
									  (yyval.condition)->right_cond = (yyvsp[(3) - (3)].condition);
									  (yyval.condition)->comp_op = 0;
									  (yyval.condition)->comp_cond = 1;
									  }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 323 "SQL.y"
    {(yyval.condition) = new struct condition;
		                              (yyval.condition)->left_type = 5;
									  (yyval.condition)->left_cond = (yyvsp[(1) - (3)].condition);
									  (yyval.condition)->right_type = 5;
									  (yyval.condition)->right_cond = (yyvsp[(3) - (3)].condition);
									  (yyval.condition)->comp_op = 0;
									  (yyval.condition)->comp_cond = 2;
									  }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 331 "SQL.y"
    {(yyval.condition) = new struct condition;
		                              (yyval.condition)->left_type = 0;
									  (yyval.condition)->right_type = 5;
									  (yyval.condition)->right_cond = (yyvsp[(2) - (2)].condition);
									  (yyval.condition)->comp_op = 0;
									  (yyval.condition)->comp_cond = 3;
									  }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 338 "SQL.y"
    {(yyval.condition) = (yyvsp[(2) - (3)].condition);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 346 "SQL.y"
    { (yyval.condition) = new struct condition;
		                                   (yyval.condition)->left_type = (yyvsp[(1) - (3)].comparator)->type;
									       (yyval.condition)->left_col = (yyvsp[(1) - (3)].comparator)->col;
										   (yyval.condition)->left_data = (yyvsp[(1) - (3)].comparator)->data;
									       (yyval.condition)->right_type = (yyvsp[(3) - (3)].comparator)->type;
									       (yyval.condition)->right_col = (yyvsp[(3) - (3)].comparator)->col;
										   (yyval.condition)->right_data = (yyvsp[(3) - (3)].comparator)->data;
									       (yyval.condition)->comp_op = (yyvsp[(2) - (3)].comp_op);
									       (yyval.condition)->comp_cond = 0;
									      }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 358 "SQL.y"
    {(yyval.comparator) = new struct comparator;
                     calculate((yyvsp[(1) - (1)].calvalue));
                     if((yyvsp[(1) - (1)].calvalue)->valuetype == 1) 
					 {
					     (yyval.comparator)->type = 1;
						 (yyval.comparator)->data = new struct dataformat;
						 (yyval.comparator)->data->data = (char *)malloc(4);
				         _itoa_s((yyvsp[(1) - (1)].calvalue)->intnum,(yyval.comparator)->data->data,4,10);
				         (yyval.comparator)->data->length = 4;
				         (yyval.comparator)->data->type = 1;
				         (yyval.comparator)->data->next = NULL; 
						 (yyval.comparator)->col = NULL;
				     }
					 if((yyvsp[(1) - (1)].calvalue)->valuetype == 2)
					 {
					     (yyval.comparator)->type = 2;
					     (yyval.comparator)->data = new struct dataformat;
						 (yyval.comparator)->data->data = (char *)malloc(8);
                         std::ostringstream o;
				         o<<(yyvsp[(1) - (1)].calvalue)->doublenum;
                         strcpy_s((yyval.comparator)->data->data,8,o.str().c_str());
				         (yyval.comparator)->data->data[8]='\0';
				         (yyval.comparator)->data->length = 8;
				         (yyval.comparator)->data->type = 2;
				         (yyval.comparator)->data->next = NULL; 
						 (yyval.comparator)->col = NULL;
                     }
                     }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 386 "SQL.y"
    {(yyval.comparator) = new struct comparator;
                     (yyval.comparator)->type = 3;
					 (yyval.comparator)->data = new struct dataformat;
					 (yyval.comparator)->data->data = (char *)malloc((yyvsp[(1) - (1)].value).length-1);
                     strcpy_s((yyval.comparator)->data->data,(yyvsp[(1) - (1)].value).length-2+1,(yyvsp[(1) - (1)].value).name+1);
			         (yyval.comparator)->data->data[(yyvsp[(1) - (1)].value).length-3]='\0';
			         (yyval.comparator)->data->length = (yyvsp[(1) - (1)].value).length-2;
                     (yyval.comparator)->col = NULL;
		             }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 395 "SQL.y"
    {(yyval.comparator) = new struct comparator;
		              if((yyvsp[(1) - (1)].colname)->exist == 2){
						(yyval.comparator)->type = 3;
					    (yyval.comparator)->data = new struct dataformat;
					    (yyval.comparator)->data->data = (char *)malloc((yyvsp[(1) - (1)].colname)->columelength+1);
						strcpy_s((yyval.comparator)->data->data,(yyvsp[(1) - (1)].colname)->columelength+1,(yyvsp[(1) - (1)].colname)->name);
			            (yyval.comparator)->data->data[(yyvsp[(1) - (1)].colname)->columelength]='\0';
						(yyval.comparator)->data->length = (yyvsp[(1) - (1)].colname)->columelength;
                        (yyval.comparator)->col = NULL;
					  }
					  else{
					    (yyval.comparator)->type = 4;
					    (yyval.comparator)->data = NULL;
                        (yyval.comparator)->col = (yyvsp[(1) - (1)].colname);
					  }
                     }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 412 "SQL.y"
    {(yyval.comp_op) = 1;}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 413 "SQL.y"
    {(yyval.comp_op) = 2;}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 414 "SQL.y"
    {(yyval.comp_op) = 3;}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 415 "SQL.y"
    {(yyval.comp_op) = 4;}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 416 "SQL.y"
    {(yyval.comp_op) = 5;}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 417 "SQL.y"
    {(yyval.comp_op) = 6;}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 437 "SQL.y"
    {
                                                               (yyval.insertsql) = new struct insertsql;
                                                               (yyval.insertsql)->tablename = (yyvsp[(3) - (6)].colname)->tablename;
															   (yyval.insertsql)->colnames = (yyvsp[(4) - (6)].colname);
															   (yyval.insertsql)->datas = (yyvsp[(5) - (6)].dataformat);
                                                               }
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 443 "SQL.y"
    {
		                                                       (yyval.insertsql) = new struct insertsql;
                                                               (yyval.insertsql)->tablename = (yyvsp[(3) - (5)].colname)->tablename;
															   (yyval.insertsql)->colnames = NULL;
															   (yyval.insertsql)->datas = (yyvsp[(4) - (5)].dataformat);
                                                               }
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 451 "SQL.y"
    {(yyval.colname) = (yyvsp[(2) - (3)].colname);}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 454 "SQL.y"
    {(yyval.dataformat) = (yyvsp[(3) - (4)].dataformat);}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 458 "SQL.y"
    {(yyval.dataformat)=(yyvsp[(1) - (1)].dataformat);}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 459 "SQL.y"
    {(yyval.dataformat) = (yyvsp[(1) - (3)].dataformat);while((yyvsp[(1) - (3)].dataformat)->next!=NULL)(yyvsp[(1) - (3)].dataformat) = (yyvsp[(1) - (3)].dataformat)->next; (yyvsp[(1) - (3)].dataformat)->next = (yyvsp[(3) - (3)].dataformat);}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 463 "SQL.y"
    {
               (yyval.dataformat) = new struct dataformat;
			   (yyval.dataformat)->data = (char *)malloc((yyvsp[(1) - (1)].value).length-1);
               strcpy_s((yyval.dataformat)->data,(yyvsp[(1) - (1)].value).length-2+1,(yyvsp[(1) - (1)].value).name+1);
			   (yyval.dataformat)->data[(yyvsp[(1) - (1)].value).length-3]='\0';
			   (yyval.dataformat)->length = (yyvsp[(1) - (1)].value).length-2;
			   (yyval.dataformat)->type = 3;
       		   (yyval.dataformat)->next = NULL;
			   }
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 472 "SQL.y"
    {(yyval.dataformat) = new struct dataformat;
	           calculate((yyvsp[(1) - (1)].calvalue));
                     if((yyvsp[(1) - (1)].calvalue)->valuetype == 1) 
					 {
						 (yyval.dataformat)->data = (char *)malloc(4);
				         _itoa_s((yyvsp[(1) - (1)].calvalue)->intnum,(yyval.dataformat)->data,4,10);
				         (yyval.dataformat)->length = 4;
				         (yyval.dataformat)->type = 1;
				         (yyval.dataformat)->next = NULL; 
				     }
					 if((yyvsp[(1) - (1)].calvalue)->valuetype == 2)
					 {
						 (yyval.dataformat)->data = (char *)malloc(8);
                         std::ostringstream o;
				         o<<(yyvsp[(1) - (1)].calvalue)->doublenum;
                         strcpy_s((yyval.dataformat)->data,8,o.str().c_str());
				         (yyval.dataformat)->data[8]='\0';
				         (yyval.dataformat)->length = 8;
				         (yyval.dataformat)->type = 2;
				         (yyval.dataformat)->next = NULL; 
                     }
	 
	          }
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 498 "SQL.y"
    { (yyval.calvalue) = new struct calvalue;
				  /* 补充代码 */
				  (yyval.calvalue)->valuetype=3;
				  (yyval.calvalue)->caltype=1;
				  (yyval.calvalue)->leftcal=(yyvsp[(1) - (3)].calvalue);
				  (yyval.calvalue)->rightcal=(yyvsp[(3) - (3)].calvalue);
				 }
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 505 "SQL.y"
    { (yyval.calvalue) = new struct calvalue;
				  /* 补充代码 */
				  (yyval.calvalue)->valuetype=3;
				  (yyval.calvalue)->caltype=2;
				  (yyval.calvalue)->leftcal=(yyvsp[(1) - (3)].calvalue);
				  (yyval.calvalue)->rightcal=(yyvsp[(3) - (3)].calvalue);
				 }
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 512 "SQL.y"
    { (yyval.calvalue) = new struct calvalue;
				  /* 补充代码 */
				  (yyval.calvalue)->valuetype=3;
				  (yyval.calvalue)->caltype=3;
				  (yyval.calvalue)->leftcal=(yyvsp[(1) - (3)].calvalue);
				  (yyval.calvalue)->rightcal=(yyvsp[(3) - (3)].calvalue);
				 }
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 519 "SQL.y"
    { (yyval.calvalue) = new struct calvalue;
				  /* 补充代码 */
				   (yyval.calvalue)->valuetype=3;
				  (yyval.calvalue)->caltype=4;
				  (yyval.calvalue)->leftcal=(yyvsp[(1) - (3)].calvalue);
				  (yyval.calvalue)->rightcal=(yyvsp[(3) - (3)].calvalue);
				 }
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 526 "SQL.y"
    { 
                  (yyval.calvalue) = new struct calvalue;
				  /* 补充代码 */
				  (yyval.calvalue)->valuetype=3;
				  (yyval.calvalue)->caltype=2;
				  (yyval.calvalue)->leftcal=NULL;
				  (yyval.calvalue)->rightcal=(yyvsp[(2) - (2)].calvalue);
                 }
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 534 "SQL.y"
    {(yyval.calvalue) = (yyvsp[(2) - (3)].calvalue);}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 535 "SQL.y"
    {(yyval.calvalue) = new struct calvalue;
                   (yyval.calvalue)->valuetype = 1;
				   (yyval.calvalue)->leftcal = NULL;
				   (yyval.calvalue)->rightcal = NULL;
				   (yyval.calvalue)->intnum = (yyvsp[(1) - (1)].value).intnum;
				  }
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 541 "SQL.y"
    {(yyval.calvalue) = new struct calvalue;
                   (yyval.calvalue)->valuetype = 2;
				   (yyval.calvalue)->leftcal = NULL;
				   (yyval.calvalue)->rightcal = NULL;
				   (yyval.calvalue)->doublenum = (yyvsp[(1) - (1)].value).doublenum; 
				  }
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 551 "SQL.y"
    {
                                                       (yyval.updatesql) = new struct updatesql;
													   (yyval.updatesql)-> tablename = (yyvsp[(2) - (6)].colname);
													   (yyval.updatesql)-> setconfs = (yyvsp[(4) - (6)].setconf);
													   (yyval.updatesql)-> condition_tree = (yyvsp[(5) - (6)].condition);
													   }
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 557 "SQL.y"
    {
                                                       (yyval.updatesql) = new struct updatesql;
													   (yyval.updatesql)-> tablename = (yyvsp[(2) - (5)].colname);
													   (yyval.updatesql)-> setconfs = (yyvsp[(4) - (5)].setconf);
													   (yyval.updatesql)-> condition_tree = NULL;
													   }
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 565 "SQL.y"
    {(yyval.setconf) = (yyvsp[(1) - (1)].setconf);(yyval.setconf)->num = 1;}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 566 "SQL.y"
    { (yyval.setconf) = (yyvsp[(1) - (3)].setconf);while((yyvsp[(1) - (3)].setconf)->next!=NULL)(yyvsp[(1) - (3)].setconf) = (yyvsp[(1) - (3)].setconf)->next; (yyvsp[(1) - (3)].setconf)->next = (yyvsp[(3) - (3)].setconf); (yyval.setconf)->num++;}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 568 "SQL.y"
    {(yyval.setconf) = new struct setconf; (yyval.setconf)->name = (yyvsp[(1) - (3)].colname);(yyval.setconf)->value = (yyvsp[(3) - (3)].dataformat);(yyval.setconf)->next = NULL;}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 571 "SQL.y"
    {(yyval.deletesql) = new struct deletesql; (yyval.deletesql)->tablename = (yyvsp[(3) - (5)].colname);(yyval.deletesql)->condition_tree = (yyvsp[(4) - (5)].condition);}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 572 "SQL.y"
    {(yyval.deletesql) = new struct deletesql; (yyval.deletesql)->tablename = (yyvsp[(3) - (4)].colname);(yyval.deletesql)->condition_tree = NULL;}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 575 "SQL.y"
    {droptable((yyvsp[(3) - (5)].colname)->tablename);}
    break;


/* Line 1792 of yacc.c  */
#line 2478 "SQL.tab.cpp"
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


/* Line 2055 of yacc.c  */
#line 582 "SQL.y"


int main()
{
	initsystem();
	exitflag = false;
	printf("SQL>>");
	while(!exitflag){
		yyparse();
		printf("\nSQL>>");
	}
	closesystem();
	return 0;
}

int yyerror(char * msg)
{
    printf("%s is error in line",msg);
    return 1;
}

      

