//
// Created by chen on 18-1-22.
//
#include "../unpipc.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        err_quit("usage: mqunlink <name>");

    mq_unlink(argv[1]);

    exit(0);
}

