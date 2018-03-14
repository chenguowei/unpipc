//
// Created by chen on 18-1-24.
//

#ifndef UNPIPC_MESG_H
#define UNPIPC_MESG_H

#include "../unpipc.h"

#define MY_DATA 8

struct mymesg
{
    long mesg_type;
    long mesg_len;
    char mesg_data[MY_DATA];
};

void client(int, int);
void server(int, int);

ssize_t mesg_send(int writefd, struct mymesg *mptr)
{
    msgsnd(writefd, &(mptr->mesg_type), mptr->mesg_len, mptr->mesg_type);
}

ssize_t mesg_recv(int readfd, struct mymesg *mptr)
{
    ssize_t n;

    n = msgrcv(readfd, &(mptr->mesg_type), MAXMESGDATA, mptr->mesg_type, 0);
    mptr->mesg_len = n;

    return n;
}

#endif //UNPIPC_MESG_H
