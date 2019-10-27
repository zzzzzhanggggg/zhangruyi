#include "head.h"
void menu_1()
{
	printf("********************************\n");
	printf("0.退出\n");
	printf("1.使用标准io\n");
	printf("2.使用系统io\n");
	printf("********************************\n");
	printf("输入你的选择(0-2):");
}
void func()
{
	int choice;
	menu_1();
	scanf("%d",&choice);
	switch(choice)
	{
		case 0:
			exit(0);
			break;
		case 1:
			func1();
			break;
		case 2:
			func2();
			break;
	}
}
