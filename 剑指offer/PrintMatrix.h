#pragma once
//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
//例如，如果输入如下矩阵： 1 2 3 4   5 6 7 8   9 10 11 12   13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

vector<int> PrintMatrix(vector<vector<int> > matrix)
{
	if (matrix.empty())
	{
		return matrix[0];
	}
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res; 
	int left = 0;
	int right = col - 1;
	int up = 0;
	int down = row - 1;
	while (left <= right && up <= down) 
	{
		for (int i = left; i <= right; ++i)
		{
			res.push_back(matrix[up][i]);
		}
		for (int i = up + 1; i <= down; ++i)
		{
			res.push_back(matrix[i][right]);
		}
		if (up != down)
		{
			for (int i = right - 1; i >= left; --i)
			{
				res.push_back(matrix[down][i]);
			}
		}
		if (left != right)
		{
			for (int i = down - 1; i > up; --i)
			{
				res.push_back(matrix[i][left]);
			}
		}
		++left;
		++up;
		--right;
		--down;
	}
	return res;
}

void TestPrintMatrix()
{
	vector<vector<int>> matrix= { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int> print = PrintMatrix(matrix);
	for (int i = 0; i < print.size(); ++i)
	{
		cout << print[i] << " ";
	}
	cout << endl;
}