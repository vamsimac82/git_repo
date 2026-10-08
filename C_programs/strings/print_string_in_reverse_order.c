#include<stdio.h>
#include<string.h>

int main()
{
    char str[50];
    int len;
    printf("Enter string:- ");
    gets(str);
    len = strlen(str);
    for(len-1;len>=0;len--)
    putchar(str[len]);
    putchar('\n');

    return 0;
}