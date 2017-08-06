#pragma once
//在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置

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