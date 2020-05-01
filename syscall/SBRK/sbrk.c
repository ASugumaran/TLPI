/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : SBRK.c                                  */         
/*  Description  : To change the data segment size         */
/*  Date         : 28/04/2020                              */
/***********************************************************/

#include "sbrk.h"
               
int main()     
{              
        void * retptr;        //program break

        retptr = sbrk(0);  // 0 can be used to find the  current location of the program break. 
                                   
        printf("program break %p\n",retptr); //retptr => will return address of Program break. After sbrk() called.
        printf("pid = %d\n",getpid());       //Process ID

	sleep(20);  //Sleeping for 20Seconds

        retptr = sbrk(20480);  //Changing the data segment to 20KB

        printf("program break %p\n",retptr); //retptr => will return address of Program break. After sbrk() called.	
        printf("pid = %d\n",getpid());       //Process ID

        sleep(20);  //Sleeping for 20Seconds

	return 0;
}              
