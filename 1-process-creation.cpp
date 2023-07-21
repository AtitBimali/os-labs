//program works only in online gdb

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	pid_t pid;
	int status;
	pid = fork();
	if(pid < 0){
		printf("Fork error");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		printf("Child process running .. \n");
		execl("/bin/1s","1s","-1",NULL);
	}
	else{
		printf("Parent process waiting for child to complete..");
		wait(&status);
		if(WIFEXITED(status)){
			printf("Child process terminated with status %d",WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status)){
			printf("Child process terminated by signal %d",	WTERMSIG(status));
		}
		exit(EXIT_SUCCESS);
	}
	return 0;
}
