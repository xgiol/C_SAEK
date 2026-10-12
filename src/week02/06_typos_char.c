#include <stdio.h>

int main(void)
{
	// Set stdout to be unbuffered
	// This must be done BEFORE any other I/O operations
	setvbuf(stdout, NULL, _IONBF, 0);

	char ch1,ch2;
	int ar1,ar2;
	printf("Dose enan xarakthra kai enan aritmo:");
	scanf("%c %d",&ch1,&ar1);
	printf("Edoses %c kai %d\n",ch1,ar1);
	printf("Dose akoma enan xarakthra kai enan aritmo:");
	scanf("%c %d",&ch2,&ar2);
	printf("Edoses %c kai %d\n",ch2,ar2);
	return 0;
}
