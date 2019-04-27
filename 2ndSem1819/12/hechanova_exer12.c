/*
	This program is a fastfood list management application
	that takes fastfoods and fastfood menus from userinput
	and saves them to a file named "fastfoods.txt". This
	program uses singly linked lists for somewhat efficient
	and dynamic resizing of a fastfood list and each fastfood's
	menus.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hechanova_exer12.h"

int main(void)
{
	// first fastfood node in linked list; NULL when list is empty
	Fastfood *first = NULL;
	int count = 0;

	// loads saved data from a text file, if any
	load(&first, &count);

	while(1)
	{
		if(switchboard(&first, &count))
		{
			break;
		}
	}

	// save data into text file
	save(first, count);
	// free all allocated memory
	deallocate(&first);

	printf("\nGoodbye!...\n");

	return 0;
}