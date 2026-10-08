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
    int i,j,k,max=0,count=1,flag=0,a[SIZE] = {0};

    srand(getpid());
    for (i = 0; i < SIZE; i++)
    {
        /* code */
        a[i] = rand()%10+1;
    }

    print_array(a);

    for(i=0;i<SIZE;i++)
    {
        k = a[i];
        for(j=i-1;j>=0 && k < a[j];j--)
            a[j+1] = a[j];
        a[j+1] = k;
    }

    printf("After Sorting Array:- \n");
    print_array(a);

    j=-1;
    for(i=0;i<(SIZE-1);i++)
    {
        if(a[i]==a[i+1])
        {
            count++;
            if(max<count)
            {
                j=i;
                max=count;
            }
        }
        else
           count = 1;
    }

    if(j != -1)
    printf("%d occurs %d times in array\n",a[j],max);
    else
    printf("No occurence Happened in array\n");

    return 0;
}