#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

// void enter_input(int a[][],int rows,int cols)
// {
//     int i,j,r;
//     for(i=0;i<rows;i++)
//     {
//         for(j=0;j<cols;j++)
//         {
//             srand(getpid()+j);
//             r = rand()%10+1;
//             a[i][j] = r;
//         }
//     }
// }

int main()
{
    int r,i,j,r1,r2,c1,c2;
    printf("Enter Number of rows for 1st matrix:- ");
    scanf("%d",&r1);
    printf("Enter Number of cols for 1st matrix:- ");
    scanf("%d",&c1);
    printf("Enter Number of rows for 2nd matrix:- ");
    scanf("%d",&r2);
    printf("Enter Number of cols for 2nd matrix:- ");
    scanf("%d",&c2);

    if(c1 != r2)
    {
        printf("For Matrices Multiplication number of cols of 1st matrix is equal to number of rows of 2nd matrix\n");
        return 0;
    }

    int mat1[r1][c1],mat2[r2][c2];
   
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            srand(getpid()+i+j);
            r = rand()%10;
            mat1[i][j] = r;
        }
    }

    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            srand(getppid()+i+j);
            r = rand()%10;
            mat2[i][j] = r;
        }
    }

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
           printf("%3d ",mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
           printf("%3d ",mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    int k,mul[r1][c2];
    
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            //mul[i][j]=mat1[i][0]*mat2[0][j] + mat1[i][1]*mat2[1][j] + mat1[i][2]*mat2[2][j];
            mul[i][j] = 0;
            for(k=0;k<c1;k++)
                mul[i][j] += mat1[i][k] * mat2[k][j];
        }
        
    }

    printf("After  Multplication of 2 Matrices:- \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%4d",mul[i][j]);
        }
        printf("\n");
        
    }
}