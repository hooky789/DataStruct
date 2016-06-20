/*************************************************************************
	> File Name: 11_One2N.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月20日 星期一 16时31分07秒
    > From: 剑指offer
************************************************************************/

#include<iostream>
using namespace std;


bool Increase(char *num)
{
    return true;    
}


void  PrintNumbers(char *num)
{

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
}


int main()
{
    return 0;
}



