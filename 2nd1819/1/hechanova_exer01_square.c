#include <stdio.h>

int main()
{
	float side;

	printf("Side: ");
	scanf("%f", &side);

	printf("Area: %f\n", side * side);

	return 0;
}