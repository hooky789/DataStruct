#include "stack.h"
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

void InitStack_Sq(SqStack &S,int maxsize,int incresize)
{
	S.stack = (ElemType *)malloc(maxsize * sizeof(ElemType));//分配栈空间
	if (S.stack == NULL)//如果分配失败，退出
	{
		 exit(0);
	}
	S.top = -1;//空栈
	S.stacksize = maxsize;
	S.increamentsize = incresize;
}

int StackLength_Sq(SqStack S)
{
	return S.top + 1;
}

bool Push_Sq(SqStack &S,ElemType e)
{
	if (StackLength_Sq(S) >= S.stacksize)
	{
		S.stack = (ElemType *) realloc (S.stack,(S.stacksize + S.increamentsize) * sizeof(ElemType));
		if (S.stack == NULL)
		{
			return false;
		}
		S.stacksize += S.increamentsize;
	}
	S.stack[++S.top] = e;
	return true;
}


bool Pop_Sq(SqStack &S,ElemType &e)
{
	if (S.top == -1)
	{
		return false;
	}
	e = S.stack[S.top--];
	return true;
}

bool GetTop_Sq(SqStack S,ElemType &e)
{
	if (S.top == -1)
	{
		return false;
	}
	e = S.stack[S.top];
	return true;
}

bool StackEmpty_Sq(SqStack S)
{
	if (S.top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void DestroyStack_Sq(SqStack &S)
{
	free(S.stack);
	S.stacksize = 0;
	S.top = -1;
}