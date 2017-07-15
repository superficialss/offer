#pragma once
//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�

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