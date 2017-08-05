#pragma once
//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
int comp(const string& str1, const string& str2)
{
	return str1 + str2 < str2 + str1;
}

string PrintMinNumber(vector<int> numbers)
{
	string res;
	vector<string> v;
	for (int i = 0; i < numbers.size(); ++i)
	{
		v.push_back(to_string(numbers[i]));
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); ++i)
	{
		res += v[i];
	}
	return res;
}

void TestPrintMinNumber()
{
	vector<int> arr = { 3,32,321 };
	string res = PrintMinNumber(arr);
	cout << res << endl;
}