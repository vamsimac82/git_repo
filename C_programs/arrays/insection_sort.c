#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 5

void print_array(int a[])
{
    for(int i=0;i<SIZE;i++)
        printf("%4d",a[i]);
    printf("\n\n");
}

int main()
{
    int i,j,temp,a[SIZE] = {0};

    for (i = 0; i < SIZE; i++)
    {
        /* code */
        srand(getpid()+i);
        a[i] = rand()%40+1;
    }

    print_array(a);

    for(i=1;i<SIZE;i++)
    {
        temp = a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }

    print_array(a);

    return 0;
}