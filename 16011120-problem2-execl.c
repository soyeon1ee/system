#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {

	pid_t pid;

	pid=fork(); //process create

	switch(pid) {
		case -1:
			perror("fork() failed\n");
			break;
		case 0: //child process
			printf("execl() executing ls beginning\n");
			execl("/bin/ls", "ls", "-l", (char *)0);
			perror("execl() failed\n");
		default: //parent process
			wait((int *)0); //parent wait until the child dies
			printf("execl() executing ls completed\n");
			exit(0);
	}

	return(0);
}
