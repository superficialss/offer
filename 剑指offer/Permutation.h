#pragma once
//输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
void _Permutation(string str, vector<string>& ret, int i)
{
	if (str.size() - 1 == i)
	{
		ret.push_back(str); 
	}
	for (int j = i; j < str.size(); ++j)
	{
		if (i != j && str[i] == str[j])
		{
			continue;
		}
		swap(str[i], str[j]);
		_Permutation(str, ret, i + 1);
	}
}

vector<string> Permutation(string str)
{
	sort(str.begin(), str.end());
	vector<string> ret;
	_Permutation(str, ret, 0);
	return ret;
}

void TestPermutation()
{
	string s = "abc";
	vector<string> ret = Permutation(s);
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
}