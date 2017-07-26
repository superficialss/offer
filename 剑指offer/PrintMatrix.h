#pragma once
//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ������
//���磬����������¾��� 1 2 3 4   5 6 7 8   9 10 11 12   13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

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