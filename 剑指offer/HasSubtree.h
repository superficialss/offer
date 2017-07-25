#pragma once
//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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

bool _HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL && pRoot2 == NULL)
	{
		return true;
	}
	if (pRoot1->val == pRoot2->val)
	{
		return _HasSubtree(pRoot1->left, pRoot2->left) 
			&& _HasSubtree(pRoot1->right, pRoot2->right);
	}
	return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL)
	{
		return false;
	}
	if (pRoot1 == NULL)
	{
		return true;
	}
	return _HasSubtree(pRoot1, pRoot2) 
		|| HasSubtree(pRoot1->left, pRoot2) 
		|| HasSubtree(pRoot1->right, pRoot2);
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

void TestHasSubtree()
{
	int array1[] = { 1,2,3,'#','#',4,'#','#',5,6 };
	int array2[] = { 4,5,'#','#',6 };
	int index1 = 0;
	int index2 = 0;
	TreeNode* tree1 = CreatTree(array1, sizeof(array1), '#', index1);
	TreeNode* tree2 = CreatTree(array2, sizeof(array2), '#', index2);
	cout << HasSubtree(tree1, tree2) << endl;
}