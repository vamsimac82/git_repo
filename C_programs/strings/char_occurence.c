#include<stdio.h>
#include<string.h>

int char_count(char str[],char ch)
{
    int count=0;
    char *ptr = str;
    while(ptr=strchr(ptr,ch))
    {
        count++;
        ptr = ptr+1;
    }
    return count;
}

int main()
{
    char str[50];
    gets(str);
    char *ptr=str,ch;
    printf("Enter the char:-");
    __fpurge(stdin);
    scanf("%c",&ch);
    printf("Number of %c in string is %d\n",ch,char_count(str,ch));

    return 0;
}