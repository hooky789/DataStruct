#ifndef __QUEUE_H_
#define __QUEUE_H_

#define QUEUE_INIT_SIZE 100
#define QUEUE_INCREMENT 100

typedef int ElemType;

typedef struct
{
	ElemType *queue;
	int front;
	int rear;
	int queuesize;
	int incresize;
}SqQueue;

void InitQueue_Sq(SqQueue &Q,int maxsize = QUEUE_INIT_SIZE,int incresize = QUEUE_INCREMENT);
int QueueLength_Sq(SqQueue Q);
bool EnQueue_Sq(SqQueue &Q,ElemType e);
bool DeQueue_Sq(SqQueue &Q,ElemType &e);
bool GetHead_Sq(SqQueue Q,ElemType &e);
bool QueueEmpty_Sq(SqQueue &Q);
void DestroyQueue_Sq(SqQueue &Q);


#endif