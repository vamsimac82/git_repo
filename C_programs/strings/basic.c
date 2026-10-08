#include<stdio.h>

int main()
{
    // 1st
    // char name[40];
    // printf("Enter the Name:- ");
    // scanf("%s",name);
    // printf("%s\n",name);
    
    // 2nd
    // char name[40];
    // printf("Enter the Name:- ");
    // gets(name);
    // printf("%s\n",name);

    // 3rd
    // char name[5];
    // printf("Sizeof(name) :- %lu\n",sizeof(name));
    // gets(name);
    // printf("Entered name:- %s\n",name);

    // 4th
    // char name[5];
    // printf("Sizeof(name) :- %lu\n",sizeof(name));
    // fgets(name,sizeof(name),stdin);
    // printf("Entered name:- %s\n",name);

    return 0;
}

/* output */
/*

1st
Enter the Name:- vamsi krishna
vamsi

2nd
Enter the Name:- vamsi krishna
vamsi krishna

3rd
Sizeof(name) :- 5
vamsi mac
Entered name:- vamsi mac
*** stack smashing detected ***: terminated
Aborted (core dumped)

4th
Sizeof(name) :- 5
mnbvcxa
Entered name:- mnbv



*/

