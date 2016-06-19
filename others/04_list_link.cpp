/*************************************************************************
	> File Name: 04_list_link.cpp
	> Author: Robin
	> Mail: chou_robin@163.com 
	> Created Time: 2016年06月19日 星期日 09时51分58秒
	> From: 剑指offer
 ************************************************************************/

#include<iostream>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};


void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;

	if(*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
}


void RemoveNode(ListNode ** pHead, int value)
{
	if(pHead == NULL || *pHead == NULL)
		return;

	ListNode *pNode = *pHead;
	ListNode *pDel = NULL;
	if(pNode->m_nValue == value)
	{
		*pHead = pNode->m_pNext;
		pDel = pNode;
	}
	else
	{
		while(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
			pNode = pNode->m_pNext;
		
		if(pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pDel = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if(pDel != NULL)
	{
		delete pDel;
		pDel = NULL;
	}
}



int main()
{	
	ListNode* lt = NULL;
	AddToTail(&lt, 10);
	AddToTail(&lt, 20);
	return 0;
}






