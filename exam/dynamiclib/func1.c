#include "head.h"

void menu_1();
void func();

void menu1_1()
{
	printf("********************************\n");
	printf("0.返回上一级\n");
	printf("1.创建新文件\n");
	printf("2.写文件\n");
	printf("3.读文件\n");
	printf("4.修改文件权限\n");
	printf("5. 查看当前文件的权限修改文件权限\n");
	printf("********************************\n");
	printf("输入你的选择(0-6):");
}

//创建一个新文件testfile.txt
void createFile1_1()
{
	FILE *fp;
	char buf[1024]="";
	fp=fopen("./testfile.txt","w+");
	if(fp==NULL)
	{
		printf("创建文件失败！\n");
		fclose(fp);
	}
	else
	{
		printf("创建文件成功！\n");
		fclose(fp);
	}
	sleep(1);
	system("reset");
}

//写文件
void writeFile1_1()
{
	FILE *fp;
	char buf[1024]="";
	fp=fopen("./testfile.txt","w+");
	printf("输入文件内容：");
	scanf("%s",buf);
	if(fwrite(buf,sizeof(char),sizeof(buf),fp)==sizeof(buf))
	{	
		printf("写文件成功！\n");
		fclose(fp);
	}
	else
	{	
		printf("写文件失败！\n");
		fclose(fp);
	}
	sleep(1);
	system("reset");
}

//读取文件
void readFile1_1()
{
	FILE *fp;
	char buf[1024]="";
	fp=fopen("./testfile.txt","r");
	if(fread(buf,sizeof(char),sizeof(buf),fp)==sizeof(buf))
	{
		printf("写入到testfile.txt文件中的内容是:%s\n",buf);
		fclose(fp);
	}
	else
	{	
		printf("读取文件失败！\n");
		fclose(fp);
	}
	sleep(1);
	system("reset");
}

//修改文件权限
void updateMode1_1()
{
	int choice1;
	printf("0.返回上一级\n");
	printf("1.将权限修改为：所有者有读取权限\n");
	printf("2.将权限修改为：所有者有写入权限\n");
	printf("3.将权限修改为：所有者有执行权限\n");
	printf("4.将权限修改为：用户组有读取权限\n");
	printf("5.将权限修改为：用户组有写入权限\n");
	printf("6.将权限修改为：用户组有执行权限\n");
	printf("7.将权限修改为：其他用户有读取权限\n");
	printf("8.将权限修改为：其他用户有写入权限\n");
	printf("9.将权限修改为：其他用户有执行权限\n");
	printf("请输入1-9：");
	scanf("%d",&choice1);
	switch(choice1)
	{
		case 0:
			//func();
			break;
		case 1:
			chmod("./testfile.txt",S_IRUSR);
			printf("修改文件权限成功!\n");
			break;
		case 2:
			chmod("./testfile.txt",S_IWUSR);
			printf("修改文件权限成功!\n");
			break;
		case 3:
			chmod("./testfile.txt",S_IXUSR);
			printf("修改文件权限成功!\n");
			break;
		case 4:
			chmod("./testfile.txt",S_IRGRP);
			printf("修改文件权限成功!\n");
			break;
		case 5:
			chmod("./testfile.txt",S_IWGRP);
			printf("修改文件权限成功!\n");
			break;
		case 6:
			chmod("./testfile.txt",S_IWGRP);
			printf("修改文件权限成功!\n");
			break;
		case 7:
			chmod("./testfile.txt",S_IROTH);
			printf("修改文件权限成功!\n");
			break;
		case 8:
			chmod("./testfile.txt",S_IWOTH);
			printf("修改文件权限成功!\n");
			break;
		case 9:
			chmod("./testfile.txt",S_IXOTH);
			printf("修改文件权限成功!\n");
			break;
		default:
			printf("请合法输入！\n");
	}
}
/*
//查看文件权限
void viewMode_1()
{
	char *argv[5]={"ls","-l","./testfile.txt",NULL};
	execv("/bin/ls",argv);
}
*/

void func1()
{
	int choice;
	char *argv[5]={"ls","-l","./testfile.txt",NULL};
	while(1)
	{
		menu1_1();
		scanf("%d",&choice);
		switch(choice)
		{
		case 0:
			func();
			break;
		case 1:
			createFile1_1();
			break;
		case 2:
			writeFile1_1();
			break;
		case 3:
			readFile1_1();
			break;
		case 4:
			//修改文件权限
			updateMode1_1();
			sleep(1);
			system("reset");
			break;
		case 5:
			//查看当前文件的权限修改文件权限
			execv("/bin/ls",argv);
			break;
		}
	}
}

