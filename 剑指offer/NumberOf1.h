#pragma once
//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

int NumberOf1(int number)
{
	int count = 0;
	/*if (number < 0)
	{
		number = number & 0x7fffffff;
		++count;
	}
	while (number != 0)
	{
		if (number & 1)
		{
			++count;
		}
		number = number >> 1;
	}*/
	while (number != 0)
	{
		number = number&(number - 1);
		++count;
	}
	return count;
}

void TestNumberOf1()
{
	int num = -1;
	cout << NumberOf1(num) << endl;
}