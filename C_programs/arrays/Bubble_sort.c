#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 10

void print_array(int a[])
{
    for(int i=0;i<SIZE;i++)
        printf("%4d",a[i]);
    printf("\n\n");
}

int main()
{
    int j,i,a[SIZE];

    for(i=0;i<SIZE;i++)
    {
        srand(getpid()+i);
        a[i] = rand()%50+1;
    }

    print_array(a);

    for(j=0;j<SIZE-1;j++)
    {
        for(i=0;i<(SIZE-j-1);i++)
        {
            if(a[i]>a[i+1])
                a[i] ^= a[i+1] ^= a[i] ^= a[i+1];
        }
    }
    printf("After Bubble Sort:-\n");
    print_array(a);

    return 0;
}