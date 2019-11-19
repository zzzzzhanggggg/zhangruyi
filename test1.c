#include "my.h"
int main()
{
	int pid;
	if((pid=fork())<0)
	{
		perror("failed to fork\n");
	}
	else if(pid==0)
	{
		printf("%d:child is exit now\n",getpid());
	}
	else
	{
		printf("%d:parent is running",getpid());
		while(1);
	}
	exit(0);
}
