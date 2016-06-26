#include <iostream>
#include <iomanip>
#include "tree.h"

using namespace std;

int main()
{
	CTree myTree;
	InitTree(myTree);
	CreateTree(myTree,"A(B(D,E(H,I),F),C(G))");
//前序遍历
	cout<<"前序遍历"<<endl;
	PreOrderTree(myTree);
//后序遍历
	cout<<endl<<"后序遍历"<<endl;
	PostOrderTree(myTree);
	DestroyTree(myTree);
}