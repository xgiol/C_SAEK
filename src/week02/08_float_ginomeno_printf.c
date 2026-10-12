#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float ar1, ar2;
	printf("Dose dyo arithmous:");
	scanf("%f %f", &ar1, &ar2);
	printf("\n %9.2f\n", ar1);
	printf("x%9.2f\n", ar2);
	printf("==========\n");
	printf(" %9.2f\n", ar1*ar2);

	return 0;
}

