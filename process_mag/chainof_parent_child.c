#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("In main()...\n");
    for(int i=0;i<3;i++)
    {

        if(fork()==0)
            printf("PID :-%d PPID :- %d\n",getpid(),getppid());
        else
            break;
    }
	return 0;
}
