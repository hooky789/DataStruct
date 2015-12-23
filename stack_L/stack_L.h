#ifndef __STACK_H__
#define __STACK_H__

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LNode,*LinkList;

typedef LinkList LinkStack;

void InitStack_L(LinkStack &S);
int StackLenth_L(LinkStack S);
bool Push_L(LinkStack &S,ElemType e);
bool Pop_L(LinkStack &S,ElemType &e);
bool GetTop_L(LinkStack S,ElemType &e);
bool StackEmpty_L(LinkStack S);
void DestroyStack_L(LinkStack &S);

#endif