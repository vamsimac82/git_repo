#include<stdio.h>

int main()
{
    int a = 10;
    int *p;
    printf("a = %13d &a = %p\n",a,&a);
    printf("*p = %14d p = %17p &p = %p\n",*p,p,&p);
    p = & a;
    printf("\n*p = %14d   p = %16p    &p = %16p\n",*p,p,&p);
    int *ptr = p;
    printf("*ptr = %12d   ptr = %p    &ptr = %p\n",*ptr,ptr,&ptr);
    *ptr = 20;
    printf("\na = %15d  &a = %p\n",a,&a);
    printf("*p = %14d   p = %16p    &p = %16p\n",*p,p,&p);
    printf("*ptr = %12d   ptr = %p    &ptr = %p\n",*ptr,ptr,&ptr);

    a=100;
    printf("\na = %15d  &a = %p\n",a,&a);
    printf("*p = %14d   p = %16p    &p = %16p\n",*p,p,&p);
    printf("*ptr = %12d   ptr = %p    &ptr = %p\n",*ptr,ptr,&ptr);

    ++*p;
    printf("\na = %15d  &a = %p\n",a,&a);
    printf("*p = %14d   p = %16p    &p = %16p\n",*p,p,&p);
    printf("*ptr = %12d   ptr = %p    &ptr = %p\n",*ptr,ptr,&ptr);

    printf("\n*(--p) = %d --p = %p \n",*p,--p);

    printf("\na = %15d  &a = %p\n",a,&a);
    printf("*p = %14d   p = %16p    &p = %16p\n",*p,p,&p);
    printf("*ptr = %12d   ptr = %p    &ptr = %p\n",*ptr,ptr,&ptr);
    
    return 0;
}