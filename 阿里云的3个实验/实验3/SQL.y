%{
	#include"Operate.h"
	#include "calculate.h"
	#include<iostream>
	using namespace std;
	extern int yylex(void);
	int yyerror(char * msg);
	bool exitflag;
%}

%union
{
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
}


/* 终结符 */
%token INT CREATE DROP USE SELECT INSERT DELETE UPDATE FROM WHERE INTO VALUES SET 
%token DATABASE DATABASES TABLE PRIMARY KEY null ORDER GROUP BY LIKE ALTER HAVING IN EXISTS TABLES ASC DESC
%token ADD COLUMN VIEW INDEX DOUBLE SHOW FOREIGN REFERENCES RESTRICT CASCADE EXIT BYE VARCHAR LRU
%token ',' ';' '(' ')' '.'
%term<value> ID STRING INTNUMBER DOUBLENUMBER STRINGS
%token '='
%token '<' '>'
%left OR
%left AND
%right NOT
%left '+' '-'
%left '*' '/' '%'
%left '!'

/* 非终结符 */
%type<value> dbname
%type<colname> colnames colname colnameconf tablename insertcolname tablecol tables tablecols
%type<coltype> coltype
%type<colconf> colconf
%type<cols> cols col
%type<tableconf> tableconf primarykeyconf foreignkeyconfs foreignkeyconf
%type<createsql> createsql

%type<dataformat> value values valuesargs 
%type<calvalue> cal
%type<insertsql> insertsql

%type<condition> condition conditions whereconf
%type<tablecolconfs> tablecolconf
%type<selectsql> select selectsql
%type <comparator> comparator
%type<comp_op> comp_op

%type<setconf> setconf setconfs
%type<updatesql> updatesql
%type<deletesql> deletesql

%%

statements :statement {return 0;}
           |statements statement {return 0;}
           ;

statement :createsql {createtable($1);}
          |selectsql {selecttable($1);}
          |insertsql {inserttable($1);}
          |updatesql {updatetable($1);}
          |deletesql {deletetable($1);}
		  |dropsql  
          |createdb 
		  |showtable 
          |dropdb 
		  |showdb 
		  |usedb 
		  |showlru
		  |EXIT  {exitflag=true;return 0;}
		  |BYE   {exitflag=true;return 0;}
          ;

/* 创建数据库 */
createdb: CREATE DATABASE dbname ';' {createdb($3.name);};

/* 删除数据库 */
dropdb: DROP DATABASE dbname ';'{dropdb($3.name);};

/* use 数据库 */
usedb: USE DATABASE dbname ';'{usedb($3.name)};

/* 数据库名称 */
dbname: ID 
	{
		$$.length = $1.length;
		$$.name = (char *)malloc($1.length+1);
		strcpy_s($$.name,$1.length+1, $1.name);
	};

/* show databases */
showdb: SHOW DATABASES ';'{showdb();};

/* show table */
showtable: SHOW TABLES ';'{showtable();};

/* show lru */
showlru: SHOW LRU ';' {showLRUlist();};

/* 建表sql */
createsql:CREATE TABLE tablename '(' cols tableconf ')' ';' 
	     {
		  $$ = new struct createsql;
		  $$->tablename = (char *)malloc($3->tablelength+1);
		  strcpy_s($$->tablename, $3->tablelength+1, $3->tablename);
		  $$->cols = $5;
		  $$->tableconf = $6;
	      }
		 |CREATE TABLE tablename '(' cols ')' ';'
		 {
		 $$ = new struct createsql;
		  $$->tablename = (char *)malloc($3->tablelength+1);
		  strcpy_s($$->tablename, $3->tablelength+1, $3->tablename);
		  $$->cols = $5;
		  $$->tableconf = NULL;
		 }
		 ;

/* table名称 */
tablename:ID
	{
		$$ = new struct colname;
		$$->tablelength = $1.length;
		$$->tablename = (char *)malloc($1.length+1);
		strcpy_s($$->tablename,$1.length+1, $1.name);
		$$->next=NULL;
	};

/* table完整性约束*/
tableconf:
          primarykeyconf {$$ = $1;}
         | foreignkeyconfs {$$ = $1;}
		 | tableconf tableconf {$$=$1; while($1->next!=NULL)$1 = $1->next; $1->next = $2;}
		 ;

/* primarykey */
primarykeyconf :
               ',' PRIMARY KEY colnameconf
			   {
					$$ = new struct tableconf;
					$$->con = 1;
					$$->colnames = $4;
					$$->next = NULL;
			   }
			   ;

/* foreignkey */
foreignkeyconfs:foreignkeyconf {$$ = $1;}
               |foreignkeyconfs foreignkeyconf {$$=$1; while($1->next!=NULL)$1 = $1->next; $1->next = $2; };

foreignkeyconf: ',' FOREIGN KEY colnameconf REFERENCES tablename'(' colnames ')'{
                                                                                 $$ = new struct tableconf;
																				 $$->con = 3; 
																				 $$->colnames = $4; 
																				 $$->refertable = $6->tablename;
																				 $$->refercol = $8->name;
																				 $$->next = NULL;};

/* 列名相关参数配置 */
colnameconf:colname {$$ = $1;}
           |'(' colnames ')' {$$ = $2;} ;

/* 多条列名 */
colnames : colnames ',' colname {$$ = $1;while($1->next!=NULL)$1 = $1->next; $1->next = $3;}
         | colname {$$ = $1;}; 

/* 多列数据类型和格式 */
cols: cols ',' col {$$ = $1;while($1->next!=NULL)$1 = $1->next; $1->next = $3;} 
	| col {$$ = $1;};

/* 单列数据类型 */
col: colname coltype colconf
	{
		$$ = new struct cols;
		$$->colname = (char *)malloc($1->columelength+1);
		strcpy_s($$->colname, $1->columelength+1, $1->name);
		$$->coltype = $2->type;
		$$->length = $2->length;
		$$->colconf = $3;
		$$->next = NULL;
	}
   | colname coltype
   {
		$$ = new struct cols;
		$$->colname = (char *)malloc($1->columelength+1);
		strcpy_s($$->colname, $1->columelength+1, $1->name);
		$$->coltype = $2->type;
		$$->length = $2->length;
		$$->colconf = NULL;
		$$->next = NULL;
   }
   ;

/* 列名 */
colname: ID
	{
		$$ = new struct colname;
		$$->columelength = $1.length;
		$$->name = (char *)malloc($1.length+1);
		strcpy_s($$->name, $1.length+1, $1.name);
		$$->name[$1.length]='\0';
		$$->exist = 1;
		$$->next = NULL;
	};

/* 列类型 */
coltype: INT {$$ = new struct coltype; $$->type = 1; $$->length = 4;}
       | DOUBLE {$$ = new struct coltype;$$->type = 2; $$->length = 8;}
	   | VARCHAR '(' INTNUMBER ')' {$$ = new struct coltype;$$->type = 3; $$->length = $3.intnum;}
	   ;

/* 列属性 可为空 */
colconf:
	    NOT null {$$ = new struct colconf;$$->con = 2;$$->next = NULL;}
	   | PRIMARY KEY {$$ = new struct colconf;$$->con = 1;$$->next = NULL;};

/* select */
selectsql: select ';' {$$ = $1;}

/* 为了嵌套查询提供 */
select: SELECT tablecolconf FROM tables whereconf groupconf orderconf
      | SELECT tablecolconf FROM tables {
	                                     $$ = new struct selectsql;
										 $$->isall = $2->isall;
										 $$->colnames = $2->colnames;
										 $$->tablenames = $4;
										 $$->condition_tree = NULL;
	                                     }
	  | SELECT tablecolconf FROM tables whereconf {
	                                                $$ = new struct selectsql;
										            $$->isall = $2->isall;
										            $$->colnames = $2->colnames;
										            $$->tablenames = $4;
										            $$->condition_tree = $5;
													}
	  | SELECT tablecolconf FROM tables groupconf 
	  | SELECT tablecolconf FROM tables orderconf
	  | SELECT tablecolconf FROM tables whereconf groupconf
	  | SELECT tablecolconf FROM tables whereconf orderconf
	  | SELECT tablecolconf FROM tables groupconf orderconf;


/* select 列属性配置 */
tablecolconf: '*' {$$ = new struct tablecolconfs; $$->isall = 1;$$->colnames = NULL;}
            | tablecols {$$ = new struct tablecolconfs; $$->isall = 0;$$->colnames = $1;};

tablecols: tablecol {$$ = $1; $$->num = 1;}
		 | tablecols ',' tablecol{ $$ = $1;while($1->next!=NULL)$1 = $1->next; $1->next = $3; $$->num++;};

tablecol: colname {$$ = new struct colname;$$->exist = 1; $$->tablename =NULL; $$->name = new char[$1->columelength+1]; strcpy_s($$->name,$1->columelength+1,$1->name);$$->name[$1->columelength]='\0';$$->next = NULL;}
        | tablename '.' colname{$$ = new struct colname; $$->exist = 1;$$->tablename =new char[$1->tablelength+1]; strcpy_s($$->tablename,$1->tablelength+1,$1->tablename);$$->tablename[$1->tablelength]='\0'; $$->name = new char[$3->columelength+1]; strcpy_s($$->name,$3->columelength+1,$3->name);$$->name[$3->columelength]='\0';$$->next = NULL;}
		| STRING {$$ = new struct colname;
		          $$->tablename = NULL;
                  $$->exist = 2;
				  $$->name = (char *)malloc($1.length-1);
                  strcpy_s($$->name,$1.length-2+1,$1.name+1);
			      $$->name[$1.length-3]='\0';
			      $$->columelength = $1.length-2;
                  $$->next = NULL;
		          }
		| STRINGS{$$ = new struct colname;
		          $$->tablename = NULL;
                  $$->exist = 2;
				  $$->name = (char *)malloc($1.length-1);
                  strcpy_s($$->name,$1.length-2+1,$1.name+1);
			      $$->name[$1.length-3]='\0';
			      $$->columelength = $1.length-2;
                  $$->next = NULL;
		          }
		;

/* select 表属性配置 */
tables : tablename {$$ = $1;$$->num = 1;}
       | tables ',' tablename { $$ = $1;while($1->next!=NULL)$1 = $1->next; $1->next = $3; $$->num++;};

/* where 条件参数 */
whereconf: WHERE conditions {$$ = new struct condition;
                             $$->left_type = 5;
							 $$->left_cond = $2;
							 $$->right_type = 0;
							 };

/* 条件判断 */
conditions:condition {$$ = $1;}
          |conditions AND conditions {$$ = new struct condition;
		                              $$->left_type = 5;
									  $$->left_cond = $1;
									  $$->right_type = 5;
									  $$->right_cond = $3;
									  $$->comp_op = 0;
									  $$->comp_cond = 1;
									  }
		  |conditions OR conditions  {$$ = new struct condition;
		                              $$->left_type = 5;
									  $$->left_cond = $1;
									  $$->right_type = 5;
									  $$->right_cond = $3;
									  $$->comp_op = 0;
									  $$->comp_cond = 2;
									  }
		  |NOT conditions            {$$ = new struct condition;
		                              $$->left_type = 0;
									  $$->right_type = 5;
									  $$->right_cond = $2;
									  $$->comp_op = 0;
									  $$->comp_cond = 3;
									  }
		  |'(' conditions ')'         {$$ = $2;}
		  |EXISTS '('select ')'
		  |comparator comp_op '(' select ')'
		  |comparator IN '(' select ')'
		  |comparator NOT IN '(' select ')';


/* 比较式 */
condition: comparator comp_op comparator { $$ = new struct condition;
		                                   $$->left_type = $1->type;
									       $$->left_col = $1->col;
										   $$->left_data = $1->data;
									       $$->right_type = $3->type;
									       $$->right_col = $3->col;
										   $$->right_data = $3->data;
									       $$->comp_op = $2;
									       $$->comp_cond = 0;
									      };

/* 比较内容 */
comparator: cal     {$$ = new struct comparator;
                     calculate($1);
                     if($1->valuetype == 1) 
					 {
					     $$->type = 1;
						 $$->data = new struct dataformat;
						 $$->data->data = (char *)malloc(4);
				         _itoa_s($1->intnum,$$->data->data,4,10);
				         $$->data->length = 4;
				         $$->data->type = 1;
				         $$->data->next = NULL; 
						 $$->col = NULL;
				     }
					 if($1->valuetype == 2)
					 {
					     $$->type = 2;
					     $$->data = new struct dataformat;
						 $$->data->data = (char *)malloc(8);
                         std::ostringstream o;
				         o<<$1->doublenum;
                         strcpy_s($$->data->data,8,o.str().c_str());
				         $$->data->data[8]='\0';
				         $$->data->length = 8;
				         $$->data->type = 2;
				         $$->data->next = NULL; 
						 $$->col = NULL;
                     }
                     }
          | STRING  {$$ = new struct comparator;
                     $$->type = 3;
					 $$->data = new struct dataformat;
					 $$->data->data = (char *)malloc($1.length-1);
                     strcpy_s($$->data->data,$1.length-2+1,$1.name+1);
			         $$->data->data[$1.length-3]='\0';
			         $$->data->length = $1.length-2;
                     $$->col = NULL;
		             }
          | tablecol {$$ = new struct comparator;
		              if($1->exist == 2){
						$$->type = 3;
					    $$->data = new struct dataformat;
					    $$->data->data = (char *)malloc($1->columelength+1);
						strcpy_s($$->data->data,$1->columelength+1,$1->name);
			            $$->data->data[$1->columelength]='\0';
						$$->data->length = $1->columelength;
                        $$->col = NULL;
					  }
					  else{
					    $$->type = 4;
					    $$->data = NULL;
                        $$->col = $1;
					  }
                     };

comp_op: '<' {$$ = 1;}
       | '>' {$$ = 2;}
	   | '<' '=' {$$ = 3;}
	   | '>' '=' {$$ = 4;}
	   | '=' {$$ = 5;}
	   | '!' '=' {$$ = 6;};

/* groupby参数 */
groupconf: GROUP BY tablecols
         | GROUP BY tablecols having;

/* having参数 */
having: HAVING conditions; 

/* orderby参数 */
orderconf: ORDER BY ordercols;

ordercols: ordercol
         | ordercols ',' ordercol;

ordercol: tablecol
        | tablecol ASC
		| tablecol DESC;

/* insert */
insertsql: INSERT INTO tablename insertcolname valuesargs ';' {
                                                               $$ = new struct insertsql;
                                                               $$->tablename = $3->tablename;
															   $$->colnames = $4;
															   $$->datas = $5;
                                                               }
         | INSERT INTO tablename valuesargs ';'               {
		                                                       $$ = new struct insertsql;
                                                               $$->tablename = $3->tablename;
															   $$->colnames = NULL;
															   $$->datas = $4;
                                                               };

/* 插入的列 可以为空 */
insertcolname: '(' colnames ')' {$$ = $2;};

/* 插入的值 可以为子查询返回值 */
valuesargs: VALUES '(' values ')' {$$ = $3;}
          | selectsql;

/* 多值 */	
values: value {$$=$1;}
      | values ',' value {$$ = $1;while($1->next!=NULL)$1 = $1->next; $1->next = $3;}
	  ;

/* 插入值类型 */
value: STRING {
               $$ = new struct dataformat;
			   $$->data = (char *)malloc($1.length-1);
               strcpy_s($$->data,$1.length-2+1,$1.name+1);
			   $$->data[$1.length-3]='\0';
			   $$->length = $1.length-2;
			   $$->type = 3;
       		   $$->next = NULL;
			   }
	 | cal    {$$ = new struct dataformat;
	           calculate($1);
                     if($1->valuetype == 1) 
					 {
						 $$->data = (char *)malloc(4);
				         _itoa_s($1->intnum,$$->data,4,10);
				         $$->length = 4;
				         $$->type = 1;
				         $$->next = NULL; 
				     }
					 if($1->valuetype == 2)
					 {
						 $$->data = (char *)malloc(8);
                         std::ostringstream o;
				         o<<$1->doublenum;
                         strcpy_s($$->data,8,o.str().c_str());
				         $$->data[8]='\0';
				         $$->length = 8;
				         $$->type = 2;
				         $$->next = NULL; 
                     }
	 
	          }
	 ;

/* 计算 */
cal: cal '+' cal{ $$ = new struct calvalue;
				  /* 补充代码 */
				  $$->valuetype=3;
				  $$->caltype=1;
				  $$->leftcal=$1;
				  $$->rightcal=$3;
				 } 				
   | cal '-' cal{ $$ = new struct calvalue;
				  /* 补充代码 */
				  $$->valuetype=3;
				  $$->caltype=2;
				  $$->leftcal=$1;
				  $$->rightcal=$3;
				 } 
   | cal '*' cal { $$ = new struct calvalue;
				  /* 补充代码 */
				  $$->valuetype=3;
				  $$->caltype=3;
				  $$->leftcal=$1;
				  $$->rightcal=$3;
				 } 
   | cal '/' cal{ $$ = new struct calvalue;
				  /* 补充代码 */
				   $$->valuetype=3;
				  $$->caltype=4;
				  $$->leftcal=$1;
				  $$->rightcal=$3;
				 } 
   | '-' cal    { 
                  $$ = new struct calvalue;
				  /* 补充代码 */
				  $$->valuetype=3;
				  $$->caltype=2;
				  $$->leftcal=NULL;
				  $$->rightcal=$2;
                 } 
   | '(' cal ')' {$$ = $2;}
   | INTNUMBER    {$$ = new struct calvalue;
                   $$->valuetype = 1;
				   $$->leftcal = NULL;
				   $$->rightcal = NULL;
				   $$->intnum = $1.intnum;
				  }
   | DOUBLENUMBER {$$ = new struct calvalue;
                   $$->valuetype = 2;
				   $$->leftcal = NULL;
				   $$->rightcal = NULL;
				   $$->doublenum = $1.doublenum; 
				  }
    ;


/* update */
updatesql:UPDATE tablename SET setconfs whereconf ';' {
                                                       $$ = new struct updatesql;
													   $$-> tablename = $2;
													   $$-> setconfs = $4;
													   $$-> condition_tree = $5;
													   } 
         |UPDATE tablename SET setconfs ';'{
                                                       $$ = new struct updatesql;
													   $$-> tablename = $2;
													   $$-> setconfs = $4;
													   $$-> condition_tree = NULL;
													   };

/* set 值设置 */
setconfs: setconf {$$ = $1;$$->num = 1;}
        | setconfs ',' setconf { $$ = $1;while($1->next!=NULL)$1 = $1->next; $1->next = $3; $$->num++;};
		
setconf: colname '=' value {$$ = new struct setconf; $$->name = $1;$$->value = $3;$$->next = NULL;}; 

/* delete */
deletesql:DELETE FROM tablename whereconf ';' {$$ = new struct deletesql; $$->tablename = $3;$$->condition_tree = $4;}
         |DELETE FROM tablename ';'{$$ = new struct deletesql; $$->tablename = $3;$$->condition_tree = NULL;};

/* 删除table */
dropsql:DROP TABLE tablename droptableconf ';' {droptable($3->tablename);};

/* 删表要求 restrict or cascade*/
droptableconf:
             |RESTRICT
			 |CASCADE;

%%

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

      

