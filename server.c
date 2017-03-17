#include"comm.h"

int main()
{
	int shmid=create_shm(4096);
	char *buf=shmat(shmid,NULL,0);
	sleep(5);
	int count=0;
	while(count<4096)
	{
		buf[count]='A'+count%26;
		count++;
		buf[count]=0;
		sleep(1);
	}
	shmdt(buf);
	destory_shm(shmid);
	return 0;
}
