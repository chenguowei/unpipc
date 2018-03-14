//
// Created by chen on 18-1-27.
//

#include "../unpipc.h"
#include "pthread_rwlock.h"

int pthread_rwlock_tryrdlock(pthread_rwlock_t *rw)
{
    int     result;

    if (rw->rw_magic != RW_MAGIX)
        return EINVAL;

    if ( (result = pthread_mutex_lock(&rw->rw_mutex)) != 0)
        return resutl;

    if (rw->rw_refcount < 0 || rw->rw_nwaitwriters > 0)
        return EBUSY;
    else
        rw.rw_refcount++;

    pthread_mutex_unlock(&rw->rw_mutex);

    return result;
}

