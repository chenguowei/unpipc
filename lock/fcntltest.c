//
// Created by chen on 18-1-29.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("hello.txt", O_RDWR | O_CREAT, 0777);
    if (fd > 0)
    {
        struct flock lock;
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len = 0;
        lock.l_pid = getpid();
        int rd = fcntl(fd, F_SETLK, &lock);
        printf("return value of lock = %d\n", rd);
        while (1)
            rd++;
    }

    return 0;
}

