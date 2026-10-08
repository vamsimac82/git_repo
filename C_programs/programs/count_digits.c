#include<stdio.h>
#include<stdlib.h>

int count_digits(unsigned long long int n)
{
	static int count;
	printf("count =%d n =%lld\n",count,n);

	if(n==0)
	{
		if(count==0)
			++count;
		return count;
	}
	else
	{
		++count;
		n = n/10;
		count_digits(n);
	}

}

int main(int arg, char *argv[])
{
	if(arg!=2)
	{
		printf("pass arguments:- ./a.out num\n");
		return 0;
	}

	printf("Number of digits in given number:- %d\n",count_digits(atoi(argv[1])));

	return 0;
}

