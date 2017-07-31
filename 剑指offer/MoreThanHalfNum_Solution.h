#pragma once
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��

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