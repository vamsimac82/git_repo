#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//6th
void fun6(char s[])
{
    s = s+5;
    printf("%s\n",s);
}


//21st
char str21[50];
char *combine(char s1[],char s2[])
{
    char str[50];
    strcpy(str21,s1);
    strcat(str21,s2);

    return str21;
}

//24th
void fun24(char p[])
{
    if(*p!='f')
    {
        printf("%c",*p);
        fun24(++p);
    }
}

//25th
void fun25(char *p)
{
    if(*p)
    {
        fun25(p+1);
        printf("%c ",*p);
    }
}

//27th
void func271(char x[])
{
    x = "vams";
    printf("In func1... ");
    puts(x);
}

void func272(char x[])
{
    x[0] ='v'; x[1] ='a'; x[2] ='m'; x[3] ='s'; x[4] ='\0'; 
    printf("In func2... ");
    puts(x);
}

int main()
{
    //1st
    // int i=0;
    // char name[10] = {'v','a','m','s','i','\0'};
    // while(name[i])
    //     putchar(name[i++]);
    // putchar('\n');

    //2nd
    // char *str;
    // gets(str);
    // printf("String is %s\n",str);

    //3rd
    // char *s1 ="Good",*s2="Morning";
    // strcat(s1,s2);  //Segmentation fault (core dumped)
    // printf("%s",s1);

    //4th
    // char s[10]="How";
    // strcat(s,'?');  //Segmentation fault (core dumped)
    // printf("%s",s);

    //5th
    // char s[10]= "vamsi";
    // s=s+3;              //error: assignment to expression with array type
    // printf("%s",s);

    //6th
    // char s[]="vamsikrishna";
    // fun6(s);

    //7th
    // char s[] = {70,97,105,116,104,0};
    // printf("%s\n",s);

    //8th
    // char *ptr = "vamsi";
    // char a[] = "vamsi";
    // *(ptr+2) = 'b';     //Segmentation fault (core dumped)
    // a[2] = 'b';
    // puts(ptr);
    // puts(a);

    //9th
    // char str[] = "vamsikrishna";
    // char *p = str+5;
    // printf("%c\n",*p);
    // printf("%s\n",p);

    //10th
    // printf("%c\t","vamsikrishna"[2]);
    // printf("%c\t",*("vamsikrishna"+2));
    // printf("%s\t","vamsikrishna"+2);
    // printf("vamsikrishna"+2);
    // printf("\n");
    // printf("vamsikrishna"+strlen("vamsi"));
    // printf("\n");
    // printf("vamsikrishna"+sizeof("vamsi"));
    // printf("\n");
    
    //11th
    // char s[] = "vamsimac";
    // char *p = s;
    // p = p+3;
    // p[3] = 't';
    // printf("%s %s\n",s,p);

    //12th
    // char *p[] ={"orange","yellow","sky","blue","black"};
    // char a[10];
    // printf("%s %s %s\n",p[1],p[2],p[3]);
    // strcpy(a,"vamsi""now");
    // printf("%s\n",a);

    //13th
    // char s[15] = "vamsi",s2[]="mac";
    // strcpy(s+strlen(s),s2);
    // printf("%s\n",s);

    //14th
    // char s1[]="vamsi";
    // char s2[10];
    // strcpy(s2,s1);
    // if(s1==s2)
    //     printf("Same\n");
    // else
    //     printf("Different\n");

    //15th
    // char x[]="vamsi";
    // char y[20];
    // y = "mac";          //error: assignment to expression with array type
    // printf("%s %s\n",x,y);

    //16th
    // char s1[] = "vamsi";
    // char s2[] = {'v','a','m','s','i'};
    // if(strcmp(s1,s2)==0)
    //     printf("Same\n");
    // else
    //     printf("Different\n");

    //17th
    // char s1[] = "vamsi";
    // char s2[] = "krishna";
    // printf("%d \n",strlen(s1)-strlen(s2));
    // if(strlen(s1)-strlen(s2)>=0)
    //     puts(s1);
    // else
    //     puts(s2);

    //18th
    // char name[15]="vamsikrishna";
    // int i =0;
    // while(name[i])
    // {
    //     printf("%c ",name[i]);
    //     i+=3;
    // }

    //19th
    // char s[10][20];
    // int i;
    // for(i=0;i<10;i++)
    //     scanf("%s",s[i]);
    // for(i=0;i<10;i++)
    //     printf("%s\t",s[i]);

    //20th
    // char *s[10];
    // int i;
    // for(i=0;i<10;i++)
    //     scanf("%s",s[i]);       //Segmentation fault (core dumped)
    // for(i=0;i<10;i++)
    //     printf("%s\t",s[i]);

    //21st
    // char s[10],s2[10],*p;
    // strcpy(s,"vamsi");
    // strcpy(s2,"krishna");
    // p = combine(s,s2);
    // puts(p);

    //22nd
    // char *str = "vamsikrishna";
    // int i=0;
    // while(str[++i])
    // printf("%d ",i);

    //23rd
    // int d,m,y;
    // char date[11] = "25/10/2001";
    // date[2]=date[5]='\0';
    // sscanf(date,"%d",&d);
    // sscanf(date+3,"%d",&m);
    // sscanf(date+6,"%d",&y);
    // date[2]=date[5]='/';
    // printf("%d %d %d\n",d,m,y);
    // printf("%s\n",date);

    //24th
    // char *str="doutful";
    // fun24(str);

    //25th
    // char *str="tap";
    // fun25(str);

    //26th
    // char *ptr;
    // ptr = "My name is %s and Age is %d\n";
    // printf(ptr,"vamsi",25);

    //27th
    // char str[5];
    // puts(str);
    // func271(str);
    // puts(str);
    // func272(str);
    // puts(str);

    //28th
    // char *ptr;
    // ptr = "Every saint has a past,\
    // Every sinner has a future.\n";
    // printf("Giving " "is " "living " "\n");
    // puts(ptr);

    //29th
    // int marks;
    // char name[50];
    // printf("Enter marks: ");
    // scanf("%d",&marks);
    // __fpurge(stdin);        //To clear the Input stream
    // printf("Enter name: ");
    // gets(name);
    // puts(name);

    


    return 0;
}