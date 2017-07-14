#pragma once
//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则.

struct ListNode {
	int val;
	struct ListNode* next;

	ListNode(int x) 
		:val(x)
		,next(NULL) 
	{}
};
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL) {
		return pHead2;
	}
	if (pHead2 == NULL) {
		return pHead1;
	}
	ListNode* NewHead = NULL;
	ListNode* Tail = NULL;
	if (pHead1->val < pHead2->val)
	{
		NewHead = Tail = pHead1;
		pHead1 = pHead1->next;
	}
	else
	{
		NewHead = Tail = pHead2;
		pHead2 = pHead2->next;
	}
	while (pHead1 && pHead2)
	{
		if (pHead1->val < pHead2->val)
		{
			Tail->next = pHead1;
			pHead1 = pHead1->next;
			Tail = Tail->next;
		}
		else
		{
			Tail->next = pHead2;
			pHead2 = pHead2->next;
			Tail = Tail->next;
		}
	}
	if (pHead1)
	{
		Tail->next = pHead1;
	}
	else
	{
		Tail->next = pHead2;
	}
	return NewHead;
	/*ListNode* NewHead = NULL;
	ListNode* Tail = NewHead;
	ListNode* cur = NULL;
	while (pHead1 && pHead2)
	{
		if (pHead1->val < pHead2->val)
		{
			cur = pHead1;
			pHead1 = pHead1->next;
		 }
		else
		{
			cur = pHead2;
			pHead2 = pHead2->next;
		}
		if (NewHead == NULL)
		{
			NewHead = Tail = cur;
		}
		else
		{
			Tail->next = cur;
			Tail = Tail->next;
		}
	}
	if (pHead1)
	{
		Tail->next = pHead1;
	}
	else
	{
		Tail->next = pHead2;
	}
	return NewHead;*/
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

void TestMergeList()
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	Push(head1, 1);
	Push(head1, 3);
	Push(head1, 5);
	Push(head1, 6);
	Push(head2, 2);
	Push(head2, 4);
	Push(head2, 8);
	Push(head2, 9);
	ListNode* NewHead = MergeList(head1, head2);
	Print(NewHead);
}