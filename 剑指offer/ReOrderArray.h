#pragma once
//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分
//保证奇数和奇数，偶数和偶数之间的相对位置不变

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