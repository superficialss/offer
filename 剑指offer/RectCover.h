#pragma once
//��2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

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