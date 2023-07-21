
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *thread_func(void *arg){
	int i;
	printf("Thread running..\n");
	for(i=0;i<10;i++){
		printf("Thread: %d\n",i);
		sleep(1);
	}
	printf("Thread finished \n");
	return NULL;
}

int main(){
	pthread_t thread;
	int ret;
	ret = pthread_create(&thread,NULL,thread_func,NULL);
	if(ret != 0){
		printf("Thread creation error");
		exit(EXIT_FAILURE);
	}
	printf("Main thread waiting for child thread to complete..\n");
	ret = pthread_join(thread,NULL);
	if(ret != 0){
		printf("Thread join error");
		exit(EXIT_FAILURE);
	}
	printf("Child thread joined successfully");
	pthread_exit(NULL);
	return 0;
}
