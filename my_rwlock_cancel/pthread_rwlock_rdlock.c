//
// Created by chen on 18-1-27.
//

#include "../my_rwlock/pthread_rwlock.h"
#include "../unpipc.h"

static void rwlock_cancelrdwait(void *arg)
{
    pthread_rwlock_t    *rw;

    rw = arg;
    rw->rw_nwaitreaders--;
    pthread_mutex_unlock(&rw->rw_mutex);
}

