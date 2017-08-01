#pragma once
//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	//int n = input.size();
	//vector<int> ret;
	//if (n == 0 || n < k)
	//{
	//	return ret;
	//}
	//
	//for (int i = k; i < n; ++i)
	//{
	//	make_heap(input.begin(), input.begin() + k);

	//	if (input[i] < input[0])
	//	{
	//		pop_heap(input.begin(), input.begin() + k);
	//		input.insert(input.begin(), input[i]);
	//		input.erase(input.begin() + i + 1);
	//	}
	//}
	//for (int i = 0; i < k; ++i)
	//{
	//	ret.push_back(input[i]);
	//}
	//sort(ret.begin(), ret.end());
	//return ret;
	int n = input.size();
	vector<int> ret;
	if (n == 0 || n < k)
	{
		return ret;
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < k; ++i) 
	{
		ret.push_back(input[i]);
	}
	return ret;
}

void TestGetLeastNumbers()
{
	vector<int> v = { 4,5,1,6,2,7,3,8 };
	int k = 4;
	vector<int> min = GetLeastNumbers_Solution(v, k);
	for (int i = 0; i < min.size(); ++i)
	{
		cout << min[i] << " ";
	}
	cout << endl;
}