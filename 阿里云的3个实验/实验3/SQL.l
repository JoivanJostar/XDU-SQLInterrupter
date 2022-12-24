%{
/****************************************************************************
SQL.l
ParserWizard generated Lex file.

Date: 2020Äê6ÔÂ7ÈÕ
****************************************************************************/
#include"Operate.h"
#include "SQL.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int yylex(void);

%}

%option noyywrap
%option caseless

digit	[0-9]
digits	{digit}+
optional_fraction	("."{digits})
letter [a-zA-Z][a-zA-Z0-9_]*
string \'[^\']*\'
strings \"[^\"]*\"

create create
drop drop
use use
select select
insert insert
delete delete
update update
from from
where where
into into
values values
set set
database database
databases {database}s
table table
tables tables
primary primary
key key
not not
null null
order order
group group
by by
having having
asc asc
desc desc
in in
exists exists
and and
or or
like like
alter alter
add add
column column
view view
index index
int int
double double
char char
show show
foreign foreign
references references
restrict restrict
cascade cascade
exit exit
bye bye
lru lru

%%

{create} {return CREATE;}
{drop} { return DROP;}
{use} {return USE;}
{select} { return SELECT;} 
{insert} { return INSERT;} 
{delete} { return DELETE;}
{update} { return UPDATE;}
{from} { return FROM;}
{where} { return WHERE;}
{into} { return INTO;}
{values} { return VALUES;}
{set} { return SET;} 
{database} { return DATABASE;} 
{databases} { return DATABASES;}
{table} { return TABLE;}
{tables} { return TABLES;}
{primary} {printf("PRIMARY"); return PRIMARY;}
{key} {printf("KEY"); return KEY;} 
{not} { return NOT;} 
{null} { return null;} 
{order} {printf("ORDER"); return ORDER;}
{group} {printf("GROUP"); return GROUP;}
{by} {printf("BY"); return BY;}
{having} {printf("HAVING"); return HAVING;}
{asc} {printf("ASC"); return ASC;}
{desc} {printf("DESC"); return DESC;}
{in} {printf("IN"); return IN;}
{exists} {printf("EXISTS"); return EXISTS;}
{and} { return AND;}
{or} {return OR;}
{like} {printf("LIKE"); return LIKE;}
{alter} {printf("ALTER"); return ALTER;}
{add} {printf("ADD"); return ADD;}
{column} { return COLUMN;}
{view} {printf("VIEW"); return VIEW;}
{index} {printf("INDEX"); return INDEX;}
{int} { return INT;}
{double} { return DOUBLE;}
{char} { return VARCHAR;}
{show} { return SHOW;}
{foreign} {printf("FOREIGN");return FOREIGN;}
{references} {printf("REFERENCES");return REFERENCES;}
{restrict} {printf("RESTRICT");return RESTRICT;}
{cascade} {printf("CASCADE");return CASCADE;}
{bye} { return BYE;}
{exit} { return EXIT;}
{lru} {return LRU;}


{letter} {
    yylval.value.length = strlen(yytext)+1;
	yylval.value.name=(char *)malloc(strlen(yytext)+1);
	_strlwr_s(yytext,strlen(yytext)+1);
	strcpy_s(yylval.value.name,strlen(yytext)+1,yytext);
	return ID;}
{string} {
    yylval.value.length = strlen(yytext)+1;
	yylval.value.name=(char *)malloc(strlen(yytext)+1);
	strcpy_s(yylval.value.name,strlen(yytext)+1, yytext);
	return STRING;}
{strings} {
    yylval.value.length = strlen(yytext)+1;
	yylval.value.name=(char *)malloc(strlen(yytext)+1);
	strcpy_s(yylval.value.name,strlen(yytext)+1, yytext);
	return STRINGS;
            }
{digits} {
    yylval.value.length = 4;
	yylval.value.intnum=atoi(yytext);
	return INTNUMBER;}
{digits}{optional_fraction} {
    yylval.value.length = 8;
	yylval.value.doublenum = atof(yytext);
	return DOUBLENUMBER;}

";" |
"(" |
")" |
"," |
"+" |
"-" |
"*" |
"/" |
"." |
"=" |
"<" |
">" |
"!" {return yytext[0];}

[ \n\t]+

%%

//int main()
//{
//	for(;;)
//	printf("", yylex());
	
//	return 0;
//}




