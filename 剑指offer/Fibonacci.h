#pragma once
//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。

int Fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int NonFibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	int first = 0;
	int second = 1;
	int sum = 0;
	for (int i = 2; i <= n; ++i)
	{
		sum = first + second;
		first = second;

		second = sum;
	}
	return sum;
}

void TestFibonacci()
{
	int n = 39;
	int num = Fibonacci(n);
	cout << num << endl;
	num = NonFibonacci(n);
	cout << num << endl;;
}