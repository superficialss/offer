#pragma once
//²ãÐò±éÀú¶þ²æÊ÷

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

//vector<int> PrintLevelTree(TreeNode* root)
//{
//	TreeNode* cur = root;
//	vector<int> v;
//	vector<TreeNode*> arr;
//	if (root == NULL)
//	{
//		return v;
//	}
//	arr.push_back(root);
//	for (int i = 0; i < arr.size(); ++i)
//	{
//		TreeNode* tmp = arr[i];
//		if (tmp->left)
//		{
//			arr.push_back(tmp->left);
//		}
//		if (tmp->right)
//		{
//			arr.push_back(tmp->right);
//		}
//		v.push_back(tmp->val);
//	}
//	return v;
//}

void PrintLevelTree(TreeNode* root)
{
	int count = 0;
	queue<TreeNode*> q;
	if (root)
	{
		q.push(root);
		++count;
	}
	while (count != 0)
	{
		TreeNode* front = q.front();
		cout << front->val << " ";
		--count;
		q.pop();
		if (front->left)
		{
			q.push(front->left);
			++count;
		}
		if (front->right)
		{
			q.push(front->right);
			++count;
		}
	}
	cout << endl;
}


TreeNode* CreatTree(int* array, size_t n, const int& invalid, int& index)
{
	TreeNode* root = NULL;
	if (array[index] != invalid && index < n)
	{
		root = new TreeNode(array[index]);
		root->left = CreatTree(array, n, invalid, ++index);
		root->right = CreatTree(array, n, invalid, ++index);
	}
	return root;
}

void TestPrintLevelTree()
{
	int array[] = { 1,2,3,'#','#',4,'#','#',5,6 };
	int index = 0;
	TreeNode* tree = CreatTree(array, sizeof(array), '#', index);
	//vector<int> res = PrintLevelTree(tree);
	//for (int i = 0; i < res.size(); ++i)
	//{
	//	cout << res[i] << " ";
	//}
	//cout << endl;
	PrintLevelTree(tree);
}