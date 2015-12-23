#ifndef __TREE_H__
#define __TREE_H__

#define MAX_SON_SIZE 10					//最多孩子数
typedef char TElemType;					//节点值类型


typedef struct  CTNode
{
	TElemType data;						//节点值
	struct CTNode *child[MAX_SON_SIZE];	//指向孩子节点的指针，最多有MAX_SON_SIZE个孩子节点
}CTNode,*CTree;

void InitTree(CTree &T);
void CreateTree(CTree &T,char *S);
void PreOrderTree(CTree T);
void PostOrderTree(CTree T);
void DestroyTree(CTree &T);

#endif