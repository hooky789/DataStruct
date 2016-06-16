#include <iostream>
#include <iomanip>
#include "stack.h"

using namespace std;

void main()
{
	SqStack myStack;
	ElemType num[10] = {0,1,2,3,4,5,6,7,8,9};
	ElemType temp;
	InitStack_Sq(myStack,100,100);
	cout<<"½øÕ»Ë³Ðò:"<<endl;
	for (int i = 0;i < 10;i ++)
	{
		if ( !Push_Sq(myStack,num[i]) )
		{
			cout<<"½øÕ»Ê§°Ü"<<endl;
			system("pause");
			return;
		}
		else
		{
			cout<<setw(4)<<num[i];
		}

	}
	cout<<endl;
	cout<<"³öÕ»Ë³Ðò:"<<endl;
	for (int i = 0;i < 10;i ++)
	{
		if (!Pop_Sq(myStack,temp))
		{
			cout<<"³öÕ»Ê§°Ü"<<endl;
			system("pause");
			return;
		}
		else
		{
			cout<<setw(4)<<temp;
		}
	}
	cout<<endl;
	DestroyStack_Sq(myStack);
	system("pause");
}