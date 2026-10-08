#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str[20]= "abcd";
    
    if(strncmp(str,"abcdefgh",4)==0)
        printf("1 -> In strncmp Both strings are Same\n");
    else
        printf("1 -> In strncmp Both strings are Different\n");

     if(strncmp(str,"abcdefgh",6)==0)
        printf("2 -> In strncmp Both strings are Same\n");
    else
        printf("2 -> In strncmp Both strings are Different\n");

    return 0;
   
}

/*
1 -> In strncmp Both strings are Same
2 -> In strncmp Both strings are Different
*/