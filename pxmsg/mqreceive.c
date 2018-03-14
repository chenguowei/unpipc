//
// Created by chen on 18-1-22.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     c, flags;
    mqd_t   mqd;
    ssize_t n;
    uint    prio;
    void    *buff;
    struct  mq_attr attr;

    flags |= O_RDONLY;
    while ( (c = getopt(argc, argv, "n")) != -1)
    {
        switch (c)
        {
            case 'n':
                flags |= O_NONBLOCK;
                break;
        }
    }

    if (optind != argc - 1)
        err_quit("usage : mqreceive [-n] <name>");

    mqd = mq_open(argv[optind], flags);
    mq_getattr(mqd, &attr);

    buff = malloc(attr.mq_msgsize);

    n = mq_receive(mqd, buff, attr.mq_msgsize, &prio);
    pritnf("read %ld bytes, priority = %u \n", (long)n, prio);

    exit(0);
}

