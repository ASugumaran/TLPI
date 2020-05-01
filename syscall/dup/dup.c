/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : dup.c                                   */         
/*  Description  : duplicate a file descriptor             */
/*  Date         : 01-05-2020                              */
/***********************************************************/

#include "dup.h"

int main()
{
	int dp;
	int op_fd;
	ssize_t wt,rd;
	char str[]="hi it is string\n";
	char buf[100];

	op_fd = open("test",O_CREAT | O_RDWR, 0664);
	perror("open");

	dp = dup(op_fd);//create a duplicate fd
	printf("fd => %d\tdp => %d\n",op_fd,dp);//return value of old and new fd

	wt = write(dp,str,strlen(str));// write to file descriptor
	perror("write");
	printf("write ret val %ld\n",wt);

	off_t seek = lseek(op_fd,0,SEEK_SET);// change the file offset to 0 (starting point)
	perror("lseek");

	rd = read(op_fd,buf,5); //read from a file descriptor
	perror("read");
	printf("read ret val %ld\n",rd);

	printf("original_fd =>%s\n",buf); //printing 5 values from that fd

	rd = read(dp,buf,5);
	perror("read");
	printf("read ret val %ld\n",rd);//printing next 5 values from that fd

	printf("duplicate_fd =>%s\n",buf);
}
