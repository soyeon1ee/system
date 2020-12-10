#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signo){

	psignal(signo, "Received Signal:");
}

int main(void)
{
	struct sigaction act;
	int count=0;

	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags=0;
	act.sa_handler=handler;

	sigaction(SIGTSTP, &act, 0);
	sigaction(SIGINT, &act, 0);

	while(1){
		
		printf("Waiting for signal to be received! Count:%d\n",count);
		count++;
		sleep(5);
	}

	return 0;
}
