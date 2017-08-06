#pragma once
//��һ���ַ���(1<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��

int FirstNotRepeatingChar(string str)
{ 
	if (str.length() == 0)
	{
		return -1;
	}
	int res[10000] = { 0 };
	int i = 0;
	while (str[i] != '\0')
	{
		res[str[i]]++;
		++i;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (res[str[i]] == 1)
		{
			return i;
		}
		++i;
	}
	return -1;
}

void TestFirstNotRepeatingChar()
{
	string s = "asghashjahcjhsdfjhc";
	int pos = FirstNotRepeatingChar(s);
	cout << pos << endl;
}