#include "header.h"

void pip_test() {
    int fd[2];
    pipe(fd);
    int fd_write = fd[1];
    int fd_read = fd[0];
    char buffer[1024] = {0};
    if(fork() == 0)
    {
        close(fd_write);
        read(fd_read, buffer, sizeof(buffer));
        printf("%s\n", buffer);
        close(fd_read);
    }else
    {

        close(fd_read);
        sleep(2);
        write(fd_write, "hello", 6);
        close(fd_write);
    }
}
