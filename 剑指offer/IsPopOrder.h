#pragma once
//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	if (pushV.size() != popV.size())
	{
		return false;
	}
	stack<int> s;
	for (int i = 0, j = 0; i < pushV.size(); ++i)
	{
		s.push(pushV[i]);
		while (j < popV.size() && s.top() == popV[j])
		{
			s.pop();
			++j;
		}
	}
	return s.empty();
}

void TestIsPopOrder()
{
	vector<int> push = { 1,2,3,4,5 };
	vector<int> pop1 = { 4,5,3,2,1 };
	vector<int> pop2 = { 4,3,5,1,2 };
	cout << IsPopOrder(push, pop1) << endl;
	cout << IsPopOrder(push, pop2) << endl;
}