/*************************************************************************
	> File Name: miniStack.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月27日 星期一 10时49分58秒
    > From : 剑指offer
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class StackWithMin
{
private:
    stack<T> m_data;
    stack<T> m_min;
public:
    void push(const T& value);
    void pop();
    T& min();
};

template<typename T>
void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);
    if(m_min.size() == 0 || value > m_min.top())
        m_min.push(m_min.top());
    else
    {
        m_min.push(value);
    }
}

template<typename T>
void StackWithMin<T>::pop()
{
    if(m_data.size() > 0 && m_min.size() > 0 )
    {
        m_data.pop();
        m_min.pop();
    }
}

template<typename T>
const T& StackWithMin<T>::min()
{
    if(m_min > 0)
        return m_min.top();
}


int main()
{
    return 0;
}


