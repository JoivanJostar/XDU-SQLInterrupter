#pragma once
#ifndef STOCK_H_
#define STOCK_H_
#include <ctype.h>
#include <stdlib.h>
#include <sstream>

#define FILE_DATABASES "SQLfile\\db.bat"

//yacc类型设置
//字段类型
//采用int型表示 int是1 double是2 varchar是3
//enum Type{int_num,double_num,var_char};

//完整性约束类型
//采用int型表示 无是0 primarykey是1 notnull是2 foreignkey是3
//enum Constraint{PRIMARYKEY,NOTNULL,FOREIGNKEY};

//ID和变量结构
struct values {
	char* name;
	int intnum;
	double doublenum;
	int length;
};

//表列名
struct colname {
	char* tablename;
	int tablelength;
	int num;
	char* name;
	int columelength;
	int exist;
	struct colname* next;
};

//列数据类型
struct coltype {
	int type;
	int length;
};

//列完整性约束
struct colconf {
	int con;
	struct colconf* next;
};

//列名和类型结构
struct cols {
	char* colname;
	int coltype;
	int length;
	int num;
	struct colconf* colconf;
	struct cols* next;
};

//表完整性约束
struct tableconf {
	struct colname* colnames;
	char* refertable;
	char* refercol;
	int con;
	struct tableconf* next;
};

//建表语句
struct createsql {
	char* tablename;
	struct cols* cols;
	struct tableconf* tableconf;
};

//表内数据结构
struct dataformat {
	char* data;
	int length;
	int type;
	int num;
	struct dataformat* next;
};

//插入语句
struct insertsql {
	char* tablename;
	struct colname* colnames;
	struct dataformat* datas;
};

//条件元素
struct comparator {
	int type;
	struct dataformat* data;
	struct colname* col;
};

//条件判断
struct condition {
	//0: 不存在 1/2/3：数值 4：列名 5：条件
	int left_type;
	struct dataformat* left_data;
	struct colname* left_col;
	struct condition* left_cond;
	int right_type;
	struct dataformat* right_data;
	struct colname* right_col;
	struct condition* right_cond;
	//0:没有 1:< 2:> 3:<= 4：>= 5: = 6:!=
	int comp_op;
	//0:无 1:AND 2:OR 3:NOT 
	int comp_cond;
	bool result;
};

//select tableconf
struct tablecolconfs {
	int isall;
	struct colname* colnames;
};



//选择语句 isall = 1表示*
struct selectsql {
	int isall;
	struct colname* colnames;
	struct colname* tablenames;
	struct condition* condition_tree;
};

struct setconf {
	struct colname* name;
	struct dataformat* value;
	int num;
	struct setconf* next;
};

//更新语句
struct updatesql {
	struct colname* tablename;
	struct setconf* setconfs;
	int num;
	struct condition* condition_tree;
};

//删除语句
struct deletesql {
	struct colname* tablename;
	struct condition* condition_tree;
};

//实现代码数据结构

//数据库结构
struct database {
	char* name;
	int tablenum;
	struct database* next;
};

//列结构
struct colume {
	char* name;
	int coltype;
	int length;
	int not_null;
	int primarykey;
	int foreignkey;
	char* refertable;
	char* refercol;
	struct colume* next;
};

//表结构
struct table {
	char* name;
	int colnum; //有多少列
	int num;   //有多少数据行
	int collength;//行字节
	struct colume* columelist;
	struct table* next;
};

//数据结构
struct datanode {
	char* tablename;
	char* name;
	int coltype;
	int length;
	char* data;
	//0是没有，1是左，2是右
	int left_or_right;
	struct condition* condition_node;
};

//实现相关函数
void initsystem();
void closesystem();
void createdb(char*);
void dropdb(char*);
void usedb(char*);
void showdb();
void showtable();
void createtable(struct createsql*);
void droptable(char*);
void inserttable(struct insertsql*);
void selecttable(struct selectsql*);
void updatetable(struct updatesql*);
void deletetable(struct deletesql*);

void showLRUlist();

#endif