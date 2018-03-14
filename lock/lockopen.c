//
// Created by chen on 18-1-29.
//

#include "../unpipc.h"

#define LOCKFILE    "/tmp/seqno.lock"

void my_lock(int fd)
{
    int     tempfd;

    while ( (tempfd = open(LOCKFILE, O_CREAT | O_RDWR | O_EXCL, FILE_MODE)) < 0)
    {
        if (errno != EEXIST)
            err_sys("open error for lock file");
        /* someone else has the lock, loop around and try again*/
    }

    close(tempfd);
}

void un_lock(int fd)
{
    unlink(LOCKFILE);
}

