/*************************************************************************
	> File Name: 10_power.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年06月20日 星期一 15时54分10秒
    > From : 剑指offer
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

double Power(double base, int exponent)
{
    double rt = base;
    unsigned int exp = 0;

    if(base < 0.000001 && base > -0.000001 && exponent == 0)   //0^0
        return 1.0;

    if(exponent < 0)
        exp = (unsigned int)(-exponent);
    else
        exp = (unsigned int)exponent;

    for(int i=1; i<exp; ++i)
    {
        rt *= base;
    }

    if(exponent < 0)
        rt = 1.0/rt;

    return rt;
}


int main()
{
    //printf("%.4lf",Power(10,-2));
    cout<<"Power(0,0): " << Power(0,0) << endl;
    cout<<"Power(0,1): " << Power(0,1) << endl;
    cout<<"Power(10,2): " << Power(10,2) << endl;
    cout<<"Power(10,-2): " << Power(10,-2) << endl;
    cout<<"Power(5,-2): " << Power(5,-2) << endl;
    cout<<"Power(3,3): " << Power(3,3) << endl;
    cout<<"Power(2,10): " << Power(2,10) << endl;
    return 0;
}



