#pragma once

class Queue
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int Pop;
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		Pop = stack2.top();
		stack2.pop();
		return Pop;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

void TestQueueWithTwoStack()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q.push(7);
	cout << q.pop() << " ";
	cout << q.pop() << " ";
	cout << q.pop() << " ";
}