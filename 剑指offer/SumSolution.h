#pragma once
//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

int Sum_Solution(int n)
{
	int sum = n;
	n && (sum += Sum_Solution(n - 1));
	return sum;
}

void TestSumSolution()
{
	int n = 0;
	cout << "������n: ";
	cin >> n;
	int sum = Sum_Solution(n);
	cout << "��Ϊ:" << sum << endl;
}