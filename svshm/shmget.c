//
// Created by chen on 18-2-26.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int c, id, oflag;
    char    *ptr;
    size_t  length;

    oflag = IPC_CREAT | SVSEM_MODE;
    while ( (c = getopt(argc, argv, "e")) != -1)
    {
        switch (c)
        {
            case 'e':
                oflag |= IPC_EXCL;
                break;
        }
    }

    if (optind != argc - 2)
        err_quit("usage: [-e] <pathname> <length>");

    length = atoi(argv[optind + 1]);

    id = shmget(ftok(argv[optind], 0), length, oflag);
    ptr = shmat(id, NULL, 0);

    exit(0);
}
