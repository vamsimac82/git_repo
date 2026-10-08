#include<stdio.h>
#include<string.h>

int main()
{
    char str[20]= "abcd";
    printf("Before strncpy str:- %s\n",str);

    strncpy(str,"efgh",3);
    printf("1 -> strncpy str:- %s\n",str);

    strncpy(str,"efgh",4);
    printf("2 -> strncpy str:- %s\n",str);

    strncpy(str,"efgh",6);
    printf("3 -> strncpy str:- %s\n",str);

    return 0;
}

/*

Before strncpy str:- abcd
1 -> strncpy str:- efgd
2 -> strncpy str:- efgh
3 -> strncpy str:- efgh

*/