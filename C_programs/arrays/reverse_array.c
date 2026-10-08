#include<stdio.h>

int main()
{
    int i,j,size,a[] = {1,2,3,4,5,6,7,8,9};
    size = (sizeof(a)/sizeof(a[0]));
    printf("Size of array:- %d\n",size);

    for(i=0,j=(size-1);i<j;i++,j--)
    {
        if(a[i]!=a[j])
            a[i] ^= a[j] ^= a[i] ^= a[j];
    }

    printf("After Reversing array:- ");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    printf("\n");
}