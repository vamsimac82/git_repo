#include<stdio.h>
#include<unistd.h>

int a=10;

int main()
{
    int b= 20;
	printf("In main()...\n");
    for(int i=0;i<3;i++)
    {

        if(fork()==0)
        {
            printf("PID :-%d PPID :- %d\n",getpid(),getppid());
            break;
        }
        else;
    }


	return 0;
}
