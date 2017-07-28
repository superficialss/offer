#pragma once
//输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
//路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

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

void _FindPath(TreeNode* root, int expectNumber, vector<int> res, vector<vector<int>>& path) 
{
	expectNumber -= root->val;
	res.push_back(root->val);
	if (root->left == NULL && root->right == NULL)
	{
		if (expectNumber == 0)
		{
			path.push_back(res);
		}
	}
	if (expectNumber != 0 && root->left != NULL)
	{
		_FindPath(root->left, expectNumber, res, path);
	}
	if (expectNumber != 0 && root->right != NULL)
	{
		_FindPath(root->right, expectNumber, res, path);
	}
	res.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
{
	vector<int> res;
	vector<vector<int>> path;
	if (root != NULL)
	{
		_FindPath(root, expectNumber, res, path);
	}
	return path;
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

void TestFindPath()
{
	int arr[] = { 1,2,3,'#','#',4,'#','#',5,6 };
	int index = 0;
	int num = 6;
	TreeNode* tree = CreatTree(arr, sizeof(arr), '#', index);
	vector<vector<int>> res = FindPath(tree, num);
	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[0].size(); ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}