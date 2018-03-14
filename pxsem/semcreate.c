//
// Created by chen on 18-1-31.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     c, flags;
    sem_t   *sem;
    unsigned int value;

    flags = O_CREAT | O_RDWR;
    value = 1;

    while ((c = getopt(argc, argv, "ei:")) != -1)
    {
        switch (c)
        {
            case 'e':
                flags |= O_EXCL;
                break;

            case 'i':
                value = atoi(optarg);
                break;
        }
    }

    if (optind != argc - 1)
        err_quit("usage: semcreate [-e] [-i initalvalue] <name> ");

    sem = sem_open(argv[optind], flags, FILE_MODE, value);

    sem_close(sem);

    exit(0);
}

