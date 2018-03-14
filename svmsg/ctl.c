//
// Created by chen on 18-1-23.
//

#include "../unpipc.h"

struct msgbuf
{
    long mtype;
    char mtext[1];
};

int main(int argc, char **argv)
{
    int     msqid;
    struct msqid_ds info;
    struct msgbuf   buff;

    msqid = msgget(IPC_PRIVATE, SVMSG_MODE | IPC_CREAT);

    buff.mtype = 1;
    buff.mtext[0] = 1;

    msgsnd(msqid, (void *)&buff, sizeof(buff), 0);

    msgctl(msqid, IPC_STAT, &info);

    printf("read-write: %03o, cbytes = %lu, qnum = %lu, qbytes = %lu\n",
        info.msg_perm.mode & 0777, (ulong) info.__msg_cbytes,
           (ulong) info.msg_qnum, (ulong) info.msg_qbytes);

    system("ipcs -q");

    msgctl(msqid, IPC_RMID, NULL);

    exit(0);
}

