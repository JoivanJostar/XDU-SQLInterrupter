%option noyywrap
%option caseless
%{
#include "yacc.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int lineno = 1;
void yyerror(char *s);
int yylex(void);
%}
char	[a-zA-Z]
digit	[0-9]
digits	{digit}+
optional_fraction	("."{digits})?
optional_exponent	((E|e)[+-]?{digits})?

%%
\n {lineno++;}
[ \t\r]+  {}   

CREATE { return CREATE;}
TABLE {return TABLE;}
CHAR {return CHAR;}
INT {return INT;}
FLOAT {return FLOAT;}
SELECT {return SELECT;}
FROM {return FROM;}
WHERE {return WHERE;}
INSERT {return INSERT;}
INTO {return INTO;}
VALUES {return VALUES;}
UPDATE {return UPDATE;}
DELETE {return DELETE;}
SET {return SET;}
SHOW {return SHOW;}
TABLES {return TABLES;}
DROP {return DROP;}
DATABASES {return DATABASES;}
DATABASE {return DATABASE;}
USE {return USE;}
AND {yylval.val_str=_strdup("AND"); return AND; }
OR {yylval.val_str=_strdup("OR"); return OR;}
"(" |
")" |
"," |
"+" |
"-" |
"*" |
"/" |
"." |
";" {return yytext[0];}

"=" |
">" |
"<" |
"!=" |
">=" |
"<=" {  yylval.val_operator=_strdup(yytext);  return OPERATOR;}

{digits} {
     yylval.val_int=(int) atoi(yytext);
     return INTEGER;}
{digits}{optional_fraction}{optional_exponent} {
    yylval.val_float=(float) atof(yytext);
     return FLOATE;}
{char}({char}|{digit}|_)*	{ 
    yylval.val_str= _strdup(yytext);
	transform( yylval.val_str,  yylval.val_str+yyleng,  yylval.val_str, ::toupper);
    return ID;
}

\"[^\"]*\" {

    yytext[yyleng-1]=0;
    yylval.val_str=_strdup(yytext+1);
    return STRING;
}
\'[^\']*\' {

    yytext[yyleng-1]=0;
    yylval.val_str=_strdup(yytext+1);
    return STRING;
}
. { printf("δ����");}
%%

