#pragma once
//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

int MoreThanHalfNum_Solution(vector<int> numbers)
{
	int ret = 0;
	int count = 0;
	int n = numbers.size();
	for (int i = 0; i < n; ++i)
	{
		if (numbers[i] == ret || count == 0)
		{
			ret = numbers[i];
			++count;
		}
		else
		{
			--count;
		}
	}
	count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (numbers[i] == ret)
		{
			++count;
		}
	}
	return count * 2 > n ? ret : 0;
}

void TestMoreThanHalfNum()
{
	vector<int> num = { 1,2,3,2,2,2,5,4,2 };
	int ret = MoreThanHalfNum_Solution(num);
	cout << ret << endl;
}