#pragma once
//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� 
//��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��


int MinNumberInRotateArray(vector<int> &rotateArray)
{
	int size = rotateArray.size();
	if (size == 0)
	{
		return 0;
	}
	while (1)
	{
		if (rotateArray[0] < rotateArray[size - 1])
		{
			break;
		}
		rotateArray.insert(rotateArray.begin(), rotateArray[size - 1]);
		rotateArray.erase(rotateArray.end() - 1);
	}
	int min = rotateArray[0];

	return min;
}

void TestMinNumberInRotateArray()
{
	vector<int> arr = { 3,4,5,1,2 };
	int min = MinNumberInRotateArray(arr);
	cout << "��ת������飺";
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "min:" << min << endl;
}