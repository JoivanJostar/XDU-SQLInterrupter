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
#line 1 "yacc.y"

	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include "ZYF_SQL.h"
	#include <list>
	#include <vector>
	#include<iostream>
	using namespace std;
	extern int yylex(void);
	extern char *yytext;
	extern int lineno;
	extern bool g_Used;
	int yyerror(char * msg);
	bool g_start=true;
	int g_index=1;
	vector<Col> colsList;
	vector<TableName> tableList;
	vector<SelectCol> selectColsList;
	vector<yyValue> valueList;
	vector<ColName> insertColsList;
	vector< struct Feild_Value> setList;

/* Line 371 of yacc.c  */
#line 92 "yacc.tab.cpp"

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
   by #include "yacc.tab.h".  */
#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
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
     INTEGER = 258,
     ID = 259,
     STRING = 260,
     FLOATE = 261,
     CREATE = 262,
     TABLE = 263,
     SELECT = 264,
     FROM = 265,
     WHERE = 266,
     INT = 267,
     CHAR = 268,
     FLOAT = 269,
     INSERT = 270,
     INTO = 271,
     VALUES = 272,
     UPDATE = 273,
     DELETE = 274,
     SET = 275,
     SHOW = 276,
     DROP = 277,
     TABLES = 278,
     DATABASE = 279,
     DATABASES = 280,
     USE = 281,
     OR = 282,
     AND = 283,
     OPERATOR = 284
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 24 "yacc.y"

	int val_int;
	float val_float;
	char *val_str;
	char * val_operator;
	struct struct_type * val_type;
	struct yyValue * val_value;
	struct CreateRootValue *val_createsql;
	struct SelectRootValue *val_selectsql;
	struct InsertRootValue *val_insertsql;
	struct Conditions      *val_condition;
	struct UpdateRootValue *val_updatesql;
	struct DeleteRootValue *val_deletesql;
	struct Feild * val_feild;


/* Line 387 of yacc.c  */
#line 181 "yacc.tab.cpp"
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

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 209 "yacc.tab.cpp"

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
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   134

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNRULES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,    34,     2,    33,     2,    35,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    30,    35,    39,    41,    45,    49,
      54,    62,    66,    68,    71,    73,    78,    80,    86,    94,
      96,    98,   102,   104,   106,   110,   114,   116,   118,   122,
     126,   130,   134,   136,   138,   140,   142,   146,   148,   160,
     169,   173,   175,   179,   181,   183,   185,   187,   195,   201,
     205,   212,   214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    45,    -1,    49,    -1,    57,    -1,    61,
      -1,    63,    -1,    43,    -1,    44,    -1,    38,    -1,    39,
      -1,    42,    -1,    40,    -1,     7,    24,    41,    30,    -1,
      22,    24,    41,    30,    -1,    26,    41,    30,    -1,     4,
      -1,    21,    25,    30,    -1,    21,    23,    30,    -1,    22,
       8,    65,    30,    -1,     7,     8,    65,    31,    46,    32,
      30,    -1,    46,    33,    47,    -1,    47,    -1,    64,    48,
      -1,    12,    -1,    13,    31,     3,    32,    -1,    14,    -1,
       9,    50,    10,    53,    30,    -1,     9,    50,    10,    53,
      11,    54,    30,    -1,    51,    -1,    34,    -1,    51,    33,
      52,    -1,    52,    -1,    64,    -1,    65,    35,    64,    -1,
      53,    33,    65,    -1,    65,    -1,    55,    -1,    31,    54,
      32,    -1,    54,    28,    54,    -1,    54,    27,    54,    -1,
      54,    29,    54,    -1,    56,    -1,     5,    -1,     3,    -1,
       6,    -1,    65,    35,    64,    -1,    64,    -1,    15,    16,
      65,    31,    58,    32,    17,    31,    59,    32,    30,    -1,
      15,    16,    65,    17,    31,    59,    32,    30,    -1,    58,
      33,    64,    -1,    64,    -1,    59,    33,    60,    -1,    60,
      -1,     5,    -1,     3,    -1,     6,    -1,    18,    65,    20,
      62,    11,    54,    30,    -1,    62,    33,    56,    29,    60,
      -1,    56,    29,    60,    -1,    19,    10,    65,    11,    54,
      30,    -1,     4,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    75,    87,   100,   111,   121,   131,   140,
     145,   150,   155,   161,   164,   167,   170,   172,   173,   174,
     177,   184,   185,   187,   193,   197,   201,   210,   216,   227,
     228,   232,   232,   233,   237,   245,   248,   254,   258,   262,
     270,   277,   288,   298,   308,   318,   329,   335,   345,   352,
     361,   364,   368,   371,   374,   381,   388,   397,   404,   416,
     430,   439,   441
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ID", "STRING", "FLOATE",
  "CREATE", "TABLE", "SELECT", "FROM", "WHERE", "INT", "CHAR", "FLOAT",
  "INSERT", "INTO", "VALUES", "UPDATE", "DELETE", "SET", "SHOW", "DROP",
  "TABLES", "DATABASE", "DATABASES", "USE", "OR", "AND", "OPERATOR", "';'",
  "'('", "')'", "','", "'*'", "'.'", "$accept", "statement", "createdb",
  "dropdb", "usedb", "databasename", "showdb", "showsql", "dropsql",
  "createsql", "feildefinition", "feild_type", "type", "selectsql",
  "fields_star", "table_fields", "table_field", "tables", "conditions",
  "condition", "feild", "insertsql", "insert_feild", "insert_values",
  "value", "updatesql", "setinfo", "deletesql", "feildname", "tablename", YY_NULL
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
      59,    40,    41,    44,    42,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    46,    47,    48,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    60,    61,    62,    62,
      63,    64,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     3,     1,     3,     3,     4,
       7,     3,     1,     2,     1,     4,     1,     5,     7,     1,
       1,     3,     1,     1,     3,     3,     1,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     1,    11,     8,
       3,     1,     3,     1,     1,     1,     1,     7,     5,     3,
       6,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,    12,    11,     7,     8,     2,     3,     4,     5,
       6,     0,     0,    61,    30,     0,    29,    32,    33,     0,
       0,    62,     0,     0,     0,     0,     0,     0,    16,     0,
       1,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      17,     0,     0,    15,     0,    13,     0,    36,    31,    61,
      34,     0,     0,     0,     0,    47,     0,     0,    19,    14,
       0,    22,     0,     0,    27,     0,     0,     0,    51,     0,
       0,     0,     0,    44,    43,    45,     0,     0,    37,    42,
       0,     0,    24,     0,    26,    23,     0,    35,    55,    54,
      56,     0,    53,     0,     0,    59,     0,     0,    46,     0,
       0,     0,     0,    60,    20,    21,     0,    28,     0,     0,
       0,    50,    57,     0,    38,    40,    39,    41,     0,    49,
      52,     0,    58,    25,     0,     0,    48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    39,    13,    14,    15,    16,
      70,    71,    95,    17,    25,    26,    27,    56,    87,    88,
      89,    18,    77,   101,   102,    19,    64,    20,    65,    66
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int8 yypact[] =
{
      40,    -4,     7,    11,     5,    23,    62,     4,    44,    53,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     5,    44,    32,   -74,    69,    55,   -74,   -74,    63,
       5,   -74,    79,     5,    56,    70,     5,    44,   -74,    71,
     -74,    72,    74,     5,   101,   102,   -10,   101,    96,   -74,
     -74,    78,    80,   -74,   102,   -74,    -1,   -74,   -74,   -74,
     -74,    81,   102,    82,     2,   -74,    83,    20,   -74,   -74,
      45,   -74,    61,    20,   -74,     5,    51,    58,   -74,    51,
      20,   101,   102,   -74,   -74,   -74,    20,   -11,   -74,   -74,
      84,   102,   -74,    85,   -74,   -74,    42,   -74,   -74,   -74,
     -74,    60,   -74,    92,   102,   -74,    54,    86,   -74,    36,
      20,    20,    20,   -74,   -74,   -74,   110,   -74,    87,    51,
      88,   -74,   -74,    51,   -74,    66,    91,    91,    89,   -74,
     -74,    51,   -74,   -74,    64,    93,   -74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -74,    -7,   -74,   -74,   -74,   -74,
     -74,    31,   -74,   -74,   -74,   -74,    90,   -74,   -72,   -74,
     -45,   -74,   -74,    -6,   -73,   -74,   -74,   -74,    -2,     1
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -63
static const yytype_int16 yytable[] =
{
      28,    96,    63,    29,    21,    32,   105,    61,   106,    31,
      73,    23,    36,    80,   109,    42,   110,   111,   112,   113,
      22,    62,    41,    83,    23,    84,    85,    30,    37,    74,
      52,    46,    75,    33,    48,    81,   107,    51,   125,   126,
     127,    24,    28,    60,    57,    29,   130,     1,    38,     2,
     132,    86,    72,    40,    98,     3,    99,   100,     4,     5,
      78,     6,     7,   110,   111,   112,     8,   -62,   124,   110,
     111,   112,   117,    92,    93,    94,    97,    90,    91,    43,
     108,   110,   111,   112,   122,    34,    49,    35,    44,    72,
     103,   104,   118,   119,   111,   112,   135,   119,    45,    47,
      50,    53,   121,    54,    55,    23,    59,    67,    68,   120,
      69,    79,    76,   128,   114,   123,   116,   129,    82,   131,
     112,   133,   115,   136,     0,   134,     0,     0,     0,     0,
       0,     0,     0,     0,    58
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       2,    73,    47,     2,     8,     4,    79,    17,    80,     4,
      11,     4,     8,    11,    86,    22,    27,    28,    29,    30,
      24,    31,    21,     3,     4,     5,     6,    16,    24,    30,
      37,    30,    33,    10,    33,    33,    81,    36,   110,   111,
     112,    34,    44,    45,    43,    44,   119,     7,     4,     9,
     123,    31,    54,     0,     3,    15,     5,     6,    18,    19,
      62,    21,    22,    27,    28,    29,    26,    35,    32,    27,
      28,    29,    30,    12,    13,    14,    75,    32,    33,    10,
      82,    27,    28,    29,    30,    23,    30,    25,    33,    91,
      32,    33,    32,    33,    28,    29,    32,    33,    35,    20,
      30,    30,   104,    31,    30,     4,     4,    11,    30,    17,
      30,    29,    31,     3,    30,    29,    31,    30,    35,    31,
      29,    32,    91,    30,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     9,    15,    18,    19,    21,    22,    26,    37,
      38,    39,    40,    42,    43,    44,    45,    49,    57,    61,
      63,     8,    24,     4,    34,    50,    51,    52,    64,    65,
      16,     4,    65,    10,    23,    25,     8,    24,     4,    41,
       0,    65,    41,    10,    33,    35,    65,    20,    65,    30,
      30,    65,    41,    30,    31,    30,    53,    65,    52,     4,
      64,    17,    31,    56,    62,    64,    65,    11,    30,    30,
      46,    47,    64,    11,    30,    33,    31,    58,    64,    29,
      11,    33,    35,     3,     5,     6,    31,    54,    55,    56,
      32,    33,    12,    13,    14,    48,    54,    65,     3,     5,
       6,    59,    60,    32,    33,    60,    54,    56,    64,    54,
      27,    28,    29,    30,    30,    47,    31,    30,    32,    33,
      17,    64,    30,    29,    32,    54,    54,    54,     3,    30,
      60,    31,    60,    32,    59,    32,    30
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
#line 64 "yacc.y"
    {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_CreateTable((yyvsp[(1) - (1)].val_createsql));
	result ? printf("Create Table Success \n") : printf("Create Table fail!\n");
	colsList.clear();g_index=1;
	
	return 0;
}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 75 "yacc.y"
    {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Select((yyvsp[(1) - (1)].val_selectsql));
	result ? printf("\nselect Success \n") : printf("\nselect fail!\n");
	selectColsList.clear();
	tableList.clear();

	return 0;
}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 87 "yacc.y"
    {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Insert((yyvsp[(1) - (1)].val_insertsql));
	//cout<<$1->table<<endl;
	result ? printf("\ninsert Success \n") : printf("\ninsert fail!\n");
	insertColsList.clear();
	valueList.clear();

	return 0;
}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 100 "yacc.y"
    {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Update((yyvsp[(1) - (1)].val_updatesql));
	result ? printf("\nupdate Success \n") : printf("\nupdate fail!\n");
	setList.clear();

	return 0;
}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 111 "yacc.y"
    {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Delete((yyvsp[(1) - (1)].val_deletesql));
	result ? printf("\ndelete Success \n") : printf("\ndelete fail!\n");

	return 0;
}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 121 "yacc.y"
    {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	ZYF_ShowTables();
	cout<<endl<<endl;

	return 0;
}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 131 "yacc.y"
    {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_DropTable((yyvsp[(1) - (1)].val_str));
	result ? printf("\ndrop Success \n") : printf("\ndrop fail!\n");
	return 0;
}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 140 "yacc.y"
    {
	bool result=ZYF_CreateDataBase((yyvsp[(1) - (1)].val_str));
	result ? printf("\ncreate database sucess \n") : printf("\ncreate database fail!\n");
	return 0;
}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 145 "yacc.y"
    {
	bool result=ZYF_DropDataBase((yyvsp[(1) - (1)].val_str));
	result ? printf("\ndrop database sucess \n") : printf("\ndrop database fail!\n");
	return 0;
}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 150 "yacc.y"
    {
	ZYF_ShowDataBase();
	cout<<endl<<endl;
	return 0;
}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 155 "yacc.y"
    {
	bool result=ZYF_UseDataBase((yyvsp[(1) - (1)].val_str));
	result ? printf("\nuse database sucess \n") : printf("\nuse database fail!\n");
	return 0;
}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 161 "yacc.y"
    {
	(yyval.val_str)=(yyvsp[(3) - (4)].val_str);
}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 164 "yacc.y"
    {
	(yyval.val_str)=(yyvsp[(3) - (4)].val_str);
}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 167 "yacc.y"
    {
	(yyval.val_str)=(yyvsp[(2) - (3)].val_str);
}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 174 "yacc.y"
    {
	(yyval.val_str)=(yyvsp[(3) - (4)].val_str);
}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 177 "yacc.y"
    {
	 (yyval.val_createsql)=(struct CreateRootValue *) malloc(sizeof(struct CreateRootValue));
	 memset((yyval.val_createsql),0,sizeof(struct CreateRootValue));
	 (yyval.val_createsql)->tablename=(yyvsp[(3) - (7)].val_str);
	 (yyval.val_createsql)->feildefinition=&colsList;
}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 187 "yacc.y"
    {
								Col col = { g_index++, string((yyvsp[(1) - (2)].val_str)), (yyvsp[(2) - (2)].val_type)->type, (yyvsp[(2) - (2)].val_type)->char_length};
								colsList.push_back(col);
								free((yyvsp[(2) - (2)].val_type));
							}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 193 "yacc.y"
    {
			(yyval.val_type)=(struct struct_type *)malloc(sizeof(struct struct_type));
			(yyval.val_type)->type=enum_INT;  (yyval.val_type)->char_length=-1;
	}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 197 "yacc.y"
    {
			(yyval.val_type)=(struct struct_type *)malloc(sizeof(struct struct_type));
			(yyval.val_type)->type=enum_CHAR;  (yyval.val_type)->char_length=(yyvsp[(3) - (4)].val_int);
	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 201 "yacc.y"
    {

			(yyval.val_type)=(struct struct_type *)malloc(sizeof(struct struct_type));
			(yyval.val_type)->type=enum_FLOAT;  (yyval.val_type)->char_length=-1;
	}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 210 "yacc.y"
    {
	(yyval.val_selectsql)=(struct SelectRootValue *)malloc(sizeof(struct SelectRootValue));
	memset((yyval.val_selectsql),0,sizeof(struct SelectRootValue));
	(yyval.val_selectsql)->cols=&selectColsList;
	(yyval.val_selectsql)->tables=&tableList;
}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 216 "yacc.y"
    {
	(yyval.val_selectsql)=(struct SelectRootValue *)malloc(sizeof(struct SelectRootValue));
	memset((yyval.val_selectsql),0,sizeof(struct SelectRootValue));
	(yyval.val_selectsql)->cols=&selectColsList;
	(yyval.val_selectsql)->tables=&tableList;
	(yyval.val_selectsql)->condition=(yyvsp[(6) - (7)].val_condition);
}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 227 "yacc.y"
    {}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 228 "yacc.y"
    {
	SelectCol col ={"","*"};
	selectColsList.push_back(col);
}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 233 "yacc.y"
    { 
	SelectCol col ={"",string((yyvsp[(1) - (1)].val_str))};
	selectColsList.push_back(col);
}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 237 "yacc.y"
    {
	SelectCol col ={string((yyvsp[(1) - (3)].val_str)),string((yyvsp[(3) - (3)].val_str))};//[table.Sno]
	selectColsList.push_back(col);
}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 245 "yacc.y"
    {
	tableList.push_back(string((yyvsp[(3) - (3)].val_str)));
}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 248 "yacc.y"
    {
	tableList.push_back(string((yyvsp[(1) - (1)].val_str)));
}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 254 "yacc.y"
    {
	//cout<<"conditions->condition\n";
	(yyval.val_condition)=(yyvsp[(1) - (1)].val_condition);
}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 258 "yacc.y"
    {
	//cout<<"conditions->(conditions)\n";
	(yyval.val_condition)=(yyvsp[(2) - (3)].val_condition);
}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 262 "yacc.y"
    {
	
	(yyval.val_condition)=(struct Conditions *)malloc(sizeof(struct Conditions));
	memset((yyval.val_condition),0,sizeof(struct Conditions));
	(yyval.val_condition)->left=(yyvsp[(1) - (3)].val_condition);
	(yyval.val_condition)->right=(yyvsp[(3) - (3)].val_condition);
	(yyval.val_condition)->comp_op=(yyvsp[(2) - (3)].val_str);
}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 270 "yacc.y"
    {
	(yyval.val_condition)=(struct Conditions *)malloc(sizeof(struct Conditions));
	memset((yyval.val_condition),0,sizeof(struct Conditions));
	(yyval.val_condition)->left=(yyvsp[(1) - (3)].val_condition);
	(yyval.val_condition)->right=(yyvsp[(3) - (3)].val_condition);
	(yyval.val_condition)->comp_op=(yyvsp[(2) - (3)].val_str);
}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 277 "yacc.y"
    {
	//cout<<"conditions->conditions OPERATOR coditions\n";
	(yyval.val_condition)=(struct Conditions *)malloc(sizeof(struct Conditions));
	memset((yyval.val_condition),0,sizeof(struct Conditions));
	(yyval.val_condition)->left=(yyvsp[(1) - (3)].val_condition);
	(yyval.val_condition)->right=(yyvsp[(3) - (3)].val_condition);
	(yyval.val_condition)->comp_op=(yyvsp[(2) - (3)].val_operator);
}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 288 "yacc.y"
    {
	//cout<<"condition->feild\n";
	(yyval.val_condition)=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset((yyval.val_condition),0,sizeof(struct Conditions));
	(yyval.val_condition)->table=(yyvsp[(1) - (1)].val_feild)->tablename;
	(yyval.val_condition)->type=enum_FEILD;
	(yyval.val_condition)->value.val_str=(yyvsp[(1) - (1)].val_feild)->feildname;
	(yyval.val_condition)->left=NULL;
	(yyval.val_condition)->right=NULL;
}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 298 "yacc.y"
    {
	//cout<<"condition->string\n";
	(yyval.val_condition)=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset((yyval.val_condition),0,sizeof(struct Conditions));
	(yyval.val_condition)->table=NULL;
	(yyval.val_condition)->type=enum_CHAR;
	(yyval.val_condition)->value.val_str=(yyvsp[(1) - (1)].val_str);
	(yyval.val_condition)->left=NULL;
	(yyval.val_condition)->right=NULL;
}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 308 "yacc.y"
    {
	//cout<<"condition->integer\n";
	(yyval.val_condition)=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset((yyval.val_condition),0,sizeof(struct Conditions));
	(yyval.val_condition)->table=NULL;
	(yyval.val_condition)->type=enum_INT;
	(yyval.val_condition)->value.val_int=(yyvsp[(1) - (1)].val_int);
	(yyval.val_condition)->left=NULL;
	(yyval.val_condition)->right=NULL;
}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 318 "yacc.y"
    {
	(yyval.val_condition)=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset((yyval.val_condition),0,sizeof(struct Conditions));
	(yyval.val_condition)->table=NULL;
	(yyval.val_condition)->type=enum_FLOAT;
	(yyval.val_condition)->value.val_float=(yyvsp[(1) - (1)].val_float);
	(yyval.val_condition)->left=NULL;
	(yyval.val_condition)->right=NULL;
}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 329 "yacc.y"
    {
	(yyval.val_feild)=(struct Feild *) malloc( sizeof(struct Feild ));
	memset((yyval.val_feild),0,sizeof(struct Feild));
	(yyval.val_feild)->tablename=(yyvsp[(1) - (3)].val_str);
	(yyval.val_feild)->feildname=(yyvsp[(3) - (3)].val_str);
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 335 "yacc.y"
    {
	(yyval.val_feild)=(struct Feild *) malloc( sizeof(struct Feild ));
	memset((yyval.val_feild),0,sizeof(struct Feild));
	(yyval.val_feild)->tablename=NULL;
	(yyval.val_feild)->feildname=(yyvsp[(1) - (1)].val_str);
}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 345 "yacc.y"
    {
	(yyval.val_insertsql)=(struct InsertRootValue *) malloc(sizeof( struct InsertRootValue));
	memset((yyval.val_insertsql),0,sizeof(struct InsertRootValue));
	(yyval.val_insertsql)->table=string((yyvsp[(3) - (11)].val_str));
	(yyval.val_insertsql)->cols=&insertColsList;
	(yyval.val_insertsql)->values=&valueList;
}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 352 "yacc.y"
    {
	(yyval.val_insertsql)=(struct InsertRootValue *) malloc(sizeof( struct InsertRootValue));
	memset((yyval.val_insertsql),0,sizeof(struct InsertRootValue));
	(yyval.val_insertsql)->table=string((yyvsp[(3) - (8)].val_str));
	insertColsList.clear();
	(yyval.val_insertsql)->cols=&insertColsList;
	(yyval.val_insertsql)->values=&valueList;
}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 361 "yacc.y"
    {
	insertColsList.push_back(string((yyvsp[(3) - (3)].val_str)));
}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 364 "yacc.y"
    {
	insertColsList.push_back(string((yyvsp[(1) - (1)].val_str)));
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 368 "yacc.y"
    {
	valueList.push_back(*(yyvsp[(3) - (3)].val_value));	
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 371 "yacc.y"
    {
	valueList.push_back(*(yyvsp[(1) - (1)].val_value));	
}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 374 "yacc.y"
    {
	(yyval.val_value)=(struct yyValue *)malloc( sizeof( struct yyValue ));
	memset((yyval.val_value),0,sizeof(struct yyValue));
	(yyval.val_value)->type_length.type=enum_CHAR;
	(yyval.val_value)->type_length.char_length=strlen((yyvsp[(1) - (1)].val_str));
	(yyval.val_value)->value.val_str=(yyvsp[(1) - (1)].val_str);
}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 381 "yacc.y"
    {
	(yyval.val_value)=(struct yyValue *)malloc( sizeof( struct yyValue ));
	memset((yyval.val_value),0,sizeof(struct yyValue));
	(yyval.val_value)->type_length.type=enum_INT;
	(yyval.val_value)->type_length.char_length=-1;
	(yyval.val_value)->value.val_int=(yyvsp[(1) - (1)].val_int);
}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 388 "yacc.y"
    {
	(yyval.val_value)=(struct yyValue *)malloc( sizeof( struct yyValue ));
	memset((yyval.val_value),0,sizeof(struct yyValue));
	(yyval.val_value)->type_length.type=enum_FLOAT;
	(yyval.val_value)->type_length.char_length=-1;
	(yyval.val_value)->value.val_float=(yyvsp[(1) - (1)].val_float);
}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 397 "yacc.y"
    {
	(yyval.val_updatesql)=(struct UpdateRootValue *) malloc(sizeof(struct UpdateRootValue));
	memset((yyval.val_updatesql),0,sizeof(struct UpdateRootValue));
	(yyval.val_updatesql)->tablename=(yyvsp[(2) - (7)].val_str);
	(yyval.val_updatesql)->conditions=(yyvsp[(6) - (7)].val_condition);
	(yyval.val_updatesql)->setList=&setList;
}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 404 "yacc.y"
    {
	//cout<<"setinfo ',' feild '=' value"<<endl;
	if((yyvsp[(4) - (5)].val_operator)[0]=='='){
	struct Feild_Value tmp;
	tmp.feild=*((yyvsp[(3) - (5)].val_feild));
	tmp.value= (yyvsp[(5) - (5)].val_value)->value;
	tmp.type= (yyvsp[(5) - (5)].val_value)->type_length.type;
	tmp.length=(yyvsp[(5) - (5)].val_value)->type_length.char_length;
	setList.push_back(tmp);
	}
	else {yyerror("syntax"); return -1;}
}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 416 "yacc.y"
    {
	//cout<<"feild '=' value"<<endl;
	if((yyvsp[(2) - (3)].val_operator)[0]=='='){
	struct Feild_Value tmp;
	tmp.feild=*((yyvsp[(1) - (3)].val_feild));
	tmp.value= (yyvsp[(3) - (3)].val_value)->value;
	tmp.type= (yyvsp[(3) - (3)].val_value)->type_length.type;
	tmp.length=(yyvsp[(3) - (3)].val_value)->type_length.char_length;
	setList.push_back(tmp);
	}
	else {yyerror("syntax error"); return -1;}
}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 430 "yacc.y"
    {
	(yyval.val_deletesql)=(struct DeleteRootValue *) malloc(sizeof(struct DeleteRootValue));
	memset((yyval.val_deletesql),0,sizeof(struct DeleteRootValue));
	(yyval.val_deletesql)->tablename=(yyvsp[(3) - (6)].val_str);
	(yyval.val_deletesql)->conditions=(yyvsp[(5) - (6)].val_condition);
}
    break;


/* Line 1792 of yacc.c  */
#line 2103 "yacc.tab.cpp"
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
#line 443 "yacc.y"




int yyerror(char * msg)
{
    printf("%s in line %d: %s\n",msg,lineno,yytext);
    return 1;

}
