/* This program is a calculator for the areas of various geometrical shapes */

#include <stdio.h>
#define pi 3.14

int main()
{
	int choice = 0;

	do
	{
		float x = 0, y = 0, z = 0;

		printf("MENU\n");
		printf("[1] Triangle\n");
		printf("[2] Square\n");
		printf("[3] Rectangle\n");
		printf("[4] Parallelogram\n");
		printf("[5] Trapezoid\n");
		printf("[6] Circle\n");
		printf("[7] Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("\nTriangle\n");
				printf("Base: ");
				scanf("%f", &x);
				printf("Height: ");
				scanf("%f", &y);

				printf("Area: %.2f\n", x * y * 0.5);
				break;

			case 2:
				printf("\nSquare\n");
				printf("Side: ");
				scanf("%f", &x);

				printf("Area: %.2f\n", x * x);
				break;

			case 3:
				printf("\nRectangle\n");
				printf("Length: ");
				scanf("%f", &x);
				printf("Width: ");
				scanf("%f", &y);

				printf("Area: %.2f\n", x * y);
				break;

			case 4:
				printf("\nParallelogram\n");
				printf("Base: ");
				scanf("%f", &x);
				printf("Height: ");
				scanf("%f", &y);

				printf("Area: %.2f\n", x * y);
				break;

			case 5:
				printf("\nTrapezoid\n");
				printf("Base: ");
				scanf("%f", &x);
				printf("Top: ");
				scanf("%f", &y);
				printf("Height: ");
				scanf("%f", &z);

				printf("Area: %.2f\n", (x + y) * z * 0.5);
				break;

			case 6:
				printf("\nCircle\n");
				printf("Radius: ");
				scanf("%f", &x);

				printf("Area: %.2f\n", x * x * pi);
				break;

			case 7:
				break;

			default:
				printf("Please choose from 1 - 7 only.\n");
		}
		printf("\n");
	}
	while(choice != 7);

	return 0;
}