#ifndef __QUEUE_L_H__
#define __QUEUE_L_H__

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LNode,*LinkList;

typedef LinkList QueuePt;

typedef struct
{
	QueuePt front;
	QueuePt rear;
}LinkQueue;


void InitQueue_L(LinkQueue &Q);
int QueueLength_L(LinkQueue &Q);
bool EnQueue_L(LinkQueue &Q,ElemType e);
bool DeQueue_L(LinkQueue &Q,ElemType &e);
bool GetHead_L(LinkQueue &Q,ElemType &e);
bool QueueEmpty(LinkQueue Q);
void DestroyQueue_L(LinkQueue &Q);


#endif