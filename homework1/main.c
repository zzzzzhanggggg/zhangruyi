#include "head.h"

int main()
{
int a[MAX];
clock_t first,second,third;
urand(a,MAX);
printf("the randam data produced----------\n");
ushow(a,MAX);
first=clock();
sort1(a,MAX);
second=clock();
sort2(a,0,MAX-1);
third=clock();
printf("the time of usort 100 data ----------\n%ld\n\n",(second-first));
printf("the time of qsort 100 data ----------\n%ld\n\n",(third-second));
return 0;
}

