/*************************************************************************
	> File Name: 08_fibnacci.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月20日 星期一 10时24分26秒
    > From : 剑指offer
 ************************************************************************/

/*
* 递归和循环
* 递归的代码比较简洁，在二叉树的遍历中用递归的实现代码上明显比非递归的实现要简洁很多倍。
* 面试的时候如果没有特别的要求最好使用递归来实现。
*
* 递归的代码虽然简洁，但是由于递归是函数的自身调用自身，函数的调用需要在内存栈中分配空间
* 用来保存运行的参数，返回地址和一些临时变量。压栈和弹栈都需要时间。
* 所以，递归的实现效率上往往不如循环。
*
* 此外，递归的很多计算都是重复的，对性能有很大的负面影响。fibnacci数列的实现就是个典型的例子。
*
* Fibnaccci数列的变形非常多：
* 1. 青蛙跳台阶问题（剑指offer）
*    一个青蛙一次可以跳1级台阶，也可以跳2级台阶。求给定的台阶数n, 青蛙的跳法有多少种？
* 分析：
*    青蛙跳台阶的跳法是n的函数，记为f(n);
*    那么有 f(1) = 1 , n = 1;
*           f(2) = 2 , n = 2;
*    n > 2的时候，第一次可以跳1级 或者第一次跳2级
*    如果第一次跳1级那么后面有f(n-1)种跳法
*    如果第一次跳2级那么后面有f(n-2)种跳法
*    总结以下就是 f(n) = f(n-1) + f(n-2) 
*                 f(1) = 1;
*                 f(2) = 2;
*    显然这是一个Fibnacci数列。
*
* 2. 用2X1的小矩形去覆盖更大的矩形，有多少种放法？
*
*
*/

#include<iostream>
using namespace std;

/*递归实现Fibnaccci数列*/
long long RCFibnacci(unsigned int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    else
    {
        return RCFibnacci(n-1) + RCFibnacci(n-2);
    }
}


long long NRFibnacci(unsigned int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    int f1 = 1;
    int f0 = 0;
    int rt = 0;
    for(int i = 2; i <= n; ++i)
    {
        rt = f1 + f0;
        f0 = f1;
        f1 = rt;
    }
    return rt;
}

int main()
{
    cout<< NRFibnacci(10) << endl;
    return 0;
}





