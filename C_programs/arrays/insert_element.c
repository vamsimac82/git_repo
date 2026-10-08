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
    int i,index,element,a[SIZE] = {0};

    for (i = 0; i < SIZE-1; i++)
    {
        /* code */
        srand(getpid()+i);
        a[i] = rand()%40+1;
    }

    print_array(a);

    printf("Enter the Element to insert:- ");
    scanf("%d",&element);
    printf("Enter Index to insert:- ");
    scanf("%d",&index);

    for(i=SIZE-1;i>index;i--)
    {
        a[i] = a[i-1];
    }

    a[index] = element;

    print_array(a);

    
}