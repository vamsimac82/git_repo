#include<stdint-gcc.h>

char *my_strcpy(char *des,const char *src)
{
    while(1)
    {
        *des++ = *src++;
        if(*src=='\0')
        {
            *des = *src;
            break;
        }
    }

    return des;
}

int main()
{
    char src[10]="vectoriu";
    char des[10]="Mirafra";
    printf("src = %s\n",src);
    printf("des = %s\n",des);
    my_strcpy(des,src);
    printf("src = %s\n",src);
    printf("des = %s\n",des);

    return 0;

}