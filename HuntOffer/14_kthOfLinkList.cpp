/*************************************************************************
	> File Name: 14_kthOfLinkList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月22日 星期三 14时46分31秒
    > From: 剑指offer
 ************************************************************************/

#include<iostream>
using namespace std;

/*
* 代码的健壮性
* 异常情况的考虑
* 边界情况的考虑
*/

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == NULL || K == 0)
        return NULL;

    ListNode* pAhead = pListHead;
    ListNode* pBehind = NULL;
    
    for(int i = 0; i < k-1; ++i)
    {
        if(pAhead->m_pNext != NULL)
            pAhead = pAhead->m_pNext;
        else
            return NULL;
    }
    
    pBehind = pListHead;

    while(pAhead->m_pNext != NULL)
    {
        pAhead = pAhead->m_pNext;
        pBehind  = pBehind->m_pNext;
    }
    
    return pBehind;
}

/**
 * 相关题目：
 * 1.求链表的中间元素
 *  定义两个指针，一个一次走一步，一个一次走两步，后面的走到结尾的时候前面的指针就到中间了。
 * 2.链表是否成环问题
 *  定义两个指针，一个一次走一步，一个一次走两步， 后面的元素追上了前面的元素就有环，到链表结尾还没追上就没有环。
 */


int main()
{
    return 0;
}



