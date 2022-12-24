#include "yacc.tab.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "ZYF_SQL.h"
#include <io.h>
#include <direct.h>
#include <algorithm>
using namespace std;
/*
CREATE TABLE Student
( Sno CHAR(9), Sname CHAR(20), Ssex CHAR(3), Sage INT );
Insert into Student values
("xd01", "ivan", "m", 18);
Insert into Student values
("xd02", "ivan", "m", 18);
Insert into Student values
("xd03", "John", "m", 18);
Insert into Student values
("xd04", "Johnson", "m", 40);

INSERT INTO Student(Sname,Sage,Ssex) VALUES ('ZHANGSAN',22,"M");

select * from Student,COURSE where( Student.Sno='xd01' AND Sage=18);

DELETE FROM Student WHERE (Sname="ivan");

UPDATE Student SET Sage=27,Ssex='W' WHERE Sname='ivan';
*/
//SELECT Sno,Sname FROM Student WHERE(Sname="ivan");

extern int lineno;

int main() {
	
	while (1) {
		lineno = 0;
		cout << "ZYF_SQL>>";
		yyparse();
	}
	

}

