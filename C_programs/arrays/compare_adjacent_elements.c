#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 10

int main()
{
    int i,a[SIZE];

    for(i=0;i<SIZE;i++)
    {
        srand(getpid()+i);
        a[i] = rand()%50+1;
    }

    for(i=0;i<SIZE;i++)
        printf("%3d",a[i]);
    printf("\n\n");

    for(i=0;i<(SIZE-1);i++)
    {
        if(a[i]>a[i+1])
            a[i] ^= a[i+1] ^= a[i] ^= a[i+1];
    }

    for(i=0;i<SIZE;i++)
        printf("%3d",a[i]);
    printf("\n\n");
}