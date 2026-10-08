#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int a[3],d;
    if((a[0]=fork())==0)
    {
        srand(getpid());
        d = rand()%5+1;
        printf("In C1....d=%d PID:-%d\n",d,getpid());
        sleep(d);
        printf("OUT C1.....\n");
        exit(1);
    }
    else
    {
        if((a[1]=fork())==0)
        {
            srand(getpid());
            d = rand()%5+1;
            printf("In C2....d=%d PID:-%d\n",d,getpid());
            sleep(d);
            printf("OUT C2.....\n");
            exit(2);
        }
        else
        {
            if((a[2]=fork())==0)
            {
                srand(getpid());
                d = rand()%5+1;
                printf("In C3....d=%d PID:-%d\n",d,getpid());
                sleep(d);
                printf("OUT C3.....\n");
                exit(3);
            }
            else{
                // exclusive parent code
                int r,s;
                printf("In parent......%d\n",getpid());
                while((r=wait(&s))!=-1)
                    printf("*****C%d******%d\n",s>>8,a[(s>>8)-1]);
            }
            printf("OUT of Parent\n");
        }

    }
}