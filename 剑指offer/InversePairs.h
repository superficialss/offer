#pragma once
//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007
//int InversePairs(vector<int> data)
//{
//	if (data.size() <= 1)
//	{
//		return 0;
//	}
//	int count = 0;
//	for (int i = 0; i < data.size() - 1; ++i)
//	{
//		for (int j = i + 1; j < data.size(); ++j)
//		{
//			if (data[i] > data[j])
//			{
//				++count;
//			}
//		}
//	}
//	return count;
//}


int _InversePairs(vector<int>& data, int start, int end)
{
	if (start >= end)
	{
		return 0;
	}
	int mid = (start + end) >> 1;
	int leftCount = _InversePairs(data, start, mid);
	int rightCount = _InversePairs(data, mid + 1, end);
	vector<int> cur(data);
	int left = mid;
	int right = end;
	int count = 0;
	int index = end;
	while (left >= start && right >= mid + 1)
	{
		if (data[left] > data[right])
		{
			cur[index--] = data[left--];
			count += (right - mid);
		}
		else
		{
			cur[index--] = data[right--];
		}
	}
	while (left >= start)
	{
		cur[index--] = data[left--];
	}
	while (right >= mid + 1)
	{
		cur[index--] = data[right--];
	}
	for (int i = start; i <= end; ++i)
	{
		data[i] = cur[i];
	}
	return leftCount + rightCount + count;
}

int InversePairs(vector<int> data)
{
	return _InversePairs(data, 0, data.size() - 1);
}

void TestInversePairs()
{
	vector<int> data = { 1,2,3,4,5,6,7,0 };
	int res = InversePairs(data);
	cout << res << endl;
}