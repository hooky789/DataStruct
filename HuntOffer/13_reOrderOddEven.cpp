/*************************************************************************
	> File Name: 13_reOrderOddEven.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月22日 星期三 14时26分12秒
    > From: 剑指offer
 ************************************************************************/


#include<iostream>
using namespace std;

/*
*  程序的可扩展性
*  函数指针的使用
*/


/*
* 重新排序数组，让奇数处于偶数的前面
* 思路和快速排序类似
*/
void ReOrderOddEven(int *pData, int len)
{
    if(!pData || len <= 0)
        return;
    
    int pBegin = pData[0];                  
    int pEnd = pData[len-1];

    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && (*pBegin & 0x01) != 0)
            ++pBegin;

        while(pBegin < pEnd && (*pEnd & 0x01) == 0)
            --pEnd;
        
        if(pBegin < pEnd)
        {
            int tmp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = tmp;
        }
    }
}

/*
* 奇数放在偶数的前面 -> 负数放在非负数的前面 -> 能被3整除的放在不能被3整除的前面
* 总结这些可以发现按照上述的思路只需要把判断的条件修改以下就可以了
* 但是，这样写三个重复的函数显然代码比较冗余，所以可以引入函数指针来抽象总结这个问题。
* 这样代码复用性就得到了很大的提高。
*/


bool isEven(int n)
{
    return (n & 0x01) == 0;
}

bool isNeg(int n)
{
    return (n < 0); 
}

void ReOrderOddEven(int *pData, int len, bool (*func)(int))
{
    if(!pData || len <= 0)
        return;
    
    int pBegin = pData[0];                  
    int pEnd = pData[len-1];

    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && !func(*pBegin))
            ++pBegin;

        while(pBegin < pEnd && func(*pEnd))
            --pEnd;
        
        if(pBegin < pEnd)
        {
            int tmp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = tmp;
        }
    }
}


int main()
{

    return 0;
}


