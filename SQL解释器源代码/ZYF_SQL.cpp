#include "ZYF_SQL.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <direct.h>
#include <Windows.h>
using namespace std;
enum intORChar {
	IsInt=4,
	IsChar
};
bool g_Used = false;
vector <string> Split(string str, string token);
string ReadLine(istream &in);
ifstream LoadSysFile();
bool GetTableInfo(Table &table, string TableName, string sysfilename);
void select(vector<Table *> &tables, vector<SelectCol> &selectcols, int recurse_depth);
Col * GetCol(vector<Table *> &tables, string colname, string tablename = "");
void ClearFlag(vector<Col>& cols);
void getColValue(Col &col, string srcvalue);
Col * GetCol(vector<Table *> &tables, string colname, char *tablename);
bool CheckConditionInvalid(vector<Table *> & tables, struct Conditions * conditions);
bool IsTrig(vector<Table *>&tables, struct Conditions * conditions);
void getSelectStarCols(vector<Table *> &tables, vector<SelectCol>& selectcols, int recurse_depth);
bool g_IsStar = false;

string g_sysfilename = "sys.txt";
string g_dbsysfilename = "sys.txt";
string g_dbpath = "";
struct Conditions * g_conditions;





void ZYF_ShowDataBase() {
	ifstream in(g_dbsysfilename);
	if (in.fail()) { cout << "ShowDataBase Error : no database sysfile sys.txt\n"; in.close(); return ; }

	cout << "databases:\n";
	while (!in.eof()) {
		string line = ReadLine(in);
		if (line.empty() || in.eof())break;
		cout << line << endl;
	}
	in.close();
}

bool GetDataBase(string database) {
	string databasename = database;
	ifstream in(g_dbsysfilename);
	if (in.fail()) { cout << "ShowDataBase Error : no database sysfile sys.txt\n"; in.close(); return false; }
	bool result = false;
	while (!in.eof()) {
		string line = ReadLine(in);
		if (line.empty() || in.eof())break;
		if (line == databasename) {
			result = true; break;
		}
	}
	in.close();
	return result;
}

bool ZYF_UseDataBase(char * database) {
	string databasename = database;
	if (false == GetDataBase(databasename)) {
		cout << "UseDataBase Error : no such database " + databasename << endl;
		return false;
	}
	else {
		g_sysfilename =".\\"+ databasename + "\\" + g_sysfilename;
		cout << "Using DataBase " + databasename << endl;
		g_dbpath = ".\\" + databasename+"\\";
		g_Used = true;
		return true;
	}
}
bool ZYF_CreateDataBase(char * database) {
	string databasename = database;
	if (true == GetDataBase(databasename)) {
		cout << "CreateDataBase Error : database " + databasename<<" has existed" << endl;
		return false;
	}
	string dbPath = ".\\" + databasename;
	if (-1 ==_mkdir(dbPath.c_str())){
		cout << "CreateDataBase Fail!\n"; return false;
	}
	ofstream out;
	out.open(g_dbsysfilename, ios::app);
	out << databasename << endl;
	out.close();
	
	out.open(".\\" + databasename + "\\sys.txt" );
	out.close();
	return true;
}
bool ZYF_DropDataBase(char * database) {
	string databasename = database;
	if (GetDataBase(databasename) == false) {
		return false;
	}
	string dbPath = ".\\" + databasename;
	string cmd = "rd /s/q ";
	system(string(cmd + dbPath).c_str());

	ifstream in;
	ofstream out;
	out.open(g_dbsysfilename + "_tmp");
	in.open(g_dbsysfilename);
	while (!in.eof()) {
		string line = ReadLine(in);
		if (line.empty() && in.eof())break;
		if (line == databasename)continue;
		out << line << endl;
	}
	in.close();
	out.close();

	in.open(g_dbsysfilename + "_tmp");
	out.open(g_dbsysfilename);
	while (!in.eof()) {
		string line = ReadLine(in);
		if (line.empty() && in.eof())break;
		out << line << endl;
	}
	in.close();
	out.close();
	DeleteFile(StringToWString(g_dbsysfilename + "_tmp").c_str());
	g_Used = false;
	return true;
}

bool ZYF_CreateTable(CreateRootValue * createInfo) {
	ifstream sys = LoadSysFile();
	if (!sys) {
		return false;
	}
	string tablename = createInfo->tablename;
	Table table;
	if (GetTableInfo(table, tablename, g_sysfilename)) {
		cout << "This table has existed \n";
		return false;
	}
	else {
		ofstream createTableFile;
		createTableFile.open(g_sysfilename, ios::out | ios::app);
		if (!createTableFile) {
			cout << "Fail to create table file \n";
			return false;
		}
		vector<Col> * cols = createInfo->feildefinition;

		for (auto it = cols->begin(); it != cols->end(); ++it) {
			createTableFile << tablename ;
			createTableFile << " " << it->index;
			createTableFile << " " << it->name;
			if (it->type == enum_INT)
				createTableFile << " " << "INT";
			else if (it->type ==enum_FLOAT)
				createTableFile << " " << "FLOAT";
			else {
				createTableFile << " " << "CHAR";
				createTableFile << " " << it->length;
			}
			createTableFile << endl;
		}

		createTableFile.close();
	}
	ofstream createTableFile(g_dbpath+tablename);
	createTableFile.close();
	sys.close();
	return true;
}

bool ZYF_Select(SelectRootValue * selectInfo) {
	g_IsStar = false;
	vector <Table *> tables;
	Table *table;
	ifstream sys = LoadSysFile();
	//获取表信息，检查待选表的存在性
	for (auto it = selectInfo->tables->begin(); it != selectInfo->tables->end(); ++it) {
		table = new Table;
		if (false == GetTableInfo(*table, *it, g_sysfilename)) {
			cout << "fail to select : no such table " + *it<<endl;
			sys.close();
			return false;
		}
		else {
			tables.push_back(table);
		}
	}//select * from Student,COURSE;
	//检查表文件的存在性
	ifstream readTable;
	for (auto it = tables.begin(); it != tables.end(); ++it) {
		string tablename = (*it)->name;
		readTable.open(g_dbpath+tablename);
		if (!readTable) {
			cout << "read Table error : so such table file" + tablename << endl;
			readTable.close(); sys.close();
			return false;
		}
		else
			readTable.close();
	}
	g_conditions = selectInfo->condition;
	if (g_conditions&&!CheckConditionInvalid(tables, g_conditions))
		return false;

	//是否是select *
	int recurse_depth = tables.size();
	vector<SelectCol> &selectcols = *(selectInfo->cols);
	g_IsStar = (selectcols.size() == 1 && selectcols[0].feildname == "*");
	if (g_IsStar) {
		selectcols.clear();
		for (int i = 0; i < tables.size(); ++i) {
			int beg = 0; 
			int end = tables[i]->cols.size();
			for (beg = 0; beg < end; ++beg) {
				selectcols.push_back({ tables[i]->name,tables[i]->cols[beg].name });
			}

		}
	}

	//列合法性检查：
	for (int i = 0; i < selectcols.size(); ++i) {
		Col * col = GetCol(tables, selectcols[i].feildname, selectcols[i].tablename);
		if (col == NULL) {
			cout << "Select error: no such table feild " + selectcols[i].feildname;
			return false;
		}
	}

	//合法：
	for (int i = 0; i < selectcols.size(); ++i) {
		for (int j = 0; j < 20; ++j)
			cout << '-';
		cout << '-';
	}
	cout << endl;
	for (int i = 0; i < selectcols.size(); ++i) {
		printf("%-20s", selectcols[i].feildname.c_str());
		cout << '|';
	}
	cout << endl;
	for (int i = 0; i < selectcols.size(); ++i) {
		for (int j = 0; j < 20; ++j)
			cout << '-';
		cout << '|';
	}
	cout << endl;
	//开始进行递归求解select的结果

	select(tables, selectcols,recurse_depth);

	sys.close();
	for (int i = 0; i < selectcols.size(); ++i) {
		for (int j = 0; j < 20; ++j)
			cout << '-';
		cout << '-';
	}
	return true;
}

bool ZYF_Insert(InsertRootValue * insertInfo) {
	
	TableName tablename = insertInfo->table;
	Table table;
	ifstream sys = LoadSysFile();
	if (!GetTableInfo(table, tablename, g_sysfilename)) {
		cout << "Insert error : no such table " + tablename << endl;
		sys.close();
		return false;
	}
	if (insertInfo->cols->empty()) {//默认动作 所有列
		for (int i = 0; i < table.cols.size(); ++i) {
			insertInfo->cols->push_back(table.cols[i].name);
		}
	}
	//检查value列表和col列表是否类型个数符合
	vector<ColName> &insertcols = *(insertInfo->cols);
	vector<yyValue> &values = *(insertInfo->values);
	if (insertcols.size() != values.size()) {
		cout << "Insert error: different amount between  columns and insert values" << endl;
		sys.close();
		return false;
	}
	//往表的列col写入value
	ClearFlag(table.cols);
	vector<Table *> tables; tables.push_back(&table);
	for (int i = 0; i < values.size(); ++i) {
		Col * col = GetCol(tables, insertcols[i]);
		if (col == NULL) {
			cout << "Insert error: no such column " + table.name + "." + insertcols[i] << endl;
			sys.close();
			return false;
		}
		if (col->type != values[i].type_length.type) {
			cout << "Insert error: different var type between table feild type and insert value type\n";
			sys.close();
			return false;
		}
		if (col->type == enum_CHAR && col->length < values[i].type_length.char_length) {
			cout << "Insert error: the string is too long： " + string(values[i].value.val_str) << endl;
			sys.close();
			return false;
		}
		//写入当前列的值到内存
		switch (col->type)
		{
		case enum_INT:
			col->value.val_int = values[i].value.val_int;
			break;
		case enum_FLOAT:
			col->value.val_float = values[i].value.val_float;
			break;
		case enum_CHAR:
			col->value.val_str = values[i].value.val_str;
			break;
		default:
			break;
		}
		col->flag = true;
	}
	//数据存盘
	ofstream out(g_dbpath+tablename, ios::app);
	for (int i = 0; i < table.cols.size(); ++i) {
		switch (table.cols[i].type)
		{
		case enum_INT:
			if (i != 0) out << " ";
			out<< table.cols[i].value.val_int;
			break;
		case enum_FLOAT:
			if (i!= 0)out << " ";
			out << table.cols[i].value.val_float;
			break;
		case enum_CHAR:
			if (i != 0)out << " ";
			if(table.cols[i].flag==true)
			//out <<"\""+ string(table.cols[i].value.val_str)+ "\"";
			out <<  string(table.cols[i].value.val_str);
			else {
				out << "NULL";
			}
		default:
			break;
		}
	}
	out << endl;
	out.close();
	sys.close();
	return true;
}

bool ZYF_Update(UpdateRootValue * updateInfo) {
	string tablename = updateInfo->tablename;
	vector<Feild_Value>&setList = *((updateInfo->setList));
	Conditions * conditions = updateInfo->conditions;
	ifstream sys(g_sysfilename);
	if (!sys) { cout << "Update:fail to open sys file\n"; sys.close(); return false; }

	Table table;
	if (GetTableInfo(table, tablename, g_sysfilename) == false) { cout << "Update : no such table" + tablename << endl; sys.close(); return false; }
	sys.close();

	//检查合法性
	vector<Table *>tables;
	tables.push_back(&table);
	for (int i = 0; i < setList.size(); ++i) {
		string feildname = setList[i].feild.feildname;
		Col * col = GetCol(tables, feildname, tablename);
		if (col == NULL) { cout << "Update: no such feild:" + feildname << endl; return false; }
		else {
			if (col->type != setList[i].type) { cout << "Update: the type is different between table cols and Set value" << endl;  return false; }
			else if (col->type == enum_CHAR && col->length < setList[i].length) {
				cout << "Update: the string is too long :" << setList[i].value.val_str << endl;
				return false;
			}

		}
	}
	ifstream tablefile(g_dbpath+tablename);
	if (!tablefile) { cout << "Update:fail to open table file " + tablename << endl; tablefile.close(); return false; }
	string line;
	ofstream out(g_dbpath+tablename+"_tmp");
	while (!tablefile.eof()) {
		line = ReadLine(tablefile);
		if (line.empty() && tablefile.eof()) { tablefile.close(); break; }
		vector<string> splited = Split(line, " ");
		//导入
		for (int i = 0; i < splited.size(); ++i) {
			getColValue(table.cols[i], splited[i]);
		}
		//更新
		if (IsTrig(tables, conditions)) {
			for (int i = 0; i < setList.size(); i++) {
				string feildname = setList[i].feild.feildname;
				Col * col = GetCol(tables, feildname, tablename);
				if (col->type == enum_INT) {
					col->value.val_int = setList[i].value.val_int;
				}
				else if (col->type == enum_FLOAT) {
					col->value.val_float = setList[i].value.val_float;
				}
				else if (col->type == enum_CHAR) {
					col->value.val_str = setList[i].value.val_str;
				}

			}
		}
		//写回


		if (!out) { cout << "Update error when save reacord to disk\n"; out.close(); return false; }
		for (int i = 0; i < table.cols.size(); ++i) {
			if (i != 0) out << " ";
			if (table.cols[i].type == enum_INT)
				out << table.cols[i].value.val_int;
			else if (table.cols[i].type == enum_FLOAT)
				out << table.cols[i].value.val_float;
			else if (table.cols[i].type == enum_CHAR)
				out << table.cols[i].value.val_str;
		}
		out << endl;
	}
	out.flush();
	out.close();
	tablefile.close();
	tablefile.open(g_dbpath+tablename + "_tmp");
	out.open(g_dbpath+tablename);
	while (!tablefile.eof()) {
		string line = ReadLine(tablefile);
		if (line.empty() && tablefile.eof())break;
		out << line << endl;
	}
	out.flush();
	out.close();
	tablefile.close();
	DeleteFile(StringToWString(g_dbpath+tablename+"_tmp").c_str());
	return true;
}
bool ZYF_Delete(DeleteRootValue * deleteInfo) {
	string tablename = deleteInfo->tablename;
	Conditions *conditions = deleteInfo->conditions;
	ifstream sys(g_sysfilename);
	if (!sys) { cout << "Delete:fail to open sys file\n"; sys.close(); return false; }

	Table table;
	if (GetTableInfo(table, tablename, g_sysfilename) == false) { cout << "Delete : no such table" + tablename << endl; sys.close(); return false; }
	sys.close();
	vector<Table *>tables;
	tables.push_back(&table);
	if (!CheckConditionInvalid(tables, conditions)) {
		cout << "Delete : Condition Invalid\n" << endl;
		return false;
	}
	ifstream tablefile(g_dbpath+tablename);
	if (!tablefile) { cout << "Delete :fail to open table file " + tablename << endl; tablefile.close(); return false; }
	string line;
	ofstream out(g_dbpath+tablename + "_tmp");
	while (!tablefile.eof()) {
		line = ReadLine(tablefile);
		if (line.empty() && tablefile.eof()) { tablefile.close(); break; }
		vector<string> splited = Split(line, " ");
		//导入
		for (int i = 0; i < splited.size(); ++i) {
			getColValue(table.cols[i], splited[i]);
		}
		//更新
		if (IsTrig(tables, conditions)) {
			continue;
		}
		//写回


		if (!out) { cout << "Update error when save reacord to disk\n"; out.close(); return false; }
		for (int i = 0; i < table.cols.size(); ++i) {
			if (i != 0) out << " ";
			if (table.cols[i].type == enum_INT)
				out << table.cols[i].value.val_int;
			else if (table.cols[i].type == enum_FLOAT)
				out << table.cols[i].value.val_float;
			else if (table.cols[i].type == enum_CHAR)
				out << table.cols[i].value.val_str;
		}
		out << endl;
	}
	out.flush();
	out.close();
	tablefile.close();
	tablefile.open(g_dbpath+tablename + "_tmp");
	out.open(g_dbpath+tablename);
	while (!tablefile.eof()) {
		string line = ReadLine(tablefile);
		if (line.empty() && tablefile.eof())break;
		out << line << endl;
	}
	out.flush();
	out.close();
	tablefile.close();
	DeleteFile(StringToWString(g_dbpath+tablename + "_tmp").c_str());
	return true;

	return true;
}


bool ZYF_DropTable(char * name) {
	string tablename = name;
	ifstream sys(g_sysfilename);
	if (!sys) { cout << "Update:fail to open sys file\n"; sys.close(); return false; }

	Table table;
	if (!GetTableInfo(table, tablename, g_sysfilename))
	{
		cout << "Drop Table: no such table :" + tablename << endl;
		sys.close(); return false;
	}

	sys.close();
	ifstream in;
	ofstream out;
	out.open(g_sysfilename + "_tmp");
	in.open(g_sysfilename);
	while (!in.eof()) {
		string line = ReadLine(in);
		if (line.empty() && in.eof())break;
		vector<string> splited = Split(line, " ");
		if (splited[0] == tablename)continue;
		out << line << endl;
	}
	in.close();
	out.close();

	in.open(g_sysfilename+"_tmp");
	out.open(g_sysfilename);
	while (!in.eof()) {
		string line = ReadLine(in);
		if (line.empty() && in.eof())break;
		out << line << endl;
	}
	in.close();
	out.close();
	DeleteFile(StringToWString(g_dbpath+tablename).c_str());
	DeleteFile(StringToWString(g_sysfilename+"_tmp").c_str());
	return true;
}
void ZYF_ShowTables() {
	ifstream sys(g_sysfilename);
	if (!sys) { cout << "Update:fail to open sys file\n"; sys.close(); return; }
	string tablename="";
	int tail = 0;
	while (!sys.eof()) {

		string line = ReadLine(sys);
		if (line.empty() && sys.eof())break;
		vector<string> splited = Split(line, " ");
		if (tablename != splited[0]) {
			cout << endl;
			printf("%-10s :", splited[0].c_str());
			tablename = splited[0];
		}
		printf("%-10s", splited[2].c_str());
	}
	sys.close();
}
void select(vector<Table *> &tables,vector<SelectCol> &selectcols,int recurse_depth)  {
	
	if (recurse_depth == 0) {
		if (IsTrig(tables, g_conditions)) {
			//满足condtion的情况才能进行输出操作
			for (int i = 0; i < selectcols.size(); ++i) {
				string tablename = selectcols[i].tablename;
				string colname = selectcols[i].feildname;
				Col * col = GetCol(tables, colname, tablename);
				if (NULL == col) {
					cout << "select error : no such column : " + tablename + "." + colname << endl;
				}
				else {
					switch (col->type)
					{
					case enum_INT:
					
						printf("%-20d", col->value.val_int);
						cout << '|';
						break;
					case enum_CHAR:
					
						printf("%-20s", col->value.val_str);
						cout << '|';
						break;
					case enum_FLOAT:
					
						printf("%-20f", col->value.val_float);
						cout << '|';
						break;
					default:
						break;
					}
				}
			}
			cout << endl;
		}
		return;
	}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
	Table & present_table = *(tables[tables.size() - recurse_depth]);

	ifstream in(g_dbpath+present_table.name);
	while (!in.eof())
	{
		string line = ReadLine(in);
		if (line.empty() && in.eof())break;
		vector<string> splited = Split(line, " ");
		for (int i = 0; i < splited.size();++i) {
			getColValue(present_table.cols[i], splited[i]);

		}//张三 19 2020
		select(tables, selectcols, recurse_depth - 1);
	}

	in.close();
	return;

}
//SELECT Sno, Sname FROM student;
bool GetTableInfo(Table &table ,string TableName,string sysfilename) {
	ifstream sysfile(sysfilename);
	if (sysfile.fail()) return false;
	string line;
	bool founded = false;
	table.name = TableName;
	while (!sysfile.eof()) {
		line = ReadLine(sysfile);
		if (line.empty() && sysfile.eof())break;
		vector<string>splited = Split(line, " ");

		if (!splited.empty())
		if (splited[0] == TableName) {
			founded = true;
			int num = splited.size();
			if (num == IsInt) {
				if (splited[3] == "INT")
				{
					Col col = { atoi(splited[1].c_str()) ,splited[2] ,enum_INT, -1 };
					col.value.val_int = 0;
					col.flag = false;
					table.cols.push_back(col);
				}
				else if (splited[3] == "FLOAT") {
					Col col = { atoi(splited[1].c_str()) ,splited[2] ,enum_FLOAT, -1 };
					col.value.val_int = 0;
					col.flag = false;
					table.cols.push_back(col);
				}
			}
			else if (num == IsChar)
			{
				Col col = { atoi(splited[1].c_str()) ,splited[2] ,enum_CHAR, atoi(splited[4].c_str()) };
				col.value.val_str = "NULL";
				col.flag = false;
				table.cols.push_back(col);
			}
			else {
				cout << "wrong sysfile record : " + line << endl;
				sysfile.seekg(ios::beg);
				return false;
			}
		}
		else continue;
	}
	return founded;
}

//return the col ptr with its colname or table.colname
Col * GetCol(vector<Table *> &tables,string colname,string tablename ) {
	int TableIndex = -1;
	int ColIndex = -1;
	if (tablename == "") {
		for (TableIndex = 0; TableIndex < tables.size(); ++TableIndex) {
			for (ColIndex = 0; ColIndex < tables[TableIndex]->cols.size();++ColIndex) {
				if (tables[TableIndex]->cols[ColIndex].name == colname)
					return  &tables[TableIndex]->cols[ColIndex];//find it
			}
		}
	}
	else {
		for (TableIndex = 0; TableIndex < tables.size(); ++TableIndex) {
			if(tables[TableIndex]->name == tablename )
			for (ColIndex = 0; ColIndex < tables[TableIndex]->cols.size(); ++ColIndex) {
				if ( tables[TableIndex]->cols[ColIndex].name == colname)
					return  &tables[TableIndex]->cols[ColIndex];//find it
			}
		}
	}
	return NULL;//didnt has this col
}
Col * GetCol(vector<Table *> &tables, string colname, char *tablename) {
	if (tablename == NULL)
		return GetCol(tables, colname, "");
	else
		return GetCol(tables, colname, string(tablename));
}
void ClearFlag(vector<Col>& cols) {
	for (auto it = cols.begin(); it != cols.end(); ++it) {
		it->flag = false;
	}
}
void getColValue(Col &col, string srcvalue) {
	switch (col.type)
	{
	case enum_INT:
		col.value.val_int = (int)atoi(srcvalue.c_str());
		break;
	case enum_CHAR:
		col.value.val_str = _strdup(srcvalue.c_str());
		break;
	//case float
	case enum_FLOAT:
		col.value.val_float = atof(srcvalue.c_str());
		break;
	default:
		break;
	}
}

void getSelectStarCols(vector<Table *> &tables, vector<SelectCol>& selectcols ,int recurse_depth) {
	if (recurse_depth == 0) return;
	Table & present_table = *(tables[tables.size() - recurse_depth]);
	SelectCol tmp;
	tmp.tablename = present_table.name;
	for (int i = 0; i < present_table.cols.size(); ++i) {
		tmp.feildname = present_table.cols[i].name;
		selectcols.push_back(tmp);
		getSelectStarCols(tables, selectcols, recurse_depth-1);
	}
}

ifstream LoadSysFile() {
	ifstream sys(g_sysfilename);
	if (!sys) {
		cout << "sys file does not exit\n";
	}
	return sys;
}
vector <string> Split(string str, string token) {
	vector <string>result;
	char * tmp = _strdup(str.c_str());
	char * piece = strtok(tmp, token.c_str());
	while (piece != NULL) {
		result.push_back(piece);
		piece = strtok(NULL, token.c_str());
	}
	free(tmp);
	return result;
}

std::wstring StringToWString(const std::string& str) {
    int num = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    wchar_t *wide = new wchar_t[num];
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wide, num);
    std::wstring w_str(wide);
    delete[] wide;
    return w_str;
}

string ReadLine(istream &in) {
	char * buf = new char[1024];
	memset(buf, 0, 1024);
	in.getline(buf, 1024);
	string line = buf;
	delete buf;
	return line;
}

bool CheckConditionInvalid(vector<Table *> & tables, struct Conditions * conditions) {
	Conditions * left = conditions->left;
	Conditions * right = conditions->right;
	char *op = conditions->comp_op;
	//如果为操作数
	switch (left->type) {
	case enum_INT:
		switch (right->type) {
		case enum_INT:
			return true;
			break;
		case enum_FLOAT:
			return true;
			break;
		case enum_CHAR:
			return false;
			break;
		case enum_FEILD: {
			Col * col = GetCol(tables, right->value.val_str, right->table);
			if (col == NULL) {
				cout << "Condition Error: no such column " + string(right->value.val_str) << endl;
				return false;
			}
			else {
				if (right->type == enum_CHAR)
					return false;
				else return true;
			}
			break;
		}
		default:
			break;
		}
		break;
	case enum_FLOAT:
		switch (right->type) {
		case enum_INT:
			return true;
			break;
		case enum_FLOAT:
			return true;
			break;
		case enum_CHAR:
			return false;
			break;
		case enum_FEILD: {
			Col * col = GetCol(tables, right->value.val_str, right->table);
			if (col == NULL) {
				cout << "Condition Error: no such column " + string(right->value.val_str) << endl;
				return false;
			}
			else {
				if (right->type == enum_CHAR)
					return false;
				else
					return true;
			}
			break;
		}
		default:
			break;
		}
		break;
	case enum_CHAR:
		switch (right->type) {
		case enum_INT:
			return false;
			break;
		case enum_FLOAT:
			return false;
			break;
		case enum_CHAR:
			return true;
			break;
		case enum_FEILD: {
			Col * col = GetCol(tables, right->value.val_str, right->table);
			if (col == NULL) {
				cout << "Condition Error: no such column " + string(right->value.val_str) << endl;
				return false;
			}
			else {
				if (right->type != enum_CHAR)
					return false;
				else
					return true;
			}
			break;
		}
		default:
			break;
		}
		break;
	case enum_FEILD: {

		Col * col_left = GetCol(tables, left->value.val_str, left->table);
		if (col_left == NULL) {
			cout << "Condition Error: no such column " + string(left->value.val_str) << endl;
			return false;
		}

		if (right->type == enum_FEILD) {
			Col * col_right = GetCol(tables, right->value.val_str, right->table);
			if (col_right == NULL) {
				cout << "Condition Error: no such column " + string(right->value.val_str) << endl;
				return false;
			}
			if (col_left->type == enum_FLOAT && col_right->type == enum_INT || col_left->type == enum_INT && col_right->type == enum_FLOAT)
				return true;
			if (col_left->type != col_right->type)
				return false;
			else return true;
		}
		else if (right->type == enum_INT) {
			if (col_left->type == enum_CHAR)
				return false;
			else
				return true;
		}
		else if (right->type == enum_FLOAT) {
			if (col_left->type == enum_CHAR) return false;
			else return true;
		}
		else if (right->type == enum_CHAR) {
			if (col_left->type != enum_CHAR)
				return false;
			else return true;
		}

		break;
	}
	default:break;
	}
	return false;
}
bool IsTrig(vector<Table *>&tables, struct Conditions * conditions) {
	if (conditions == NULL) return true;
	Conditions * left = conditions->left;
	Conditions * right = conditions->right;
	char *op = conditions->comp_op;

	//如果下一层为最后一层：数值层
	if (left != NULL && right != NULL && left->comp_op == NULL && right->comp_op == NULL) {
		if (string(op) == "=") {
			switch (left->type) {
			case enum_INT:
				switch (right->type) {
				case enum_INT:
					return left->value.val_int == right->value.val_int;
				case enum_FLOAT:
					return (float)left->value.val_int == (float)right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_int == col->value.val_int;
					else
						return (float)left->value.val_int == col->value.val_float;
				}
			case enum_FLOAT:
				switch (right->type) {
				case enum_INT:
					return (float)left->value.val_int == right->value.val_float;
				case enum_FLOAT:
					return left->value.val_float == right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_float == (float)col->value.val_int;
					else
						return (float)left->value.val_float == col->value.val_float;
				}
			case enum_CHAR:
				switch (right->type) {
				case enum_CHAR:
					return string(left->value.val_str) == string(right->value.val_str);
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					return string(left->value.val_str) == string(col->value.val_str);
				}
			case enum_FEILD: {
				Col * col_left = GetCol(tables, left->value.val_str, left->table);
				if (right->type == enum_FEILD) {
					Col * col_right = GetCol(tables, right->value.val_str, right->table);
					if (col_left->type == enum_INT)
						return col_left->value.val_int == col_right->value.val_int;
					else if (col_left->type == enum_FLOAT)
						return col_left->value.val_float == col_right->value.val_float;
					else
						return string(col_left->value.val_str) == string(col_right->value.val_str);
				}
				else if (right->type == enum_INT) {
					return col_left->value.val_int == right->value.val_int;
				}
				else if (right->type == enum_FLOAT) {
					return col_left->value.val_float == right->value.val_float;
				}
				else if (right->type == enum_CHAR) {
					return  string(col_left->value.val_str) == string(right->value.val_str);
				}
			}

			}

		}
		if (string(op) == ">=") {
			switch (left->type) {
			case enum_INT:
				switch (right->type) {
				case enum_INT:
					return left->value.val_int >= right->value.val_int;
				case enum_FLOAT:
					return (float)left->value.val_int >= (float)right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_int >= col->value.val_int;
					else
						return (float)left->value.val_int >= col->value.val_float;
				}
			case enum_FLOAT:
				switch (right->type) {
				case enum_INT:
					return (float)left->value.val_int >= right->value.val_float;
				case enum_FLOAT:
					return left->value.val_float >= right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_float >= (float)col->value.val_int;
					else
						return (float)left->value.val_float >= col->value.val_float;
				}
			case enum_CHAR:
				switch (right->type) {
				case enum_CHAR:
					return string(left->value.val_str) >= string(right->value.val_str);
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					return string(left->value.val_str) >= string(col->value.val_str);
				}
			case enum_FEILD: {
				Col * col_left = GetCol(tables, left->value.val_str, left->table);
				if (right->type == enum_FEILD) {
					Col * col_right = GetCol(tables, right->value.val_str, right->table);
					if (col_left->type == enum_INT)
						return col_left->value.val_int >= col_right->value.val_int;
					else if (col_left->type == enum_FLOAT)
						return col_left->value.val_float >= col_right->value.val_float;
					else
						return string(col_left->value.val_str) >= string(col_right->value.val_str);
				}
				else if (right->type == enum_INT) {
					return col_left->value.val_int >= right->value.val_int;
				}
				else if (right->type == enum_FLOAT) {
					return col_left->value.val_float >= right->value.val_float;
				}
				else if (right->type == enum_CHAR) {
					return  string(col_left->value.val_str) >= string(right->value.val_str);
				}
			}

			}

		}
		if (string(op) == ">") {
			switch (left->type) {
			case enum_INT:
				switch (right->type) {
				case enum_INT:
					return left->value.val_int > right->value.val_int;
				case enum_FLOAT:
					return (float)left->value.val_int > (float)right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_int > col->value.val_int;
					else
						return (float)left->value.val_int > col->value.val_float;
				}
			case enum_FLOAT:
				switch (right->type) {
				case enum_INT:
					return (float)left->value.val_int > right->value.val_float;
				case enum_FLOAT:
					return left->value.val_float > right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_float > (float)col->value.val_int;
					else
						return (float)left->value.val_float > col->value.val_float;
				}
			case enum_CHAR:
				switch (right->type) {
				case enum_CHAR:
					return string(left->value.val_str) > string(right->value.val_str);
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					return string(left->value.val_str) > string(col->value.val_str);
				}
			case enum_FEILD: {
				Col * col_left = GetCol(tables, left->value.val_str, left->table);
				if (right->type == enum_FEILD) {
					Col * col_right = GetCol(tables, right->value.val_str, right->table);
					if (col_left->type == enum_INT)
						return col_left->value.val_int > col_right->value.val_int;
					else if (col_left->type == enum_FLOAT)
						return col_left->value.val_float > col_right->value.val_float;
					else
						return string(col_left->value.val_str) > string(col_right->value.val_str);
				}
				else if (right->type == enum_INT) {
					return col_left->value.val_int > right->value.val_int;
				}
				else if (right->type == enum_FLOAT) {
					return col_left->value.val_float > right->value.val_float;
				}
				else if (right->type == enum_CHAR) {
					return  string(col_left->value.val_str) >
						string(right->value.val_str);
				}
			}

			}

		}
		if (string(op) == "<=") {
			switch (left->type) {
			case enum_INT:
				switch (right->type) {
				case enum_INT:
					return left->value.val_int <= right->value.val_int;
				case enum_FLOAT:
					return (float)left->value.val_int <= (float)right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_int <= col->value.val_int;
					else
						return (float)left->value.val_int <= col->value.val_float;
				}
			case enum_FLOAT:
				switch (right->type) {
				case enum_INT:
					return (float)left->value.val_int <= right->value.val_float;
				case enum_FLOAT:
					return left->value.val_float <= right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_float <= (float)col->value.val_int;
					else
						return (float)left->value.val_float <= col->value.val_float;
				}
			case enum_CHAR:
				switch (right->type) {
				case enum_CHAR:
					return string(left->value.val_str) <= string(right->value.val_str);
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					return string(left->value.val_str) <= string(col->value.val_str);
				}
			case enum_FEILD: {
				Col * col_left = GetCol(tables, left->value.val_str, left->table);
				if (right->type == enum_FEILD) {
					Col * col_right = GetCol(tables, right->value.val_str, right->table);
					if (col_left->type == enum_INT)
						return col_left->value.val_int <= col_right->value.val_int;
					else if (col_left->type == enum_FLOAT)
						return col_left->value.val_float <= col_right->value.val_float;
					else
						return string(col_left->value.val_str) <= string(col_right->value.val_str);
				}
				else if (right->type == enum_INT) {
					return col_left->value.val_int <= right->value.val_int;
				}
				else if (right->type == enum_FLOAT) {
					return col_left->value.val_float <= right->value.val_float;
				}
				else if (right->type == enum_CHAR) {
					return  string(col_left->value.val_str) <= string(right->value.val_str);
				}
			}

			}

		}
		if (string(op) == "<") {
			switch (left->type) {
			case enum_INT:
				switch (right->type) {
				case enum_INT:
					return left->value.val_int < right->value.val_int;
				case enum_FLOAT:
					return (float)left->value.val_int < (float)right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_int < col->value.val_int;
					else
						return (float)left->value.val_int < col->value.val_float;
				}
			case enum_FLOAT:
				switch (right->type) {
				case enum_INT:
					return (float)left->value.val_int < right->value.val_float;
				case enum_FLOAT:
					return left->value.val_float < right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_float < (float)col->value.val_int;
					else
						return (float)left->value.val_float < col->value.val_float;
				}
			case enum_CHAR:
				switch (right->type) {
				case enum_CHAR:
					return string(left->value.val_str) < string(right->value.val_str);
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					return string(left->value.val_str) < string(col->value.val_str);
				}
			case enum_FEILD: {
				Col * col_left = GetCol(tables, left->value.val_str, left->table);
				if (right->type == enum_FEILD) {
					Col * col_right = GetCol(tables, right->value.val_str, right->table);
					if (col_left->type == enum_INT)
						return col_left->value.val_int < col_right->value.val_int;
					else if (col_left->type == enum_FLOAT)
						return col_left->value.val_float < col_right->value.val_float;
					else
						return string(col_left->value.val_str) < string(col_right->value.val_str);
				}
				else if (right->type == enum_INT) {
					return col_left->value.val_int < right->value.val_int;
				}
				else if (right->type == enum_FLOAT) {
					return col_left->value.val_float < right->value.val_float;
				}
				else if (right->type == enum_CHAR) {
					return  string(col_left->value.val_str) < string(right->value.val_str);
				}
			}

			}

		}
		if (string(op) == "!=") {
			switch (left->type) {
			case enum_INT:
				switch (right->type) {
				case enum_INT:
					return left->value.val_int != right->value.val_int;
				case enum_FLOAT:
					return (float)left->value.val_int != (float)right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_int != col->value.val_int;
					else
						return (float)left->value.val_int != col->value.val_float;
				}
			case enum_FLOAT:
				switch (right->type) {
				case enum_INT:
					return (float)left->value.val_int != right->value.val_float;
				case enum_FLOAT:
					return left->value.val_float != right->value.val_float;
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					if (col->type == enum_INT)
						return left->value.val_float != (float)col->value.val_int;
					else
						return (float)left->value.val_float != col->value.val_float;
				}
			case enum_CHAR:
				switch (right->type) {
				case enum_CHAR:
					return string(left->value.val_str) != string(right->value.val_str);
				case enum_FEILD:
					Col * col = GetCol(tables, right->value.val_str, right->table);
					return string(left->value.val_str) != string(col->value.val_str);
				}
			case enum_FEILD: {
				Col * col_left = GetCol(tables, left->value.val_str, left->table);
				if (right->type == enum_FEILD) {
					Col * col_right = GetCol(tables, right->value.val_str, right->table);
					if (col_left->type == enum_INT)
						return col_left->value.val_int != col_right->value.val_int;
					else if (col_left->type == enum_FLOAT)
						return col_left->value.val_float != col_right->value.val_float;
					else
						return string(col_left->value.val_str) != string(col_right->value.val_str);
				}
				else if (right->type == enum_INT) {
					return col_left->value.val_int != right->value.val_int;
				}
				else if (right->type == enum_FLOAT) {
					return col_left->value.val_float != right->value.val_float;
				}
				else if (right->type == enum_CHAR) {
					return  string(col_left->value.val_str) != string(right->value.val_str);
				}
			}

			}

		}

		else {
			return false;
		}
	}
	else if (left != NULL && right != NULL && left->comp_op != NULL && right->comp_op != NULL) {
		//中间层：布尔层
		if (string(op) == "AND")
			return IsTrig(tables, left) && IsTrig(tables, right);
		if (string(op) == "OR")
			return IsTrig(tables, left) || IsTrig(tables, right);
	}
	else
	{
		cout << "程序有逻辑错误\n" << endl;

		exit(0);
	}
	return false;
}


