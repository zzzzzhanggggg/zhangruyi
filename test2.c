#include "my.h"

#define NUM_THREADS 4
void hello(void *t)
{
	pthread_t my_tid;
	my_tid=pthread_self();
	printf("\tThread %p:my tid is %lx,Hello world\n",t,my_tid);
}
int main()
{
	pthread_t tid;
	int rv,t;
	for(t=0;t<NUM_THREADS;t++)
	{
		rv=pthread_create(&tid,NULL,(void *(*)())hello,(void*)t);
		if(rv!=0)
		{
			printf("thread create failed\n");
			return -1;
		}
		printf("create thread %lx\n",tid);
	}
	printf("good bye\n");
	pthread_join(tid,NULL);
}
