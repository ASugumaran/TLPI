/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : store_shm.c                             */         
/*  Description  : posix shared memory                     */
/*  Date         : 21-05-2020                              */
/***********************************************************/

#include "posix_shm.h"

int main()
{
   int open_fd, munmap_ret, msync_ret;
   ssize_t write_fd;
   char *mmap_ret;
   char buff[50]="Data stored in posix shared memory\n";

   //creates  and opens a new, or opens an existing, POSIX shared  memory  object
   open_fd = shm_open("/posix" , O_CREAT | O_RDWR | O_TRUNC , 0644);
   if(open_fd == -1){
  	   perror("shm_open");
	   printf("Return value of shm_open %d\n",open_fd);
   }else {
	   perror("shm_open");
	   printf("Return value of shm_open %d\n",open_fd);
   }


   //write to a file descriptor
   write_fd = write(open_fd,buff,strlen(buff)+1);
   if(write_fd == -1){
   	perror("write");
   }else {
   	perror("write");
   }

   // creates  a  new mapping in the virtual address
   //map files or devices into memory
   mmap_ret = mmap(NULL , 4096 , PROT_READ | PROT_WRITE, MAP_SHARED ,open_fd ,0);
   perror("mmap");

   //synchronize a file with a memory map
   //msync()  flushes  changes made to the in-core copy of a file that was mapped into memory using mmap
   msync_ret = msync(mmap_ret, 4096, MS_SYNC);
   if(msync_ret == -1){
	   perror("msync");
   }else {
	   perror("msync");
   }

   //unmap files or devices into memory
   munmap_ret = munmap(mmap_ret, 4096);
   if(munmap_ret == -1) {
	   perror("munmap");
   }else {
	   perror("munmap");
   }	   
   
}
