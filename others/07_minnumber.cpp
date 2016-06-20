/*************************************************************************
	> File Name: 07_minnumber.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月20日 星期一 09时50分42秒
    > From: 剑指offer
 ************************************************************************/

/*
 * 旋转数组的最小数字
*/
#include<iostream>
#include<stdlib.h>

using namespace std;
//using namespace std::exception;

int MinOrder(int *numbers, int index1, int index2)
{
    int rt = numbers[index1];
    for(int i=index1; i<index2; ++i)
    {
        if(numbers[i] < rt)
            rt = numbers[i];
    }
    return rt;
}


int Min(int *numbers, int len)
{
    if(numbers == NULL || len <=0)
    {
        cout<<"Input Error"<<endl;
        exit(-1);
    }
    
    int index1 = 0;
    int index2 = len - 1;
    int indexMin = index1;

    while(numbers[index1] >= numbers[index2])
    {
        if(index2 - index1 == 1)        //找到最小值
        {
            indexMin = index2;
            break;
        }
        indexMin = (index1 + index2)/2;
        
        //考虑这样的数字序列的问题 1 0 1 1 1
        //或者1 1 1 0 1
        //这样的序列有一个问题就是不能判断序列的增减，遇到这样的情况就只能去挨个遍历查找了
        if(numbers[indexMin] == numbers[index1] && numbers[indexMin] == numbers[index2])
            return MinOrder(numbers, index1, index2);

        
        if(numbers[indexMin] >= numbers[index2])
            index1 = indexMin;
        else if(numbers[indexMin] <= numbers[index2])
            index2 = indexMin;
    }
    return numbers[indexMin];
}


int main()
{
    int num[5] = {4,5,1,2,3};
    int num2[5] = {1,0,1,1,1};
    cout<<Min(num2,5)<<endl;
    return 0;
}


