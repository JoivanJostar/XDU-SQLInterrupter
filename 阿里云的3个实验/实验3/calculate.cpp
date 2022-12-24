#include "calculate.h"
#include<stdio.h>

void calculate(struct calvalue* cal) {
	
	switch (cal->valuetype)
	{
	case 1:break;
	case 2:break;
	case 3:
		calculate(cal->rightcal);
		if (cal->leftcal != NULL) {
			calculate(cal->leftcal);
			switch (cal->caltype)
			{
			case 1:
				if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 1) {
					cal->intnum = cal->leftcal->intnum + cal->rightcal->intnum;
					cal->valuetype = 1;
				}
				else if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->intnum + cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 1) {
					cal->doublenum = cal->leftcal->doublenum + (double)cal->rightcal->intnum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->doublenum + cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				break;
			case 2:
				if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 1) {
					cal->intnum = cal->leftcal->intnum - cal->rightcal->intnum;
					cal->valuetype = 1;
				}
				else if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->intnum - cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 1) {
					cal->doublenum = cal->leftcal->doublenum - (double)cal->rightcal->intnum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->doublenum - cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				break;
			case 3:
				if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 1) {
					cal->intnum = cal->leftcal->intnum * cal->rightcal->intnum;
					cal->valuetype = 1;
				}
				else if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->intnum *  cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 1) {
					cal->doublenum = cal->leftcal->doublenum *  (double)cal->rightcal->intnum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->doublenum * cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				break;
			case 4:
				if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 1) {
					cal->intnum = cal->leftcal->intnum / cal->rightcal->intnum;
					cal->valuetype = 1;
				}
				else if (cal->leftcal->valuetype == 1 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->intnum / cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 1) {
					cal->doublenum = cal->leftcal->doublenum / (double)cal->rightcal->intnum;
					cal->valuetype = 2;

				}
				else if (cal->leftcal->valuetype == 2 && cal->rightcal->valuetype == 2) {
					cal->doublenum = (double)cal->leftcal->doublenum / cal->rightcal->doublenum;
					cal->valuetype = 2;

				}
				break;
			default:
				break;
			}
		}
		else {
			if (cal->valuetype == 2) {
				if (cal->rightcal->valuetype == 1) {
					cal->valuetype = 1;
					cal->intnum = -cal->rightcal->intnum;
				}
				else if (cal->rightcal->valuetype == 2) {
					cal->valuetype = 2;
					cal->doublenum = -cal->rightcal->doublenum;
				}
			}else if (cal->valuetype == 1) {
				if (cal->rightcal->valuetype == 1) {
					cal->valuetype = 1;
					cal->intnum = cal->rightcal->intnum;
				}
				else if (cal->rightcal->valuetype == 2) {
					cal->valuetype = 2;
					cal->doublenum = cal->rightcal->doublenum;
				}
			}
		}
		break;
	default:
		break;
	}
	//use database test;
}//insert into t1 values(2+(1-3)*5/2,2.4/0.3);