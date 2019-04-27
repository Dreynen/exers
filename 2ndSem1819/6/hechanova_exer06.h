// gets an integer from the user
int get_int (int * n, char c)
{
	printf("Enter %c: ", c);
	scanf("%d", n);

	return *n;
}

// gets a random integer from the user inputs
int get_rand_int(int x, int y, int z)
{
	srand(time(NULL));
	int n = rand() % 3;

	if (n == 0) return x;
	else if (n == 1) return y;
	else return z;
}

// checker if prime
int isprime(int n)
{
	for(int i = 2; i < n; i++)
	{
		if(n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

// outputs all found prime numbers
void prime_out(int n)
{
	printf("Int is %d\n\n", n);
	for(int i = 2; i <= n; i++)
	{
		if(isprime(i))
		{
			printf("%d\n", i);
		}
	}
}
