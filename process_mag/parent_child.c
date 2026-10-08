#include<stdio.h>
#include<unistd.h>

int a=10;

int main()
{
    int b= 20;
	printf("In main()...\n");
    if(fork())
    {
        printf("In parent...PID :-%d PPID :- %d\n",getpid(),getppid());
        printf("a=%d b=%d\n",a,b);
        a = 2*a;
        b = 2*b;
        printf("a=%d b=%d\n",a,b);
    }
    else
    {
        printf("In Child...PID :-%d PPID :- %d\n",getpid(),getppid());
        printf("a=%d b=%d\n",a,b);
        a = 3*a;
        b = 3*b;
        printf("a=%d b=%d\n",a,b);
    }
	printf("Exit main()...\n");

	return 0;
}
