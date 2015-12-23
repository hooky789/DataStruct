#include <iostream>
#include <iomanip>
#include "queue_L.h"

using namespace std;

void main()
{
	ElemType num[] = {89,12,20,13,24,59,61,73,58,29};
	ElemType temp;
	LinkQueue myQueue;
	InitQueue_L(myQueue);

	for (int i = 0;i < 10;i++)
	{
		if (!EnQueue_L(myQueue,num[i]))
		{
			cout<<"进队错误"<<endl;
			system("pause");
			return;
		}
		cout<<setw(3)<<num[i];
	}
	cout<<endl;
	for (int i=0;i < 10;i++)
	{
		if (!DeQueue_L(myQueue,temp))
		{
			cout<<"出队错误"<<endl;
			system("pause");
			return;
		}
		cout<<setw(6)<<"出队元素:"<<temp<<endl;
		if (!GetHead_L(myQueue,temp))
		{
			cout<<"获取队首元素错误"<<endl;
		}
		else
			cout<<"当前队首元素:"<<temp<<endl;	
	}
	DestroyQueue_L(myQueue);
	cout<<endl;
	system("pause");
}