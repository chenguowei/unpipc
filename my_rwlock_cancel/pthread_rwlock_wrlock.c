//
// Created by chen on 18-1-27.
//



#include <pthread.h>
#include "../my_rwlock/pthread_rwlock.h"

static void rwlock_cannelwrwait(void *arg)
{
    pthread_rwlock_t *rw;

    rw = (pthread_rwlock_t *)arg;
    rw->rw_nwaitwriters--;
    pthread_mutex_unlock(&rw->rw_mutex);
}

