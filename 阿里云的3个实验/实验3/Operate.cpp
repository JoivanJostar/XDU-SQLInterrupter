#include "Operate.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

int databasenum;
struct database* usedatabase;
struct database* db_list;
struct table* usedbtable_list;
ifstream infile[3];
ofstream outfile[3];
const string dbfile = "..\\SQLfile\\db.bat";
const string filehead = "..\\SQLfile\\";
const string tablefile = "\\table.bat";
const string filemid = "\\";
const string fileend = ".bat";

void showLRUlist(){}
//创建数据库节点
struct database* makedatabasenode(char* name, int tablenum) {
	struct database* node = new struct database;
	node->name = name;
	node->tablenum = tablenum;
	node->next = NULL;
	return node;
}

//创建列节点
struct colume* makecolumenode(char* name, enum Type coltype, int length, int not_null, int primarykey, int foreignkey, char* refertable, char* refercol) {
	struct colume* node = new struct colume;
	node->name = name;
	node->coltype = coltype;
	node->length = length;
	node->not_null = not_null;
	node->primarykey = primarykey;
	node->foreignkey = foreignkey;
	node->refertable = refertable;
	node->refercol = refercol;
	node->next = NULL;
	return node;

}

//创建表节点
struct table* maketablenode(char* name, int colnum, int num, int length,struct colume* columelist) {
	struct table* node = new struct table;
	node->name = name;
	node->colnum = colnum;
	node->num = num;
	node->collength = length;
	node->columelist = columelist;
	node->next = NULL;
	return node;
}

//写入单个数据库节点
void writedatabase(struct database *node)
{
	int namenum = strlen(node->name);
	outfile[0].write((char*)&namenum, sizeof(int));
	outfile[0].write(node->name, strlen(node->name) * sizeof(char));
	outfile[0].write((char*)&node->tablenum, sizeof(int));
}

//写入全部数据库节点
void writedatabases(int num, struct database* node) {
	int i = 0;
	for (i; i < num; i++)
	{
		writedatabase(node);
		node = node->next;
	}
}

//读出单个数据库节点
struct database* readdatabase() {
	int namenum;
	char* name;
	int tablenum;

	infile[0].read((char*)&namenum, sizeof(int));
	name = new char[namenum+1];
	infile[0].read(name, namenum*sizeof(char));
	name[namenum] = '\0';
	infile[0].read((char*)&tablenum, sizeof(int));
	return makedatabasenode(name, tablenum);
}

//读出全部数据库节点
void readdatabases(int num, struct database* &node) {
	struct database* first = new struct database;
	node = first;
	int i = 0;
	for (i = 0; i < num; i++)
	{
		node->next = readdatabase();
		node = node->next;
	}
	node = first->next;
	delete first;
}

//写入单个列节点
void writecolume(struct colume* node){
	int namenum = strlen(node->name);
	outfile[1].write((char*)&namenum, sizeof(int));
	outfile[1].write(node->name, strlen(node->name) * sizeof(char));
	outfile[1].write((char*)&node->coltype, sizeof(int));
	outfile[1].write((char*)&node->length, sizeof(int));
	outfile[1].write((char*)&node->not_null, sizeof(int));
	outfile[1].write((char*)&node->primarykey, sizeof(int));
	outfile[1].write((char*)&node->foreignkey, sizeof(int));
	if (node->foreignkey == 1) {
		namenum = strlen(node->refertable);
		outfile[1].write((char*)&namenum, sizeof(int));
		outfile[1].write(node->refertable, strlen(node->refertable) * sizeof(char));
		namenum = strlen(node->refercol);
		outfile[1].write((char*)&namenum, sizeof(int));
		outfile[1].write(node->refercol, strlen(node->refercol) * sizeof(char));
	}
}

//写入全部列节点
void writecolumes(int colnum, struct colume* list) {
	int i;
	for (i = 0; i < colnum; i++)
	{
		writecolume(list);
		list = list->next;
	}
}

//读出单个列节点
struct colume* readcolume() {
	int namenum;
	char* name;
	enum Type coltype;
	int length;
	int not_null;
	int primarykey;
	int foreignkey;
	char* refertable;
	char* refercol;
	infile[1].read((char*)&namenum, sizeof(int));
	name = new char[namenum + 1];
	infile[1].read(name, namenum * sizeof(char));
	name[namenum] = '\0';
	infile[1].read((char*)&coltype, sizeof(int));
	infile[1].read((char*)&length, sizeof(int));
	infile[1].read((char*)&not_null, sizeof(int));
	infile[1].read((char*)&primarykey, sizeof(int));
	infile[1].read((char*)&foreignkey, sizeof(int));
	refertable = NULL;
	refercol = NULL;
	if (foreignkey == 1)
	{
		infile[1].read((char*)&namenum, sizeof(int));
		infile[1].read(refertable, namenum*sizeof(char));
		refertable[namenum] = '\0';
		infile[1].read((char*)&namenum, sizeof(int));
		infile[1].read(refercol, namenum * sizeof(char));
		refercol[namenum] = '\0';
	}
	return makecolumenode(name, coltype, length, not_null, primarykey, foreignkey, refertable, refercol);
}

//读出全部列节点
void readcolumes(int colnum, struct colume* &list) {
	struct colume* first = new struct colume;
	list = first;
	int i = 0;
	for (i = 0; i < colnum; i++)
	{
		list->next = readcolume();
		list = list->next;
	}
	list = first->next;
	delete first;
}

//写入单个表节点
void writetable(struct table* node) {
	int namenum = strlen(node->name);
	outfile[1].write((char*)&namenum, sizeof(int));
	outfile[1].write(node->name, strlen(node->name) * sizeof(char));
	outfile[1].write((char*)&node->colnum, sizeof(int));
	outfile[1].write((char*)&node->num, sizeof(int));
	outfile[1].write((char*)&node->collength, sizeof(int));
	writecolumes(node->colnum, node->columelist);
}

//写入全部表节点
void writetables(int tablenum,struct table* list) {
	string dbnamestr(usedatabase->name);
	outfile[1].open((filehead + dbnamestr + tablefile).c_str(), ios::binary);
	int i;
	for (i = 0; i < tablenum; i++) {
		writetable(list);
		list = list->next;
	}
	outfile[1].close();
}

//读出单个表节点
struct table* readtable() {
	int namenum;
	char* name;
	int colnum;
	int num;
	int length;
	struct colume* columelist;

	infile[1].read((char*)&namenum, sizeof(int));
	name = new char[namenum + 1];
	infile[1].read(name, namenum * sizeof(char));
	name[namenum] = '\0';
	infile[1].read((char*)&colnum, sizeof(int));
	infile[1].read((char*)&num, sizeof(int));
	infile[1].read((char*)&length, sizeof(int));
	readcolumes(colnum, columelist);
	return maketablenode(name, colnum, num,length, columelist);
}

//读出全部表节点
void readtables(int tablenum, struct table* &list) {
	string dbnamestr(usedatabase->name);
	infile[1].open((filehead + dbnamestr + tablefile).c_str(), ios::binary);
	struct table* first = new struct table;
	list = first;
	list->next = NULL;
	int i = 0;
	for (i = 0; i < tablenum; i++)
	{
		list->next = readtable();
		list = list->next;
	}
	list = first->next;
	delete first;
	infile[1].close();
}

//初始化程序
void initsystem()
{
	//初始化全局变量
	db_list = NULL;
	usedbtable_list = NULL;
	usedatabase = NULL;

	//初始化文件流
	infile[0].open(dbfile.c_str(), ios::binary);
	if (infile[0].is_open() ){
		infile[0].read((char*)&databasenum, sizeof(int));
		readdatabases(databasenum, db_list);
	}
	else {
		databasenum = 0;
	}

	infile[0].seekg(0, ios::beg);
	infile[0].close();
	cout << "SQL init is ok" << endl;
}

//关闭程序
void closesystem()
{
	infile[0].close();
	infile[1].close();
	infile[2].close();
	outfile[0].close();
	outfile[1].close();
	outfile[2].close();

	cout << "bye" << endl;
}

//创建数据库
void createdb(char* name)
{

	char* dbname = new char[strlen(name) + 1];
	strcpy_s(dbname, strlen(name) + 1, name);
	string dbnamestr(dbname);
	bool flag = CreateDirectory((filehead + dbnamestr).c_str(), NULL);
	if (!flag) {
		cout << dbnamestr << " is existed";
		return;
	}
	outfile[1].open((filehead + dbnamestr + tablefile).c_str(), ios::binary);
	outfile[1].close();
	struct database* new_node = makedatabasenode(dbname, 0);
	new_node->next = db_list;
	db_list = new_node;
	databasenum++;
	outfile[0].open(dbfile.c_str(), ios::binary);
	outfile[0].write((char*)&databasenum, sizeof(int));
	writedatabases(databasenum, db_list);
	outfile[0].close();

	printf("database %s is created", dbname);
}

//显示数据库
void showdb()
{
	int i = 0;
	if (databasenum == 0) {
		cout << "emtpy databases" << endl;
		return;
	}
	cout << "databases:" << endl;
	struct database* node = db_list;
	for (i; i < databasenum; i++)
	{
		cout << node->name << endl;
		node = node->next;
	}
}

//定位数据库节点所处链表位置
int locatedb(char* name)
{
	struct database* node = db_list;
	int i = 0;
	while (i<databasenum&&strcmp(name, node->name) != 0) {
		node = node->next;
		i++;
	}
	if (i >= databasenum) i = -1;
	return i;
}

//切换数据库
void usedb(char* name) {
	struct database* node = db_list;
	int id = locatedb(name);
	if (id == -1) {
		printf("database %s not exists", name);
		return;
	}
	int i = 0;
	for (i; i < id; i++) {
		node = node->next;
	}
	usedatabase = node;
	readtables(usedatabase->tablenum, usedbtable_list);
	printf("use %s is ok", name);
}

//删除链表内指定位置的数据库节点
void deletedb_list(int i)
{
	struct database* node1, *node2;
	if (i == 0) {
		node1 = db_list;
		db_list = db_list->next;
		delete node1;
	}
	else {
		node1 = db_list;
		for (; i > 1; i--) {
			node1 = node1->next;
		}
		node2 = node1->next;
		node1->next = node2->next;
		delete node2;
	}
}

//删除数据库
void dropdb(char* name)
{
	char* dbname = new char[strlen(name) + 1];
	strcpy_s(dbname, strlen(name) + 1, name);
	dbname[strlen(name)] = '\0';
	int id = locatedb(dbname);
	if (id == -1) {
		printf("database %s not exists", dbname);
		return;
	}

	char* nodename = NULL;

	if (usedatabase != NULL) {
		nodename = new char[strlen(usedatabase->name) + 1];
		strcpy_s(nodename, strlen(usedatabase->name) + 1, usedatabase->name);
	}
	
	usedb(dbname);

	int num = usedatabase->tablenum;
	int i = 0;
	for (i = 0; i < num; i++) {
		droptable(usedbtable_list->name);
	}

	if (usedatabase->tablenum != 0) {
		cout << "drop database error";
		return;
	}

	string dbnamestr(dbname);
	if (remove((filehead + dbnamestr + tablefile).c_str()) != 0) {
		cout << "drop database error";
		return;
	}

	bool flag = RemoveDirectory((filehead + dbnamestr).c_str());
	if (!flag) {
		cout << "drop database error";
		return;
	}

	deletedb_list(id);
	databasenum--;
	outfile[0].open(dbfile.c_str(), ios::binary);
	outfile[0].write((char*)&databasenum, sizeof(int));
	writedatabases(databasenum, db_list);
	outfile[0].close();

	if(nodename == NULL) usedatabase = NULL;
	else if (strcmp(dbname, nodename) == 0) usedatabase = NULL;
	else usedb(nodename);
	
	cout << "drop database " << dbname << " is ok";
}

//创建列
void createcol(struct cols* col,struct colume* &columelist,int colnum, int &ifprimarykey)
{
	struct colume* newcol = new struct colume;
	newcol->name = new char[strlen(col->colname)+1];
	strcpy_s(newcol->name, strlen(col->colname)+1, col->colname);
	newcol->name[strlen(col->colname)] = '\0';
	newcol->coltype = col->coltype;
	newcol->length = col->length;
	newcol->not_null = 0;
	newcol->primarykey = 0;
	newcol->foreignkey = 0;
	newcol->refertable = NULL;
	newcol->refercol = NULL;
	struct colconf* list = col->colconf;
	/*while (1)
	{
		if (list == NULL) {
			cout << "111\n"; goto l1;
		}
		switch (list->con)
		{
		case 1: newcol->primarykey = 1; ifprimarykey = 1; break;
		case 2: newcol->not_null = 2; break;
		default: list->next = NULL;
		}
		list = list->next;
	}*/
	newcol->next = NULL;
	if (colnum == 0) {
		columelist = newcol;
		return;
	}
	struct colume* node = columelist;
	int i = 0;
	for (i; i < colnum-1; i++) {
		node = node->next;
	}
	node->next = newcol;
}

//创建表
void createtable(struct createsql* sql)
{
	if (usedatabase == NULL) {
		printf("not use datbase");
		return;
	}
	struct table* newtable = new struct table;
	newtable->name = new char[strlen(sql->tablename) + 1];
	strcpy_s(newtable->name, strlen(sql->tablename) + 1, sql->tablename);

	int i = 0;
	struct table* tablelist = usedbtable_list;
	for (i; i < usedatabase->tablenum; i++) {
		if (strcmp(tablelist->name, newtable->name) == 0) {
			cout << "table " << newtable->name << " is existed";
			return;
		}
		tablelist = tablelist->next;
	}

	newtable->columelist = NULL;
	newtable->colnum = 0;
	newtable->num = 0;
	newtable->collength = 0;
	struct cols* list = sql->cols;
	list = sql->cols;
	int ifprimarykey = 0;
	i = list->num;
	while (list!=NULL)
	{
		createcol(list, newtable->columelist,newtable->colnum,ifprimarykey);
		newtable->colnum++;
		newtable->collength += list->length;
		list = list->next;
		i--;
	}

	struct tableconf* conflist = sql->tableconf;
	struct colume* collist;
	struct colname* colnamelist;
	while (conflist != NULL)
	{
		switch (conflist->con) {
		case 1: if (ifprimarykey == 1) return;
				else {
					colnamelist = conflist->colnames;
					while ( colnamelist != NULL) {
						collist = newtable->columelist;
						while (collist != NULL) {
							if (strcmp(colnamelist->name, collist->name) == 0) {
								collist->primarykey = 1;
							}
							collist = collist->next;
						}
						colnamelist = colnamelist->next;
					}
				}
				break;
		case 2: collist = newtable->columelist;
				while (collist != NULL) {
					if (strcmp(conflist->colnames->name, collist->name) == 0) {
						collist->foreignkey = 1;
						collist->refertable = conflist->refertable;
						collist->refercol = conflist->refercol;
					}
					collist = collist->next;
				}break;
		default: conflist->next = NULL;
		}
		conflist = conflist->next;
	}

	newtable->next = usedbtable_list;
	usedbtable_list = newtable;
	usedatabase->tablenum++;

	outfile[0].open(dbfile.c_str(), ios::binary);
	outfile[0].write((char*)&databasenum, sizeof(int));
	writedatabases(databasenum, db_list);
	outfile[0].close();

	writetables(usedatabase->tablenum, usedbtable_list);

	string dbnamestr(usedatabase->name);
	string tablenamestr(newtable->name);
	outfile[2].open((filehead + dbnamestr + filemid + tablenamestr + fileend).c_str(), ios::binary);
	outfile[2].close();

	printf("table %s is create", newtable->name);
}

//显示表
void showtable() {
	if (usedatabase == NULL) {
		printf("not use datbase");
		return;
	}
	int i = 0;
	struct table* list = usedbtable_list;
	cout << "show tables:" << endl;
	cout <<"tablenum:"<< usedatabase->tablenum << endl;
	for (i; i < usedatabase->tablenum; i++) {
		cout << list->name << "\t" << list->colnum <<"\t"<<list->num<<"\t"<<endl;
		list = list->next;
	}
}

//删除表
void droptable(char* name) {
	if (usedatabase == NULL) {
		printf("not use datbase");
		return;
	}
	struct table* node;
	string dbnamestr(usedatabase->name);
	string tablenamestr(name);
	if (strcmp(usedbtable_list->name, name) == 0) {
		
		if (remove((filehead + dbnamestr + filemid + tablenamestr + fileend).c_str()) != 0) {
			cout << "delete error";
			return;
		}

		node = usedbtable_list;
		usedbtable_list = usedbtable_list->next;
		delete node;
		cout << "delete table " << name << " is ok";
		usedatabase->tablenum--;

		outfile[0].open(dbfile.c_str(), ios::binary);
		outfile[0].write((char*)&databasenum, sizeof(int));
		writedatabases(databasenum, db_list);
		outfile[0].close();

		writetables(usedatabase->tablenum, usedbtable_list);

		return;
	}
	struct table* tablelist = usedbtable_list;
	while (tablelist->next!=NULL) {
		if (strcmp(tablelist->next->name, name) == 0) {
			
			if (remove((filehead + dbnamestr + filemid + tablenamestr + fileend).c_str()) != 0) {
				cout << "delete error";
				return;
			}

			node = tablelist->next;
			tablelist->next = tablelist->next->next;
			delete node;
			cout << "delete table " << name << " is ok ";
			usedatabase->tablenum--;

			outfile[0].open(dbfile.c_str(), ios::binary);
			outfile[0].write((char*)&databasenum, sizeof(int));
			writedatabases(databasenum, db_list);
			outfile[0].close();

			writetables(usedatabase->tablenum, usedbtable_list);

			return;
		}
		tablelist = tablelist->next;
	}
	cout << "table " << name << " is not exist";
}

//插入数据
void inserttable(struct insertsql* sql) {
	if (usedatabase == NULL) {
		printf("not use datbase");
		return;
	}

	struct table* node = usedbtable_list;
	while (node != NULL) {
		if (strcmp(node->name, sql->tablename) == 0) break;
		node = node->next;
	}
	if (node == NULL) {
		cout << "table " << sql->tablename << " is not exist";
		return;
	}

	struct datanode* dataarray = new struct datanode[node->colnum];
	int i = 0;
	struct colume* collist = node->columelist;
	for (i = 0; i < node->colnum; i++) {
		dataarray[i].tablename = sql->tablename;
		dataarray[i].name = collist->name;
		dataarray[i].coltype = collist->coltype;
		dataarray[i].length = collist->length;
		dataarray[i].data = new char[1];
		dataarray[i].data[0] = '\0';
		dataarray[i].left_or_right = 0;
		dataarray[i].condition_node = NULL;
		collist = collist->next;
	}

	if (sql->colnames!= NULL) {
		struct colname* namelist = sql->colnames;
		struct dataformat* datalist = sql->datas;
		while (namelist != NULL&&datalist != NULL) {
			for (i = 0; i < node->colnum; i++) {
				
				if (strcmp(dataarray[i].name, namelist->name) == 0) {
					if (dataarray[i].coltype == datalist->type && dataarray[i].length >= datalist->length) {
						dataarray[i].data = new char[dataarray[i].length+1];
						strcpy_s(dataarray[i].data, datalist->length + 1, datalist->data);
						dataarray[i].data[datalist->length] = '\0';
						break;
					}
					else {
						cout << namelist->name<<"type error";
						return;
					}
				}
			}
			if (i >= node->colnum) {
				cout << namelist->name << "is not exit";
				return;
			}
			namelist = namelist->next;
			datalist = datalist->next;
		}
		if (!(namelist == NULL&&datalist == NULL)) {
			cout << "col num != data num";
			return;
		}
	}
	else {
		struct dataformat* datalist = sql->datas;
		for (i = 0; i < node->colnum; i++) {
			if (datalist == NULL) {
				cout << "col num != data num";
				return;
			}
			if (dataarray[i].coltype == datalist->type && dataarray[i].length+1 >= datalist->length) {
				dataarray[i].data = new char[dataarray[i].length+1];
				strcpy_s(dataarray[i].data, datalist->length, datalist->data);
				dataarray[i].data[datalist->length] = '\0';
			}
			else {
				cout << dataarray[i].length << endl;
				cout<<datalist->length<<endl;
				cout << dataarray[i].name << "type error";
				return;
			}
			datalist = datalist->next;
		}
		if (datalist != NULL) {
			cout << "col num != data num";
			return;
		}
	}

	string dbnamestr(usedatabase->name);
	string tablenamestr(sql->tablename);
	fstream file;
	file.open((filehead + dbnamestr + filemid + tablenamestr + fileend).c_str(), ios::in|ios::out|ios::binary);
	file.seekp(node->num*node->collength, ios_base::beg);
	
	for (i = 0; i < node->colnum; i++) {
		file.write(dataarray[i].data, dataarray[i].length);
	}

	file.close();

	node->num++;
	writetables(usedatabase->tablenum, usedbtable_list);

	cout << "insert is ok";
}

//选择条件内还有列数据的条件，并与数据项绑定
void choosecondition(struct condition* node, struct datanode** nodearray, int tablenum ,int* colnums) {
	if (node->left_type != 5 && node->right_type != 5) return;
	int i, j;
	//判断左子树
	if (node->left_type == 5) {
		struct condition* newnode = node->left_cond;
		if (newnode->left_type == 4) {
			int x, y, num = 0;
			if (newnode->left_col->tablename == NULL) {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->left_col->name, dataarray[j].name) == 0) {
							x = i; y = j; num++;
						}
					}
				}
			}
			else {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->left_col->name, dataarray[j].name) == 0 && strcmp(newnode->left_col->tablename, dataarray[j].tablename) == 0) {
							x = i; y = j; num++;
						}

					}
				}
			}
			struct datanode* datanodes;
			switch (num) {
			case 0: cout << newnode->left_col->name << "can't find" << endl; break;
			case 1: datanodes = nodearray[x]; datanodes[y].condition_node = newnode; datanodes[y].left_or_right = 1; newnode->left_type = datanodes[y].coltype; newnode->left_data = new struct dataformat; break;
			default: cout << newnode->left_col->name << "have more cols" << endl; break;
			}
		}
		if (newnode->right_type == 4) {
			int x, y, num = 0;
			if (newnode->right_col->tablename == NULL) {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->right_col->name, dataarray[j].name) == 0) {
							x = i; y = j; num++;
						}
					}
				}
			}
			else {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->right_col->name, dataarray[j].name) == 0 && strcmp(newnode->right_col->tablename, dataarray[j].tablename) == 0) {
							x = i; y = j; num++;
						}

					}
				}
			}
			struct datanode* datanodes;
			switch (num) {
			case 0: cout << newnode->right_col->name << "can't find"<< endl; ; break;
			case 1: datanodes = nodearray[x]; datanodes[y].condition_node = newnode; datanodes[y].left_or_right = 2; newnode->right_type = datanodes[y].coltype; newnode->right_data = new struct dataformat; break;
			default: cout << newnode->right_col->name << "have more cols"<< endl; ; break;
			}
		}
		if (newnode->left_type == 5 || newnode->right_type == 5) choosecondition(newnode, nodearray, tablenum, colnums);
	}
	//判断右子树
	if (node->right_type == 5) {
		struct condition* newnode = node->right_cond;
		if (newnode->left_type == 4) {
			int x, y, num = 0;
			if (newnode->left_col->tablename == NULL) {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->left_col->name, dataarray[j].name) == 0) {
							x = i; y = j; num++;
						}
					}
				}
			}
			else {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->left_col->name, dataarray[j].name) == 0 && strcmp(newnode->left_col->tablename, dataarray[j].tablename) == 0) {
							x = i; y = j; num++;
						}

					}
				}
			}
			struct datanode* datanodes;
			switch (num) {
			case 0: cout << newnode->left_col->name << "can't find"<< endl; break;
			case 1: datanodes = nodearray[x]; datanodes[y].condition_node = newnode; datanodes[y].left_or_right = 1; newnode->left_type = datanodes[y].coltype; newnode->left_data = new struct dataformat; break;
			default: cout << newnode->left_col->name << "have more cols"<< endl; break;
			}
		}
		if (newnode->right_type == 4) {
			int x, y, num = 0;
			if (newnode->right_col->tablename == NULL) {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->right_col->name, dataarray[j].name) == 0) {
							x = i; y = j; num++;
						}
					}
				}
			}
			else {
				for (i = 0; i < tablenum; i++) {
					struct datanode* dataarray = nodearray[i];
					for (j = 0; j < colnums[i]; j++) {
						if (strcmp(newnode->right_col->name, dataarray[j].name) == 0 && strcmp(newnode->right_col->tablename, dataarray[j].tablename) == 0) {
							x = i; y = j; num++;
						}

					}
				}
			}
			struct datanode* datanodes;
			switch (num) {
			case 0: cout << newnode->right_col->name << "can't find"<< endl;  break;
			case 1: datanodes = nodearray[x]; datanodes[y].condition_node = newnode; datanodes[y].left_or_right = 2; newnode->right_type = datanodes[y].coltype; newnode->right_data = new struct dataformat; break;
			default: cout << newnode->right_col->name << "have more cols"<< endl;  break;
			}
		}
		if (newnode->left_type == 5 || newnode->right_type == 5) choosecondition(newnode, nodearray, tablenum, colnums);
	}
}

//判断条件是否成立
boolean dealcondition(struct condition* node) {
	//逻辑语句实现
	if (node->comp_cond == 0) {

		//判断条件是否有效
		if(node->left_type==1 || node->left_type==2)
			if (node->right_type != 1 && node->right_type != 2) {
				cout << "type error" << endl;
				node->result = false;
			}
		if(node->left_type==3)
			if (node->right_type != 3) {
				cout << "type error" << endl;
				node->result = false;
			}
		if (node->left_type == 4 || node->right_type == 4) {
			cout << "type error" << endl;
			node->result = false;
		}

		//条件判断

		//int int
		if (node->left_type == 1 && node->right_type == 1) {
			int a = atoi(node->left_data->data); int b = atoi(node->right_data->data);
			switch (node->comp_op) {
			case 1:node->result = (a < b); break;
			case 2:node->result = (a > b); break;
			case 3:node->result = (a <= b); break;
			case 4:node->result = (a >= b); break;
			case 5:node->result = (a == b); break;
			case 6:node->result = (a != b); break;
			}
		}

		//int double
		if (node->left_type == 1 && node->right_type == 2) {
			int a = atoi(node->left_data->data); double b = atof(node->right_data->data);
			switch (node->comp_op) {
			case 1:node->result = (a < b); break;
			case 2:node->result = (a > b); break;
			case 3:node->result = (a <= b); break;
			case 4:node->result = (a >= b); break;
			case 5:node->result = (a == b); break;
			case 6:node->result = (a != b); break;
			}
		}

		//double int
		if (node->left_type == 2 && node->right_type == 1) {
			double a = atof(node->left_data->data); int b = atoi(node->right_data->data);
			switch (node->comp_op) {
			case 1:node->result = (a < b); break;
			case 2:node->result = (a > b); break;
			case 3:node->result = (a <= b); break;
			case 4:node->result = (a >= b); break;
			case 5:node->result = (a == b); break;
			case 6:node->result = (a != b); break;
			}
		}
		
		//double double
		if (node->left_type == 2 && node->right_type == 2) {
			double a = atof(node->left_data->data); double b = atof(node->right_data->data);
			switch (node->comp_op) {
			case 1:node->result = (a < b); break;
			case 2:node->result = (a > b); break;
			case 3:node->result = (a <= b); break;
			case 4:node->result = (a >= b); break;
			case 5:node->result = (a == b); break;
			case 6:node->result = (a != b); break;
			}
		}

		//string string
		if (node->left_type == 3 && node->right_type == 3) {
			char* a = node->left_data->data; char* b = node->right_data->data;
			switch (node->comp_op) {
			case 1:node->result = (strcmp(a, b)<0); break;
			case 2:node->result = (strcmp(a, b)>0); break;
			case 3:node->result = (strcmp(a, b)<=0); break;
			case 4:node->result = (strcmp(a, b)>=0); break;
			case 5:node->result = (strcmp(a, b)==0); break;
			case 6:node->result = (strcmp(a, b)!=0); break;
			}
		}

		if (node->left_data->data[0] == '\0' || node->right_data->data[0] == '\0') {
			switch (node->comp_op) {
			case 1:node->result = false; break;
			case 2:node->result = false; break;
			case 3:node->result = false; break;
			case 4:node->result = false; break;
			case 5:node->result = false; break;
			case 6:node->result = true; break;
			}
		}
	}
	else {
		boolean right = dealcondition(node->right_cond);
		boolean left;
		switch (node->comp_cond) {
		case 1:left = dealcondition(node->left_cond); node->result = (left&&right); break;
		case 2:left = dealcondition(node->left_cond); node->result = (left||right); break;
		case 3:node->result = (!right); break;
		}
	}
	return node->result;
}

//判断将来要显示的数据项内容
void showselect(struct datanode** nodearray, int* colnums,struct selectsql* sql) {
	int i, j;
	if (sql->isall == 1) {
		for (i = 0; i < sql->tablenames->num; i++) {
			struct datanode* dataarray = nodearray[i];
			for (j = 0; j < colnums[i]; j++) {
				if (dataarray[j].data[0] == '\0')cout << "NULL" << "\t"; else cout << dataarray[j].data << "\t";
			}
		}
	}
	else {
		struct colname* collist = sql->colnames;
		while (collist != NULL) {
			if (collist->exist == 1) {
				int x, y, num = 0;
				if (collist->tablename == NULL) {
					for (i = 0; i < sql->tablenames->num; i++) {
						struct datanode* dataarray = nodearray[i];
						for (j = 0; j < colnums[i]; j++) {
							if (strcmp(collist->name, dataarray[j].name) == 0) {
								x = i; y = j; num++;
							}
						}
					}
				}
				else {
					for (i = 0; i < sql->tablenames->num; i++) {
						struct datanode* dataarray = nodearray[i];
						for (j = 0; j < colnums[i]; j++) {
							if (strcmp(collist->name, dataarray[j].name) == 0 && strcmp(collist->tablename, dataarray[j].tablename) == 0) {
								x = i; y = j; num++;
							}

						}
					}
				}
				struct datanode* datanodes;
				switch (num) {
				case 0: cout << collist->name << "can't find"; return;
				case 1: datanodes = nodearray[x]; if (datanodes[y].data[0] == '\0')cout << "NULL" << "\t";else cout << datanodes[y].data << "\t";  break;
				default: cout << collist->name << "have more cols"; return;
				}
			}
			if (collist->exist == 2) {
				cout << collist->name << "\t";
			}
			collist = collist->next;
		}
	}
}

//进行select操作
void select(struct datanode** nodearray, int tablenum,int* colnums, int* nums,struct condition* node,int id,struct selectsql* sql) {
	struct datanode* dataarray = nodearray[id];
	int colnum = colnums[id];
	int num = nums[id];
	string dbnamestr(usedatabase->name);
	string tablenamestr(dataarray[0].tablename);
	ifstream file;
	file.open((filehead + dbnamestr + filemid + tablenamestr + fileend).c_str(), ios::binary);

	int i, j;
	long sum = 0;
	for (i = 0; i < num; i++) {
		for (j = 0; j < colnum; j++) {
			dataarray[j].data = new char[dataarray[j].length + 1];
			file.read(dataarray[j].data, dataarray[j].length);
			dataarray[j].data[dataarray[j].length + 1] = '\0';
			if (dataarray[j].left_or_right == 1) {
				dataarray[j].condition_node->left_data->data = new char[strlen(dataarray[j].data) + 1];
				strcpy_s(dataarray[j].condition_node->left_data->data, strlen(dataarray[j].data) + 1, dataarray[j].data);
				dataarray[j].condition_node->left_data->data[strlen(dataarray[j].data) + 1] = '\0';
				dataarray[j].condition_node->left_type = dataarray[j].coltype;
			}
			if (dataarray[j].left_or_right == 2) {
				dataarray[j].condition_node->right_data->data = new char[strlen(dataarray[j].data) + 1];
				strcpy_s(dataarray[j].condition_node->right_data->data, strlen(dataarray[j].data) + 1, dataarray[j].data);
				dataarray[j].condition_node->right_data->data[strlen(dataarray[j].data) + 1] = '\0';
				dataarray[j].condition_node->right_type = dataarray[j].coltype;
			}
		}
		if (id < tablenum-1) select(nodearray, tablenum, colnums, nums, node, id + 1,sql);
		else if (node==NULL) {
			showselect(nodearray, colnums, sql);
			cout << endl;
			sum++;
		}
		else {
			if (dealcondition(node)) {
				showselect(nodearray, colnums, sql);
				cout << endl;
				sum++;
			}
		}
	}
	file.close();
	cout << "select row num: " << sum<<" ";
}

//选择数据
void selecttable(struct selectsql* sql) {
	clock_t start, finish;
	double duration;
	start = clock();
	//初始化
	struct datanode ** dataarrays = new struct datanode*[sql->tablenames->num];
	int* colnums = new int[sql->tablenames->num];
	int* nums = new int[sql->tablenames->num];

	//判断usedatabase
	if (usedatabase == NULL) {
		printf("not use datbase");
		return;
	}

	//从表中提取表内的每一项
	struct colname* tablelist = sql->tablenames;
	int i = 0, j = 0;
	for (i = 0; i < sql->tablenames->num; i++) {
		struct table* node = usedbtable_list;

		while (node != NULL) {
			if (strcmp(node->name, tablelist->tablename) == 0) break;
			node = node->next;
		}

		if (node == NULL) {
			cout << "table " << tablelist->tablename << " is not exist";
			return;
		}

		struct datanode* dataarray = new struct datanode[node->colnum];
		struct colume* collist = node->columelist;
		for (j = 0; j < node->colnum; j++) {
			dataarray[j].tablename = tablelist->tablename;
			dataarray[j].name = collist->name;
			dataarray[j].coltype = collist->coltype;
			dataarray[j].length = collist->length;
			dataarray[j].data = new char[1];
			dataarray[j].data[0] = '\0';
			dataarray[j].left_or_right = 0;
			dataarray[j].condition_node = NULL;
			collist = collist->next;
		}

		dataarrays[i] = dataarray;
		colnums[i] = node->colnum;
		nums[i] = node->num;

		tablelist = tablelist->next;
	}

	//判断条件中需要进行判断的项
	struct condition* node = sql->condition_tree;
	if (node != NULL)choosecondition(node, dataarrays, sql->tablenames->num, colnums);

	//显示列名
	if (sql->isall == 1) {
		for (i = 0; i < sql->tablenames->num; i++) {
			struct datanode* dataarray = dataarrays[i];
			for (j = 0; j < colnums[i]; j++) {
				if (sql->tablenames->num > 1) cout << dataarray[j].tablename << ".";
				cout << dataarray[j].name << "\t";
			}
		}
	}
	else {
		struct colname* collist = sql->colnames;
		while (collist != NULL) {
			if (collist->exist == 1) {
				int x, y, num = 0;
				if (collist->tablename == NULL) {
					for (i = 0; i < sql->tablenames->num; i++) {
						struct datanode* dataarray = dataarrays[i];
						for (j = 0; j < colnums[i]; j++) {
							if (strcmp(collist->name, dataarray[j].name) == 0) {
								x = i; y = j; num++;
							}
						}
					}
				}
				else {
					for (i = 0; i < sql->tablenames->num; i++) {
						struct datanode* dataarray = dataarrays[i];
						for (j = 0; j < colnums[i]; j++) {
							if (strcmp(collist->name, dataarray[j].name) == 0 && strcmp(collist->tablename, dataarray[j].tablename) == 0) {
								x = i; y = j; num++;
							}

						}
					}
				}
				switch (num) {
				case 0: cout << collist->name << "can't find"; return;
				case 1: if (collist->tablename != NULL)cout << collist->tablename << "."; cout << collist->name << "\t";  break;
				default: cout << collist->name << "have more cols"; return;
				}
			}
			if (collist->exist == 2) {
				cout << collist->name << "\t";
			}
			collist = collist->next;
		}
	}
	cout << endl;

	if(sql->condition_tree!=NULL)select(dataarrays, sql->tablenames->num, colnums, nums, sql->condition_tree->left_cond, 0, sql);
	else select(dataarrays, sql->tablenames->num, colnums, nums, NULL, 0, sql);

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "use time: " << duration << "s";
}

//更新操作
void updatetable(struct updatesql* sql) {
	clock_t start, finish;
	double duration;
	start = clock();

	if (usedatabase == NULL) {
		printf("not use datbase");
		return;
	}

	struct table* node = usedbtable_list;
	while (node != NULL) {
		if (strcmp(node->name, sql->tablename->tablename) == 0) break;
		node = node->next;
	}
	if (node == NULL) {
		cout << "table " << sql->tablename->tablename << " is not exist";
		return;
	}

	//列表转为可操作数组
	struct datanode* dataarray = new struct datanode[node->colnum];
	int i, j;
	struct colume* collist = node->columelist;
	for (i = 0; i < node->colnum; i++) {
		dataarray[i].tablename = node->name;
		dataarray[i].name = collist->name;
		dataarray[i].coltype = collist->coltype;
		dataarray[i].length = collist->length;
		dataarray[i].data = new char[1];
		dataarray[i].data[0] = '\0';
		dataarray[i].left_or_right = 0;
		dataarray[i].condition_node = NULL;
		collist = collist->next;
	}

	//判断条件中需要进行判断的项
	struct condition* conditionnode = sql->condition_tree;
	if (conditionnode != NULL)choosecondition(conditionnode, &dataarray, 1, &node->colnum);

	//相关操作
	string dbnamestr(usedatabase->name);
	string tablenamestr(node->name);
	fstream file;
	file.open((filehead + dbnamestr + filemid + tablenamestr + fileend).c_str(), ios::in|ios::out|ios::binary);

	for (i = 0; i < node->num; i++) {
		file.seekg(i*node->collength, ios_base::beg);
		for (j = 0; j < node->colnum; j++) {
			dataarray[j].data = new char[dataarray[j].length + 1];
			file.read(dataarray[j].data, dataarray[j].length);
			dataarray[j].data[dataarray[j].length + 1] = '\0';
			if (dataarray[j].left_or_right == 1) {
				dataarray[j].condition_node->left_data->data = dataarray[j].data;
				dataarray[j].condition_node->left_type = dataarray[j].coltype;
			}
			if (dataarray[j].left_or_right == 2) {
				dataarray[j].condition_node->right_data->data = dataarray[j].data;
				dataarray[j].condition_node->right_type = dataarray[j].coltype;
			}
		}
		if (sql->condition_tree == NULL) {
			struct setconf* setlist = sql->setconfs;
			while (setlist != NULL) {
				for (j = 0; j < node->colnum; j++) {
					if (strcmp(setlist->name->name, dataarray[j].name) == 0) {
						dataarray[j].data = setlist->value->data;
						break;
					}
					if (j == node->colnum) {
						cout << setlist->name->name << "is not exit";
						return;
					}
				}
				setlist = setlist->next;
			}
			file.seekp(i*node->collength, ios_base::beg);
			for (j = 0; j < node->colnum; j++) {
				file.write(dataarray[j].data, dataarray[j].length);
			}

		}
		else {
			if (dealcondition(sql->condition_tree->left_cond)) {
				struct setconf* setlist = sql->setconfs;
				while (setlist != NULL) {
					for (j = 0; j < node->colnum; j++) {
						if (strcmp(setlist->name->name, dataarray[j].name) == 0) {
							dataarray[j].data = setlist->value->data;
							break;
						}
						if (j == node->colnum) {
							cout << setlist->name->name << "is not exit";
							return;
						}
					}
					setlist = setlist->next;
				}
				file.seekp(i*node->collength, ios_base::beg);
				for (j = 0; j < node->colnum; j++) {
					file.write(dataarray[j].data, dataarray[j].length);
				}
			}
		}
	}
	file.close();
	cout << "update is ok ";

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "use time: " << duration << "s";


}

//删除操作
void deletetable(struct deletesql* sql) {
	clock_t start, finish;
	double duration;
	start = clock();

	if (usedatabase == NULL) {
		printf("not use datbase");
		return;
	}

	struct table* node = usedbtable_list;
	while (node != NULL) {
		if (strcmp(node->name, sql->tablename->tablename) == 0) break;
		node = node->next;
	}
	if (node == NULL) {
		cout << "table " << sql->tablename->tablename << " is not exist";
		return;
	}

	//列表转为可操作数组
	struct datanode* dataarray = new struct datanode[node->colnum];
	int i, j;
	struct colume* collist = node->columelist;
	for (i = 0; i < node->colnum; i++) {
		dataarray[i].tablename = node->name;
		dataarray[i].name = collist->name;
		dataarray[i].coltype = collist->coltype;
		dataarray[i].length = collist->length;
		dataarray[i].data = new char[1];
		dataarray[i].data[0] = '\0';
		dataarray[i].left_or_right = 0;
		dataarray[i].condition_node = NULL;
		collist = collist->next;
	}

	//判断条件中需要进行判断的项
	struct condition* conditionnode = sql->condition_tree;
	if (conditionnode != NULL)choosecondition(conditionnode, &dataarray, 1, &node->colnum);

	//相关操作
	string dbnamestr(usedatabase->name);
	string tablenamestr(node->name);
	fstream file;
	file.open((filehead + dbnamestr + filemid + tablenamestr + fileend).c_str(), ios::in | ios::out | ios::binary);

	for (i = 0; i < node->num; i++) {
		file.seekg(i*node->collength, ios_base::beg);
		for (j = 0; j < node->colnum; j++) {
			dataarray[j].data = new char[dataarray[j].length + 1];
			file.read(dataarray[j].data, dataarray[j].length);
			dataarray[j].data[dataarray[j].length + 1] = '\0';
			if (dataarray[j].left_or_right == 1) {
				dataarray[j].condition_node->left_data->data = dataarray[j].data;
				dataarray[j].condition_node->left_type = dataarray[j].coltype;
			}
			if (dataarray[j].left_or_right == 2) {
				dataarray[j].condition_node->right_data->data = dataarray[j].data;
				dataarray[j].condition_node->right_type = dataarray[j].coltype;
			}
		}
		if (sql->condition_tree == NULL) {
			int k = i + 1;
			for (k; k < node->num; k++) {
				file.seekg(k*node->collength, ios_base::beg);
				for (j = 0; j < node->colnum; j++) {
					dataarray[j].data = new char[dataarray[j].length + 1];
					file.read(dataarray[j].data, dataarray[j].length);
					dataarray[j].data[dataarray[j].length + 1] = '\0';
				}
				file.seekp((k - 1)*node->collength, ios_base::beg);
				for (j = 0; j < node->colnum; j++) {
					file.write(dataarray[j].data, dataarray[j].length);
				}
			}
			i--;
			node->num--;

		}
		else {
			if (dealcondition(sql->condition_tree->left_cond)) {
				int k = i + 1;
				for (k; k < node->num; k++) {
					file.seekg(k*node->collength, ios_base::beg);
					for (j = 0; j < node->colnum; j++) {
						dataarray[j].data = new char[dataarray[j].length + 1];
						file.read(dataarray[j].data, dataarray[j].length);
						dataarray[j].data[dataarray[j].length + 1] = '\0';
					}
					file.seekp((k-1)*node->collength, ios_base::beg);
					for (j = 0; j < node->colnum; j++) {
						file.write(dataarray[j].data, dataarray[j].length);
					}
				}
				i--;
				node->num--;
			}
		}
	}

	file.close();
	writetables(usedatabase->tablenum, usedbtable_list);

	cout << "delete is ok ";

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "use time: " << duration << "s";
}
