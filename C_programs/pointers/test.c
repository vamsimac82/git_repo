#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


//19th
    int a=5,b=10;
    void change1(int *p)
    {
        printf("In change1 :- %p %d\n",p,*p);
        p=&a;
        printf("In change1 :- %p %d\n",p,*p);

    }
    void change2(int **pp)
    {
        printf("In change2 :- %p %d\n",*pp,**pp);
        *pp=&b;
        printf("In change1 :- %p %d\n",*pp,**pp);
    }

    //20th
    void func20(int x,int *y)
    {
        int temp;
        temp = x;
        x=*y;
        *y=temp;
    }

    //21st
    void func21(int **pp)
    {
        int num=10;
        *pp = &num;
    }

    //22nd
    void func22(int x,int y)
    {
        int temp;
        temp  = *(&x);
        *(&x) = *(&y);
        *(&y) = temp;

    }

    //23rd
    void func231(int *p)
    {
        p++;
        printf("In func1 %p\n",p);
    }
    void func232(int **p)
    {
        printf("In func2 %p\n",*p);
        (*p)++;
        printf("In func2 %p\n",*p);
    }

    //24th
    void func24(int a[10])
    {
        int b[10],x=10;
        a = &x;
        //b = &x;         // error: assignment to expression with array type
    }

    //27th
    void func27(int *p)
    {
        for(int i=0;p[i]!=8;i++)
        {
            printf("%5d",p[i]);
        }
        printf("\n");
    }

    //28th
    void swap(int *x,int *y)
    {
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

    //30th
    int *func301()
    {
        int a=8, *p=&a;
        return p;

    }

    int *func302()
    {
        int *p;
        p = (int *)malloc(sizeof(int));
        *p = 9;
        return p;
    }


int main()
{
    // 1st
    // int a,*ptr;
    // ptr = &a;
    // scanf("%d",ptr);
    // printf("%d\n",a);

    // 2nd
    // int *ptr;
    // scanf("%d",ptr);
    // printf("%d\n",*ptr);

    //3rd
    // int a[5],i;
    // srand(getpid());
    // for(i=0;i<5;i++)
    //     printf("%p  ",a+i);
    // for(i=0;i<5;i++)
    //     *(a+i) = rand()%50+5;
    // for(i=0;i<5;i++)
    //     printf("%5d",*(a+i));
    //     printf("\n");

    // //4th
    // int i,a[5]={25,30,35,40,45},*p;
    // p = a;
    // for(i=0;i<5;i++)
    //     printf("%d\t%d\t",*(p+i),p[i]);
    // printf("\n\n");

    //5th
    // int i,a[5]={25,30,35,40,45},*p;
    // p = &a[4];
    // for(i=0;i<5;i++)
    //     printf("%d\t%d\t",*(p-i),p[-i]);
    // printf("\n\n");

    //6th
    // int i,a[5]={25,30,35,40,45};
    // for(i=0;i<5;i++)
    // {
    //     printf("%5d",*a);
    //     a = a+i;            // error: lvalue required as increment operand
    //     a = a++;            // error: lvalue required as increment operand
    //     a++;                // error: assignment to expression with array type
    // }
    // printf("\n\n");
    
    //7th
    // int i,a[5]={25,30,35,40,45},*p = a;
    // for(i=0;i<5;i++)
    // {
    //     (*p)++;
    //     printf("%5d",*p);
    //     p++;
    // }
    // printf("\n\n");

    //8th
    // int i,a[5]={25,30,35,40,45},*p = a;
    // for(i=0;i<5;i++)
    // {
    //     printf("%5d",*p++);
    // }
    // printf("\n\n");
    // for(i=0;i<5;i++)
    // {
    //     printf("%5d",*--p);
    // }
    // printf("\n\n");

    //9th
    // int i,a[5]={25,40,55,70,85},*p = a;
    // for(i=0;i<8;i++)
    //     printf("%5d",++*p);
    // printf("\n\n");

    // for(i=0;i<7;i++)
    //     printf("%5d",(*p)++);
    // printf("\n\n");

    //10th
    // int i,a[10]={25,30,35,40,55,60,65,70,85,90},*p = a;
    // for(p=&a[0];p<a+10;p++)
    //     printf("%p ",p);
    // printf("\n\n");

    //11th
    // int i,a[10]={25,30,35,40,55,60,65,70,85,90},*p = a;
    // for(p=a+2;p<a+8;p=p+2)
    //     printf("%5d ",*p);
    // printf("\n\n");

    //12th
    // int i,a[10]={25,30,35,40,55,60,65,70,85,90},*p = a;
    // p = a+9;
    // for(i=0;i<10;i++)
    //     printf("%5d ",*p--);
    // printf("\n\n");

    //13th
    // int i,a[10]={25,30,35,40,55,60,65,70,85,90},*p;
    // for(p=a+9;p>=a;p--)
    //     printf("%5d ",*p);
    // printf("\n\n");

    //14th
    // int a[4] = {10,20,30,40};
    // int x=100, *p = a;
    // printf("%p\t%5d %5d\n",p,*p,x);
    // x=*p++;
    // printf("%p\t%5d %5d\n",p,*p,x);
    // x=*++p;
    // printf("%p\t%5d %5d\n",p,*p,x);
    // x=++*p;
    // printf("%p\t%5d %5d\n",p,*p,x);
    // x=(*p)++;
    // printf("%p\t%5d %5d\n",p,*p,x);

    //15th
    // int x,a[8] =  {11,22,33,44,55,66,77,88};
    // x=(a+2)[3];
    // printf("%d\n",x);

    //16th
    // int x,a[8] =  {11,22,33,44,55,66,77,88};
    // int *p,*q;
    // q=a/2;              //error: invalid operands to binary / (have ‘int *’ and ‘int’)
    // p=q*2;              //error: invalid operands to binary * (have ‘int *’ and ‘int’)
    // printf("%5d %5d\n",*p,*q);
    
    //17th
    // int a[6] = {1,2,3,4,5,6};
    // int *p =a;
    // printf("sizeof(p) :- %lu sizeof(a):- %lu\n",sizeof(p),sizeof(a));

    //18th
    // float a=5,*p,**pp;
    // p = &a;
    // pp = &p;
    // printf("a=%f p=%p pp=%p\n",a,p,pp);
    // a = a+1;
    // p = p+1;
    // pp = pp+1;
    // printf("a=%f p=%p pp=%p \n",a,p,pp);

    //19th
    // int x=20,*p = &x;
    // printf("%p %d\n",p,*p);
    // change1(p);
    // printf("%p %d\n",p,*p);
    // change2(&p);
    // printf("%p %d\n",p,*p);

    //20th
    // int a=2,b=6;
    // func20(a,&b);
    // printf("a=%d b=%d\n",a,b);

    //21st
    // int *ptr;
    // func21(&ptr);
    // printf(" %d\n",*ptr);

    //22nd
    // int a=5,b=8;
    // func22(a,b);
    // printf("a=%5d b=%5d\n",a,b);

    //23rd
    // int a[5] = {1,2,3,4,5};
    // int *p = a;
    // printf("%p\n",p);
    // func231(p);
    // printf("%p\n",p);
    // func232(&p);
    // printf("%p\n",p);

    //24th
    // int a[10] = {5};
    // func24(a);
    // printf("a[0] = %d\n",a[0]);

    //25th
    // int a[3][4];
    // printf("%p\n",a);
    // printf("%p\n",a[0]);
    // printf("%p\n",&a[0][0]);
    // printf("sizeof(a)       :- %u\n",sizeof(a));
    // printf("sizeof(a[0])    :- %u\n",sizeof(a[0]));
    // printf("sizeof(a[0][0]) :- %u\n",sizeof(a[0][0]));

    //26th
    //  int a[3][4][5];
    // printf("%p\n",a);
    // printf("%p\n",a[0]);
    // printf("%p\n",a[0][0]);
    // printf("%p\n",&a[0][0][0]);
    // printf("sizeof(a)       :- %u\n",sizeof(a));
    // printf("sizeof(a[0])    :- %u\n",sizeof(a[0]));
    // printf("sizeof(a[0][0]) :- %u\n",sizeof(a[0][0]));
    // printf("sizeof(a[0][0][0]) :- %u\n",sizeof(a[0][0][0]));

    //27th
    // int a[10] = {1,2,3,4,5,6,7,8,9,10};
    // func27(a+3);

    //28th
    // int i,j,a[10] = {3,2,4,1,5,9,8,10,7,6};
    // for(i=0;i<10;i++)
    // {
    //     for(j=0;j<10-i-1;j++)
    //     {
    //         if(*(a+j)>*(a+j+1))
    //             swap(a+j,a+j+1);
    //     }
    // }
    // for(i=0;i<10;i++)
    //     printf("%5d",a[i]);

    //29th
    // int i,a[3][4] = {{10,11,12,13},{20,21,22,23},{30,31,32,33}};
    // int *pa[3];
    // int (*p)[4];

    // p=a;
    // for(i=0;i<3;i++)
    //     pa[i] = a[i];
    // printf("%5d %5d %5d\n",pa[0][0],pa[0][1],pa[2][3]);
    // printf("%5d %5d %5d\n",p[0][0],p[0][1],p[2][3]);

    //30th
    // int *p1,*p2;
    // p1 = func301();
    // p2 = func302();

    // printf("%5d %5d\n",*p1,*p2);
    // free(p2);

    //31st
    // int i,a[3][4] = {{10,11,12,13},{20,21,22,23},{30,31,32,33}};
    // int *p = &a[0][0];
    // for(i=0;i<12;i++)
    //     printf("%3d",p[i]);

    //32nd
    // int a[2][3] = {100};
    // a[0][0] = 9;
    // printf("%d\n",*a[1,1,0]);

    //33rd
    int a[5] = {1}, b[5] = {1};
    if(a==b)
        printf("Same\n");
    else
        printf("Different\n");

    return 0;

}