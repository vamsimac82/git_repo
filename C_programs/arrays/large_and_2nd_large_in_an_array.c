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
    int i,large,s_large,a[SIZE] ;

    for (i = 0; i < SIZE; i++)
    {
        /* code */
        srand(getpid()+i);
        a[i] = rand()%40+1;
    }


    print_array(a);

    large = s_large = 0;
    for(i=0;i<SIZE;i++)
    {
        if(a[i]>large)
        {
            s_large = large;
            large = a[i];
        }
        else if(a[i]>s_large)
            s_large = a[i];
        
        
        
    }

    printf("large %d Second large %d\n",large,s_large);

    return 0;

}