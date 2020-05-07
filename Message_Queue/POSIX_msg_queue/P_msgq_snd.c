/*****************************************************************/
/*  Author       : Sugumaran_A                                   */
/*  File_Name    : P_msgq_snd.c                                  */
/*  Description  : open and send message to a queue( POSIX )     */
/*  Date         : 07-05-2020                                    */
/*****************************************************************/

#include "P_msgq_snd.h"

char str[]="Data from POSIX msg queue send\n";


//struct mq_attr {
//               long mq_flags;       /* Flags: 0 or O_NONBLOCK */
//               long mq_maxmsg;      /* Max. # of messages on queue */
//               long mq_msgsize;     /* Max. message size (bytes) */
//               long mq_curmsgs;     /* # of messages currently in queue */
//           };

int main()
{
	int mq_op_ret,mq_send_ret;
	struct mq_attr my_mq_attr;

	my_mq_attr.mq_flags   = 0;   //
	my_mq_attr.mq_maxmsg  = 10;
	my_mq_attr.mq_msgsize = 8192;

	//open a message queue
	//mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);
	mq_op_ret = mq_open("/P_msgq", O_CREAT | O_RDWR, 0644, &my_mq_attr);
	perror("mq_open");

	printf("ret value of mq_open = %d\n",mq_op_ret);//return value of msg_open

	//send a message to a message queue
	mq_send_ret = mq_send(mq_op_ret, str, strlen(str)+1,10);
	perror("mq_send");

	printf("ret value of mq_send = %d\n",mq_send_ret);//return value of mq_send
}
