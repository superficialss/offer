#pragma once
//��ֻ��������2��3��5��������������Ugly Number����
//����6��8���ǳ�������14���ǣ���Ϊ����������7�� ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������
//bool IsUgly(int num)
//{
//	while (num % 2 == 0)
//	{
//		num /= 2;
//	}
//	while (num % 3 == 0)
//	{
//		num /= 3;
//	}
//	while (num % 5 == 0)
//	{
//		num /= 5;
//	}
//	return num == 1 ? true : false;
//}
//
//int GetUglyNumber_Solution(int index)
//{
//	if (index <= 0)
//	{
//		return 0;
//	}
//	int num = 0;
//	int count = 0;
//	while (count < index)
//	{
//		++num;
//		if (IsUgly(num))
//		{
//			++count;
//		}
//	}
//	return num;
//}
int GetUglyNumber_Solution(int index) {
	if (index < 7)
		return index;
	vector<int> res(index);
	res[0] = 1;
	int num2 = 0, num3 = 0, num5 = 0, i;
	for (i = 1; i < index; ++i)
	{
		res[i] = min(res[num2] * 2, min(res[num3] * 3, res[num5] * 5));
		if (res[i] == res[num2] * 2)
			num2++;
		if (res[i] == res[num3] * 3)
			num3++;
		if (res[i] == res[num5] * 5)
			num5++;
	}
	return res[index - 1];
}

void TestGetUglyNumber()
{
	int num = 8;
	cout << GetUglyNumber_Solution(num) << endl;
}