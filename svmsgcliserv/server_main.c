//
// Created by chen on 18-1-24.
//

#include "svmsg.h"

void server(int, int);

int main(int argc, char **argv)
{
    int     readid, writeid;

    readid = msgget(MQ_KEY1, SVMSG_MODE | IPC_CREAT);
    writeid = msgget(MQ_KEY2, SVMSG_MODE | IPC_CREAT);

    server(readid, writeid);

    exit(0);
}

