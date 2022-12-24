#pragma once
#ifndef _CALCULATE_H_
#define _CALCULATE_H_

//enum valueType{INT,DOUBLE,CAL};

//enum calType{ADD,SUB,MUL,DIV};

struct calvalue {
	//valuetype: 1��int��2��double��3�Ǳ��ʽ���� 1+2����
	int valuetype;
	int intnum;
	double doublenum;
	struct calvalue* leftcal;
	//caltype: 1��+��2��-��3��*��4��/
	int caltype;
	struct calvalue* rightcal;
};

void calculate(struct calvalue* cal);




#endif // !_CALCULATE_H_
