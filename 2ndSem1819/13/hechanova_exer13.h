typedef struct Food_item
{
	char name[50];
	float price;
	struct Food_item *next;
} Food_item;

typedef struct Fastfood
{
	char name[50];
	Food_item *first;
	int count;
	struct Fastfood *next;
} Fastfood;

int switchboard(Fastfood ** first, int *count);
int get_int(char *prompt);
float get_float(char *prompt);
char * get_string(char *prompt);
void capitalize(char *s);
int compare_names(char *s, char *t);
Fastfood * found_ff(Fastfood *first, char *name);
void add_ff(Fastfood **first, int * count);
void add_ff_node(Fastfood **first, Fastfood *new);
void view(Fastfood *first, int option);
void view_all(Fastfood *first);
void view_ff(Fastfood *ptr);
Food_item * found_item(Fastfood *ff, char *name);
void add_item(Fastfood *first);
void add_item_node(Fastfood *ff, Food_item *new);
void rm_ff(Fastfood ** first, int * count);
void rm_ff_node(Fastfood **first, Fastfood *to_delete);
void rm_item(Fastfood *first);
void rm_item_head(Fastfood *ff);
void rm_item_node(Fastfood *ff, Food_item *to_delete);
void rm_all_items(Fastfood *ff);
void deallocate(Fastfood **first);
void save(Fastfood *first, int count);
void load(Fastfood **first, int *count);

int switchboard(Fastfood ** first, int *count)
{
    printf("[1] Add a Fastfood\n");
    printf("[2] View All Fastfood Chains\n");
    printf("[3] View a Fastfood Chain\n");
    printf("[4] Add an Item\n");
    printf("[5] Remove a Fastfood\n");
    printf("[6] Remove an Item\n");
    printf("[7] Exit\n");
    int choice = get_int("Choice: ");
    switch(choice)
	{
		case 1:
			add_ff(first, count);
			break;
		case 2:
			view(*first, 1);
			break;
		case 3:
			view(*first, 0);
			break;
		case 4:
			add_item(*first);
			break;
		case 5:
			rm_ff(first, count);
			break;
		case 6:
			rm_item(*first);
			break;
		case 7:
			break;
		default:
			printf("1 - 7 only.\n");
	}

	if(choice == 7)
	{
		return 1;
	}

	return 0;
}

int get_int(char *prompt)
/* gets an integer from the user */
{
	int i;
	printf("%s", prompt);
	scanf("%d", &i);

	return i;
}

float get_float(char *prompt)
/* prompts user for positive integer */
{
	float f;
	do
	{
		printf("%s", prompt);
		scanf("%f", &f);
		if(f < 0)
		{
			printf("\nPlease enter a positive number.\n");
		}
	}
	while(f < 0);

	return f;
}

char * get_string(char *prompt)
/* gets a string from the user */
{
	char s[45], *t;
	printf("%s", prompt);
	scanf("%s", s);
	t = malloc(strlen(s) + 1);
	strcpy(t, s);

	return t;
}

void capitalize(char *s)
/* replaces string parameter with a capitalized string */
{
	for(int i = 0, n = strlen(s); i < n; i++)
	{
		s[i] = toupper(s[i]);
	}
}

int compare_names(char *s, char *t)
// returns a positive int if s comes alphabetically before t
{
	char namecpy0[30];
	char namecpy1[30];
	strcpy(namecpy0, s);
	strcpy(namecpy1, t);
	capitalize(namecpy0);
	capitalize(namecpy1);

	return strcmp(namecpy0, namecpy1);
}

Fastfood * found_ff(Fastfood *first, char *name)
/*
	returns a Fastfood pointer if fastfood with same name
	is found in list else returns NULL
*/
{
	for(Fastfood *ptr = first; ptr; ptr = ptr -> next)
	{
		if(!compare_names(ptr -> name, name))
		{
			return ptr;
		}
	}

	return NULL;
}

void add_ff(Fastfood **first, int * count)
/*
	gets fastfood name from user and checks if fastfood is
	already in list, alloc new fastfood node if not found
*/
{
	char *name = get_string("Enter name of fastfood: ");
	if(!found_ff(*first, name))
	{
		// allocate space for new fastfood node
		Fastfood *new = malloc(sizeof(Fastfood));
		strcpy(new -> name, name);
		new -> first = NULL;
		new -> count = 0;
		new -> next = NULL;
		add_ff_node(first, new);

		printf("\nFastfood added successfully.\n\n");
		(*count)++;
	}
	else
	{
		printf("\nFastfood already in list.\n\n");
	}

	free(name);
}

void add_ff_node(Fastfood **first, Fastfood *new)
/*
	add node to list in sorted manner
*/
{
	if(!(*first) || compare_names((*first) -> name, new -> name) > 0)
	// if list is NULL or new node comes before first node
	{
		new -> next = *first;
		*first = new;
	}
	else
	{
		for(Fastfood *ptr = *first; ptr; ptr = ptr -> next)
		{
			if(compare_names(ptr -> name, new -> name) > 0)
			// if new node is before a certain node ptr
			{
				for(Fastfood *prev = *first; prev; prev = prev -> next)
				// get node before ptr
				{
					if((prev -> next) == ptr)
					{
						new -> next = ptr;
						prev -> next = new;
						break;
					}
				}
				break;
			}

			if(!(ptr -> next))
			// if tail node
			{
				ptr -> next = new;
				new -> next = NULL;
				break;
			}
		}
	}
}

void view(Fastfood *first, int option)
/*
	checks if a list exists; prints fastfood info if list exists
*/
{
	if(first)
	//	check if list is not NULL
	{
		if(option)
		{
			view_all(first);
		}
		else
		{
			char *name = get_string("Enter name of fastfood: ");
			Fastfood *ptr = found_ff(first, name);
			if(ptr)
			{
				view_ff(ptr);
			}
			else
			{
				printf("\nFastfood not found.\n\n");
			}

			free(name);
		}
	}
	else
	{
		printf("\nNo fastfoods in list yet.\n\n");
	}
}

void view_all(Fastfood *first)
/* prints all fastfoods in list and their menus */
{
	for(Fastfood *ptr = first; ptr; ptr = ptr -> next)
	{
		view_ff(ptr);
	}
}

void view_ff(Fastfood *ptr)
/* prints details of fastfood parameter */
{
	printf("%s\n", ptr -> name);
	if(ptr -> first)
	//	print food items if fastfood has list of items
	{
		for(Food_item *tmp = ptr -> first; tmp; tmp = tmp -> next)
		{
			printf("%s\t%0.2f\n", tmp -> name, tmp -> price);
		}
	}
	printf("\n");
}

Food_item * found_item(Fastfood *ff, char *name)
/*
	returns a food item pointer item with same name is found in list
	else returns NULL
*/
{
	for(Food_item *tmp = ff -> first; tmp; tmp = tmp -> next)
	{
		if(!compare_names(tmp -> name, name))
		{
			return tmp;
		}
	}

	return NULL;
}

void add_item(Fastfood *first)
/*
	gets name of fastfood to which user will add item and checks
	if it exists; gets name of food item and checks if already in list
	and allocs new food item if food item is not found in list
*/
{
	if(first)
	//	check if fastfood list is not NULL
	{
		char *name = get_string("Enter name of fastfood: ");
		Fastfood *ff = found_ff(first, name);
		if(ff)
		//	check if fastfood exists
		{
			char *item_name = get_string("Enter name of food item: ");
			if(!found_item(ff, item_name))
			//	if item with same name is not in list yet
			{
				// allocate space for new food item node
				Food_item *new = malloc(sizeof(Food_item));
				strcpy(new -> name, item_name);
				new -> price = get_float("Enter price: ");
				new -> next = NULL;
				add_item_node(ff, new);

				printf("\nFood item added successfully.\n\n");
				(ff -> count)++;
			}
			else
			{
				printf("\nFood item already in list.\n\n");
			}

			free(item_name);
		}
		else
		{
			printf("\nFastfood does not exist.\n\n");
		}

		free(name);
	}
	else
	{
		printf("\nNo fastfoods in list yet.\n\n");
	}
}

void add_item_node(Fastfood *ff, Food_item *new)
/*
	adds node to end of linked list if there
	are 1> nodes in list; else adds to front
*/
{
	if(!(ff -> first) || (ff -> first -> price) > (new -> price))
	// if list is NULL or new node comes before head node
	{
		new -> next = ff -> first;
		ff -> first = new;
	}
	else
	{
		for(Food_item *ptr = ff -> first; ptr; ptr = ptr -> next)
		{
			if((ptr -> price) > (new -> price))
			// if new is before a certain node ptr
			{
				for(Food_item *prev = ff -> first; prev; prev = prev -> next)
				// get node before ptr
				{
					if((prev -> next) == ptr)
					{
						new -> next = ptr;
						prev -> next = new;
						break;
					}
				}
				break;
			}

			if(!(ptr -> next))
			// if tail node
			{
				ptr -> next = new;
				new -> next = NULL;
				break;
			}
		}
	}
}

void rm_ff(Fastfood ** first, int * count)
/*
	removes fastfood from front or end of linked list and decrements
	the fastfood counter
*/
{
	if(*first)
	//	check if list is not NULL
	{
		char *name = get_string("Enter name of fastfood: ");
		Fastfood *to_delete = found_ff(*first, name);
		if(to_delete)
		//	check if node to be deleted exists
		{
			rm_ff_node(first, to_delete);

			printf("\nFastfood removed successfully.\n\n");
			(*count)--;
		}
		else
		{
			printf("\nFastfood not found.\n\n");
		}

		free(name);
	}
	else
	{
		printf("\nNo fastfoods in list yet.\n\n");
	}
}

void rm_ff_head(Fastfood **first)
/*
	deallocates linked list of food items and removes
	fastfood node from front of list */
{
	Fastfood *ptr = *first;
	rm_all_items(ptr);
	*first = ptr -> next;
	free(ptr);
}

void rm_ff_node(Fastfood **first, Fastfood *to_delete)
/*
	deallocates linked list of food items and removes
	fastfood node from list
*/

{
	if(!((*first) -> next) || (*first) == to_delete)
	// if there is only one item in list or if head node is to be deleted
	{
		rm_ff_head(first);
	}
	else
	{
		for(Fastfood *prev = *first; prev; prev = prev -> next)
		// get node before the node which will be removed
		{
			if((prev -> next) == to_delete)
			{
				prev -> next = to_delete -> next;
				free(to_delete);
				break;
			}
		}
	}
}

void rm_item(Fastfood *first)
/*	removes a specific food item from a fastfood if fastfood and food item exist */
{
	if(first)
	//	check if fastfood list is not NULL
	{
		char *name = get_string("Enter name of fastfood: ");
		Fastfood *ff = found_ff(first, name);
		if(ff)
		{
			if(ff -> first)
			{
				char *item_name = get_string("Enter name of food item: ");
				Food_item *to_delete = found_item(ff, item_name);
				if(to_delete)
				{
					rm_item_node(ff, to_delete);

					printf("\nItem removed successfully.\n\n");
					(ff -> count)--;
				}
				else
				{
					printf("\nFood item not found.\n\n");
				}
			}
			else
			{
				printf("\nNo food item in fastfood yet.\n\n");
			}
		}
		else
		{
			printf("\nFastfood not found.\n\n");
		}

		free(name);
	}
	else
	{
		printf("\nNo fastfoods in list yet.\n\n");
	}
}

void rm_item_head(Fastfood *ff)
/* removes food item node from the front of list */
{
	Food_item *tmp = ff -> first;
	ff -> first = tmp -> next;
	free(tmp);
}

void rm_item_node(Fastfood *ff, Food_item *to_delete)
/*
	removes food item node from end of list if there are
	1> nodes in list; else removes from front
*/
{
	if(!(ff -> first -> next) || (ff -> first) == to_delete)
	// if there is only one item in list or if head node is to be deleted
	{
		rm_item_head(ff);
	}
	else
	{
		for(Food_item *prev = ff -> first; prev; prev = prev -> next)
		// get node before node which will be deleted
		{
			if((prev -> next) == to_delete)
			{
				prev -> next = to_delete -> next;
				free(to_delete);
				break;
			}
		}
	}
}

void rm_all_items(Fastfood *ff)
/* removes all items in a fastfood's linked list of food items */
{
	while(ff -> first)
	{
		rm_item_head(ff);
	}
}

void deallocate(Fastfood **first)
/* removes all fastfoods and their menus from linked list */
{
	while(*first)
	// while list is not NULL
	{
		rm_ff_head(first);
	}
}

void save(Fastfood *first, int count)
/* saves data to a text file */
{
	FILE *file = fopen("fastfoods.txt", "w");
	if(file)
	//	check if file was opened properly
	{
		fprintf(file, "%d\n", count);
		for(Fastfood *ptr = first; ptr; ptr = ptr -> next)
		{
			fprintf(file, "%s %d\n", ptr -> name, ptr -> count);
			for(Food_item *tmp = ptr -> first; tmp; tmp = tmp -> next)
			{
				fprintf(file, "%s %0.2f\n", tmp -> name, tmp -> price);
			}
		}
		fclose(file);
	}
}

void load(Fastfood **first, int *count)
/*
	loads count values from saved file, allocates fastfood and
	food item nodes accordingly, and adds nodes to linked lists.
*/
{
	FILE *file = fopen("fastfoods.txt", "r");
	if(file)
	// check if file was opened properly
	{
		fscanf(file, "%d\n", count);
		for(int i = 0; i < (*count); i++)
		{
			Fastfood *new_ff = malloc(sizeof(Fastfood));
			fscanf(file, "%s %d\n", new_ff -> name, &(new_ff -> count));
			new_ff -> first = NULL;
			for(int j = 0; j < (new_ff -> count); j++)
			{
				Food_item *new_item = malloc(sizeof(Food_item));
				fscanf(file, "%s %f\n", new_item -> name, &(new_item -> price));
				add_item_node(new_ff, new_item);
			}
			add_ff_node(first, new_ff);
		}
		fclose(file);
	}
}