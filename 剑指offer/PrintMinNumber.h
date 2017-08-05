#pragma once
//����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��
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