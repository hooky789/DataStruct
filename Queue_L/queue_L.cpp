#include "queue_L.h"
#include <iomanip>
#include <stdlib.h>
#include <iostream>

using namespace std;


void InitQueue_L(LinkQueue &Q)
{
	Q.front = NULL;
	Q.rear = NULL;
}

int QueueLength_L(LinkQueue Q)
{
	int len = 0;
	QueuePt pt = Q.front;
	while (pt != NULL)
	{
		len++;
		pt = pt->next;
	}
	return len;
}


bool EnQueue_L(LinkQueue &Q,ElemType e)
{
	QueuePt em = (QueuePt)malloc(sizeof(LNode));
	if (em == NULL)
	{
		return false;
	}
	em->data = e;
	em->next = NULL;
	if (Q.rear == NULL)
	{
		Q.rear = em;
		Q.front = em;
	}
	Q.rear->next = em;
	Q.rear = Q.rear->next;
	return true;
}

bool DeQueue_L(LinkQueue &Q,ElemType &e)
{
	QueuePt ptr;
	if (Q.front == NULL)
	{
		return false;
	}
	ptr = Q.front;
	e = Q.front->data;
	Q.front = Q.front->next;
	if (Q.front == NULL)
	{
		Q.rear = NULL;
	}
	free(ptr);
	return true;
}

bool GetHead_L(LinkQueue &Q,ElemType &e)
{
	QueuePt ptr;
	if (Q.front == NULL)
	{
		return false;
	}
	ptr = Q.front;
	e = Q.front->data;
	return true;
}

bool QueueEmpty(LinkQueue Q)
{
	if (Q.front == NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void DestroyQueue_L(LinkQueue &Q)
{
	QueuePt ptr;
	ptr = Q.front;
	while (Q.front != NULL)
	{
		Q.front = Q.front->next;
		free(ptr);
		ptr = Q.front;
	}
	Q.front = NULL;
	Q.rear = NULL;
}