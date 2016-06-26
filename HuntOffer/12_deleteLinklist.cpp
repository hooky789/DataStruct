/*************************************************************************
	> File Name: 12_deleteLinklist.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月22日 星期三 14时02分56秒
    > From: 剑指offer
 ************************************************************************/
#include<iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

/*
 * pListHead 链表头
 * pToBeDeleted 链表中需要删除的元素
*/
void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    if(pToBeDeleted->m_pNext != NULL)                   //不是最后一个元素，且不止一个元素
    {
        ListNode* pNext = pToBeDeleted->m_pNext;        //Copy待删除元素的下一个节点到删除节点，然后删除待删除节点的下一个节点
        pToBeDeleted->m_nValue = pNext->m_nValue;       
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = NULL;
    }
    else if(*pListHead == pToBeDeleted)                 //是最后一个元素，而且只有一个元素
    {
        delete pToBeDeleted;                            //直接删除元素
        pToBeDeleted = NULL;
        *pListHead = NULL;
    }
    else                                                //是最后一个元素
    {
        ListNode* pNode = *pListHead;

        while(pNode-m_pNext != pToBeDeleted)            //一直移动到待删除元素的前一个元素
            pNode = pNode->m_pNext;

        pNode->m_pNext = NULL;                          
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}


int main()
{

    return 0;
}




