#pragma once
#ifndef SQLOP_H
#define SQLOP_H
#include <string>
#include <vector>
#include <list>
using namespace std;
enum Type {
	enum_INT,
	enum_CHAR,
	enum_FLOAT,
	enum_FEILD
};

union Value {
	int val_int;
	float val_float;
	char * val_str;
};

struct struct_type {
	enum Type type;
	int char_length;
};
typedef struct {
	int index;
	string name;
	enum Type type;
	int length;
	union Value value;//用于select时暂存当前行的数据 用于insert时临时存储要的写数据
	bool flag;//
}Col; //用于内存
typedef struct {
	string name;
	vector <Col> cols;
}Table;



struct CreateRootValue {
	char *tablename;
	vector<Col> * feildefinition;
};



typedef string TableName;
typedef string ColName;
typedef struct{
	string tablename;
	string feildname;
}SelectCol;

struct SelectRootValue {
	vector<SelectCol> * cols;
	vector<TableName> * tables;
	struct Conditions *condition;
};
struct yyValue {
	union Value value;
	struct struct_type type_length;
};
struct InsertRootValue {
	TableName table;
	vector<ColName> * cols;
	vector<yyValue> * values;
};



struct Conditions {/*条件*/
	struct Conditions *left; //左部条件
	struct Conditions *right; //右部条件
	char * comp_op; /* 'a'是and, 'o'是or, '<' , '>' , '=', ‘!=' */
	enum Type type; /* 0是字段，1是字符串，2是整数 */
	union Value value;;/* 根据type存放字段名、字符串或整数 */
	char * table;/* NULL或表名  */
};

struct Feild {
	char * tablename;
	char * feildname;
};
struct Feild_Value {
	struct Feild feild;
	union Value value;
	enum Type type;
	int length;
};

struct UpdateRootValue {
	char * tablename;
	Conditions * conditions;
	vector<struct Feild_Value> *setList;
};
struct DeleteRootValue {
	char * tablename;
	Conditions *conditions;
};
extern bool g_Used;
bool ZYF_CreateTable(CreateRootValue * createInfo);
bool ZYF_Select(SelectRootValue * selectInfo);
bool ZYF_Insert(InsertRootValue * insertInfo);
bool ZYF_Update(UpdateRootValue * updateInfo);
bool ZYF_Delete(DeleteRootValue * deleteInfo);
bool ZYF_DropTable(char * tablename);
void ZYF_ShowTables();
bool ZYF_DropDataBase(char * database);
bool ZYF_CreateDataBase(char * database);
bool ZYF_UseDataBase(char * database);
void ZYF_ShowDataBase();
string ReadLine(istream &in);
vector <string> Split(string str, string token);
std::wstring StringToWString(const std::string& str);
#endif