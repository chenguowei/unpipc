//
// Created by chen on 18-1-16.
//
#include "../unpipc.h"
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char **argv)
{
    int     i, msqid;

    for (i = 0; i < 10; i++)
    {
        msqid = msgget(IPC_PRIVATE,  SVMSG_MODE | IPC_CREAT);
        printf("msqid = %d\n", msqid);

        msgctl(msqid, IPC_RMID, NULL);
    }

    atoi("123");
    msqid = semget(IPC_PRIVATE, i, IPC_CREAT);
    printf("semid = %d\n", msqid);
    semctl(msqid, i, IPC_RMID, NULL);

    exit(0);
}

