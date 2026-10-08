#include<stdio.h>

int main()
{
	int data =44, setbit = 4, clearbit = 2,revbit = 5;
	printf("data Binary = %15d\t%b\t0x%x\n",data,data,data);

	printf("Set Bit %d in data %d :- %5d\t%b\t0x%x\n",setbit,data,(data | (1<<setbit)),(data | (1<<setbit)), (data | (1<<setbit)));
	printf("Clear Bit %d in data %d :-  %d\t%b\t0x%x\n",clearbit,data,(data & ~(1<<clearbit)),(data & ~(1<<clearbit)),(data & ~(1<<clearbit)));
	printf("Rev Bit %d in data %d :- %5d\t%b\t0X%x\n", revbit,data,(data^(1<<revbit)),(data^(1<<revbit)),(data^(1<<revbit)));

	return 0;
}
