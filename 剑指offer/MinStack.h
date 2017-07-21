#pragma once
//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。,

class MinStack 
{
public:
	void push(int value)
	{
		Stack.push(value);
		if (Min.empty())
		{
			Min.push(value);
		}
		else
		{
			int min = Min.top();
			if (min > value)
			{
				Min.push(value);
			}
			else
			{
				Min.push(min);
			}
		}
	}

	int pop()
	{
		int Pop = Stack.top();
		Stack.pop();
		Min.pop();
		return Pop;
	}

	int top()
	{
		return Stack.top();
	}
	
	int min()
	{
		return Min.top();
	}

protected:
	stack<int> Stack;
	stack<int> Min;
};

void TestMinStack()
{
	MinStack s;
	s.push(3);
	s.push(5);
	s.push(1);
	s.push(4);
	s.push(2);
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
	s.pop();
	cout << s.min() << endl;
}