//
// Created by chen on 18-1-23.
//

#include "../unpipc.h"

int main(int argc, char **argv)
{
    printf("MQ_OPEN_MAX = %ld, MQ_PRIO_MAX = %ld\n", sysconf(_SC_MQ_OPEN_MAX),
        sysconf(_SC_MQ_PRIO_MAX));

    exit(0);
}

