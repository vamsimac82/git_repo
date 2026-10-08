#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("In main()...\n");
	system("ls");
	system("ls -l;pwd;date");
	printf("Exit main()...\n");

	return 0;
}
