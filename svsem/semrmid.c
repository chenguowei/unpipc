//
// Created by chen on 18-2-7.
//

#include "../unpipc.h"

int main(int argc, char** argv)
{
    int     semid;

    if (argc != 2)
        err_quit("usage: semrmid <pathname>");

    semid = semget(ftok(argv[1], 0), 0, 0);
    semctl(semid,0, IPC_RMID);

    exit(0);
}

