#include<stdio.h>
#define MAX 10

int y = 20;
static int m = 100;

int main()
{
	static int m = 23;
	// this is new  test program
	int x = 5;
	int a[1] = {2};
#ifdef MAX
	x += MAX;
#else
	x -= MAX;
#endif
	return 0;
}
