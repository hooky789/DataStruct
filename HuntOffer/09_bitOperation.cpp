/*************************************************************************
	> File Name: 09_bitOperation.cpp
	> Author: robin
	> Mail: chou_robin@163.com
	> Created Time: 2016年06月20日 星期一 11时11分19秒
    > From: 剑指offer
 ************************************************************************/

#include<iostream>
using namespace std;

/* 
 * 解法一
 * 问题： 如果输入是负数，也就是说二进制的最高为是1，比如 0x8000 右移一位 变成了 0xc000 
 * 这里需要注意因为负数右移要保证负号不变。一次移动下去就边成了0xffff. 函数就成了死循环。
*/
int Numberof1_1(int n)
{
    int count = 0;
    while(n)
    {
        if(n&1)
            ++count;
        n = n >> 1;
    }
    return count;
} 

/*
* 解法二
* 思路和上面的类似，不同的是我们从最低位逐位的判断数字n。
* 由于这里变动的是fg(正整数) 所以解决了上面的死循环的问题。
*/
int Numberof1_2(int n)
{
    int count = 0;
    int fg = 1;
    while(fg)
    {
        if(fg & n)
            ++count;
        fg = fg << 1;
    }
    return count;
}

/*
* 解法三
* 观察数字的特征
* */
int Numberof1_3(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = n & (n-1);
    }
    return count;
}





int main()
{
    cout << Numberof1_3(10) << endl;
    
    cout << Numberof1_3(-10) << endl;

    return 0;
}


