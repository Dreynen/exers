/*
	This is a program that takes fastfoods and fastfood menu items from
	user input and stores them in a file.
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hechanova_exer11.h"

int main(void)
{
	Fastfood ff_chain[50];
	int ff_count = 0, choice = 0;
	FILE * file = fopen("fastfoods.txt", "r");
	if(file)
	{
		read_fastfoods(file, ff_chain, &ff_count);

		fclose(file);
	}

	while(1)
	{
		menu_out();
		choice = get_int("Choice: ");

		if(choice == 5)
		{
			break;
		}

		switch(choice)
		{
			case 1:
				add_ff(ff_chain, &ff_count);
				break;
			case 2:
				view_ff(ff_chain, ff_count);
				break;
			case 3:
				view_menu(ff_chain, ff_count);
				break;
			case 4:
				add_item(ff_chain, ff_count);
				break;
			default:
				printf("\n1 - 5 only\n.");
		}
	}

	printf("\n\n...Goodbye!\n");
	save_ff(ff_chain, ff_count);

	return 0;
}