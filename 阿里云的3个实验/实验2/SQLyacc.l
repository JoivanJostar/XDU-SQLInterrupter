%option noyywrap
%option caseless
%{
#include "SQLyacc.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
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

AND { return AND; }
OR {return OR;}
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
"<=" {   return OPERATOR;}

{digits} {
     return INTEGER;}
{digits}{optional_fraction}{optional_exponent} {
     return FLOATE;}
{char}({char}|{digit}|_)*	{ 
    return ID;
}

\"[^\"]*\" {

    return STRING;
}
\'[^\']*\' {

    return STRING;
}
. { printf("exception ");}
%%

