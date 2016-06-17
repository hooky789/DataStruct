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
			cout<<"Insert Elements error! "<<endl;
			//system("pause");
			return 0;
		}
	}
	cout<<"String before deleted: "<<endl;
	ListTraverse_L(head);
	cout<<"List length: "<<ListLengh_L(head)<<endl;
	cout<<"Delete the 4th element: "<<endl;
	ListDelete_L(head,4,x);
	cout<<"Deleted elemente: "<<x<<endl;
	cout<<"String after deleted: "<<endl;
	ListTraverse_L(head);
	cout<<"List length: "<<ListLengh_L(head)<<endl;
	DestroyList_L(head);
	//system("pause");
	return 0;
}


