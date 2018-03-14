//
// Created by chen on 18-2-10.
//

#include "../unpipc.h"

#define    SEM_NAME    "mysem"

int     count = 0;

int main(int argc, char** argv)
{
    int     i, nloop;
    sem_t   *mutex;

    if (argc != 2)
        err_quit("usage: incrl <#nloop>");
    nloop = atoi(argv[1]);

    mutex = sem_open(SEM_NAME, O_CREAT | O_EXCL, FILE_MODE, 1);
    sem_unlink(SEM_NAME);

    setbuf(stdout, NULL);   // stdout is unbuffered
    if (fork() == 0)
    {
        for (i = 0; i < nloop; i++)
        {
            sem_wait(mutex);
            printf("chld: %d\n", count++);
            sem_post(mutex);
        }
        exit(0);
    }

    for (i = 0; i < nloop; i++)
    {
        sem_wait(mutex);
        printf("parent: %d\n", count++);
        sem_post(mutex);
    }

    exit(0);


}