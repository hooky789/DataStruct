/*************************************************************************
	> File Name: 15_ReverseLinkList.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月22日 星期三 15时02分57秒
    > From : 剑指offer
 ************************************************************************/

#include<iostream>
#include <stack>

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

//逆序打印链表
void ReversPrint(ListNode **pHead)
{
	
	stack<ListNode*> sk;
	ListNode* pNode = *pHead;
	while(pNode != NULL)
	{
		sk.push(pNode);
		pNode = pNode->m_pNext;
	}
	cout<< "ReversPrint :" << endl;
	//打印并且出栈
	while(!sk.empty())
	{
		cout << (sk.top())->m_nValue << endl;
		sk.pop();
	}
	cout<<endl;
}

void Recur(ListNode **pHead)
{
	if(*pHead != NULL)
	{
		if((*pHead)->m_pNext != NULL)
			Recur(&((*pHead)->m_pNext));
		cout<< (*pHead)->m_nValue << endl;
	}
}

//反转链表
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* NewHead = NULL;               //
    ListNode* pNode = pHead;                //
    ListNode* pPrev = NULL;                 //

    while(pNode != NULL)                    //
    {
        ListNode* pNext = pNode->m_pNext;   //

        if(pNext == NULL)                   //
            NewHead = pNode;
        
        pNode->m_pNext = pPrev;             //
        
        pPrev = pNode;
        pNode = pNext;
    }
    return NewHead;
}

//合并两个链表
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;

    ListNode* NewHead = NULL;

    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        NewHead = pHead1;
        NewHead->m_pNext = MergeList(pHead1->m_pNext, pHead2);
    }
    else
    {
        NewHead = pHead2;
        NewHead->m_pNext = MergeList(pHead1, pHead2->m_pNext);
    }

    return NewHead;
}


void printList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        cout << pNode->m_nValue << " ";
        pNode = pNode->m_pNext;
    }
    cout<<endl;
}


int main()
{	
	ListNode* lt = NULL;
	AddToTail(&lt, 10);
	AddToTail(&lt, 20);
	AddToTail(&lt, 11);
	AddToTail(&lt, 41);

    ListNode* lt2  = NULL;
	AddToTail(&lt2, 11);
	AddToTail(&lt2, 21);
	AddToTail(&lt2, 31);
	AddToTail(&lt2, 40);

    printList(lt);
    printList(lt2);

    lt = MergeList(lt, lt2);

	//ReversPrint(&lt);
	//lt = ReverseList(lt);
	
    printList(lt);
    //ReversPrint(&lt);
	
    return 0;
}


