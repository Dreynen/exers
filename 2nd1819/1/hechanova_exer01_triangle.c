#include <stdio.h>

int main()
{
	float height, base;

	printf("Height: ");
	scanf("%f", &height);

	printf("Base: ");
	scanf("%f", &base);

	printf("Area: %f\n", height * base);

	return 0;
}