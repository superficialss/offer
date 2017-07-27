#pragma once
//输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
// 假设输入的数组的任意两个数字都互不相同。
bool _VerifySquenceOfBST(vector<int> sequence, int left, int right) 
{
	if (left >= right)
	{
		return true;
	}
	int i = right - 1;
	while (i > left && sequence[i] > sequence[right])
	{
		--i;
	}
	for(int j = left; j < i; ++j) 
	{
		if (sequence[j] > sequence[right])
		{
			return false;
		}
	}
	return _VerifySquenceOfBST(sequence, left, i) && _VerifySquenceOfBST(sequence, i + 1, right - 1);
}

bool VerifySquenceOfBST(vector<int> sequence)
{
	if (sequence.empty())
	{
		return false;
	}
	if (sequence.size() == 1)
	{
		return true;
	}
	return _VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
}

void TestVerifySquenceOfBST()
{
	vector<int> v1 = { 1,2,3,4,5,6 };
	vector<int> v2 = { 3,7,1,6,5 };
	vector<int> v3 = { 3,1,7,6,5 };
	vector<int> v4;
	cout << VerifySquenceOfBST(v1) << endl;
	cout << VerifySquenceOfBST(v2) << endl;
	cout << VerifySquenceOfBST(v3) << endl;
	cout << VerifySquenceOfBST(v4) << endl;

}