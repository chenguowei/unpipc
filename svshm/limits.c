//
// Created by chen on 18-2-26.
//

#include "../unpipc.h"

#define MAX_NIDS    4096

int main(int argc, char **argv)
{
    int     i, j, shmid[MAX_NIDS];
    void    *addr[MAX_NIDS];
    unsigned long size;

    for (i = 0; i <= MAX_NIDS; i++)
    {
        shmid[i] = shmget(IPC_PRIVATE, 1024, SVSHM_MODE | IPC_CREAT);
        if (shmid[i] == -1)
        {
            printf("%d identifiers open at once\n", i);
            break;
        }
    }

    for (j = 0; j < i; j++)
        shmctl(shmid[j], IPC_RMID, NULL);

    /* now see how many we can attach*/
    for (i = 0; i <= MAX_NIDS; i++)
    {
        shmid[i] = shmget(IPC_PRIVATE, 1024, SVSHM_MODE | IPC_CREAT);
        addr[i] = shmat(shmid[i], NULL, 0);
        if (addr[i] == (void *)-1)
        {
            printf("%d shared memory segments attached at once\n", i);
            shmctl(shmid[i], IPC_RMID, NULL);
            break;
        }
    }

    for (j = 0; j < i; j++)
    {
        shmdt(addr[j]);
        shmctl(shmid[j], IPC_RMID, NULL);
    }


    /* see how small a shared memory segment we can create*/
    for (size = 1; ; size++)
    {
        shmid[0] = shmget(IPC_PRIVATE, size, SVSHM_MODE | IPC_CREAT);
        if (shmid[0] != -1)
        {
            printf("mininum size of shared memory segment = %lu\n", size);
            shmctl(shmid[0], IPC_RMID, NULL);
            break;
        }
    }


    /* see how large a shared memory segment we can create*/
    for (size = 65536; ; size += 4096)
    {
        shmid[0] = shmget(IPC_PRIVATE, size, SVSHM_MODE|IPC_CREAT);
        if (shmid[0] == -1)
        {
            printf("maximun size of shared memory segment = %lu\n", size - 4096);
            break;
        }
        shmctl(shmid[0], IPC_RMID, NULL);
    }

    exit(0);
}

