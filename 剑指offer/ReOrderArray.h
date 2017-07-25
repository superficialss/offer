#pragma once
//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿��
//��֤������������ż����ż��֮������λ�ò���

void ReOrderArray(vector<int> &array)
{
	for (int i = 0; i < array.size(); ++i)
	{
		for (int j = array.size() - 1; j > i; --j)
		{
			if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
			{
				swap(array[j], array[j - 1]);
			}
		}
	}
}

void TestReOrderArray()
{
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	ReOrderArray(arr);
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}