#include<stdio.h>
#include<stdlib.h>

int main(int arg,char *argv[])
{
	int r,dec=0,bin,p=1,temp;
	if(arg!=2)
	{
		printf("passing Arguents:- ./a.out binary_number\n");
		return 0;
	}

	bin = atoi(argv[1]);
	temp = bin;

	while(temp)
	{
		r = temp%10;
		dec += r*p;
		p *=2;
		temp /=10;
	}

	printf("Binary :- %d \tDecimal :- %d\n",bin,dec);
	return 0;
}

