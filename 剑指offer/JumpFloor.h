#pragma once
//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж���������

int JumpFloor(int number)
{
	if (number <= 0)
	{
		return -1;
	}
	else if (number == 1)
	{
		return 1;
	}
	else if (number == 2)
	{
		return 2;
	}
	else
	{
		return JumpFloor(number - 1) + JumpFloor(number - 2);
	}
}
 
void TestJumpFloor()
{
	int num = 5;
	int sol = JumpFloor(num);
	cout << sol << endl;
}