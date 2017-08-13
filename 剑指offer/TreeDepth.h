#pragma once
//����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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

int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	int left = TreeDepth(pRoot->left);
	int right = TreeDepth(pRoot->right);
	return (left > right) ? left + 1 : right + 1;
}

int TreeDepthNonR(TreeNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	queue<TreeNode*> q;
	q.push(pRoot);
	int depth = 0;
	while (!q.empty())
	{
		int size = q.size();
		++depth;
		for (int i = 0; i < size; ++i)
		{
			TreeNode* node = q.front();
			q.pop();
			if (node->left)
			{
				q.push(node->left);
			}
			if(node->right)
			{
				q.push(node->right);
			}
		}
	}
	return depth;
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

void TestTreeDepth()
{
	int arr[] = { 4,2,1,'#','#',3,'#','#',6,5 };
	int index = 0;
	TreeNode* tree = CreatTree(arr, sizeof(arr) / sizeof(arr[0]), '#', index);
	cout << TreeDepth(tree) << endl;
	cout << TreeDepthNonR(tree) << endl;
}