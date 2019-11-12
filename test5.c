#include "my.h"
static void callback1()
{
	printf("----------callback1----------\n");
}
static void callback2()
{
	printf("\n----------callback2----------\n");
}
static void _attribute_((constructor)) before_main()
{
	printf("----------constructot----------\n");
}
static void _attribute_((destructor)) after_main()
{
	printf("\n----------destructor----------\n");
}
int main()
{
	atexit(callback1);
	atexit(callback2);
	FILE *fp;
	char buf[]={"test data from full buffer!\n"};
	if((fp=fopen("test.bat","w+"))==NULL)
	{
		perror("failed to open\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("failed to fputs\n");
		return -1;
	}
	printf("printf:data from line buffer\n");
	//exit(0);
	_exit(0);
	//return 0;
}
