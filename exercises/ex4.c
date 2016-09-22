#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

void *Print(){
	pthread_t tid = pthread_self();
	printf("Nova thread criada. TID=%u", tid);
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]){
	pthread_t thread;
	pthread_create(&thread, NULL, Print, NULL);
	pthread_join(thread, NULL);
	pthread_exit(NULL);
}

