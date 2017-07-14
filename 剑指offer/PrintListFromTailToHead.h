#pragma once
//输入一个链表，从尾到头打印链表每个节点的值。

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		,next(NULL) 
	{}
};

vector<int> PrintListFromTailToHead(ListNode* head)
{
	vector<int> arr;
	while (head)
	{
		arr.push_back(head->val);
		head = head->next;
	}
	return vector<int>(arr.rbegin(), arr.rend());
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

void TestprintListFromTailToHead()
{
	ListNode* head = NULL;
	Push(head, 1);
	Push(head, 2);
	Push(head, 3);
	Push(head, 4);
	cout << "Before:";
	Print(head);
	vector<int> ret = PrintListFromTailToHead(head);
	cout << "After:";
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}