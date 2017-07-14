#pragma once
//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�����

bool Find(int target, vector<vector<int> > array) 
{
	int row = array.size();
	int col = array[0].size();
	int i = 0;
	int j = 0;
	for (i = row - 1, j = 0; i >= 0 && j <= (col - 1); ) 
	{
		if (target == array[i][j]) 
		{
			return true;
		}
		else if (target < array[i][j]) 
		{
			--i;
		}
		else 
		{
			++j;
		}
	}
	return false;
}

void TestFindInArray()
{
	vector<vector<int> > array = { {1,2,3,4},{2,3,4,5},{5,6,7,8},{6,7,8,9} };
	int target = 3;
	int ret = Find(target, array);
	cout << ret << endl;
}