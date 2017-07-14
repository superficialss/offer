#pragma once
//����һ����������������е�����k����㡣

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x)
		:val(x)
		, next(NULL)
	{}
};



ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	assert(pListHead != NULL);
	//��������ָ�룬֮��Ĳ�ֵΪk��
	ListNode* first = pListHead;
	ListNode* second = pListHead;
	unsigned int i = k;
	int count = 0;
	while (first)
	{
		++count;
		first = first->next;
		if (i < 1 || i > k)
		{
			second = second->next;
		}
		--i;
	}
	if (count < k)
	{
		return NULL;
	}
	return second;
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

void TestFindKthToTail()
{
	ListNode* list = NULL;
	Push(list, 1);
	Push(list, 2);
	Push(list, 3);
	Push(list, 4);
	Push(list, 5);
	int k = 0;
	cout << "��������Ҫ���ҵĵ�����K���ڵ�: ";
	cin >> k;
	ListNode* node = FindKthToTail(list, k);
	assert(node != NULL);
	cout << node->val << endl;
}