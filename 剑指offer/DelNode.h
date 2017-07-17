#pragma once
//删除一个无头单链表的非尾节点

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x)
		:val(x)
		,next(NULL)
	{}
};

ListNode* DelNode(ListNode*& head, int x)
{
	ListNode* del = head;
	ListNode* cur = head;
	while (del)
	{
		
		if (del->val == x)
		{
			cur->next = del->next;
			return del;
		}
		cur = del;
		del = del->next;
	}
	return NULL;
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

void Print(ListNode* head)
{
	ListNode* cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
}

void TestDelNode()
{
	ListNode* head = NULL;
	Push(head, 1);
	Push(head, 2);
	Push(head, 3);
	Push(head, 4);
	Push(head, 5);
	Push(head, 6);
	Push(head, 7);
	Push(head, 8);
	Push(head, 9);
	ListNode* del = DelNode(head, 2);
	Print(head);
}