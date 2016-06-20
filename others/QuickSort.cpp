#include <iostream>

using namespace std;

/*
* 快速排序的递归实现
*/
template<class T>
void QuickSort(T a[], int l, int r)
{
	T tmp = a[l];
	int i = l;
	int j = r;
	while(i < j)
	{
		while(i < j && a[j] >= tmp) --j;
		if(i < j)
		{
			a[i] = a[j];
			++i;
		}
		
		while(i < j && a[i] < tmp) ++i;
		if(i < j)
		{
			a[j] = a[i];
			--j;
		}
	}
	a[i] = tmp;
	if(l < i-1)
		QuickSort(a, l, i-1);
	if(j+1 < r)
		QuickSort(a, j+1, r);
}

int a[10] = {1,3,2,6,9,12,34,8,56,22};

int main()
{
	
	for(int i = 0; i < 10; ++i)
		cout<<a[i]<<" ";
	
	cout<<endl;
	QuickSort(a, 0, 9);

	
	for(int i = 0; i < 10; ++i)
		cout<<a[i]<<" ";
	
	cout<<endl;
	return 0;
}



