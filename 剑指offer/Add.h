#pragma once
//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ�� + �� - ��*�� / ����������š�

int Add(int num1, int num2)
{
	int tmp = 0;
	while (num2 != 0)
	{
		tmp = num1 ^ num2;
		num2 = (num1 & num2) << 1;
		num1 = tmp;
	}
	return num1;
}

void TestAdd()
{
	int num1 = 0;
	int num2 = 0;
	cout << "��������������";
	cin >> num1 >> num2;
	int sum = Add(num1, num2);
	cout << sum << endl;
}