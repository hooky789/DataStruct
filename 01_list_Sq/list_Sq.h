#ifndef __LIST_H__
#define __LIST_H__

#define LIST_INIT_SIZE 100  //顺序表的初始分配最大容量
#define LISTINCREAMENT 10	//(默认)增补空间量

typedef int ElemType;		//类型重定义

typedef struct
{
	ElemType *elem;			//顺序表元素
	int length;				//顺序表长度
	int listsize;			//当前分配数组容量
	int increamentsize;		//增补空间量(以ElemType为单位)
}SqList;					//动态顺序表


//初始化线性表
void InitList_Sq(SqList &L,int maxsize = LIST_INIT_SIZE,int incresize = LISTINCREAMENT);
//计算线性表长度
int  ListLengh_Sq(SqList L);
//查找元素e的位置
int  LocateElem_Sq(SqList L,ElemType e);
//插入元素
bool ListInsert_Sq(SqList &L,int i,ElemType e);
//删除元素
bool ListDelete_Sq(SqList &L,int i,ElemType &e);
//遍历元素
void ListTraverse_Sq(SqList L);
//获取元素
bool GetElem_Sq(SqList L,int i,ElemType &e);

#endif


