#pragma once
#ifndef _CALCULATE_H_
#define _CALCULATE_H_

//enum valueType{INT,DOUBLE,CAL};

//enum calType{ADD,SUB,MUL,DIV};

struct calvalue {
	//valuetype: 1是int，2是double，3是表达式（如 1+2）；
	int valuetype;
	int intnum;
	double doublenum;
	struct calvalue* leftcal;
	//caltype: 1是+，2是-，3是*，4是/
	int caltype;
	struct calvalue* rightcal;
};

void calculate(struct calvalue* cal);




#endif // !_CALCULATE_H_
