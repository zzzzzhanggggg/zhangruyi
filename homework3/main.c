#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//feof ferror bzero
//用fread和fwrite把一个文件拷贝到另外一个文件
int main(int argc,char *argv[])
{  
    FILE *read_fp,*write_fp;

    if(argc !=3)
    {
        printf("usage %s <filename1> <filename2>\n",argv[0]);
        exit(1);
    } 

    read_fp = fopen(argv[1],"r");//分别打开
    if(read_fp == NULL)
    {
        perror("1fopen");
        exit(1);
    }

    write_fp = fopen(argv[2],"w");//分别打开
    if(write_fp == NULL)
    {
        perror("2fopen");
        exit(1);
    }
    int ret;
    char buf[20];
    while( !feof(read_fp) && !ferror(read_fp))//没有到文件末尾并且没有出错
    {  
        //bzero(buf,20);//清空
        ret = fread(buf,sizeof(char),20,read_fp);//fread返回值是读取的数量，必须要有fread
        fwrite(buf,sizeof(char),ret,write_fp);       
        fwrite(buf,sizeof(char),ret,stdout);    //标准输出   
    }

    fclose(read_fp);
    fclose(write_fp);

    return 0;
}

