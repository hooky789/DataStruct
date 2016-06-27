/*************************************************************************
	> File Name: 05_tree.cpp
	> Author: Robin
	> Mail: chou_robin@163.com 
	> Created Time: 2016年06月19日 星期日 11时05分08秒
	> From : 剑指offer
 ************************************************************************/

/*
 * 1.前序遍历的 递归实现和 非递归实现
 * 2.中序遍历的 递归实现和 非递归实现
 * 3.后序遍历的 递归实现和 非递归实现
 * 4.根据两项遍历结果 重构树结构
 *
*/


#include<iostream>
#include <stdlib.h>
#include <stack>
#include <deque>
using namespace std;

struct BTreeNode
{
	int m_nValue;			//数值域
	BTreeNode* m_pLeft;		//左孩子
	BTreeNode* m_pRight;	//右孩子
};


//重建二叉树
BTreeNode* ConstructionCore(int *startPre, int *endPre, int *startIn, int *endIn)
{
	//int rootValue = startPre[0];
	BTreeNode* root = new BTreeNode();
	root->m_nValue = startPre[0];
	root->m_pLeft = root->m_pRight = NULL;

	if(startPre == endPre)
	{
		if(startIn == endIn && *startPre == *startIn)
		{
			return root;
		}
		else
		{
			cout<<"Input Error!"<<endl;
			exit(-1);
		}
	}

	int *rootIn = startIn;
	while(rootIn <= endIn && *rootIn != root->m_nValue)
		++rootIn;

	if(rootIn == endIn && *rootIn != root->m_nValue)
	{
		cout<<"Inout Error!"<<endl;
		exit(-1);
	}

	int leftlen = rootIn - startIn;
	int *leftPreEnd = startPre + leftlen;
	if(leftlen > 0)
	{
		root->m_pLeft = ConstructionCore(startPre+1, leftPreEnd, startIn, rootIn - 1);
	}
	if(leftlen < endPre - startPre)
	{
		root->m_pRight = ConstructionCore(leftPreEnd+1, endPre, rootIn+1, endIn);
	}
	return root;
}


BTreeNode* Construct(int *preorder, int *inorder, int len)
{
	if(preorder == NULL || inorder == NULL || len <= 0)
		return NULL;

	return ConstructionCore(preorder, preorder+len-1, inorder, inorder+len-1);
}

void LevelTree(BTreeNode *pHead)
{
    if(!pHead)
        return;
    
    deque<BTreeNode*> de;
    de.push_back(pHead);
    while(de.size() > 0)
    {
        BTreeNode*  tmp = de.front();
        de.pop_front();
        cout << tmp->m_nValue << " ";
        if(tmp->m_pLeft)
            de.push_back(tmp->m_pLeft);
        
        if(tmp->m_pRight)
            de.push_back(tmp->m_pRight);
    }
}


//二叉树的三种遍历方式
//前序遍历递归实现
void PreBTree(BTreeNode *pHead)
{
	if(pHead)
	{
		cout<< pHead->m_nValue << " ";
		PreBTree(pHead->m_pLeft);
		PreBTree(pHead->m_pRight);
	}
//	cout<<endl;
}


//前序遍历非递归实现
void NRPreBTree(BTreeNode *pHead)
{
	stack<BTreeNode*> sk;
	while(pHead != NULL || !sk.empty())
	{
		if(pHead != NULL)
		{
			cout << pHead->m_nValue << " ";
			sk.push(pHead);
			pHead = pHead->m_pLeft;
		}
		else
		{
			pHead = sk.top();			//弹出父节点
			sk.pop();					
			pHead = pHead->m_pRight;	
		}
	}
	cout<<endl;
}


//中序遍历的递归实现
void InBTree(BTreeNode *pHead)
{
	if(pHead != NULL)
	{
		InBTree(pHead->m_pLeft);
		cout << pHead->m_nValue << " ";
		InBTree(pHead->m_pRight);
	}
}


//中序遍历的非递归实现
void NRInBTree(BTreeNode *pHead)
{
	stack<BTreeNode*> sk;
	while(pHead != NULL || !sk.empty())
	{
		if(pHead != NULL)
		{
			//cout << pHead->m_nValue << " ";
			sk.push(pHead);
			pHead = pHead->m_pLeft;
		}
		else
		{
			pHead = sk.top();			//弹出父节点
			sk.pop();
			cout << pHead->m_nValue << " ";
			pHead = pHead->m_pRight;	
		}
	}
}

//后序遍历的递归实现
void PostBTree(BTreeNode *pHead)
{
	if(pHead != NULL)
	{
		PostBTree(pHead->m_pLeft);
		PostBTree(pHead->m_pRight);
		cout << pHead->m_nValue << " ";
	}
}


//后序遍历的非递归实现
void NRPostBTree(BTreeNode *pHead)
{
	stack<BTreeNode*> sk;
	BTreeNode* q;
	int flag = 0;
	do
	{
		while(pHead)
		{
			sk.push(pHead);
			pHead = pHead->m_pLeft;
		}
		q = NULL;
		flag = 1;
		while(!sk.empty() && flag)
		{
			pHead = sk.top();
			if(pHead->m_pRight == q)
			{
				sk.pop();
				cout<< pHead->m_nValue <<" ";
				q = pHead;
			}
			else
			{
				pHead = pHead->m_pRight;
				flag = 0;
			}
		}
	}
	while(!sk.empty());
}



int main()
{
	int pre[8] = {1,2,4,7,3,5,6,8};
	int in[8] = {4,7,2,1,5,3,8,6};
	BTreeNode *tr = Construct(pre, in, 8);
	
	cout<<"前序遍历递归"<<endl;
	PreBTree(tr);
	cout<<endl<<"前序遍历非递归"<<endl;
	NRPreBTree(tr);

	cout<<"中序遍历递归"<<endl;
	InBTree(tr);
	cout<<endl<<"中序遍历非递归"<<endl;
	NRInBTree(tr);

	cout<<endl<<"后序遍历递归"<<endl;
	PostBTree(tr);
	cout<<endl<<"后序遍历非递归"<<endl;
	NRPostBTree(tr);
	cout<<endl;

    cout<<"层序遍历"<<endl;
    LevelTree(tr);
    cout<<endl;

	return 0;
}



