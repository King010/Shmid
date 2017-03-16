#include"comm.h"
static int comm_shm(int size,int flags)
{
	key_t key=ftok(PATHNAME,PROJ_ID);
	if(key<0){
	perror("ftok");
	return -1;
	}
	int shmid=shmget(key,size,flags);
	if(shmid<0)
	{
		perror("shmget");
		return -2;
	}
	return shmid;
}
int get_shm()
{
	return comm_shm(0,IPC_CREAT);
}

int create_shm(int size)
{
	return comm_shm(size,IPC_CREAT|IPC_EXCL|0666);
}

int destory_shm(int shmid)
{
	return shmctl(shmid,IPC_RMID,NULL);
}


