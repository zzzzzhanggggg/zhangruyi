#include "my.h"

int main()
{
	printf("pid=%d,signo=%d,times=%d\n",pid,signo,times);
	for(i=0;i<times;i++)
	{
		if(kill(pid,signo)==-1)
		{
			fprintf(stderr,"sned signo(%d) to pid(%d) failed,reason(%s)\n",signo,pid,strerror(errno));
			return -3;
		}
	}
}
