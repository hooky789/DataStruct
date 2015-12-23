#ifndef __LIST_L_H__
#define __LIST_L_H__

typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}LNode,*LinkList;

void InitList_L(LinkList &L);
int ListLengh_L(LinkList L);
bool ListInsert_L(LinkList &L,int i,ElemType e);
bool ListDelete_L(LinkList &L,int i,ElemType &e);
bool GetElem_L(LinkList L,int i,ElemType &e);
void ListTraverse_L(LinkList L);
void DestroyList_L(LinkList &L);



#endif