#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 180
int global = 0;
sem_t semaphore;

void *Print(){
	for (int i = 0; i < 100; ++i) {
		sem_wait(&semaphore);
		global++;
		sem_post(&semaphore);
	}
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]){
	pthread_t thread[MAX_THREADS];
	sem_init(&semaphore, 0, 1);
	for (int i = 0; i < MAX_THREADS; ++i) {
		pthread_create(&thread[i], NULL, Print, NULL);
	}
	for (int i = 0; i < MAX_THREADS; ++i) {
		pthread_join(thread[i], NULL);
	}
	printf("Global = %i\n", global);
	sem_destroy(&semaphore);
	pthread_exit(NULL);
	}