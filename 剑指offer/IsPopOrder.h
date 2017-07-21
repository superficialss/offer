#pragma once
//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//��������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�

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