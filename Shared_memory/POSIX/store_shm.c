/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : store_shm.c                             */         
/*  Description  : posix shared memory                     */
/*  Date         : 21-05-2020                              */
/***********************************************************/

#include "posix_shm.h"

int main()
{
   int open_fd,shmid;
   ssize_t write_fd;
   char *addr;
   char buff[50]="Data stored in posix shared memory\n";

   //creates  and opens a new, or opens an existing, POSIX shared  memory  object
   open_fd = shm_open("/posix" , O_CREAT | O_RDWR , 0644);
   perror("shm_open");

   //write to a file descriptor
   write_fd = write(open_fd,buff,strlen(buff)+1);

   // creates  a  new mapping in the virtual address
   addr = mmap(NULL , 20 , PROT_READ | PROT_WRITE, MAP_SHARED ,open_fd ,0);
   perror("mmap");
}
