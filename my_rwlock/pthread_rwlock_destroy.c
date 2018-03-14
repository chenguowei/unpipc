//
// Created by chen on 18-1-27.
//

#include "../unpipc.h"
#include "pthread_rwlock.h"

int pthread_rwlock_destroy(pthread_rwlock_t *rw)
{
    if (rw->rw_magic != RW_MAGIX)
        return (EINVAL);

    if (rw->rw_refcount != 0 ||
        rw->rw_nwaitreaders != 0 || rw->rw_nwaitwriters != 0)
        return EBUSY;

    pthread_mutex_destroy(&rw->rw_mutex);
    pthread_cond_destroy(&rw->rw_condreaders);
    pthread_cond_destory(&rw->rw_condwriters);
    rw->rw_magic = 0;

    return 0;
}

