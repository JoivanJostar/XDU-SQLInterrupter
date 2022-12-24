%option noyywrap
%option caseless
%{
#include <stdio.h>
#include <iostream>
using namespace std;

#define ID 0
enum LITERAL{
	BEG_LITERAL=ID,
	
	INTEGER,FLOAT,STRING,
	
	END_LITERAL
};
enum KEYWORD{
	BEG_KEYWORD=END_LITERAL,
	CREATE,SHOW,DROP,USE,INSERT,SELECT,DATABASE,DATABASES,TABLE,TABLES,VALUES,
	INTO,FROM,WHERE,ANY,OP_AND,OP_OR,OP_NOT,UPDATE,DELETE,SET,CHAR,INT,COL,
	END_KEYWORD
};
enum OP{
	BEG_OP=END_KEYWORD,
	
	ADD,SUB,MULT,DIV,LP,RP,
	EQUAL,ABOVE,BELOW,AE,BE,NOT_EQUAL,
	//AND,OR,NOT,
	END_OP
};
enum DELIMITER{
	BEG_DELIMITER=END_OP,
	
	COMMA,SEMIC,
	
	END_DELIMITER
};
%}
char	[a-zA-Z]
digit	[0-9]
digits	{digit}+
optional_fraction	("."{digits})?
optional_exponent	((E|e)[+-]?{digits})?

%%
[ \t\n]+  {}   
create {printf("recognize CREATE\n"); return CREATE;}
show	{printf("recognize SHOW\n"); return SHOW;}
drop	{printf("recognize DROP\n"); return DROP;}
use		{printf("recognize USE\n"); return USE;}
insert	{printf("recognize INSERT\n"); return INSERT;}
select {printf("recognize SELECT\n"); return SELECT;}
database {printf("recognize DATABASE\n"); return DATABASE;}
databases {printf("recognize DATABASES\n"); return DATABASES;}
table	{printf("recognize TABLE\n"); return TABLE;}
tables	{printf("recognize TABLES\n"); return TABLES;}
values	{printf("recognize VALUES\n"); return VALUES;}
into	{printf("recognize INTO\n"); return INTO;}
from	{printf("recognize FROM\n"); return FROM;}
where	{printf("recognize WHERE\n"); return WHERE;}
[*]		{printf("recognize *\n"); return ANY;} 
and		{printf("recognize AND\n"); return OP_AND;} 
or		{printf("recognize OR\n"); return OP_OR;}
not		{printf("recognize NOT\n"); return OP_NOT;}
update	{printf("recognize UPDATE\n"); return UPDATE;}
set		{printf("recognize SET\n"); return SET;}
delete	{printf("recognize DELETE\n"); return DELETE;}
char	{printf("recognize CHAR\n"); return CHAR;}
int		{printf("recognize INT\n"); return INT;}
col{digits} {printf("recognize COL%s\n",yytext); return COL;}
{digits} {printf("recognize Literal Int %s\n",yytext); return INTEGER;}
{digits}{optional_fraction}{optional_exponent} {printf("recognize Literal Float %s\n",yytext); return INTEGER;}
{char}({char}|{digit}|_)*	{ 
										printf("recognize Id %s len is %d\n", yytext, yyleng);
										return ID;
									}
"(" {cout<<"recognize ("<<endl; return LP;}
")" {cout<<"recognize )"<<endl; return RP;}
= {cout<<"recognize ="<<endl; return EQUAL;}
">" {cout<<"recognize >"<<endl; return ABOVE;}
"<" {cout<<"recognize <"<<endl; return BELOW;}
"<"= {cout<<"recognize <="<<endl; return BE;}
">"= {cout<<"recognize >="<<endl; return AE;}
!= {cout<<"recognize !="<<endl; return NOT_EQUAL;}
, {cout<<"recognize ,"<<endl; return COMMA;}
; {cout<<"recognize ;"<<endl; return SEMIC;}
. { cout<<"Unknown Lex"<<yytext<<endl;return -1;}
%%

int main(){
	while(1)
	yylex();
}