#include <stdio.h>

int main()
{
	float length, width;

	printf("Length: ");
	scanf("%f", &length);

	printf("Width: ");
	scanf("%f", &width);

	printf("Area: %f\n", length * width);

	return 0;
}