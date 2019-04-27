#include <stdio.h>

int main()
{
	float base, top, height;

	printf("Base: ");
	scanf("%f", &base);

	printf("Top: ");
	scanf("%f", &top);

	printf("Height: ");
	scanf("%f", &height);

	printf("Area: %f\n", base * top * height);

	return 0;
}