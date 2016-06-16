#include "list_Sq.h"
#include "string.h"							//memset所在库
#include "stdlib.h" 
#include "iostream"
#include "iomanip"
using namespace std;

void InitList_Sq(SqList &L,int maxsize,int incresize)
{
	L.elem = new ElemType[maxsize];			//分配制定大小的空间
	if (!L.elem)
	{
		exit(1);							//分配失败则退出
	}
	L.length = 0;							//线性表初始长度为0
	L.listsize = maxsize;					//线性表可用最大长度
	L.increamentsize = incresize;			//线性表可增加长度
}


int  ListLengh_Sq(SqList L)					
{
	return L.length;						//返回线性表的长度
}


//查找线性表中值为e的元素位置
int  LocateElem_Sq(SqList L,ElemType e)		
{
	for (int i = 0;i<L.length;i++)			//从线性表的表头至最大长度查找
	{
		if (L.elem[i] == e)					
		{
			return i;						//若找到则返回改元素位置
		}
	}
	return -1;								//未找到该元素，则返回-1
}


//向线性表插入元素
bool ListInsert_Sq(SqList &L,int i,ElemType e)
{
	int j;
	if (i < 0 || i > L.length)				//插入位置非法则退出
	{
		return false;
	}
	
	if (L.length > L.listsize)				//若线性表的长度大于线性表可用总容量
	{
		//扩大elem指针的可用范围，增加线性表长度
		L.elem = (ElemType*)realloc(L.elem,(L.listsize + L.increamentsize) * sizeof(ElemType));
		if (!L.elem)	//若分配失败，则退出
		{
			exit(1);
		}
		L.listsize += L.increamentsize;		//更新表长
	}
	for (j = L.length;j > i;j++)			//插入元素及以后元素向表后移动
	{
		L.elem[j] = L.elem[j-1];
	}
	L.elem[i] = e;							//插入元素
	L.length++;								//表长加1
	return true;
}


bool ListDelete_Sq(SqList &L,int i,ElemType &e)
{
	int j;
	if (i < 0 || i >= L.length)				//若删除位置非法,退出
	{
		return false;
	}
	if (L.length <= 0)						//线性表为空，退出
	{
		return false;
	}
	e = L.elem[i];							//待删除值转存
	for (j = i + 1;j <= L.length - 1;j++)	
	{
		L.elem[j-1] = L.elem[j];			//删除元素以后的元素逐个向前移动
	}
	L.length--;								//线性表长度减1
	return true;
}


void ListTraverse_Sq(SqList L)
{
	int i;
	for (i = 0;i < L.length; i++)			//从线性表表头至表尾依次输出元素
	{
		cout<<setw(5)<<L.elem[i];
	}
	cout<<endl;
}

//获取位置为i的线性表中元素
bool GetElem_Sq(SqList L,int i,ElemType &e)
{
	if (i<0 || L.length)					//给定位置非法，退出
	{
		return false;
	}
	if (L.length <= 0)						//线性表为空，退出
	{
		return false;
	}
	e = L.elem[i];							//获取位置为i的元素
	return true;
}

