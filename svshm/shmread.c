//
// Created by chen on 18-2-26.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     i, id;
    struct shmid_ds buff;
    unsigned char c, *ptr;

    if (argc != 2)
        err_quit("usage: shmread <pathname>");

    id = shmget(ftok(argv[1], 0), 0, SVSHM_MODE);
    ptr = shmat(id, NULL, 0);
    shmctl(id, IPC_STAT, &buff);

    for (i = 0; i < buff.shm_segsz; i++)
    {
        if ( (c = *ptr++) != (i % 256))
            err_ret("ptr[%d] = %d", i, c);
        printf("ptr[%d] = %c\n", i, *ptr++);
    }

    exit(0);
}

