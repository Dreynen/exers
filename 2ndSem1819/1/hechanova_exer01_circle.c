#include <stdio.h>
#define pi 3.14

int main()
{
	float radius;

	printf("Radius: ");
	scanf("%f", &radius);

	printf("Area: %f\n", pi * radius * radius);

	return 0;
}