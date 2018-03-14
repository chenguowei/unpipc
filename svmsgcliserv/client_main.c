//
// Created by chen on 18-1-24.
//

#include "svmsg.h"

void client(int, int);

int main(int argc, char **argv)
{
    int     readid, writeid;

    writeid = msgget(MQ_KEY1, 0);
    readid = msgget(MQ_KEY2, 0);

    client(readid, writeid);

    /* now we can delete the queues */
    msgctl(readid, IPC_RMID, NULL);
    msgctl(writeid, IPC_RMID, NULL);

    exit(0);
}

