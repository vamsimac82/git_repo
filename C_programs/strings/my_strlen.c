#include<stdio.h>
#include<stddef.h>

//using Array
size_t my_strlen(char const str[])
{
    size_t i=0;
    while(str[i] != NULL)
        i++;

    return i;
}

//Using pointer
size_t my_strlen_ptr(char const *str)
{
    char *p = str;
    while(*p != NULL)
        p++;

    return p-str;
}

int main()
{
    char str[50];
    printf("ENter the string:- ");
    gets(str);
    printf("Length of string is %lu\n",my_strlen(str));
    printf("Length of string is %lu\n",my_strlen_ptr(str));

    return 0;
}