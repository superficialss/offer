#pragma once
//操作给定的二叉树，将其变换为源二叉树的镜像。

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

void Mirror(TreeNode *pRoot)
{
	if (pRoot == NULL)
	{
		return;
	}
	TreeNode* tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;
	if (pRoot->left)
	{
		Mirror(pRoot->left);
	}
	if (pRoot->right)
	{
		Mirror(pRoot->right);
	}
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

void TestMirror()
{
	int arr[] = { 1,2,3,'#','#',4,'#','#',5,6 };
	int index = 0;
	TreeNode* tree = CreatTree(arr, sizeof(arr), '#', index);
	Mirror(tree);
}