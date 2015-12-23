#include <iostream>
#include <iomanip>

#include "bitree.h"

using namespace std;

int main()
{
	BiTree myTree;           //实例化一棵树
	InitTree(myTree);        //初始化树
	CreateTree(myTree);      //创建树
	PreOrderBiTree(myTree);  //前序遍历树
	DestroyBiTree(myTree);   //销毁树
	return 0;
}