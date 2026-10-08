#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("In main()...\n");
    fork();
    printf("PID:- %d PPID:- %d\n",getpid(),getppid());
	printf("Exit main()...\n");

	return 0;
}
