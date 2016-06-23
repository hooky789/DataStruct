#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "bitree.h"

using namespace std;

//ABD#G###CE##F##
void InitTree(BiTree &Bt)
{
	Bt = NULL;
}


int CreateTree(BiTree &Bt)
{
	TElemType a;
	cin>>a;
	if (a == '#')//如果节点值表示为#则表示子树为空
	{
		Bt = NULL;
	}
	else
	{
		Bt = (BiTree)malloc(sizeof(BiTNode));//分配一个树节点空间
		if (!Bt)
		{
			exit(0);
		}
		Bt->data = a;			//加载树节点的值
		CreateTree(Bt->lchild);//递归创建左子树
		CreateTree(Bt->rchild);//递归创建右子树
	}
}


bool BiTreeEmpty(BiTree Bt)
{
	if (!Bt)
		return true;
	else
		return false;
}

int BiTreeDepth(BiTree Bt)
{
	int lh,rh;
	if (!Bt)//判断树空
		return 0;
	lh = BiTreeDepth(Bt->lchild);//递归左子树
	rh = BiTreeDepth(Bt->rchild);//递归右子树
	if (lh >= rh)//返回最大值
		return lh;
	else
		return rh;
}


BiTree SearchBiTree(BiTree Bt,TElemType e)
{
	BiTree p;
	if (!Bt)//树空
		return NULL;
	if (Bt->data == e)
		return Bt;
	//左子树非空，查找左子树
	if (Bt->lchild)
	{
		p = SearchBiTree(Bt->lchild,e);//递归查找
		if (p)
			return p;
	}
	//右子树非空，查找右子树
	if (Bt->rchild)
	{
		p = SearchBiTree(Bt->rchild,e);//递归查找
		if (p)
			return p;
	}
}

void PreOrderBiTree(BiTree Bt)
{
	if (Bt)
	{
		cout<<setw(2)<<Bt->data;
		PreOrderBiTree(Bt->lchild);
		PreOrderBiTree(Bt->rchild);
	}
}

void PostOrderBiTree(BiTree Bt)
{
	if (Bt)
	{
		PostOrderBiTree(Bt->lchild);
		PostOrderBiTree(Bt->rchild);
		cout<<setw(2)<<Bt->data;
	}
}

void DestroyBiTree(BiTree &Bt)
{
	if (Bt)
	{
		DestroyBiTree(Bt->lchild);
		DestroyBiTree(Bt->rchild);
		free(Bt);
		Bt = NULL;
	}
}
