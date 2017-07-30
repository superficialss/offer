#pragma once
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x)
		:val(x)
		, left(NULL)
		, right(NULL)
	{}
}; 

void _Convert(TreeNode* pRootOfTree, TreeNode*& prev) 
{
	if (pRootOfTree == NULL)
	{
		return;
	}
	_Convert(pRootOfTree->left, prev);
	pRootOfTree->left = prev;
	if (prev)
	{
		prev->right = pRootOfTree;
	}
	prev = pRootOfTree;
	_Convert(pRootOfTree->right, prev);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
	{
		return NULL;
	}
	TreeNode* prev = NULL;
	_Convert(pRootOfTree, prev);
	while (pRootOfTree->left)
	{
		pRootOfTree = pRootOfTree->left;
	}
	return pRootOfTree;
}

TreeNode* CreatTree(int* array, size_t n, const int& invalid, int& index)
{
	TreeNode* root = NULL;
	if (array[index] != invalid && index < n)
	{
		root = new TreeNode(array[index]);
		root->left = NULL;
		root->right = NULL;
		root->left = CreatTree(array, n, invalid, ++index);
		root->right = CreatTree(array, n, invalid, ++index);
	}
	return root;
}

void TestConvert()
{
	int arr[] = { 4,2,1,'#','#',3,'#','#',6,5 };
	int index = 0;
	TreeNode* tree = CreatTree(arr, sizeof(arr), '#', index);
	TreeNode* list = Convert(tree);
}
