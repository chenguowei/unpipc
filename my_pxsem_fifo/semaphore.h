//
// Created by chen on 18-2-6.
//

#ifndef UNPIPC_SEMAPHORE_H
#define UNPIPC_SEMAPHORE_H

typedef struct
{
    int     sem_fd[2];
    int     sem_magic;
}sem_t;

#define SEM_MAGIC   0x89674523

#ifdef SEM_FAILED
#undef SEM_FAILED
#define SEM_FAILD ((sem_t *)(-1))
#endif

#endif //UNPIPC_SEMAPHORE_H
