//
// Created by chen on 18-1-22.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    mqd_t   mqd;
    void    *ptr;
    size_t  len;
    uint    prio;

    if (argc != 4)
        err_quit("usage: mqsend <name> <#bytes> <priority>");

    len = atoi(argv[2]);
    prio = atoi(argv[3]);

    ptr = calloc(len, sizeof(char));
    mq_send(mqd, ptr, len, prio);

    exit(0);
}

