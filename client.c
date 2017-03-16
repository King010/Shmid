#include"comm.h"

int main()
{
	int shmid=get_shm();
	char *buf=shmat(shmid,NULL,0);
	sleep(5);
	int count=0;
	while(count<4096)
	{
		printf("%s\n",buf);
		count++;
		sleep(1);
	}
	shmdt(buf);
	// destory_shm(shmid);
	return 0;
}
