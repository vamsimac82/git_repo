#include<stdio.h>
#include<stdlib.h>

#define SIZE 20

void print_array(int a[])
{
    for(int i=0;i<SIZE;i++)
        printf("%4d",a[i]);
    printf("\n\n");
}

int linearsearch(int arr[],int element)
{

    int i=0;
    for(i=0;i<SIZE;i++)
    {
        if(element == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int i,n,index,a[SIZE];
    for(i=0;i<SIZE;i++)
    {
        srand(getpid()+i);
        a[i] = rand()%201 + 1;
    }

    print_array(a);

    printf("Enter the searching element:- ");
    scanf("%d",&n);

    index = linearsearch(a,n);

    if(index==-1)
        printf("%d is not found in Array\n",n);
    else
        printf("%d is found at Index %d\n",n,index);

    return 0;
}