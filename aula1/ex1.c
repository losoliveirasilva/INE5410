#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	pid_t pid;

	pid = fork();

	if (pid == 0)
	{
		printf("Processo criado(Filho)\n");
	}else
	{
		printf("Processo criado(Pai)\n");
	}
	return 0;
}
