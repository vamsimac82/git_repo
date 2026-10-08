#include<stdio.h>

int my_strcmp(const char *str1,const char *str2)
{
    int i=0;
    while(str1[i]==str2[i])
    {
        if(str1[i]==NULL)
            return 0;
        i++;
    }
    return str1[i]-str2[i];
}

int main()
{
    char str1[20]="QWERTY",str2[20]="QWERTY";
    if(my_strcmp(str1,str2)==0)
        printf("Both strings are same\n");
    else
        printf("Different\n");

    return 0;
}