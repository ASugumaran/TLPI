/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : store_shm.c                             */         
/*  Description  : System V Shared memory [ Storing ]      */
/*  Date         : 19-05-2020                              */
/***********************************************************/

#include "sys_v_shm.h"

int main()
{
	char string[100]="i am data from shared memory\n";
	int shmid;
	char *data;

	shmid = shmget(1000, 100, IPC_CREAT | 0664);
	perror("shmget ");

	data = shmat(shmid, NULL, 0);
	perror("shmat");

	strcpy(data,string);
	perror("strcpy");

	shmdt(data);
	perror("shmat");

}
