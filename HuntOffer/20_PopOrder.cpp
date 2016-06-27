/*************************************************************************
	> File Name: 20_PopOrder.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月27日 星期一 11时13分58秒
    > From: 剑指offer
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

bool IsPopOrder(int *pPush, int* pPop, int len)
{
    int rt = false;
    if(pPush == NULL || pPop == NULL || len < 0)
        return false;

    const int * pPushNext = pPush;
    const int * pPopNext = pPop;

    stack<int> sk;

    while(pPopNext - pPop < len)
    {
        while(sk.empty() || sk.top() != *pPopNext)  //栈为空或者栈顶元素与待弹出元素不等，则表示要将数据压入栈内
        {
            if(pPushNext - pPush == len) break; //数据全部压入栈中，跳出
            sk.push(*pPushNext); 
            pPushNext++;                        //
        }
        
        if(sk.top() != *pPopNext)               //
            break;
        
        sk.pop();                               //
        pPopNext++;                             //
    }

    if(sk.empty() || pPopNext-pPop == len)
        rt = true;
    return rt;
}


int main()
{
    return 0;
}


