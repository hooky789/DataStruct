/*************************************************************************
	> File Name: 18_MirroTree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月27日 星期一 10时33分50秒
    > From 剑指offer
 ************************************************************************/

#include<iostream>
using namespace std;

struct BTreeNode
{
    int m_nValue;
    struct BTreeNode* m_pLeft;
    struct BTreeNode* m_pRight;
};


//递归的镜像二叉树
void MirroTree(BTreeNode* pHead)
{
    if(pHead == NULL || (pHead->m_pLeft == NULL && pHead->m_pRight == NULL))
        return;

    BTreeNode* pTmp = pHead->m_pLeft;
    pHead->m_pLeft = pHead->m_pRight;
    pHead->m_pRight = pTmp;
    
    if(pHead->m_pLeft)
        MirroTree(pHead->m_pLeft);
    
    if(pHead->m_pRight)
        MirroTree(pHead->m_pRight);
}


int main()
{

    return 0;
}




