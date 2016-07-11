/*************************************************************************
	> File Name: maxthread.c
	> Author: Robin
	> Mail: chou_robin@163.com 
	> Created Time: 2016年07月11日 星期一 19时22分09秒
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void *th_fun(void* arg)
{
	return (void *)1;
}


int main()
{
	pthread_t tid;
	int i = 0;
	int err = 0;

	while(1)
	{
		err = pthread_create(&tid, NULL, th_fun, NULL);
		if(err == 0)
			printf("cur no: %d, sum: %d \n", (unsigned int)pthread_self(), i++);
		else
		{
			printf("%s\n", strerror(err));
			exit(1);
		}
	}
	return 0;
}




