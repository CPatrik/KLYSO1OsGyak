#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

	pid_t pid;
	
	if((pid = fork()) < 0) {
		perror("fork error");
	} else if (pid == 0) {
		if(execl("./child.out", "child", (char*) NULL) < 0){
			perror("execl error");
		}
	}
	if(waitpid(pid, NULL, 0) < 0){
		perror("wait error");
	}
	return 0;
}
