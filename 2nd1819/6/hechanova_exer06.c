/*
	This is a program that takes 3 integers as input from the user
	and prints out the prime numbers from 1 to an integer randomly
	chosen from the user inputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hechanova_exer06.h"

int main(void)
{
	int x, y, z, rand_int;
	x = get_int(&x, 'x');
	y = get_int(&y, 'y');
	z = get_int(&z, 'z');
	printf("\n");

	rand_int = get_rand_int(x, y, z);

	prime_out(rand_int);

	return 0;
}