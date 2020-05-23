/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : read_shm.c                              */         
/*  Description  : posix shared memory                     */
/*  Date         : 21-05-2020                              */
/***********************************************************/

#include "posix_shm.h"

int main()
{
   int open_fd, munmap_ret, msync_ret;
   ssize_t read_fd;
   char *mmap_ret;
   char buff[50];

   //creates  and opens a new, or opens an existing, POSIX shared  memory  object
   open_fd = shm_open("/posix" , O_RDWR , 0644);
   if(open_fd == -1){
  	   perror("shm_open");
	   printf("Return value of shm_open %d\n",open_fd);
   }else {
	   perror("shm_open");
	   printf("Return value of shm_open %d\n",open_fd);
   }


   //Read from a file descriptor
   read_fd = read(open_fd,buff,4096);
   if(read_fd == -1){
   	perror("read");
   }else {
   	perror("read");
   }

   // creates  a  new mapping in the virtual address
   //map files or devices into memory
   mmap_ret = mmap(NULL , 4096 , PROT_READ | PROT_WRITE, MAP_SHARED ,open_fd ,0);
   perror("mmap");

   //synchronize a file with a memory map
   msync_ret = msync(mmap_ret, 4096, MS_SYNC);
   if(msync_ret == -1){
	   perror("msync");
   }else {
	   perror("msync");
   }

   //Print the data
   printf("%s\n",buff);

   //unmap files or devices into memory
   munmap_ret = munmap(mmap_ret, 4096);
   if(munmap_ret == -1) {
	   perror("munmap");
   }else {
	   perror("munmap");
   }
}
