//
// Created by chen on 18-1-23.
//

#include "../unpipc.h"

#ifndef __USR_GNU
#define __USR_GNU
#endif

int main(int argc, char **argv)
{
    int     mqid;
    size_t  len;
    long    type;
    struct msgbuf   *ptr;

    if (argc != 4)
        err_quit("usage : msgsnd <pathname> <#bytes> <type>");

    len = atoi(argv[2]);
    type = atoi(argv[3]);

    mqid = msgget(ftok(argv[1], 0), MSG_W);

    ptr = calloc(sizeof(long)+len, sizeof(char));
    ptr->mtype = type;

    msgsnd(mqid, ptr, len, 0);

    exit(0);
}

