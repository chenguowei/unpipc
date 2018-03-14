//
// Created by chen on 18-1-25.
//

#include "../unpipc.h"

#define MAXNITENS      1000000
#define MAXNTHREADS     100

int nitems;
int buff[MAXNITENS];

void *prodece(void *arg);
void *consume(void *arg);

struct
{
    pthread_mutex_t     mutex;
    int nput;
    int nval;
} put = {
        PTHREAD_MUTEX_INITIALIZER
};

struct
{
    pthread_mutex_t     mutex;
    pthread_cond_t      cond;
    int nready;
} nready = {
        PTHREAD_MUTEX_INITIALIZER, PTHREAD_COND_INITIALIZER
};


void *produce(void *arg)
{
    for (; ; )
    {
        pthread_mutex_lock(&put.mutex);
        if (put.nput >= nitems)
        {
            pthread_mutex_unlock(&put.mutex);
            return NULL;
        }

        buff[put.nput] = put.nval;
        put.nput++;
        put.nval++;
        pthread_mutex_unlock(&put.mutex);

        pthread_mutex_lock(&nready.mutex);
        if (nready.nready == 0)
            pthread_cond_signal(&nready.cond);
        nready.nready++;
        pthread_mutex_unlock(&nready.mutex);

        *((int *) arg) += 1;
    }

}

void *consume(void *arg)
{
    int     i;

    for (i = 0; i < nitems; i++)
    {
        pthread_mutex_lock(&nready.mutex);
        while (nready.nready == 0)
            pthread_cond_wait(&nready.cond, &nready.mutex);

        nready.nready--;
        pthread_mutex_unlock(&nready.mutex);

        if (buff[i] != i)
            printf("buff[%d] = %d\n",  i, buff[i]);
    }

    return NULL;
}
