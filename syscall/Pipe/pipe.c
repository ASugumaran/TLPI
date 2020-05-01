/**********************************************************************************/
/*  Author       : Sugumaran_A                                                    */
/*  File_Name    : pipe.c                                                         */
/*  Description  : creating a pipe parent write a data & child read that data     */
/*  Date         : 30/04/2020                                                    */
/**********************************************************************************/

#include "pipe.h"

int main()
{
	char str_1[] = "Hi i am data from pipe\n"; 
	char str_2[50];
	int fd[2];  //fd for pipe ,fd[0] for read & fd[1] for write in pipe

	ssize_t write_ret = 0;
	ssize_t read_ret = 0;
	int pipe_ret;
	pipe_ret = pipe(fd);

	printf("pipe_ret %d\n",pipe_ret);

	int fk = fork();//to create a child process

	printf("PID => %d\tfd[0] => %d\tfd[1] => %d\n",getpid(),fd[0],fd[1]);

	if(fk > 0) {//Parent process
		close(fd[0]); //closing read end of a pipe
		write_ret = write(fd[1],str_1,strlen(str_1)+1); //writing a data(string) on a one end of a pipe by fd
		printf("write ret_val => %ld\n",write_ret);  // return value of write()
	}
	else if(fk == 0) {//Child process
		close(fd[1]); //closing write end of a pipe
		read_ret = read(fd[0],str_2,50);   //reading a data(string) from a pipe by fd
		printf("read ret_val => %ld\n",read_ret); // return value of read()
	}
	else {
		printf("fork failed\n");
	}

	printf("String from pipe ==> %s\n",str_2);

	if(fk == 0){
		close(fd[0]);//close a write end of child
	}
	if(fk > 0){
		close(fd[1]);//close a read end of parent
	}

}
