#include<stdio.h>
#include<stdlib.h>

int count_bits(int data)
{
	int count=0;

	for(int i=31;i>=0;i--)
	{
		if((data >> i)&1)
			count++;
	}

	return count;
}

int main(int arg,char *argv[])
{
	if(arg!=2)
	{
		printf(" pass :- ./a.out data\n");
		return 0;
	}

	int data = atoi(argv[1]);
	printf(" count the set bits in given Number %d \n",data);

	printf("Number of set bits in %d is %d\n",data,count_bits(data));

	return 0;
}
