#pragma once
//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

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