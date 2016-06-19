/*************************************************************************
	> File Name: replace.cpp
	> Author: Robin
	> Mail: chou_robin@163.com 
	> Created Time: 2016年06月18日 星期六 10时28分15秒
	> From : 剑指offer
 ************************************************************************/

#include<iostream>

using namespace std;

//len表示允许的总长度
void replaceBlank(char a[], int len)
{
	if(a == NULL || len < 0)
		return;

	int i = 0;
	int count = 0;
	int originlen = 0;
	//for(i = 0; i < len; ++i)
	while(a[i] != '\0')
	{
		if(a[i] == ' ')
			++count;
		++originlen;
		++i;
	}

	int newlen = originlen + count*2;
	if(newlen > len)
		return;
	
	int indexorigin = originlen;
	int indexnew = newlen;

	while(indexorigin >= 0 && indexnew > indexorigin)
	{
		if(a[indexorigin] == ' ')
		{
			a[indexnew--] = '0';
			a[indexnew--] = '2';
			a[indexnew--] = '%';
		}
		else
		{
			a[indexnew--] = a[indexorigin];
		}
		--indexorigin;
	}
}


char tb[30] = "h el lo wo rld! ";

int main()
{
	replaceBlank(tb, 30);


	return 0;
}


