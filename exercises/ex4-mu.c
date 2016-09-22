#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 3281
int global = 0;
pthread_mutex_t mutex_global;

void *Print(){
	for (int i = 0; i < 100; ++i) {
		pthread_mutex_lock(&mutex_global);
		global++;
		pthread_mutex_unlock(&mutex_global);
	}
	pthread_exit(NULL);
}

int main(int argc, char const *argv[]){
	pthread_t thread[MAX_THREADS];
	pthread_mutex_init(&mutex_global, NULL);
	for (int i = 0; i < MAX_THREADS; ++i) {
		pthread_create(&thread[i], NULL, Print, NULL);
	}
	for (int i = 0; i < MAX_THREADS; ++i) {
		pthread_join(thread[i], NULL);
	}
	printf("Global = %i\n", global);
	pthread_mutex_destroy(&mutex_global);
	pthread_exit(NULL);
	}