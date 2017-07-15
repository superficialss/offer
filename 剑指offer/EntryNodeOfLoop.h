#pragma once
//一个链表中包含环，请找出该链表的环的入口结点。
//附加：环的长度

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x)
		:val(x)
		, next(NULL)
	{}
};

pair<ListNode*, int>EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return pair<ListNode*, int>(NULL, 0);
	}
	//使用快慢指针，相遇则带环
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			fast = pHead;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			int count = 0;
			fast = fast->next;
			while (fast == slow)
			{
				fast = fast->next;
				++count;
			}
			return pair<ListNode*, int>(fast, count);
		}
	}
	return pair<ListNode*, int>(NULL, 0);
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

void TestEntryNodeOfLoop()
{
	//不带环情况
	ListNode* list = NULL;
	Push(list, 1);
	Push(list, 2);
	Push(list, 3);
	Push(list, 4);
	Push(list, 5);
	Push(list, 6);
	Push(list, 7);
	Push(list, 8);
	Push(list, 9);
	pair<ListNode*, int> node = EntryNodeOfLoop(list);
	if (node.first == NULL)
	{
		cout << "不带环" << endl;
	}
	else
	{
		cout << "带环， 该环入口节点的数据为：" << node.first->val << "           环的长度：" << node.second << endl;
	}

	//刚好构成一个环
	ListNode* cur = list;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = list;
	node = EntryNodeOfLoop(list);
	if (node.first == NULL)
	{
		cout << "不带环" << endl;
	}
	else
	{
		cout << "带环， 该环入口节点的数据为：" << node.first->val << "           环的长度：" << node.second << endl;
	}

	//后边带环
	cur->next = list->next;
	node = EntryNodeOfLoop(list);
	if (node.first == NULL)
	{
		cout << "不带环" << endl;
	}
	else
	{
		cout << "带环， 该环入口节点的数据为：" << node.first->val << "           环的长度：" << node.second << endl;
	}
	//中间带环
	cur->next = NULL;
	cur = list;
	while (cur->next->next)
	{
		cur = cur->next;
	}
	cur->next = list->next->next;
	node = EntryNodeOfLoop(list);
	if (node.first == NULL)
	{
		cout << "不带环" << endl;
	}
	else
	{
		cout << "带环， 该环入口节点的数据为：" << node.first->val << "           环的长度：" << node.second << endl;
	}
}