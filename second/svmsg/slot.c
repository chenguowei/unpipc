//
// Created by chen on 18-3-2.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     i, msgid;

    for (i = 0; i < 10; i++)
    {
        msgid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);
        printf("msgid= %d\n", msgid);
        msgctl(msgid, IPC_RMID, NULL);
    }

    exit(0);
}

