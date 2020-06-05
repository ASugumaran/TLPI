/***********************************************************/
/*  Author       : Sugumaran_A                             */
/*  File_Name    : socket_unixTCP_client.c                 */
/*  Description  : Sending data to a server                */
/*  Date         : 05-06-2020                              */
/***********************************************************/

int main()
{
	int soc_fd, bind_fd;
	int connect_fd;
	ssize_t write_fd;
	char buff[]="data from client\n";

	struct sockaddr_un addr;
	addr.sun_family = AF_UNIX;

	//Patnname of a socket file
	strcpy(addr.sun_path, PATHNAME);
	perror("strcpy");

	//create an endpoint for communication
	soc_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	perror("socket");
	printf("Return value of Socket = %d\n",soc_fd);

	//initiate a connection on a socket
	connect_fd = connect(soc_fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_un));
	perror("connect");

	//write to a file descriptor
	write_fd = write(soc_fd, buff, sizeof(buff));
	perror("write");

	close(soc_fd);
}
