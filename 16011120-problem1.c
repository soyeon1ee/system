#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid=fork();//process create

	if(pid==-1)
		perror("fork failed");
	else if(pid!=0){
		printf("Child PID is %d, Parent PID is %d\n",pid,getpid());
		printf("Parent PID is %d\n",getpid());
	}

	return 0;
}
