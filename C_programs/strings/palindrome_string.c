#include<stdio.h>
#include<string.h>

int main()
{
    char str1[50],str2[50];
    int len,i=0;
    printf("Enter string:- ");
    gets(str1);
    len = strlen(str1);
    len--;

    do
    {
        str2[i] = str1[len];
        len--;
        i++;
    }while(len>=0);
    str2[i] = '\0';

    if(strcmp(str1,str2)==0)
        printf("Given string is palindrome\n");
    else
        printf("Given string is not palindrome\n");

    return 0;    
}