#include<stdio.h>

int main()
{
	int i = 13;
	float f = 5;

	printf("int i =13; \nfloat f =5;\n");
	printf("Imlict TypeCasting i/f = %f \t int -> float\n", i/f);
	printf("explict TypeCasting i/(int)f = %d \tfloat -> int\n", i/(int)f);

	return 0;
}
