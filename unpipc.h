//
// Created by chen on 18-1-16.
//

//
// Created by 陈国威 on 2018/1/14.
//

#ifndef UNPIPC_UNPIPC_H
#define UNPIPC_UNPIPC_H

#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

#ifdef HAVE_MQUEUE_H
#include <mqueue.h>
#endif

#include <sys/mman.h>

#include <mqueue.h> /* posix  */

#include <sys/msg.h>

#include <sys/sem.h>

#include <sys/shm.h>

#include <pthread.h>

#include <semaphore.h>

#define	MAXLINE 1024

void err_ret(const char *fmt, ...);

void err_sys(const char *fmt, ...);

void err_dump(const char *fmt, ...);

void err_msg(const char* fmt, ...);

void err_quit(const char* fmt, ...);


#ifndef	PATH_MAX
#define PATH_MAX	1024
#endif

#define MAX_PATH	1024
#define BUFFSIZE	8192

#define MSG_R		0400
#define MSG_W		0200
#define SEM_R		0400
#define SEM_W		0200
#define	SHM_R		0400
#define SHM_W		0200



#define	FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

#define	DIR_MODE	(FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

#define	SVMSG_MODE	(MSG_R | MSG_W | MSG_R >> 3| MSG_R >> 6)

#define SVSEM_MODE	(SEM_R | SEM_W | SEM_R >> 3 | SEM_R >> 6)

#define SVSHM_MODE  (SHM_R | SHM_W | SHM_R >> 3 | SEM_R >> 6)

struct msgbuf
{
    long mtype;
    char mtext[1];
};

union semun
{
    int             val;
    struct semid_ds *buf;
    ushort          *array;
};


#endif //UNPIPC_UNPIPC_H
