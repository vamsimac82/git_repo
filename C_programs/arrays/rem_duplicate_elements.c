#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 15
int n = SIZE;
void print_array(int a[])
{
    for(int i=0;i<n;i++)
        printf("%4d",a[i]);
    printf("\n\n");
}

int main()
{
    int i,j,k,a[SIZE] = {0};

    for (i = 0; i < SIZE; i++)
    {
        /* code */
        srand(getpid()+i);
        a[i] = rand()%15+1;
    }

    print_array(a);

    for(i=0;i<SIZE;i++)
    {
        k = a[i];
        for(j=i-1;j>=0 && k<a[j];j--)
            a[j+1] = a[j];
        a[j+1] = k;
    }

    printf("After Sorting Array:- \n");
    print_array(a);

    for(i=0;i<(n-1);i++)
    {
        if(a[i]==a[i+1])
       {
            for(j=i;j<(n-1);j++)
            {
                a[j]=a[j+1];
            }
            n--;
            i--;
       }
    }
    printf("After Removing Duplicate elements in an Array:- \n");
    print_array(a);

    return 0;
}