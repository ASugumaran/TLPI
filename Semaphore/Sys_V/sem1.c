/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : sem1.c                                  */         
/*  Description  : Locking and unlocking a semaphore       */
/*  Date         : 26-05-2020                              */
/***********************************************************/

#include "semaphore.h"

char str[]="semaphore is in lock\n";
char buff[1024];
int main()
{
	int open_fd;
	ssize_t write_fd,read_fd;
	struct sembuf sem_buf;
	sem_buf.sem_num = 3; /* semaphore number */
	sem_buf.sem_op  = -1; /* semaphore operation */

	int semid;

	//get a System V semaphore set identifier
	//The semget() system call returns the System V semaphore set identifier associated with the argument key.
	semid = semget(93, 5,IPC_CREAT | 0600);
	perror("semget");

	//System V semaphore control operations
	semctl(semid, 3, SETVAL, 2);
	perror("semctl");

	//System V semaphore operations
	semop(semid, &sem_buf, 1); //getting lock
	perror("semop");


	open_fd = open("test.txt",O_CREAT | O_RDONLY, 0644);
	perror("open");

	read_fd = read(open_fd, buff, 1024);
	perror("read");

	close(open_fd);
	perror("close");
	
	for(int i=0; i<10; i++) {
	printf("%s\n",buff);
	sleep(1);
	}

	sem_buf.sem_op = 1;
	semop(semid, &sem_buf, 1);// getting unlock
	perror("semop");
}
