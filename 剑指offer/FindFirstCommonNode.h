#pragma once
//输入两个链表，找出它们的第一个公共结点。
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		,next(NULL) 
	{}
};

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	stack<ListNode*> stack1;
	stack<ListNode*> stack2;
	while (pHead1)
	{
		stack1.push(pHead1);
		pHead1 = pHead1->next;
	}
	while (pHead2)
	{
		stack2.push(pHead2);
		pHead2 = pHead2->next;
	}
	ListNode* cur = NULL;
	while (!stack1.empty() && !stack2.empty())
	{
		if (stack1.top() != stack2.top())
		{
			return cur;
		}
		cur = stack1.top();
		stack1.pop();
		stack2.pop();
	}
	return cur;
}

void Push(ListNode*& head, int val)
{
	if (head == NULL)
	{
		head = new ListNode(val);
	}
	else
	{
		ListNode* cur = head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = new ListNode(val);
	}
}

void TestFindFirstCommonNode()
{
	ListNode* list1 = NULL;
	Push(list1, 1);
	Push(list1, 3);
	Push(list1, 5);
	Push(list1, 6);
	Push(list1, 7);
	Push(list1, 8);
	Push(list1, 9);
	ListNode* list2 = NULL;
	Push(list2, 2);
	Push(list2, 4);
	list2->next->next = list1->next->next->next;
	ListNode* cur = FindFirstCommonNode(list1, list2);
	if (cur)
	{
		cout << cur->val << endl;
	}
	else
	{
		cout << "无公共结点" << endl;
	}
}