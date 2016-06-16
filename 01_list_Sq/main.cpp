#include "stdlib.h"
#include "iostream"
#include "list_Sq.h"

using namespace std;

int main()
{
	SqList mylist;
	int i, a[] = {6,8,16,2,34,56,7,10,22,45};
	InitList_Sq(mylist,50,10);
	for (i=0;i<10;i++)
	{
		if (!ListInsert_Sq(mylist,i,a[i]))
		{
			cout<< " Insert Error! "<<endl;
			return -1;
		}
	}
	cout<<"The current linear list is: ";
	ListTraverse_Sq(mylist);
	return 0;
}


