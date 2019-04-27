/*
	This is a program that takes an array of positive numbers
	and chooses a number from the array and prints out factors
	of the number that are also in the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include "hechanova_exer07.h"

int get_int(char *);
void print_menu();
void print_factors(int, int *, int);

int main(void)
{
	int choice, index, size, *arr = NULL;

	do
	{
		size = get_int("Enter size of array: ");
	}
	while (size < 1);

	do
	{
		print_menu();
		choice = get_int("Choice: ");
		switch(choice)
		{
			case 0:
				if(!arr)
				{
					arr = (int *) malloc(sizeof(int) * size);
				}

				for (int i = 0; i<size; i++)
				{
					arr[i] = get_int("Enter number: ");
				}

				break;

			case 1:
				if(arr)
				{
					do
					{
						index = get_int("Enter index of element: ");
						if (index >= size || index < 0)
						{
							printf("Invalid index!\n");
						}
					}
					while(index >= size || index < 0);

					print_factors(size, arr, index);
				}
				else
				{
					printf("\n\nInvalid! Array still empty!\n");
				}

				break;

			case 2:
				if(arr)
				{
					for (int i = 0; i < size; i++)
					{
						print_factors(size, arr, i);
					}
				}
				else
				{
					printf("\n\nInvalid! Array still empty!\n");
				}

				break;

			case 3:
				printf("\nGoodbye!\n");
				break;

			default:
				printf("\n0 - 3 only.\n");
		}
	}
	while(choice != 3);

	free(arr);

	return 0;
}