//
// Created by chen on 18-2-7.
//
#include "../unpipc.h"

int main(int argc, char** argv)
{
    int     semid, nsems, i;

    struct semid_ds seminfo;
    unsigned short  *ptr;
    union   semun   arg;

    if (argc != 2)
        err_quit("usage: semgetvalues <pathname>");

    semid = semget(ftok(argv[1], 0), 0, 0);
    arg.buf = &seminfo;
    semctl(semid, 0, IPC_STAT, arg);
    nsems = arg.buf->sem_nsems;

    ptr = calloc(nsems, sizeof(unsigned short));
    arg.array = ptr;

    semctl(semid, 0, GETALL, arg);
    for (i = 0; i < nsems; i++)
    {
        printf("semval[%d] = %d\n", i, ptr[i]);
    }

    exit(0);
}

