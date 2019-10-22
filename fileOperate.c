#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int fd;
	char buf[1024]="this is writed into testfile.txt";
	int choice;
	char *argv[5]={"ls","-l","./testfile.txt",NULL};
	while(1)
	{
		printf("********************************\n");
		printf("0.退出\n");
		printf("1.创建新文件\n");
		printf("2.写文件\n");
		printf("3.读文件\n");
		printf("4.修改文件权限\n");
		printf("5. 查看当前文件的权限修改文件权限\n");
		printf("********************************\n");
		printf("Please input your choice(0-6):");
		scanf("%d",&choice);
		switch(choice)
		{
		case 0:
			close(fd);exit(0);
		case 1:
			//创建一个新文件testfile.txt
			fd=open("./testfile.txt",O_RDWR|O_TRUNC|O_CREAT,0644);
			if (fd == -1)
			{
				perror("open file:\n");
				exit(1);
			}
			break;
		case 2:
			//写文件
			if (write(fd,buf,strlen(buf)) == -1)
			{
				perror("write file:\n");
				exit(1);
			}
			break;
		case 3:
			//读取文件
			if (read(fd,buf,sizeof(buf)) == -1)
			{
				perror("read file:\n");
				exit(1);
			} 
			printf("the content of testfile is:%s\n",buf);
			break;
		case 4:
			//修改文件权限
			chmod("./testfile.txt",0777);
			printf("change mode success!\n");
			break;
		case 5:
			//查看当前文件的权限修改文件权限
			execv("/bin/ls",argv);
			break;
		}
	}
	return 0;
}
