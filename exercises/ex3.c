#include <pthread.h>
#include <stdio.h>

void *PrintHello(void *arg){
	long int val = (long int) arg;
	pthread_t tid = pthread_self();
	printf("Thread %u: Hello! arg=%ld\n", (unsigned int)tid, val);
	pthread_exit(NULL);
}

int main(int argc, char **argv){
	pthread_t thread[4];
	long int arg = 123;

	
	for (long int i = 0; i < 4; ++i){
		pthread_create(&thread[i], NULL, PrintHello, (void*)i);
	}
	for (int i = 0; i < 4; ++i){
		pthread_join(thread[i], NULL);
	}
	pthread_exit(NULL);
}