//
// Created by chen on 18-2-7.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     semid, nsems, i;
    struct semid_ds seminfo;
    unsigned short  *ptr;
    union semun arg;

    if (argc < 2)
        err_quit("usage: semsetvalues <pathname> [values ..]");

    semid = semget(ftok(argv[1], 0), 0, 0);
    arg.buf = &seminfo;
    semctl(semid, 0, IPC_STAT, arg);
    nsems = arg.buf->sem_nsems;

    if (argc != nsems + 2)
        err_quit("%d semaphores in set, %d values specified", nsems, argc-2);

    ptr = calloc(nsems, sizeof(unsigned short));
    arg.array = ptr;
    for (i = 0; i < nsems; ++i) {
       ptr[i] = atoi(argv[i+2]) ;
    }

    semctl(semid, 0, SETALL, arg);

    exit(0);
}

