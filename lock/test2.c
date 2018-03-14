//
// Created by chen on 18-1-29.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    int     fd;

    fd = open("test1.data", O_RDWR | O_CREAT, FILE_MODE);

    read_lock(fd, 0, SEEK_SET, 0);
    printf("%s: parent has read lock\n", Gf_time());

    if (fork() == 0)
    {
        sleep(1);
        printf("%s; first child tries to obtain write lock\n", Gf_time());
        writew_lock(fd, 0, SEEK_SET, 0);
        printf("%s, first chid obtains write lock\n", Gf_time());
        sleep(2);
        un_lock(fd, 0, SEEK_SET, 0);
        printf("%s: first child releases write lock\n", Gf_time());
        exit(0);
    }

    if (fork() == 0)
    {

    }
}

