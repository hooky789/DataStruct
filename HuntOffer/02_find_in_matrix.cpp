/*************************************************************************
	> File Name: find_in_matrix.cpp
	> Author: Robin
	> Mail:  chou_robin@163.com
	> Created Time: 2016年06月17日 星期五 11时33分23秒
    > from: 剑指offer
 ************************************************************************/

#include<iostream>
using namespace std;

int tb[16] = {1, 2,  8, 9, 
              2, 4,  9, 12,
              4, 7, 10, 13,
              6, 8, 11, 15};


bool find_in_matrix(int *mat, const int row, const int col, const int num)
{
    if(mat == NULL || row < 0 || col < 0)
        return false;

    int i = col-1, j=0;
    for(;i >= 0 && j< row;)
    {
        if(mat[j * col + i] > num) 
            --i;
        else if(mat[j*col + i] == num) 
            return true;
        else
            ++j;
        
    }
    return false;
}


int main()
{
    cout << find_in_matrix(tb, 4, 4, 5) << endl;
    cout << find_in_matrix(tb, 4, 4, 7) << endl;
    cout << find_in_matrix(tb, 4, 4, 11) << endl;
    return 0;
}

