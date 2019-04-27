/*
	This is a program that lets people play the
	classic game FLAMES in an automated manner.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hechanova_exer09.h"

int main(void)
{
	int counter = 0;
	char * name1 = get_string();
	char * name2 = get_string();

	// filter the 2 strings of non-alpha chars
	filter(name1);
	filter(name2);

	// outputs the corresponding word in FLAMES
	FLAMES(get_flames(name1, name2));

	free(name1);
	free(name2);
}