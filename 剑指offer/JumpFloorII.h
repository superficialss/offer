#pragma once
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������

int JumpFloorII(int number)
{
	if (number <= 0)
	{
		return 0;
	}
	else if (number == 1)
	{
		return 1;
	}
	else
	{
		return JumpFloorII(number - 1) << 1;
	}
}

void TestJumpFloorII()
{
	int num = 5;
	int sum = JumpFloorII(num);
	cout << sum << endl;
}