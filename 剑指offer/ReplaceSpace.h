#pragma once
//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

char* replaceSpace(char *str, int length) {
	int count = 0;
	for(int i = 0; i < length; i++)
	{
		if (isspace(str[i]))
		{
			++count;
		}
	}
	int newlength = length + 2 * count;
	char* newstr = (char*)malloc(newlength);
	for(int i = 0, j = 0; i < newlength; )
	{
		if (isspace(str[j]))
		{
			newstr[i++] = '%';
			newstr[i++] = '2';
			newstr[i++] = '0';
			++j;
		}
		else
		{
			newstr[i++] = str[j++];
		}
	}
	newstr[newlength] = 0;
	return newstr;
}

void TestRepalceSpace()
{
	char* str = "hello world";
	int length = strlen(str);
	char* newstr = replaceSpace(str, length);
	cout << newstr << endl;
}