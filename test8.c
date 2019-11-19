#include "my.h"
int main()
{
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r,0,sizeof(buf_r));
	if(pipe(pipe_fd)<0)
	{
		printf("创建管道失败\n");
		return -1;
	}
	result=fork();
	if(result<0)
	{
		perror("创建子进程失败\n");
		exit;
	}
	else if(result==0)
	{
		close(pipe_fd[1]);
		if((r_num=read(pipe_fd[0],buf_r,100))>0)
			printf("子进程从管道读取%d个字符，读取的字符串：%s\n",r_num,buf_r);
		close(pipe_fd[0]);
		exit(0);
	}
}
