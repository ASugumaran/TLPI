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
	sem_buf.sem_num = 3;
	sem_buf.sem_op  = -1;

	int semid;
        //get a System V semaphore set identifier
	semid = semget(93, 5,IPC_CREAT | 0600);
	perror("semget");

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
	semop(semid, &sem_buf, 1);
	perror("semop");
}
