#pragma once
//输入一棵二叉树，判断该二叉树是否是平衡二叉树。
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

int GetDepth(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = GetDepth(root->left);
	int right = GetDepth(root->right);
	return left > right ? left + 1 : right + 1;
}

bool IsBalanced_Solution(TreeNode* pRoot)
{
	if (pRoot == NULL)
	{
		return true;
	}
	int left = GetDepth(pRoot->left);
	int right = GetDepth(pRoot->right);
	if (abs(left - right) > 1)
	{
		return false;
	}
	return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
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

void TestIsBalanced()
{
	int arr[] = { 4,2,1,'#','#',3,'#','#',6,5 };
	int index = 0;
	TreeNode* tree = CreatTree(arr, sizeof(arr) / sizeof(arr[0]), '#', index);
	cout << IsBalanced_Solution(tree) << endl;
}