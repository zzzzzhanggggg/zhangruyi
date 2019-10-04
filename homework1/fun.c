#include "head.h"

void ushow(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}

void urand(int *a,int n){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++){
		a[i]=(int)(rand()%1000+1);
	}
}

void sort1(int *a,int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void sort2(int *a, int l, int r)
{
    if (l < r)
    {
        int i,j,x;
 
        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while(i < j && a[j] > x)
                j--; // 从右向左找第一个小于x的数
            if(i < j){
                //a[i++] = a[j];
                a[i] = a[j];
                i++;
            }
            while(i < j && a[i] < x)
                i++; // 从左向右找第一个大于x的数
            if(i < j){
                a[j] = a[i];
                j--;
            }
        }
        a[i] = x;
        sort2(a, l, i-1); /* 递归调用 */
        sort2(a, i+1, r); /* 递归调用 */
    }
}

