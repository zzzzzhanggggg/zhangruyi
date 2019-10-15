#include "dylib.h"
#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
int main()
{
	void *hd;
	char *error;
	void(*f1)(),(*f2)();
	int(*f3)(),(*f4)();
	hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1=dlsym(hd,"init");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2=dlsym(hd,"show");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f3=dlsym(hd,"max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f4=dlsym(hd,"sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	int a[5];
	f1(a,5);
	f2(a,5);
	printf("max=%d\n",f3(a,5));
	printf("sum=%d\n",f4(a,5));
	if(dlclose(hd)<0)
	{
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	return 0;
}
