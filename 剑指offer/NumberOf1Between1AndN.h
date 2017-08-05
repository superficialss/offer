#pragma once
//���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����
//1~13�а���1��������1��10��11��12��13��˹�����6��,�ܿ���������Ǹ�����������1���ֵĴ�����
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