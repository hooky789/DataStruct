/*************************************************************************
	> File Name: 11_One2N.cpp
	> Author: Robin
	> Mail: chou_robin@163.com
	> Created Time: 2016年06月20日 星期一 16时31分07秒
    > From: 剑指offer
************************************************************************/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

bool Increase(char *num)
{
	int len = strlen(num);
	int nTakeOver = 0;				     //进位

	for(int i=len-1; i>=0; --i)
	{
		int nSum = num[i] - '0' + nTakeOver;
		if(i == len - 1)
			++nSum;

		if(nSum >= 10)					//有进位
		{
			if(i == 0)					//i=0表示到达最高位，超过最大值了，需要退出
				return true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				num[i] = '0' + nSum;
			}
		}
		else							//没有进位
		{
			num[i] = '0' + nSum;
			break;
		}
	}
    return false;    
}


void  PrintNumbers(char *num)
{
    int len = strlen(num);
    int i = 0;
    while(num[i] == '0')
        ++i;
    for(; i<len; ++i)
        printf("%c", num[i]);
    printf("\t");
}


void PrintOne2N(int n)
{
    if(n <= 0) return;
    char* numbers = new char[n + 1];
    memset(numbers, '0', sizeof(char) * (n+1));
    numbers[n] = 0;

    while(!Increase(numbers))
    {
        PrintNumbers(numbers);
    }
	delete[] numbers;
}

//递归
void Recursive(char* num, int length, int index)
{
    if(index == length-1)
    {
        PrintNumbers(num);
        return;
    }

    for(int i=0; i<10; ++i)
    {
        num[index + 1] = i + '0';
        Recursive(num, length, index + 1);
    }

}

//递归的方法实现
void RCPrintOne2N(int n)
{
    if(n <= 0) return;
    char* numbers = new char[n + 1];
    memset(numbers, '0', sizeof(char) * (n+1));
    numbers[n] = 0;

    for(int i=0; i<10; ++i)
    {
        numbers[0] = i + '0';
        Recursive(numbers, n, 0);
    }
    delete[] numbers;
}


int main()
{
	RCPrintOne2N(3);
    return 0;
}



