//
// Created by chen on 18-2-5.
//


#include "../unpipc.h"

#define NBUFF 10

int nitems;
struct {
    int     buff[NBUFF];
    sem mutex, nempty, nstored;
}shared;

void* produce(void*);
void* consume(void*);

int main(int argc, char **argv)
{
    pthread_t tid_produce, tid_consume;

    if (argc != 2)
        err_quit("usage: prodcons2 <#items>");
    nitems = atoi(argv[1]);

    sem_init(&shared.mutex, 0, 1);
    sem_init(&shared.nempty, 0, NBUFF);
    sem_init(&shared.nstored, 0, 0);

    pthread_create(&tid_produce, NULL, produce, NULL);
    pthread_create(&tid_consume, NULL, consume, NULL);

    pthread_join(tid_produce, NULL);
    pthread_join(tid_consume, NULL);

    sem_destroy(&shared.mutex);
    sem_destroy(&shared.nempty);
    sem_destroy(&shared.nstored);

    exit(0);
}


void* produce(void *arg)
{
    int i;

    for(i = 0; i < nitems; i++)
    {
        sem_wait(&shared.nempty);
        sem_wait(&shared.mutex);
        shared.buff[i % NBUFF] = i;
        sem_post(&shared.mutex);
        sem_post(&shared.nstored);
    }
    return NULL;
}

void* consume(void *arg)
{
    int i;

    for(i = 0; i < nitems; i++)
    {
        sem_wait(&shared.nstored);
        sem_wait(&shared.mutex);
        if (shared.buff[i % NBUFF] != i)
            printf("buff[%d] = %d\n", i, shared.buff[i % NBUFF]);
        sem_post(&shared.mutex);
        sem_post(&shared.nempty);
    }

    return NULL;
}

