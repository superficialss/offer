#pragma once
//����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�

//Definition for binary tree
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) 
		:val(x)
		,left(NULL)
		,right(NULL)
	{}
};


TreeNode* ReConstructBinaryTree(vector<int> pre, vector<int> vin)
{
	int size = vin.size();
	if (size == 0) 
	{
		return NULL;
	}
	vector<int> PreLeft;
	vector<int> PreRight;
	vector<int> InLeft;
	vector<int> InRight;
	TreeNode* cur = new TreeNode(pre[0]);
	int i = 0;
	for (; i < size; ++i) 
	{
		if (vin[i] == pre[0]) 
		{
			break;
		}
	}
	int j = 0;
	for (; j < size; ++j)	
	{
		if (j < i)
		{
			InLeft.push_back(vin[j]);
			PreLeft.push_back(pre[j + 1]);
		}
		else if (j > i) 
		{
			InRight.push_back(vin[j]);
			PreRight.push_back(pre[j]);
		}
	}
	cur->left = ReConstructBinaryTree(PreLeft, InLeft);
	cur->right = ReConstructBinaryTree(PreRight, InRight);
	return cur;
}


void TestReConstructBinaryTree()
{
	vector<int> PreOrder = { 1,2,4,7,3,5,6,8 };
	vector<int> InOrder = { 4,7,2,1,5,3,8,6 };
	TreeNode* tree = ReConstructBinaryTree(PreOrder, InOrder);
}