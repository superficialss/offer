#pragma once
//һ�������а����������ҳ�������Ļ�����ڽ�㡣
//���ӣ����ĳ���

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
	//ʹ�ÿ���ָ�룬���������
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
	//���������
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
		cout << "������" << endl;
	}
	else
	{
		cout << "������ �û���ڽڵ������Ϊ��" << node.first->val << "           ���ĳ��ȣ�" << node.second << endl;
	}

	//�պù���һ����
	ListNode* cur = list;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = list;
	node = EntryNodeOfLoop(list);
	if (node.first == NULL)
	{
		cout << "������" << endl;
	}
	else
	{
		cout << "������ �û���ڽڵ������Ϊ��" << node.first->val << "           ���ĳ��ȣ�" << node.second << endl;
	}

	//��ߴ���
	cur->next = list->next;
	node = EntryNodeOfLoop(list);
	if (node.first == NULL)
	{
		cout << "������" << endl;
	}
	else
	{
		cout << "������ �û���ڽڵ������Ϊ��" << node.first->val << "           ���ĳ��ȣ�" << node.second << endl;
	}
	//�м����
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
		cout << "������" << endl;
	}
	else
	{
		cout << "������ �û���ڽڵ������Ϊ��" << node.first->val << "           ���ĳ��ȣ�" << node.second << endl;
	}
}