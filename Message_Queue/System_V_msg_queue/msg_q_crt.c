/***********************************************************************/
/*  Author       : Sugumaran_A                                         */
/*  File_Name    : msg_q_crt.c                                         */         
/*  Description  : Creating a SYS V message queue and sending data     */
/*  Date         : 05-05-2020                                          */
/***********************************************************************/

#include "msg_q_crt.h"

//The msgp argument is a pointer to a caller-defined structure of the following general form:
struct mymsg {
	long mtype;
	char mtext[200];//max size of a string length
};


char str1[]="Message from str1\n";
char str2[]="Message from str2\n";
char str3[]="Message from str3\n";

int main(){
	printf("\033[1;31mSystem V Message queue Creating a message\033[0m\n");
	int mesg_id,msgsnd_return;

	struct mymsg my_data1,my_data2,my_data3;//struct variable

	//mtype value can be used by the receiving process for message selection
	my_data1.mtype  = 1; 
	my_data2.mtype  = 2;
	my_data3.mtype  = 3;

	//copy a string to a structure
	strncpy(my_data1.mtext,str1,strlen(str1)+1);
	strncpy(my_data2.mtext,str2,strlen(str2)+1);
	strncpy(my_data3.mtext,str3,strlen(str3)+1);

	//int msgget(key_t key, int msgflg);
	mesg_id = msgget(103,IPC_CREAT|0644);//creating a new message queue
	perror("msgget");

	//int msgsnd(int msqid , const void * msgp , size_t msgsz , int msgflg );
	//Sending a string to a message queue
	msgsnd_return = msgsnd(mesg_id, &my_data1, strlen(str1)+1, 1);
	perror("msgsnd");
	msgsnd_return = msgsnd(mesg_id, &my_data2, strlen(str2)+1, 2);
	perror("msgsnd");
	msgsnd_return = msgsnd(mesg_id, &my_data3, strlen(str3)+1, 3);
	perror("msgsnd");
}
