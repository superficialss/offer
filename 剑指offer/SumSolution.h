#pragma once
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

int Sum_Solution(int n)
{
	int sum = n;
	n && (sum += Sum_Solution(n - 1));
	return sum;
}

void TestSumSolution()
{
	int n = 0;
	cout << "请输入n: ";
	cin >> n;
	int sum = Sum_Solution(n);
	cout << "和为:" << sum << endl;
}