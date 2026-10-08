#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 10


int main()
{
    int i,j,a[10][10];

    
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0 || i==j)
                a[i][j] = 1;
            else
                a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
  

    printf("Prascal Triangle:- \n");
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%4d",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}