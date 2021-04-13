#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MSIZE 128


int main(){
    
    char inBuffer[MSIZE];
    int pid, fileDesc;
    char input[] = "Czobor Patrik";
    char * fifo = "/OP/klyso1";

    mkfifo(fifo, 0666);
    pid = fork();

    if (pid < 0) {
        exit(2);
    }
    else if (pid == 0){
        fileDesc = open(fifo, O_WRONLY);
        write(fileDesc, input, strlen(input)+1);
    }
    
    else if (pid > 0 ){
        fileDesc = open(fifo, O_RDONLY);
        read(fileDesc, inBuffer, strlen(input)+1);
        printf("%s\n", inBuffer);
        close(fileDesc);
    }
    return 0;
}