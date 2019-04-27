#include <stdio.h>

int main()
{
	float base, height;

	printf("Base: ");
	scanf("%f", &base);

	printf("Height: ");
	scanf("%f", &height);

	printf("Area: %f\n", base * height);

	return 0;
}