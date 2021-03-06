#pragma once
//用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

int RectCover(int number)
{
	if (number <= 0)
	{
		return 0;
	}
	else if (number == 1 || number == 2)
	{
		return number;
	}
	else
	{
		return RectCover(number - 1) + RectCover(number - 2);
	}
}

void TestRectCover()
{
	int num = 4;
	cout << RectCover(num) << endl;
}