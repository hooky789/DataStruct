#include <iostream>
#include "stdlib.h"
#include "list_L.h"

using namespace std;

int main()
{
	LinkList head;
	ElemType x=0;
	int i,a[] = {6,8,16,2,34,56,7,10,22,45};
	InitList_L(head);
	for (i=1;i<=10;i++)
	{
		if (!ListInsert_L(head,i,a[i-1]))
		{
			cout<<"插入失败！"<<endl;
			system("pause");
			return 0;
		}
	}
	cout<<"删除前的链表为："<<endl;
	ListTraverse_L(head);
	cout<<"当前链表长度为："<<ListLengh_L(head)<<endl;
	cout<<"删除第4个元素"<<endl;
	ListDelete_L(head,4,x);
	cout<<"被删除的元素是:"<<x<<endl;
	cout<<"删除后的链表为："<<endl;
	ListTraverse_L(head);
	cout<<"当前链表长度为："<<ListLengh_L(head)<<endl;
	DestroyList_L(head);
	system("pause");
	return 0;
}