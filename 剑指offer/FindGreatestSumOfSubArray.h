#pragma once
//在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。(子向量的长度至少是1)

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