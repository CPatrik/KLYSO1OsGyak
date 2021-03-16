#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

	pid_t pid;
	
	if((pid = fork()) < 0) {
		perror("fork error");
		exit(0);
	} else if (pid == 0) {
		if(execl("./child2.out", "child2", (char*) NULL) < 0){
			perror("execl error");
			exit(0);
		}
	}

	int statusz;
	
	waitpid(pid, &statusz, 0);

	if (WIFEXITED(statusz))
	{
		int e_statusz = WEXITSTATUS(statusz);
		printf("Kilepesi ertek: %d\n", e_statusz);
	}
	return 0;
}
