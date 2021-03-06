//
// Created by chen on 18-3-7.
//
#include "../unpipc.h"

int main(int argc, char **argv)
{
    size_t n;
    char buff[MAXLINE], command[MAXLINE];
    FILE *fp;

    // read pathname
    fgets(buff, MAXLINE, stdin);
    n = strlen(buff);
    if (buff[n - 1] == '\n')
        n--;

    snprintf(command, sizeof(command), "cat %s", buff);
    fp = popen(command, "r");

    //copy from pipe to standard output
    while (fgets(buff, MAXLINE, fp) != NULL)
        fputs(buff, stdout);

    pclose(fp);
    exit(0);
}

