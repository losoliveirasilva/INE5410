#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5

void *Print(){
	pthread_t tid = pthread_self();
	printf("Nova thread criada. TID=%u \n", tid);
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]){
	pthread_t thread[MAX_THREADS];
	for (int i = 0; i < MAX_THREADS; ++i) {
		pthread_create(&thread[i], NULL, Print, NULL);
	}
	for (int i = 0; i < MAX_THREADS; ++i) {
		pthread_join(thread[i], NULL);
	}
	pthread_exit(NULL);
}