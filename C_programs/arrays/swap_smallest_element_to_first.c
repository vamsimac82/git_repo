#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 20

void swap_smallest_element(int a[])
{
    int i,j=0,small=a[0];
    for(i=1;i<SIZE;i++)
    {
        if(a[i]<small)
        {
            j=i;
            small = a[i];
        }
            
    }
    //swap to 0th element
    a[j] ^= a[0] ^= a[j] ^= a[0];
}

int main()
{
    int i,a[SIZE];
    for(i=0;i<SIZE;i++)
    {
        srand(getpid()+i);
        a[i] = rand()%201+2;
    }

    for(i=0;i<SIZE;i++)
        printf("%4d",a[i]);
    printf("\n\n");

    swap_smallest_element(a);

    for(i=0;i<SIZE;i++)
        printf("%4d",a[i]);
    printf("\n\n");

    return 0;

}