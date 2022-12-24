#pragma once
#ifndef STOCK_H_
#define STOCK_H_
#include <ctype.h>
#include <stdlib.h>
#include <sstream>

#define FILE_DATABASES "SQLfile\\db.bat"

//yacc��������
//�ֶ�����
//����int�ͱ�ʾ int��1 double��2 varchar��3
//enum Type{int_num,double_num,var_char};

//������Լ������
//����int�ͱ�ʾ ����0 primarykey��1 notnull��2 foreignkey��3
//enum Constraint{PRIMARYKEY,NOTNULL,FOREIGNKEY};

//ID�ͱ����ṹ
struct values {
	char* name;
	int intnum;
	double doublenum;
	int length;
};

//������
struct colname {
	char* tablename;
	int tablelength;
	int num;
	char* name;
	int columelength;
	int exist;
	struct colname* next;
};

//����������
struct coltype {
	int type;
	int length;
};

//��������Լ��
struct colconf {
	int con;
	struct colconf* next;
};

//���������ͽṹ
struct cols {
	char* colname;
	int coltype;
	int length;
	int num;
	struct colconf* colconf;
	struct cols* next;
};

//��������Լ��
struct tableconf {
	struct colname* colnames;
	char* refertable;
	char* refercol;
	int con;
	struct tableconf* next;
};

//�������
struct createsql {
	char* tablename;
	struct cols* cols;
	struct tableconf* tableconf;
};

//�������ݽṹ
struct dataformat {
	char* data;
	int length;
	int type;
	int num;
	struct dataformat* next;
};

//�������
struct insertsql {
	char* tablename;
	struct colname* colnames;
	struct dataformat* datas;
};

//����Ԫ��
struct comparator {
	int type;
	struct dataformat* data;
	struct colname* col;
};

//�����ж�
struct condition {
	//0: ������ 1/2/3����ֵ 4������ 5������
	int left_type;
	struct dataformat* left_data;
	struct colname* left_col;
	struct condition* left_cond;
	int right_type;
	struct dataformat* right_data;
	struct colname* right_col;
	struct condition* right_cond;
	//0:û�� 1:< 2:> 3:<= 4��>= 5: = 6:!=
	int comp_op;
	//0:�� 1:AND 2:OR 3:NOT 
	int comp_cond;
	bool result;
};

//select tableconf
struct tablecolconfs {
	int isall;
	struct colname* colnames;
};



//ѡ����� isall = 1��ʾ*
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

//�������
struct updatesql {
	struct colname* tablename;
	struct setconf* setconfs;
	int num;
	struct condition* condition_tree;
};

//ɾ�����
struct deletesql {
	struct colname* tablename;
	struct condition* condition_tree;
};

//ʵ�ִ������ݽṹ

//���ݿ�ṹ
struct database {
	char* name;
	int tablenum;
	struct database* next;
};

//�нṹ
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

//��ṹ
struct table {
	char* name;
	int colnum; //�ж�����
	int num;   //�ж���������
	int collength;//���ֽ�
	struct colume* columelist;
	struct table* next;
};

//���ݽṹ
struct datanode {
	char* tablename;
	char* name;
	int coltype;
	int length;
	char* data;
	//0��û�У�1����2����
	int left_or_right;
	struct condition* condition_node;
};

//ʵ����غ���
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