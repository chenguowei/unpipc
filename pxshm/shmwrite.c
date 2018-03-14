//
// Created by chen on 18-2-11.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     i, fd;
    struct stat stat1;
    unsigned char *ptr;

    if (argc != 2)
        err_quit("usage: shmwrite <name>");

    fd = sem_open(argv[1], O_RDWR, FILE_MODE);
    fstat(fd, &stat1);
    ptr = mmap(NULL, stat1.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    close(fd);

    for (i = 0; i < stat1.st_size; i++)
    {
        *ptr++ = i % 256;
    }

    exit(0);
}

