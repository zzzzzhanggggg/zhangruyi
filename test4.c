#include "my.h"
int main()
{
	int pid1,pid2;
	if((pid1=fork())<0)
	{
		perror("failed to fork1\n");
	}
	if((pid2=fork())<0)
	{
		perror("failed to fork2\n");
	}
	if(pid1==0)
	{
		printf("%d:child1 is running now\n",getpid());
		//getchar();
		//while(1);
		printf("%d:child1 is exit now\n",getpid());
		exit(0);
	}
	if(pid2==0)
	{
		printf("%d:child2 is running now\n",getpid());
		//getchar();
		//while(1);
		printf("%d:child2 is exit now\n",getpid());
		exit(0);
	}
	if(pid1>0) 
	{
		printf("%d:parent is running now\n",getpid());
		//wait(&pid1);
		//while(1);
		//printf("%d:parent is waiting zombie1 now\n",getpid());
	}
	if(pid2>0) 
	{
		printf("%d:parent is waiting zombie2 now\n",getpid());
		wait(&pid2);
		while(1);
		printf("%d:parent is waiting zombie2 now\n",getpid());
	}
	exit(0);
}
