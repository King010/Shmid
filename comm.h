#ifndef _COMM_
#define _COMM_

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>


#define PATHNAME "."
#define PROJ_ID 0x6666

int create_shm(int size);
int get_shm();
int destory_shm(int shmid);


#endif
