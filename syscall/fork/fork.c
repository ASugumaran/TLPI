#include "fork.h"

int main()
{
	pid_t pid;

	pid = fork();

	if(pid == 0) {//Child process
		printf("child process....\n");
		printf("PID = %d\nPPID = %d\n",getpid(),getppid());
		printf("child process exit......\n");
	}
	else if(pid > 0 ){//Parent process
		int status;
		printf("Before child process creation\n");

		pid_t wt_rv = wait(&status);//wait for the child to execute
		printf("Parent process....\n");

		printf("PID = %d\nPPID = %d\n",getpid(),getppid());//process ID and Parent process ID
		printf("Status %d\n",WIFEXITED(status));  //returns true if the child terminated normally

		printf("Wait ret value %d\n",wt_rv);// on success, returns the process ID of the terminated child; on error, -1 is returned.
		printf("Parent process exit......\n");
	}
	else{
		printf("Fork failed\n");
	}
}
