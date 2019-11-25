#include "my.h"

int main()
{
    int pipefd[2];
    if(pipe(pipefd) == -1)
    {
        perror("pipe failed.\n");
        return -1;
    }
    int ret;
    int count = 0;
    int flag = fcntl(pipefd[1],F_GETFL);
    fcntl(pipefd[1],F_SETFL,flag|O_NONBLOCK);
    while(1)
    {
        ret = write(pipefd[1],"1",1);
        if(ret == -1)
        {
            printf("error %s\n",strerror(errno));
            break;
        }
        count++;
    }
    printf("count = %d\n",count);

}

