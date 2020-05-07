/********************************************************************/
/*  Author       : Sugumaran_A                                      */
/*  File_Name    : msg_q_rcv.h                                      */         
/*  Description  : Reading and Print a message from a message queue */
/*  Date         : 05-05-2020                                       */
/********************************************************************/

#include "msg_q_crt.h"

struct msgbuf{
       	long mtype;/* message type, must be > 0 */
	char mtext[200];    /* message data */
};



int main(){
	
	printf("\033[1;31mSystem V Message queue Receiving a message\033[0m\n");
	int mesg_id;
	ssize_t fd;
	struct msgbuf my_data1,my_data2,my_data3;

	//get a System V message queue identifier
	//int msgget(key_t key, int msgflg);
	mesg_id = msgget(103,IPC_CREAT|0644);
	perror("msgget");

	//receive messages from, a System V message queue
	//ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
	fd = msgrcv(mesg_id, &my_data2, 200, 0, 4);
	perror("msgrcv");

	//Printing message type and received message
	printf("%ld  %s\n",my_data1.mtype,my_data1.mtext);

	fd = msgrcv(mesg_id, &my_data2, 200, 0, 2);
	perror("msgrcv");

	//Printing message type and received message
	printf("%ld  %s\n",my_data2.mtype,my_data2.mtext);

	fd = msgrcv(mesg_id, &my_data3, 200, 0, 0);
	perror("msgrcv");

	//Printing message type and received message
	printf("%ld  %s\n",my_data3.mtype,my_data3.mtext);
}
