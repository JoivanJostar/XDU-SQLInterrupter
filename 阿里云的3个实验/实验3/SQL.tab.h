/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
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


/* Line 2058 of yacc.c  */
#line 143 "SQL.tab.h"
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
