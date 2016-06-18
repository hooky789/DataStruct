/*************************************************************************
	> File Name: CMyString.cpp
	> Author: Robin 
	> Mail: chou_robin@163.com
	> Created Time: 2016年06月17日 星期五 10时37分14秒
    > from 剑指offer
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class CMyString
{
public:
    CMyString(char *str = NULL);
    CMyString(const CMyString & str);
    ~CMyString();
    
    CMyString& operator=(const CMyString& str);

private:
    char* m_pData;
};


CMyString::CMyString(char *str)
{
    m_pData = NULL;
    if(str == NULL)
        return;
    int len = strlen(str);
    m_pData = new char[len + 1];
    strcpy(m_pData, str);
    m_pData[len] = 0;
}


CMyString::CMyString(const CMyString & str)
{
    
}


CMyString::~CMyString()
{
    if(m_pData != NULL)
        delete[] m_pData;
    m_pData = NULL;
}


/*
//考虑：如果在delete之后，分配空间的时候出现内存不够的时候会出现什么情况？
//之前的数据被删除了，然而后面的数据也没有拷贝成功。
CMyString& CMyString::operator=(const CMyString& str)
{
    if(this == &str)
        return *this;
    
    delete[] this->m_pData;
    this->m_pData = NULL;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}
*/


CMyString& CMyString::operator=(const CMyString& str)
{
    if(this != &str)
    {
        CMyString tmp(str.m_pData);     //构造一个临时的对象，临时对象会在该函数退出的时候调用析构函数销毁
        char* p = this->m_pData;        //交换两者的数据域
        this->m_pData = tmp.m_pData;
        tmp.m_pData = p;
    }
    return *this;
}


int main()
{
    CMyString str1("hello");
    CMyString str2("Chow Robin");
//    cout << str1.m_pData << endl;
//    cout << str2.m_pData << endl;
    str1 = str2;
//    cout << str1.m_pData << endl;
//    cout << str2.m_pData << endl;

    return 0;
}




