#include<stdio.h>
#include<string.h>

void rev_letters(char *ptr,int length)
{
    int i,j=length;
    for(i=0;i<j;i++,j--)
    {
        if(ptr[i]!=ptr[j])
            ptr[i]^=ptr[j]^=ptr[i]^=ptr[j];
    }
}
void rev_string(char *ptr)
{
    int i,j,len = strlen(ptr);
    for(i=0,j=len-1;i<j;i++,j--)
    {
        if(ptr[i]!=ptr[j])
            ptr[i]^=ptr[j]^=ptr[i]^=ptr[j];
    }
}

int main()
{
    char str[50];
    gets(str);
    rev_string(str);
    puts(str);
    char *ptr=NULL,*s_ptr=str, *e_ptr=str+(strlen(str)-1);

    while(ptr=strchr(s_ptr,' '))
    {
        e_ptr = ptr-1;
        rev_letters(s_ptr,(e_ptr-s_ptr));

        s_ptr = ptr+1;
    }
    rev_letters(s_ptr,(str+(strlen(str)-1) - s_ptr));

    printf("After revesing string:- %s\n",str);

}