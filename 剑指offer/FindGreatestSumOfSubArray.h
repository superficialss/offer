#pragma once
//�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
//����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��(�������ĳ���������1)

int FindGreatestSumOfSubArray(vector<int> array)
{
	int n = array.size();
	if (n == 0)
	{
		return 0;
	}
	int total = array[0];
	int MaxSum = array[0];
	for (int i = 1; i < n; ++i)
	{
		if (total >= 0)
		{
			total += array[i];
		}
		else
		{
			total = array[i];
		}
		if (total > MaxSum)
		{
			MaxSum = total;
		}
	}
	return MaxSum;
}

void TestFindGreatestSumOfSubArray()
{
	vector<int> arr = { 6,-3,-2,7,-15,1,2,2 };
	int ret = FindGreatestSumOfSubArray(arr);
	cout << ret << endl;
}