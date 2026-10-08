#include<stdio.h>

int main()
{
    int i,small,large,a[8]={1,2,3,4,5,6,7,8};
    small = large = a[0];
    for(i=1;i<8;i++)
    {
        if(small<a[i])
            small = a[i];
        else if(large > a[i])
            large = a[i];
    }

    printf("Small :- %d Large :- %d\n",small,large);
}