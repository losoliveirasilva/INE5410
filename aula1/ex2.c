#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int pid = 0;
	for (int i = 0; i < 4; ++i)
	{
		pid = fork();
		if(pid == 0){
			printf("Processo filho %d seu pai %d\n", getpid(), getppid());
			break;
		}else if (pid > 0)
		{
			wait(NULL);
		}
		
	} 

	return 0;
}