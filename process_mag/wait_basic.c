#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    if(fork()==0)
    {
        printf("In child.......PID:-%d PPID:-%d\n",getpid(),getppid());
        sleep(5);
        exit(4);
    }
    else{
        int r,s;
        printf("In parent...Before wait....PID:-%d PPID:-%d\n",getpid(),getppid());
        r=wait(&s);
        printf("In parent....After Wait....PID:-%d PPID:-%d\n",getpid(),getppid());
        printf("r=%d s=%d\n",r,(s>>8));
    }
    return 0;

}