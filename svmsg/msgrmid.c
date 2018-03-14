//
// Created by chen on 18-1-23.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     mqid;

    if (argc != 2)
        err_quit("usage : msgrmid <pathname>");

    mqid = msgget(ftok(argv[1], 0), 0);
    msgctl(mqid, IPC_RMID, NULL);

    exit(0);
}


