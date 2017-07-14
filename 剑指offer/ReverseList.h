#pragma once
//输入一个链表，反转链表后，输出链表的所有元素


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) 
		:val(x)
		,next(NULL) 
	{}
};

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	ListNode* NewHead = pHead;
	pHead = pHead->next;
	NewHead->next = NULL;
	ListNode* cur = NULL;
	while (pHead)
	{
		cur = pHead;
		pHead = pHead->next;
		cur->next = NewHead;
		NewHead = cur;
	}
	return NewHead;
}

//void PushFront(ListNode*& head, int x)
//{
//	if (head == NULL)
//	{
//		head = new ListNode(x);
//	}
//	else
//	{
//		ListNode* cur = new ListNode(x);
//		cur->next = head;
//		head = cur;
//	}
//}
//
//ListNode* ReverseList(ListNode* pHead) 
//{
//	if (pHead == NULL)
//	{
//		return NULL;
//	}
//	ListNode* NewHead = NULL;
//	while (pHead)
//	{
//		PushFront(NewHead, pHead->val);
//		pHead = pHead->next;
//	}
//	return NewHead;
//}

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

void TestReverseList()
{
	ListNode* list = NULL;
	Push(list, 1);
	Push(list, 2);
	Push(list, 3);
	Push(list, 4);
	Push(list, 5);
	ListNode* NewList = ReverseList(list);
	Print(NewList);
}