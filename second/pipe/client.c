//
// Created by chen on 18-3-7.
//

#include "../unpipc.h"

void client(int readfd, int writefd)
{
    size_t len;
    ssize_t n;
    char    buff[MAXLINE];

    fgets(buff, MAXLINE, stdin);
    len = strlen(buff);

    if (buff[len - 1] == '\n')
        len--;              //delete newline from fgets

    //write pathname to IPC channel
    write(writefd, buff, len);

    //read from IPC ,write to standard output
    while ( (n = read(readfd, buff, MAXLINE)) > 0)
    {
        write(STDOUT_FILENO, buff, n);
    }


}

