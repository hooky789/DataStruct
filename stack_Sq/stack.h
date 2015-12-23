#ifndef __STACK_H__
#define __STACK_H__

#define STACK_INITSIZE 100
#define STACK_INCREAMENT 100
typedef int ElemType;

typedef struct 
{
	ElemType *stack;
	int top;
	int stacksize;
	int increamentsize;
}SqStack;

void InitStack_Sq(SqStack &S,int maxsize = STACK_INITSIZE,int increamentsize = STACK_INCREAMENT);
int StackLength_Sq(SqStack S);
bool Push_Sq(SqStack &S,ElemType e);
bool Pop_Sq(SqStack &S,ElemType &e);
bool GetTop_Sq(SqStack S,ElemType &e);
bool StackEmpty_Sq(SqStack S);
void DestroyStack_Sq(SqStack &S);

#endif
