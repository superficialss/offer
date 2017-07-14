#pragma once
//写一个函数，求两个整数之和，要求在函数体内不得使用 + 、 - 、*、 / 四则运算符号。

int Add(int num1, int num2)
{
	int tmp = 0;
	while (num2 != 0)
	{
		tmp = num1 ^ num2;
		num2 = (num1 & num2) << 1;
		num1 = tmp;
	}
	return num1;
}

void TestAdd()
{
	int num1 = 0;
	int num2 = 0;
	cout << "请输入两个数：";
	cin >> num1 >> num2;
	int sum = Add(num1, num2);
	cout << sum << endl;
}