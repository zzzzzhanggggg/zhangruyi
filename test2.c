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
		printf("%d:child is running now\n",getpid());
		//getchar();
		//while(1);
		printf("%d:child is exit now\n",getpid());
		exit(0);
	}
	else
	{
		printf("%d:parent is waiting zombie now\n",getpid());
		//wait(NULL);
		while(1);
		//sleep(2);
		printf("%d:parent is exit now\n",getpid());

	}
	exit(0);
}
