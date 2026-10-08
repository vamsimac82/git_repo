#include<stdio.h>
#include<string.h>

void replace_char(char str[],char ch1,char ch2)
{
    char *ptr = str;
    while(ptr=strchr(ptr,ch1))
    {
        *ptr = ch2;
        ptr = ptr+1;
    }
}

int main()
{
    char str[50];
    gets(str);
    char *ptr=str,ch1,ch2;
    printf("Enter the char:-");
    __fpurge(stdin);
    scanf("%c",&ch1);
     printf("Enter the replace char:-");
    __fpurge(stdin);
    scanf("%c",&ch2);
    replace_char(str,ch1,ch2);
   printf("After replacing %c with %c the string is:- %s\n",ch1,ch2,str);

    return 0;
}