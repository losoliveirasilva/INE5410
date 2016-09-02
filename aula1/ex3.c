#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int pid = 0;
	int pid1 = 0;
	for (int i = 0; i < 2; ++i)
	{
		pid = fork();
		if(pid == 0){
			printf("Processo filho %d seu pai %d\n", getpid(), getppid());
			
			for (int i = 0; i < 2; ++i)	{
				pid1 = fork();
				if (pid1 == 0){
					printf("Processo filho %d seu pai %d\n", getpid(), getppid());
					break;
				} else if (pid1 > 0){
					wait(NULL);
				}
			}break;
		}else if (pid > 0){
			wait(NULL);
		}		
	} 
	return 0;
}