//
// Created by chen on 18-1-27.
//


#include "../unpipc.h"
#include "pthread_rwlock.h"

int pthread_rwlock_tryrwlock(pthread_rwlock_t *rw)
{
    int     result;

    if (rw->rw_magic != RW_MAGIX)
        return EINVAL;

    if ( (result = pthread_mutex_lock(&rw->rw_mutex)) != 0)
        return result;

    if (rw->rw_refcount != 0)
        return EBUSY;
    else
        rw->rw_refcount = -1;

    pthread_mutex_unlock(&rw->rw_mutex);

    return result;
}
