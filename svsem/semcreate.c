//
// Created by chen on 18-2-7.
//


#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     c, oflag, semid, nsems;

    oflag = SVMSG_MODE | IPC_CREAT;
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
        err_quit("usage: semcreate [-e] <pathname> <nsems>");

    nsems = atoi(argv[optind + 1]);

    semid = semget(ftok(argv[1], 0), nsems, oflag);

    exit(0);
}
