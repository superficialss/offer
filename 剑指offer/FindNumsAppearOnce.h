#pragma once
//一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
{
	if (data.size() < 2)
	{
		return;
	}
	int tmp = data[0];
	for (int i = 1; i < data.size(); ++i)
	{
		tmp ^= data[i];
	}
	int flag = 1;
	while ((tmp & flag) == 0)
	{
		flag <<= 1;
	}
	*num1 = tmp;
	*num2 = tmp;
	for (int i = 0; i < data.size(); ++i)
	{
		if ((flag & data[i]) == 0)
		{
			*num1 ^= data[i];
		}
		else
		{
			*num2 ^= data[i];
		}
	}
}

void TestFindNumsAppearOnce()
{
	vector<int> data = { 1,1,2,2,3,5,4,5,7,8,7,4 };
	int num1 = 0;
	int num2 = 0;
	FindNumsAppearOnce(data, &num1, &num2);
	cout << num1 << " " << num2 << endl;
}