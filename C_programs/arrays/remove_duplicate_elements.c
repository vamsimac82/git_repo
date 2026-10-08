#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 10
int n = SIZE;
void print_array(int a[])
{
    for(int i=0;i<n;i++)
        printf("%4d",a[i]);
    printf("\n\n");
}

int main()
{
    int i,j,k,a[SIZE] = {};

    for (i = 0; i < SIZE; i++)
    {
        /* code */
        srand(getpid()+i);
        a[i] = rand()%15+1;
    }

    print_array(a);

    for(i=0;i<(n-1);i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {
                for(k=j;k<(n-1);k++)
                    a[k] = a[k+1];
                //a[k] = 0;  -> optional
                n--;
                j--;
            }
        }
    }
    print_array(a);

    return 0;
}