%{
	#include<stdio.h>
	extern int yylex(void);
	int yyerror(char * msg);
%}


%token  INTEGER
%token  ID STRING
%token FLOATE
%token CREATE TABLE SELECT FROM WHERE INT CHAR FLOAT INSERT INTO VALUES UPDATE DELETE SET SHOW DROP TABLES
%left OR
%left AND
%right OPERATOR
%%

statements : statements statement 
			| statement

statement: createsql { printf("createsql\n");return 0;}
| selectsql {printf("selectsql\n");return 0;}
| insertsql { printf("insertsql\n");return 0;}
| updatesql{ printf("updatesql\n");return 0;}
| deletesql{ printf("deletesql\n");return 0;}
| showsql { printf("showtables\n");return 0;}
| dropsql { printf("dropsql\n");return 0;}

showsql: SHOW TABLES ';'
dropsql: DROP TABLE tablename ';' {}
createsql: CREATE TABLE tablename  '('feildefinition')'';'{}

feildefinition: feildefinition','feild_type |feild_type 

feild_type: feildname type {}

type: INT {} |CHAR'('INTEGER')' {} |FLOAT{}





selectsql: SELECT fields_star FROM tables ';'{}
		| SELECT fields_star FROM tables WHERE conditions ';' {}




fields_star: table_fields {}  | '*' {}
table_fields:   table_fields ',' table_field | table_field
table_field: feildname {}  | tablename '.' feildname{}




tables: tables ',' tablename {} | tablename {}



conditions: condition {}
		| '(' conditions ')' {}
		| conditions AND conditions {}
		| conditions OR conditions {}
		| conditions OPERATOR conditions {}



condition: feild {}
		| STRING {}
		| INTEGER {}
		| FLOATE {}


feild: tablename '.' feildname{} | feildname {}




insertsql: INSERT INTO tablename '(' insert_feild ')' VALUES '(' insert_values ')' ';'{}
			| INSERT INTO tablename VALUES '(' insert_values ')' ';'{}
insert_feild: insert_feild ',' feildname {}  | feildname {}

insert_values: insert_values','value {} | value {}

value: STRING {} | INTEGER{} | FLOATE{}


updatesql : UPDATE tablename SET setinfo WHERE conditions ';'{}
setinfo: setinfo ',' feild OPERATOR value {}  | feild OPERATOR value {}


deletesql: DELETE FROM tablename WHERE conditions ';' {}



feildname: ID 

tablename: ID



%%

int main()
{
	while(1){
		yyparse();
	}
	return 0;
}

      

	  

int yyerror(char * msg)
{
    printf("yyerror");
    return 1;

}