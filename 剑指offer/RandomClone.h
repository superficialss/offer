#pragma once
//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) 
		:label(x)
		,next(NULL)
		,random(NULL) 
	{}
};


RandomListNode* RandomClone(RandomListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	RandomListNode* cur = pHead;
	RandomListNode* tmp = NULL;
	while (cur) 
	{
		tmp = new RandomListNode(cur->label);
		tmp->next = cur->next;
		cur->next = tmp;
		cur = tmp->next;
	}
 	cur = pHead;
	while (cur)
	{
		if (cur->random)
		{
			cur->next->random = cur->random->next;
		}
		cur = cur->next->next;
	}
	cur = pHead;
	RandomListNode* NewHead = cur->next;
	tmp = NULL;
	while (cur)
	{
		tmp = cur->next;
		cur->next = cur->next->next;
		cur = cur->next;
	}
	return NewHead;
}

RandomListNode* CreatList()
{
	RandomListNode* node1 = new RandomListNode(1);
	RandomListNode* node2 = new RandomListNode(2);
	RandomListNode* node3 = new RandomListNode(3);
	RandomListNode* node4 = new RandomListNode(4);
	RandomListNode* node5 = new RandomListNode(5);
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	node1->random = node4;
	node2->random = node2;
	node3->random = node1;
	node4->random = node5;
	node5->random = node5;
	return node1;
}

void TestRandomClone()
{
	RandomListNode* list = CreatList();
	RandomListNode* CloneList = RandomClone(list);
}