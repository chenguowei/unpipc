//
// Created by chen on 18-3-7.
//

#include "../unpipc.h"

void server(int readfd, int writefd)
{
    int fd;
    ssize_t n;
    char buf[MAXLINE - 1];

    // read pathname from IPC channel
    if ( (n = read(readfd, buf, MAXLINE)) == 0)
        err_quit("end-of-file while reading pathname");
    buf[n] = '\0';

    if ( (fd = open(buf, O_RDONLY)) < 0)
    {
        snprintf(buf + n, sizeof (buf), ": can't open, %s\n", strerror(errno));
        n = strlen(buf);
        write(writefd, buf, n);
    } else
    {
        while ( (n = read(fd, buf, MAXLINE)) > 0)
        {
            write(writefd, buf, n);
        }
        close(fd);
    }
}

