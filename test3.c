#include "my.h"
int main()
{
	pid_t p1,p2,p3;
	int count;
	p1=fork();
	p2=fork();
	p3=fork();	
	if(p1<0||p2<0||p3<0)
	{
		perror("fork failed.\n");
		return -1;
	}
	else if(p1==0)
	{
		count+=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(0);
	}
	else if(p2==0)
	{
		count+=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(0);
	}
	else if(p3==0)
	{
		count+=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(0);
	}
	else
	{
		printf("parent sleeping\n");
		sleep(2);
		printf("parent pid=%d,count=%d\n",getpid(),count);
		return 0;
	}
}
