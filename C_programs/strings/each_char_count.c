#include<stdio.h>
#include<string.h>

int char_count(char str[],char ch)
{
    int count=0;
    char *ptr = str;
    while(ptr=strchr(ptr,ch))
    {
        ptr++;
        count++;
    }
        return count;
}

int main()
{
    char str[50],str2[50]={0},ch;
    int i,j=0;
    gets(str);

    for(i=0;i<strlen(str);i++)
    {
        if(!strchr(str2,str[i]))
        {
            str2[j++] = str[i];
            printf("%c occurs %d times in this string : %s\n",str[i],char_count(str,str[i]),str);
        }
        
    }

    return 0;
}