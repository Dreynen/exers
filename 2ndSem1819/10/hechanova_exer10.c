#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hechanova_exer10.h"

int main(void)
{
	Fastfood ff_chain[50];
	int ff_count = 0, choice = 0;

	while(1)
	{
		menu_out();
		printf("Choice: ");
		choice = get_int();

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

	deallocate(ff_chain, ff_count);

	return 0;
}