#include "my.h"

void sig(int signo,siginfo_t *info,void *context)
{
	printf("\nget signal:%d\n",signo);
	printf("signal number si %d\n",info->si_signo);
	printf("pid=%d\n",info->si_pid);
	printf("signal=%d\n",info->si_value.sival_int);
}

int main()
{
	struct sigaction new;
	sigemptyset(&new.sa_mask);
	new.sa_sigaction=sig;
	new.sa_flags|=SA_SIGINFO|SA_RESTART;
	if(sigaction(36,&new,NULL)==-1)
	{
		perror("set signal process node.\n");
	}
	while(1)
		pause();
	printf("Done.\n");
	exit(0);
}
