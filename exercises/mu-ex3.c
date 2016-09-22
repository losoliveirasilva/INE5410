#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 32
int global = 0;

void *Print(){
	for (int i = 0; i < 100; ++i) {
		global++;
	}
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
	printf("Global = %i\n", global);
	pthread_exit(NULL);
	}