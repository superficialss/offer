#pragma once
//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法

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