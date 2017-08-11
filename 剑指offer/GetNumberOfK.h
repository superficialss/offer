#pragma once
//统计一个数字在排序数组中出现的次数。
//int FirstIndex(vector<int> data, int k, int start, int end)
//{
//	if (start > end)
//	{
//		return -1;
//	}
//	int mid = (start + end) >> 1;
//	if (data[mid] >= k)
//	{
//		if (mid == start || data[mid - 1] != k)
//		{
//			return mid;
//		}
//		else
//		{
//			return FirstIndex(data, k, start, mid - 1);
//		}
//	}
//	else
//	{
//		return FirstIndex(data, k, mid + 1, end);
//	}
//}
//
//int LastIndex(vector<int> data, int k, int start, int end)
//{
//	if (start > end)
//	{
//		return -1;
//	}
//	int mid = (start + end) >> 1;
//	if (data[mid] <= k)
//	{
//		if (mid == end || data[mid + 1] != k)
//		{
//			return mid;
//		}
//		else
//		{
//			return LastIndex(data, k, mid + 1, end);
//		}
//	}
//	else
//	{
//		return LastIndex(data, k, start, mid - 1);
//	}
//}
//
//int GetNumberOfK(vector<int> data, int k)
//{
//	if (data.empty())
//	{
//		return 0;
//	 }
//	int num = 0;
//	int first = FirstIndex(data, k, 0, data.size() - 1);
//	int last = LastIndex(data, k, 0, data.size() - 1);
//	if (first != -1 && last != -1)
//	{
//		num = last - first + 1;
//	}
//	return num;
//}

int GetNumberOfK(vector<int> data, int k)
{
	if (data.empty())
	{
		return 0;
	}
	int count = 0;
	for (int i = 0; i < data.size(); ++i)
	{
		if (data[i] == k)
		{
			++count;
		}
	}
	return count;
}


void TestGetNumberOfK()
{
	vector<int> data = { 1,2,3,3,3,3,4,5 };
	int count = GetNumberOfK(data, 3);
	cout << count << endl;
}