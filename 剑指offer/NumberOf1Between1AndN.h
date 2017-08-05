#pragma once
//求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
//1~13中包含1的数字有1、10、11、12、13因此共出现6次,很快的求出任意非负整数区间中1出现的次数。
//int _NumberOf1Between1AndN_Solution(int num)
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 10 == 1)
//		{
//			++count;
//		}
//		num /= 10;
//	}
//	return count;
//}
//
//int NumberOf1Between1AndN_Solution(int n)
//{
//	int count = 0;
//	for (int i = 0; i <= n; ++i)
//	{
//		count += _NumberOf1Between1AndN_Solution(i);
//	}
//	return count;
//}

int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	int high = 0;
	int cur = 0;
	int low = 0;
	int i = 1;
	while ((n / i) != 0)
	{
		high = n / (i * 10);
		cur = (n / i) % 10;
		low = n - (n / i) * i;
		if (cur == 0)
		{
			count += high * i;
		}
		else if (cur == 1)
		{
			count += high * i + low + 1;
		}
		else
		{
			count += (high + 1) * i;
		}
		i *= 10;
	}
	return count;
}

void TestNumberOf1Between1AndN()
{
	int n = 1;
	cout << NumberOf1Between1AndN_Solution(n) << endl;
}