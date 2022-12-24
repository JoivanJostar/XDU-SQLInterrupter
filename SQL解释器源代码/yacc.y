%{
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
%}
%union{
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
}



%token <val_int> INTEGER
%token <val_str> ID STRING
%token <val_float> FLOATE
%token CREATE TABLE SELECT FROM WHERE INT CHAR FLOAT INSERT INTO VALUES UPDATE DELETE SET SHOW DROP TABLES
%token DATABASE DATABASES USE
%left <val_str> OR
%left <val_str> AND
%right <val_operator> OPERATOR
%type <val_str> tablename feildname databasename;
%type <val_type> type
%type <val_createsql> createsql
%type <val_selectsql> selectsql
%type <val_insertsql> insertsql
%type <val_updatesql> updatesql
%type <val_deletesql> deletesql
%type <val_value> value
%type <val_condition> condition conditions 
%type <val_feild> feild
%type <val_str> dropsql dropdb usedb createdb
%%


statement: createsql {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_CreateTable($1);
	result ? printf("Create Table Success \n") : printf("Create Table fail!\n");
	colsList.clear();g_index=1;
	
	return 0;
}
| selectsql {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Select($1);
	result ? printf("\nselect Success \n") : printf("\nselect fail!\n");
	selectColsList.clear();
	tableList.clear();

	return 0;
}
| insertsql {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Insert($1);
	//cout<<$1->table<<endl;
	result ? printf("\ninsert Success \n") : printf("\ninsert fail!\n");
	insertColsList.clear();
	valueList.clear();

	return 0;
}
| updatesql{
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Update($1);
	result ? printf("\nupdate Success \n") : printf("\nupdate fail!\n");
	setList.clear();

	return 0;
}
| deletesql{
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_Delete($1);
	result ? printf("\ndelete Success \n") : printf("\ndelete fail!\n");

	return 0;
}
| showsql {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	ZYF_ShowTables();
	cout<<endl<<endl;

	return 0;
}
| dropsql {
	if(g_Used==false){
		cout<<"database is not used\n";
		return 0;
	}
	bool result=ZYF_DropTable($1);
	result ? printf("\ndrop Success \n") : printf("\ndrop fail!\n");
	return 0;
}
| createdb{
	bool result=ZYF_CreateDataBase($1);
	result ? printf("\ncreate database sucess \n") : printf("\ncreate database fail!\n");
	return 0;
}
| dropdb {
	bool result=ZYF_DropDataBase($1);
	result ? printf("\ndrop database sucess \n") : printf("\ndrop database fail!\n");
	return 0;
}
| showdb {
	ZYF_ShowDataBase();
	cout<<endl<<endl;
	return 0;
}
| usedb {
	bool result=ZYF_UseDataBase($1);
	result ? printf("\nuse database sucess \n") : printf("\nuse database fail!\n");
	return 0;
}

createdb: CREATE DATABASE databasename ';' {
	$$=$3;
}
dropdb: DROP DATABASE databasename ';' {
	$$=$3;
}
usedb : USE databasename ';' {
	$$=$2;
}
databasename: ID;

showdb : SHOW DATABASES ';'
showsql: SHOW TABLES ';'
dropsql: DROP TABLE tablename ';' {
	$$=$3;
}
createsql: CREATE TABLE tablename  '('feildefinition')'';'{
	 $$=(struct CreateRootValue *) malloc(sizeof(struct CreateRootValue));
	 memset($$,0,sizeof(struct CreateRootValue));
	 $$->tablename=$3;
	 $$->feildefinition=&colsList;
}

feildefinition: feildefinition','feild_type
|feild_type 

feild_type: feildname type {
								Col col = { g_index++, string($1), $2->type, $2->char_length};
								colsList.push_back(col);
								free($2);
							}

type: INT {
			$$=(struct struct_type *)malloc(sizeof(struct struct_type));
			$$->type=enum_INT;  $$->char_length=-1;
	}
	|CHAR'('INTEGER')' {
			$$=(struct struct_type *)malloc(sizeof(struct struct_type));
			$$->type=enum_CHAR;  $$->char_length=$3;
	}
	| FLOAT{

			$$=(struct struct_type *)malloc(sizeof(struct struct_type));
			$$->type=enum_FLOAT;  $$->char_length=-1;
	}




selectsql: SELECT fields_star FROM tables ';'{
	$$=(struct SelectRootValue *)malloc(sizeof(struct SelectRootValue));
	memset($$,0,sizeof(struct SelectRootValue));
	$$->cols=&selectColsList;
	$$->tables=&tableList;
}
| SELECT fields_star FROM tables WHERE conditions ';'{
	$$=(struct SelectRootValue *)malloc(sizeof(struct SelectRootValue));
	memset($$,0,sizeof(struct SelectRootValue));
	$$->cols=&selectColsList;
	$$->tables=&tableList;
	$$->condition=$6;
}




fields_star: table_fields {}
| '*' {
	SelectCol col ={"","*"};
	selectColsList.push_back(col);
}
table_fields:   table_fields ',' table_field | table_field
table_field: feildname { 
	SelectCol col ={"",string($1)};
	selectColsList.push_back(col);
}
| tablename '.' feildname{
	SelectCol col ={string($1),string($3)};//[table.Sno]
	selectColsList.push_back(col);
}




tables: tables ',' tablename {
	tableList.push_back(string($3));
}
| tablename {
	tableList.push_back(string($1));
}



conditions: condition {
	//cout<<"conditions->condition\n";
	$$=$1;
}
| '(' conditions ')' {
	//cout<<"conditions->(conditions)\n";
	$$=$2;
}
| conditions AND conditions {
	
	$$=(struct Conditions *)malloc(sizeof(struct Conditions));
	memset($$,0,sizeof(struct Conditions));
	$$->left=$1;
	$$->right=$3;
	$$->comp_op=$2;
}
| conditions OR conditions{
	$$=(struct Conditions *)malloc(sizeof(struct Conditions));
	memset($$,0,sizeof(struct Conditions));
	$$->left=$1;
	$$->right=$3;
	$$->comp_op=$2;
}
| conditions OPERATOR conditions {
	//cout<<"conditions->conditions OPERATOR coditions\n";
	$$=(struct Conditions *)malloc(sizeof(struct Conditions));
	memset($$,0,sizeof(struct Conditions));
	$$->left=$1;
	$$->right=$3;
	$$->comp_op=$2;
}



condition: feild {
	//cout<<"condition->feild\n";
	$$=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset($$,0,sizeof(struct Conditions));
	$$->table=$1->tablename;
	$$->type=enum_FEILD;
	$$->value.val_str=$1->feildname;
	$$->left=NULL;
	$$->right=NULL;
}
| STRING {
	//cout<<"condition->string\n";
	$$=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset($$,0,sizeof(struct Conditions));
	$$->table=NULL;
	$$->type=enum_CHAR;
	$$->value.val_str=$1;
	$$->left=NULL;
	$$->right=NULL;
}
| INTEGER {
	//cout<<"condition->integer\n";
	$$=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset($$,0,sizeof(struct Conditions));
	$$->table=NULL;
	$$->type=enum_INT;
	$$->value.val_int=$1;
	$$->left=NULL;
	$$->right=NULL;
}
| FLOATE {
	$$=(struct Conditions *) malloc( sizeof(struct Conditions ));
	memset($$,0,sizeof(struct Conditions));
	$$->table=NULL;
	$$->type=enum_FLOAT;
	$$->value.val_float=$1;
	$$->left=NULL;
	$$->right=NULL;
}


feild: tablename '.' feildname{
	$$=(struct Feild *) malloc( sizeof(struct Feild ));
	memset($$,0,sizeof(struct Feild));
	$$->tablename=$1;
	$$->feildname=$3;
}
| feildname {
	$$=(struct Feild *) malloc( sizeof(struct Feild ));
	memset($$,0,sizeof(struct Feild));
	$$->tablename=NULL;
	$$->feildname=$1;
}




insertsql: INSERT INTO tablename '(' insert_feild ')' VALUES '(' insert_values ')' ';'{
	$$=(struct InsertRootValue *) malloc(sizeof( struct InsertRootValue));
	memset($$,0,sizeof(struct InsertRootValue));
	$$->table=string($3);
	$$->cols=&insertColsList;
	$$->values=&valueList;
}
| INSERT INTO tablename VALUES '(' insert_values ')' ';'{
	$$=(struct InsertRootValue *) malloc(sizeof( struct InsertRootValue));
	memset($$,0,sizeof(struct InsertRootValue));
	$$->table=string($3);
	insertColsList.clear();
	$$->cols=&insertColsList;
	$$->values=&valueList;
}
insert_feild: 
insert_feild ',' feildname {
	insertColsList.push_back(string($3));
}
| feildname {
	insertColsList.push_back(string($1));
}

insert_values: insert_values','value {
	valueList.push_back(*$3);	
}
| value {
	valueList.push_back(*$1);	
}
value: STRING {
	$$=(struct yyValue *)malloc( sizeof( struct yyValue ));
	memset($$,0,sizeof(struct yyValue));
	$$->type_length.type=enum_CHAR;
	$$->type_length.char_length=strlen($1);
	$$->value.val_str=$1;
}
| INTEGER{
	$$=(struct yyValue *)malloc( sizeof( struct yyValue ));
	memset($$,0,sizeof(struct yyValue));
	$$->type_length.type=enum_INT;
	$$->type_length.char_length=-1;
	$$->value.val_int=$1;
}
| FLOATE{
	$$=(struct yyValue *)malloc( sizeof( struct yyValue ));
	memset($$,0,sizeof(struct yyValue));
	$$->type_length.type=enum_FLOAT;
	$$->type_length.char_length=-1;
	$$->value.val_float=$1;
}


updatesql : UPDATE tablename SET setinfo WHERE conditions ';'{
	$$=(struct UpdateRootValue *) malloc(sizeof(struct UpdateRootValue));
	memset($$,0,sizeof(struct UpdateRootValue));
	$$->tablename=$2;
	$$->conditions=$6;
	$$->setList=&setList;
}
setinfo: setinfo ',' feild OPERATOR value {
	//cout<<"setinfo ',' feild '=' value"<<endl;
	if($4[0]=='='){
	struct Feild_Value tmp;
	tmp.feild=*($3);
	tmp.value= $5->value;
	tmp.type= $5->type_length.type;
	tmp.length=$5->type_length.char_length;
	setList.push_back(tmp);
	}
	else {yyerror("syntax"); return -1;}
}
| feild OPERATOR value {
	//cout<<"feild '=' value"<<endl;
	if($2[0]=='='){
	struct Feild_Value tmp;
	tmp.feild=*($1);
	tmp.value= $3->value;
	tmp.type= $3->type_length.type;
	tmp.length=$3->type_length.char_length;
	setList.push_back(tmp);
	}
	else {yyerror("syntax error"); return -1;}
}


deletesql: DELETE FROM tablename WHERE conditions ';'{
	$$=(struct DeleteRootValue *) malloc(sizeof(struct DeleteRootValue));
	memset($$,0,sizeof(struct DeleteRootValue));
	$$->tablename=$3;
	$$->conditions=$5;
}



feildname: ID 

tablename: ID

%%



int yyerror(char * msg)
{
    printf("%s in line %d: %s\n",msg,lineno,yytext);
    return 1;

}
