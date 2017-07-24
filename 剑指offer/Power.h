#pragma once
//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
#define EXP 0.000000000001

double GetPower(double base, int exp)
{
	if (exp == 0)
	{
		return 1.0;
	}
	double res = GetPower(base, exp >> 1);
	res *= res;
	if ((exp & 1) == 1)
	{
		res *= base;
	}
	return res;
}

double Power(double base, int exponent)
{
	if (exponent == 0)
	{
		return 1.0;
	}
	if (base >= -EXP && base <= EXP)
	{
		return 0.0;
	}
	int exp = exponent;
	if (exponent < 0)
	{
		exp = -exponent;
	}
	double res = GetPower(base, exp);
	if (exponent < 0)
	{
		res = 1.0 / res;
	}
	return res;
}

void TestPower()
{
	double base = 5.2;      //浮点数
	int exponent = 2;
	cout << Power(base, exponent) << endl;
}