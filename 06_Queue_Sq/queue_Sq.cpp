#include <iostream>
#include <iomanip>
#include "queue_Sq.h"

using namespace std;

void InitQueue_Sq(SqQueue &Q,int maxsize,int incresize)
{
	Q.queue = (ElemType *)malloc(maxsize * sizeof(ElemType));
	if (Q.queue == NULL)
	{
		exit(0);
	}
	Q.rear = 0;
	Q.front = 0;
	Q.queuesize = maxsize;
	Q.incresize = incresize;
}

int QueueLength_Sq(SqQueue Q)
{
	return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

bool EnQueue_Sq(SqQueue &Q,ElemType e)
{
	if ( (Q.rear + 1) % Q.queuesize == Q.front)//队列满
	{
		//重新分配内存
		Q.queue = (ElemType *)realloc(Q.queue,(Q.queuesize+Q.incresize)*sizeof(ElemType));
		if (Q.queue == NULL)
		{
			return false;
		}
		//队头下标在队尾下标前面
		if (Q.front > Q.rear)
		{
			for (int i=Q.queuesize;i>=Q.front;i--)
			{
				Q.queue[i+Q.incresize] = Q.queue[i];
			}
			Q.front += Q.incresize;
		}
		Q.queuesize += Q.incresize;
	}
	Q.queue[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;
	return true;
}

bool DeQueue_Sq(SqQueue &Q,ElemType &e)
{
	if (Q.front == Q.rear)//队空
	{
		return false;
	}
	e = Q.queue[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;
	return true;
}

bool GetHead_Sq(SqQueue Q,ElemType &e)
{
	if (Q.front == Q.rear)//队空
	{
		return false;
	}
	e = Q.queue[Q.front];
	return true;
}

bool QueueEmpty_Sq(SqQueue &Q)
{
	if (Q.front == Q.rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DestroyQueue_Sq(SqQueue &Q)
{
	free(Q.queue);
	Q.front = 0;
	Q.rear = 0;
}