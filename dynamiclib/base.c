#include <stdio.h>
#include <time.h>
#include <dylib.h>
void show(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%4d : %4d\n",i,a[i]);
}
void init(int *a,int n)
{
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
		a[i]=(int)(rand()%1000+1);
	}
}
