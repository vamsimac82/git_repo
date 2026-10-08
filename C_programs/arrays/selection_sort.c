#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define SIZE 20

void print_array(int a[])
{
    for(int i=0;i<SIZE;i++)
        printf("%4d",a[i]);
    printf("\n\n");
}

void selection_sorting(int a[])
{
    int i,j,temp=0,small;
    for(j=0;j<(SIZE);j++)
    {
        small = a[j];
        for(i=j+1;i<SIZE;i++)
        {
            if(a[i]<small)
            {
                small = a[i];
                a[i] ^= a[j] ^= a[i] ^= a[j];
            }
                
        }
    }
}

int main()
{
    int i,a[SIZE];
    for(i=0;i<SIZE;i++)
    {
        srand(getpid()+i);
        a[i] = rand()%201+2;
    }

    print_array(a);

    selection_sorting(a);

    printf("After selection Sort:- \n");
    print_array(a);

    return 0;

}