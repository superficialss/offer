#pragma once
//使用两个队列实现一个栈

class Stack
{
public:
	void Push(int x)
	{
		if (!queue1.empty())
		{
			queue2.push(x);
			while (!queue1.empty())
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
		}
		else
		{
			queue1.push(x);
			while (!queue2.empty())
			{
				queue1.push(queue2.front());
				queue2.pop();
			}
		}
	}

	int Pop()
	{
		int Pop = 0;
		if (queue1.empty())
		{
			Pop = queue2.front();
			queue2.pop();
		}
		else
		{
			Pop = queue1.front();
			queue1.pop();
		}
		return Pop;
	}
protected:
	queue<int> queue1;
	queue<int> queue2;
};

void TestStackWithTwoQueue()
{
	Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);
	cout << s.Pop() << " ";
	cout << s.Pop() << " ";
	cout << s.Pop() << " ";
	cout << s.Pop() << " ";
}