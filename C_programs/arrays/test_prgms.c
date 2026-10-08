#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

/* 4th */
// void func(int a[])
// {
//     int i=5,sum=0;
//     while (i>2)
//     {
//         /* code */
//         sum += a[--i];
//     }
//     printf("%4d \n",sum);
    
// }

/* 8th */
// void fun(int a[], int i, int j)
// {
//     if(i>j)
//         return;
//     fun(a,i+1,j);
//     printf("%3d",a[i]);
// }

/* 9th */
// int func(int a[],int size)
// {
//     if(size==0)
//         return 0;
//     return a[size-1] + func(a,size-1);
// }

/* 16th */
int fun(int a[],int size)
{
    int m;
    if(size==1)
        return a[0];
    m=fun(a,size-1);
    if(a[size-1]<m)
        return a[size-1];
    else
        return m;
}

/* 17th */
int fun17(int a[],int low,int high)
{
    int mid,left,right;
    if(low==high)
        return a[low];
    mid = (low+high)/2;
    left = fun17(a,low,mid);
    right = fun17(a,mid+1,high);

    if(left<right)
        return left;
    else
        return right;
}

int main()
{

    /* 1st */
    // int i,size=5,a[size];
    // for(i=0;i<5;i++)
    //     scanf("%d",&a[i]);
    // for(i=0;i<5;i++)
    //     printf("%4d",a[i]);
    // printf("\n");

    /* 2nd */
    // int i=3,j=0,a[4]= {2,4,8,16};
    // while(i)
    // {
    //     j += a[i];
    //     i--;
    // }
    // printf("  %d\n",j);

    /* 3rd */
    // int i=0,j=0,a[]= {2,4,6,0,7,2,12};
    // while(a[i])
    // {
    //     j += a[i];
    //     i++;
    // }
    // printf("  %d\n",j);

    /* 4th */
    // int a[]= {2,4,15,20,25};
    // func(a);

    /* 5th */
    // int x[10],y[3][4],z[2][3][5];
    // printf("%5u %5u %5u\n",sizeof(x),sizeof(y),sizeof(z));

    /* 7th */
    // int i,j,a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    // for(i=0;i<4;i++)
    // {
    //     for(j=0;j<3;j++)
    //     {
    //         printf("%3d",a[j][i]);
    //     }
    //     printf("\n");
    // }

    /* 8th */
    // int a[] = {1,6,2,7,3,4,8,10,9,5};
    // fun(a,2,7);

    /* 9th */
    // int a[] = {1,2,3,4,8,10};
    // printf("%d\n",func(a,6));

    /* 16th */
    // int a[10] = {2,3,1,4,6,34};
    // printf("%d\n",fun(a,6));

    /* 17th */
    int a[10] = {3,4,2,11,8,10};
    printf("\t%d\n",fun17(a,0,5));

    
    return 0;
}