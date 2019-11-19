#include "my.h"
int main()
{
	pid_t pid1,pid2;
	FILE *fp;
	fp=fopen("out.dat","w+");
	pid1=fork();
	pid2=fork();	
	if(pid1<0||pid2<0)
	{
		perror("fork error!");
	}
	else if(pid1=0)
	{
		sleep(2);
        fwrite("pid1:0123456789",1,strlen("pid1:0123456789"),fp);
		exit(0);
	}
	else if(pid2=0)
	{
		sleep(2);
        fwrite("pid2:0123456789",1,strlen("pid2:0123456789"),fp);
		exit(0);
	}
	else
	{
		int status=0;
		wait(&status);
		if(WIFEXITED(status))
		{
            printf("child process return %d\n",WEXITSTATUS(status));
        }
	}
}
