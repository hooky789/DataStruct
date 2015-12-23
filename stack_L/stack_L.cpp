#include <iostream>
#include <iomanip>
#include "stack_L.h"

using namespace std;

void InitStack_L(LinkStack &S)
{
	S = NULL;
}

int StackLenth_L(LinkStack S)
{
	LinkStack pt = S;
	int cnt=0;
	while (pt != NULL)
	{
		cnt++;
		pt = pt->next;
	}
	return cnt;
}

bool Push_L(LinkStack &S,ElemType e)
{
	LinkStack p;
	if ((p = (LinkStack)malloc(sizeof(LNode))) == NULL)
	{
		return false;
	}
	p->next = S;
	S = p;
	p->data = e;
	return true;
}

bool Pop_L(LinkStack &S,ElemType &e)
{
	LinkStack p;
	if (S != NULL)
	{
		e = S->data;
		p = S;
		S = p->next;
		free(p);
		return true;
	}
	else
	{
		return false;
	}
}

bool GetTop_L(LinkStack S,ElemType &e)
{
	if (S != NULL)
	{
		e = S->data;
		return true;
	}
	else
	{
		return false;
	}
}

bool StackEmpty_L(LinkStack S)
{
	if (S != NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void DestroyStack_L(LinkStack &S)
{
	LinkStack pt1,pt2;
	pt1 = S;
	while (pt1)
	{
		pt2 = pt1->next;
		free(pt1);
		pt1 = pt2;
	}
}