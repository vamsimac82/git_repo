#include<stdio.h>

void dec_conversation(int num,int n)
{
    int r,i;
    char a[20];
    for(i=0;num;i++)
    {
        r = num%n;
        if(r > 9)
            a[i] = 'A' + (r-10);
        else
            a[i] = r + '0';
        
        num /=n;
    }

    printf("i:- %d\n",i);
    for(--i;i>=0;i--)
        printf("%C ",a[i]);
    printf("\n");
}

int main()
{
    int num,choice;
    printf("Enter Number :- ");
    scanf("%d",&num);
    printf("Enter your choice:- \n1 Binary\n2 Octal\n3 Hexadecimal\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: dec_conversation(num,2);
                break;
        case 2: dec_conversation(num,8);
                break;
        case 3: dec_conversation(num,16);
                break;
    }
}