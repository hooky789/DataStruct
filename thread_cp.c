/*************************************************************************
	> File Name: thread_cp.c
	> Author: Robin
	> Mail: chou_robin@163.com 
	> Created Time: 2016年07月11日 星期一 23时00分04秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>

#define THREADS_COUNT 50
#define THREADS_BUFF_SIZE 1024

struct thread_block
{
	int infd;
	int outfd;
	size_t start;
	size_t end;
	size_t cp;
};


size_t get_filesize(int fd)
{
	struct stat st;
	fstat(fd, &st);
	return st.st_size;
}


/*线程函数体*/
void *thread_copy_fun(void *arg)
{
	struct thread_block * block = (struct thread_block *)arg;
	char buf[THREADS_BUFF_SIZE];
	int ret;
	size_t count  = block->start;
	
	int bytes_read = 0;
	int bytes_write = 0;

	ret = lseek(block->infd, block->start, SEEK_SET);
	ret = lseek(block->outfd, block->start, SEEK_SET);
	
	while(count < block->end)
	{
		bytes_write = 0;
		bytes_read = read(block->infd, buf, sizeof(buf));

		if(bytes_read > 0)	//读到内容
		{
			count += bytes_read;
			block->cp += bytes_read;
			char *ptr_wr = buf;

			//将读取的内容写入
			while((bytes_write = write(block->outfd, ptr_wr, bytes_read)) != 0)
			{
				if(-1 == bytes_write){
					printf("write error!\n");
					break;
				}
				if(bytes_read = bytes_write)
				{
					//printf("thread copy OK!\n");
					break;
				}
				else if(bytes_write > 0)
				{
					ptr_wr += bytes_write;
					bytes_read == bytes_write;
				}
			}
		}
	}
}


void * thread_ui(void *arg)
{
	printf("------ui------\n");
	struct thread_block *blocks = (struct thread_block *)arg;
	int sum = 0;
	size_t file_size = get_filesize(blocks[0].infd);  //得到文件大小
	
	int i = 0;
	float rt = 0;

	while(sum < file_size)
	{
		for(i = 0; i<THREADS_COUNT; ++i)
		{
			sum += blocks[i].cp;
		}
		rt = (float)sum/file_size;
		printf("%f\n", rt);
		
		usleep(1000);
	}
	printf("Copy Success!\n");
}

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("args error!\n");
		return -1;
	}

	int i = 0;
	int infd = open(argv[1], O_RDONLY);							//原文件
	int outfd = open(argv[2], O_CREAT | O_WRONLY, 0644);		//目标文件
	if(infd == -1 || outfd == -1)								//文件打开状态是否出错
	{
		printf("open error!\n");
		return -1;
	}
	
	size_t file_size = get_filesize(infd);						//获得文件大小
	size_t thread_size = THREADS_COUNT;							//线程个数
	
	/*申请堆空间供给线程函数使用*/
	struct thread_block *blocks = (struct thread_block *)malloc(sizeof(struct thread_block)*thread_size);
	
	size_t percent = file_size / thread_size;					//每个线程应该拷贝的文件大小

	printf("filesize = %d\t, thread_size = %d \t, percent = %d\n",(int)file_size, (int)thread_size, (int)percent);
	
	/*传入参数赋值*/
	for(; i<thread_size; ++i)
	{
		blocks[i].infd = infd;
		blocks[i].outfd = outfd;
		blocks[i].start = i * percent;
		blocks[i].end = blocks[i].start + percent;
		blocks[i].cp = 0;
	}
	blocks[i].end = file_size;									//最后一个线程的结尾应该是文件大小

	pthread_t tid[thread_size];									
	
	for(i=0; i<thread_size; ++i)								//创建线程
	{
		pthread_create(&tid[i], NULL, thread_copy_fun, &(blocks[i]));
	}


	pthread_t ui_tid;

	pthread_create(&ui_tid, NULL, thread_ui, blocks);

	
	for(i=0; i<thread_size; ++i)								//阻塞等待
	{
		pthread_join(tid[i], NULL);
	}

	pthread_join(ui_tid, NULL);

	free(blocks);												//释放栈空间
	close(infd);												//关闭文件描述符
	close(outfd);

	return 0;
}



