/*************************************************************************
	> File Name: 17_Subtree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月27日 星期一 10时19分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct BTreeNode
{
    int m_nValue;
    struct BTreeNode* m_pLeft;
    struct BTreeNode* m_pRight;
};


bool DoseHasSubtree(BTreeNode* t1, BTreeNode* t2)
{
    if(t2 == NULL)
        return true;
    
    if(t1 == NULL)
        return false;

    return DoseHasSubtree(t1->m_pLeft, t2->m_pLeft) && DoseHasSubtree(t1->m_pRight, t2->m_pRight);
}


bool HasSubtree(BTreeNode* t1, BTreeNode* t2)
{
    bool rt = false;
    if(t1 == NULL || t2 == NULL)
        return false;

    if(t1->m_nValue == t2.m_nValue)
        rt = DoseHasSubtree(t1, t2);

    if(!rt)
        rt = HasSubtree(t1->m_pLeft, t2);

    if(!rt)
        rt = HasSubtree(t1->m_pRight, t2);

    return rt;
}


int main()
{

    return 0;
}


