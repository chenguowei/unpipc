//
// Created by chen on 18-1-31.
//


#include "../unpipc.h"

int main(int argc, char **argv)
{
    sem_t   *sem;
    int      val;

    if (argc != 2)
        err_quit("ussage: semwait <name>");

    sem = sem_open(argv[1], 0);
    sem_wait(sem);
    sem_getvalue(sem, &val);
    printf("pid %ld has semaphore, value = %d\n", (long)getpid(), val);

    pause();
    exit(0);
}
