//
// Created by chen on 18-3-7.
//

#include "../unpipc.h"

#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"

void client(int, int);
void server(int, int);

int main(int argc, char **argv)
{
    int     readfd, writefd;
    pid_t   childpid;

    // create two fifos; OK if they already exist;
    if (mkfifo(FIFO1, FILE_MODE) < 0 && (errno != EEXIST))
        err_sys("can't create %s", FIFO1);
    if ( (mkfifo(FIFO2, FILE_MODE) < 0) && (errno != EEXIST))
    {
        unlink(FIFO1);
        err_sys("can't create %s", FIFO2);
    }

    if ( (childpid = fork()) == 0)
    {
        readfd = open(FIFO1, O_RDONLY, 0);
        writefd = open(FIFO2, O_WRONLY, 0);

        server(readfd, writefd);
        exit(0);
    }

    // parent
    //readfd = open(FIFO2, O_RDONLY, 0);
    writefd = open(FIFO1, O_WRONLY, 0);
    readfd = open(FIFO2, O_RDONLY, 0);

    client(readfd, writefd);

    waitpid(childpid, NULL, 0);

    close(readfd);
    close(writefd);

    unlink(FIFO1);
    unlink(FIFO2);

    exit(0);
}

