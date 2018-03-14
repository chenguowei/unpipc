//
// Created by chen on 18-3-2.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    struct stat stat1;

    if (argc != 2)
        err_quit("usage: ftok <pathname>");

    stat(argv[1], &stat1);
    printf("st_dev: %lx, st_ino: %lx, key: %x\n",
           (u_long)stat1.st_dev, (u_long)stat1.st_ino, ftok(argv[1], 0x57));

    exit(0);
}

