/******************************************************************************/
/*  Author       : Sugumaran_A                                                */
/*  File_Name    : P_msgq_rcv.c                                               */
/*  Description  : open and receive message from a message queue( POSIX )     */
/*  Date         : 07-05-2020                                                 */
/******************************************************************************/

#include "P_msgq_rcv.h"

char buffer[8192];

int main()
{
	int mq_op_ret,mq_rcv_ret;
	struct mq_attr my_mq_attr;
	unsigned int msg_pri = 10;

	my_mq_attr.mq_flags    = 0;
	my_mq_attr.mq_maxmsg  = 10;
	my_mq_attr.mq_msgsize = 8192;

	//open a message queue
	// mqd_t mq_open(const char *name, int oflag);
	mq_op_ret = mq_open("/P_msgq", O_RDONLY);
	perror("mq_open");

	printf("ret value of mq_open = %d\n",mq_op_ret);//return value of mq_open

	//receive a message from a message queue
	//ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);
	mq_rcv_ret = mq_receive(mq_op_ret, buffer, 8192,&msg_pri);
	perror("mq_receive");

	printf("ret value of mq_receive = %d\n",mq_rcv_ret);//return value of mq_receive
	printf("Data from sender ==> %s\n",buffer);

}
