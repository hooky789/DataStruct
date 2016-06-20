/*************************************************************************
	> File Name: 06_stack2queue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月20日 星期一 09时06分44秒
    > From: 剑指offer
 ************************************************************************/

#include<iostream>
#include<stack>
#include<stdlib.h>
using namespace std;

/*
* 两个栈实现队列
* 求解思路：
* 从队头添加元素时，添加到sk1.
* 删除的时候首先检查sk2,
* 如果sk2为空，那么就将sk1的数据全部搬迁到sk2中，然后从sk2的栈顶删除元素即可。
* 如果sk2非空，那么直接从sk2的栈顶删除数据即可。
*/
template<class T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node);
    T deleteHead();

private:
    stack<T> sk1;
    stack<T> sk2;
};

template<class T>
CQueue<T>::CQueue(void)
{}

template<class T>
CQueue<T>::~CQueue(void)
{}

template<class T>
void CQueue<T>::appendTail(const T& node)
{
    sk1.push(node);
}

template<class T>
T CQueue<T>::deleteHead()
{
    if(sk2.size() <= 0)
    {
        while(sk1.size > 0)
        {
            T& tmp = sk1.top();
            sk1.pop();
            sk2.push(tmp);
        }
    }

    if(sk2.size == 0)
    {
        cout<< "Queue Empty!"<< endl;
        exit(-1);
    }
    
    T head = sk2.top();
    sk2.pop();
    return head;
}


int main()
{
    CQueue<int> que;
    que.appendTail(10);
    return 0;
}


