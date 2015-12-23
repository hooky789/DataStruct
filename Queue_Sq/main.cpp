#include <iostream>
#include <iomanip>
#include "queue_Sq.h"

using namespace std;

void main()
{
	ElemType num[]={21,1,2,3,4,5,6,7,8,9};
	ElemType temp;
	SqQueue myQueue;
	InitQueue_Sq(myQueue,5,9);
	cout<<"进队顺序:"<<endl;
	for (int i=0;i < 10;i++)
	{
		if (!EnQueue_Sq(myQueue,num[i]))
		{
			cout<<"进队错误"<<endl;
			system("pause");
			return;
		}
		cout<<setw(3)<<num[i];
	}
	cout<<endl;

	if (!GetHead_Sq(myQueue,temp))
	{
		cout<<"获取队首元素错误"<<endl;
	}
	else
		cout<<"当前队首元素:"<<temp<<endl;	

	cout<<"出队顺序:"<<endl;
	for (int i=0;i < 10;i++)
	{
		if (!DeQueue_Sq(myQueue,temp))
		{
			cout<<"出队错误"<<endl;
			system("pause");
			return;
		}
		cout<<setw(3)<<temp;
	}
	DestroyQueue_Sq(myQueue);
	cout<<endl;
	system("pause");
}