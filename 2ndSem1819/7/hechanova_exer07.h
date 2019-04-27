int get_int(char * prompt)
{
	// gets an integer from the user
	int n;
	do
	{
		printf("%s", prompt);
		scanf("%d", &n);
	}
	while(n < 0);

	return n;
}

void print_menu()
{
	// prints a menu for the user
	printf("\n------------------------------------\n");
	printf("0. Input numbers\n");
	printf("1. Factors of an element in array\n");
	printf("2. Factors of all elements in array\n");
	printf("3. Exit\n");
	printf("------------------------------------\n");
}

void print_factors(int size, int * arr, int index)
{
	// prints the factors of the integer that are in the array
	printf("The factors of %d in the array are:", *(arr + index));
	for (int i = 0; i < size; i++)
	{
		if(*(arr + index) == *(arr + i))
		{
			continue;
		}
		else if(*(arr + index) % *(arr + i) == 0)
		{
			printf(" %d", *(arr + i));
		}
	}
	printf("\n");
}