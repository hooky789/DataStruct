#include "list_L.h"
#include "iostream"
#include "iomanip"
#include <stdlib.h>

using namespace std;

void InitList_L(LinkList &L)
{
	L = (LNode*)malloc(sizeof(LNode));		//分配一个节点的空间
	if (!L)									//若分配失败，则退出
	{
		exit(1);
	}
	L->next = NULL;							//链表的下一节点为空
}


int ListLengh_L(LinkList L)
{
	LinkList p;
	int k = 0;
	p = L->next;
	while (p)
	{
		k++;
		p = p->next;
	}
	return k;
}


bool ListInsert_L(LinkList &L,int i,ElemType e)
{
	LinkList p,s;
	int j = 0;
	p = L;
	while ((p->next) && (j < i - 1))
	{
		p = p->next;
		j++;
	}
	if (j != i - 1)
	{
		return false;
	}
	if ((s = (LNode*)malloc(sizeof(LNode))) == NULL)
	{
		exit(1);
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListDelete_L(LinkList &L,int i,ElemType &e)
{
	LinkList p,q;
	int j = 0;
	p = L;
	while ((p->next->next) && (j < i - 1))
	{
		p = p->next;
		j++;
	}
	if (j != i - 1)
	{
		return false;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return true;
}

void ListTraverse_L(LinkList L)
{
	LinkList pL = L->next;
	while (pL)
	{
		cout<<setw(6)<<pL->data;
		pL = pL->next;
	}
	cout<<endl;
}

void DestroyList_L(LinkList &L)
{
	LinkList p,p1;
	p = L;
	while (p)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
	L = NULL;
}

