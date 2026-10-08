#include<stdio.h>

#define SIZE 20

int binarysearch(int a[],int element)
{
    int lower = 0,up = (SIZE-1),mid;
    while(lower<=up)
    {
        mid = (lower+up)/2; 

        if(a[mid]>element)
            up = mid-1;
        else if(a[mid]<element)
            lower = mid+1;
        else
            return mid;

    }

    return -1;
}

int main()
{
    int i,index,n,a[SIZE];
    for(i=0;i<SIZE;i++)
        a[i] = ((i*i)+10);
    
     for(i=0;i<SIZE;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");

    printf("Enter searching Element in Array:- ");
    scanf("%d",&n);
    index = binarysearch(a,n);
    if(index==-1)
        printf("%d not found in Array\n\n",n);
    else
        printf("%d is found at Index %d\n\n",n,index);\

    return 0;
}