#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char str[20]= {"abcd"};
    printf("Before strncat str:- %s\n",str);

    strncat(str,"efgh",3);
    printf("1 -> strncat str:- %s\n",str);

    strncat(str,"efgh",6);
    printf("2 -> strncat str:- %s\n",str);

    return 0;
   
}
/*

Before strncat str:- abcd
1 -> strncat str:- abcdefg
2 -> strncat str:- abcdefgefgh

*/