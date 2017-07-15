#pragma once
//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
//例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。


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
	cout << "旋转后的数组：";
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "min:" << min << endl;
}