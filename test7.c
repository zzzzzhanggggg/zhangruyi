#include"my.h"
int main()
{
	FILE *fp;
	int pid1,pid2,status1,status2;
	if((fp=fopen("out.dat","w+")) == NULL)
	{
		printf("Create failed!\n");
		exit(1);
	}
	
	else if((pid1=fork())&&(pid2=fork()) < 0)
	{
		perror("fork failed!\n");
	}
	else if(pid1 == 0)
	{
		printf("%d: child1 running\n",getpid());
		fwrite("123456789",strlen("123456789"),1,fp);
		exit(120);
	}
	else if(pid2 == 0)
	{
		printf("%d: child2 running\n",getpid());
		fwrite("123456789",strlen("123456789"),1,fp);
		exit(130);
	}
	else
	{
		printf("%d:parent is exiting now\n",getpid());
		printf("%d:parent is waiting zombie now\n",getpid());
		wait(&status2);
		if(WEXITSTATUS(status2))
		{
			printf("child2 %d is exiting normally.exit code=%d\n",pid2,WEXITSTATUS(status2));
		}
		wait(&status1);
		if(WEXITSTATUS(status1))
		{
			printf("child1 %d is exiting normally.exit code=%d\n",pid1,WEXITSTATUS(status1));
		}

		printf("parent finished!\n");
	}
	fclose(fp);
	return 0;
}

