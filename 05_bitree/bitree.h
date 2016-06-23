#ifndef  __BITREE_H__
#define  __BITREE_H__

typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode,*BiTree;

void InitTree(BiTree &Bt);
int CreateTree(BiTree &Bt);
bool BiTreeEmpty(BiTree Bt);
int BiTreeDepth(BiTree Bt);
BiTree SearchBiTree(BiTree bt,TElemType e);
BiTree Parent(BiTree Bt,TElemType e);
void PreOrderBiTree(BiTree Bt);
void PostOrderBiTree(BiTree Bt);

void DestroyBiTree(BiTree &Bt);


#endif // ! __BITREE_H_
