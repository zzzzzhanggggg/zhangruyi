#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(void)
{
    int fd;
    char read_buf[1024];
    char write_buf[32] = "hello world";

    /* lseek后，读取文件 */
    printf("READ:\n");
    fd = open("./test.txt", O_RDWR | O_APPEND|O_CREAT,0644);
    if (fd == -1)
    {
        printf("open failed\n");
        goto EXIT;
    }

    //将文件指针设置在文件开头
    //ret = lseek(fd,3, SEEK_SET);
    if (lseek(fd,3, SEEK_SET) == -1)
    {
        printf("lseek function failed.\n");
        close(fd);
        goto EXIT;
    }
    printf("After lseek position is:%d\n", lseek(fd,3, SEEK_SET));

    //读取文件
    if (read(fd, read_buf, sizeof(read_buf)) == -1)
    {
        printf("read failed\n");
        close(fd);
        goto EXIT;

    }
    //printf("read number of character == %d\n", read(fd, read_buf, sizeof(read_buf)));
    printf("read_buf:%s\n", read_buf);
    close(fd);


    /* lseek后，写入文件 */
    printf("WRITE:\n");
    fd = open("./test.txt", O_RDWR | O_APPEND|O_CREAT,0644);
    if (fd == -1)
    {
        printf("open failed\n");
        goto EXIT;
    }

    //将文件指针设置在文件开头
    if (lseek(fd, 5, SEEK_SET) == -1)
    {
        printf("lseek failed.\n");
        close(fd);
        goto EXIT;
    }
    printf("After lseek position is:%d\n", lseek(fd, 5, SEEK_SET));

    //读取文件
    if (write(fd, write_buf, strlen(write_buf)) == -1)
    {
        printf("write failed\n");
        close(fd);
        goto EXIT;

    }
    printf("write number of character == %d\n", write(fd, write_buf, strlen(write_buf)));
    close(fd);

EXIT:
    return 0;
}

