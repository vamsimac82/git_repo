#include<stdio.h>
#include<string.h>

void char_delete(char str[],char ch)
{

    char *ptr = str;
    while(ptr=strchr(ptr,ch))
        memmove(ptr,ptr+1,strlen(ptr));
    
}

int main()
{
    char str[50];
    gets(str);
    char *ptr=str,ch;
    printf("Enter the char:-");
    __fpurge(stdin);
    scanf("%c",&ch);
    char_delete(str,ch);
    printf("After delete %c char from string is:- %s\n\n",ch,str);
    return 0;
}