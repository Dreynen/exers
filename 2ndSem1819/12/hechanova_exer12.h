typedef struct Food_item
{
	char name[50];
	float price;
	struct Food_item *next;
}
Food_item;

typedef struct Fastfood
{
	char name[50];
	Food_item *first;
	int count;
	struct Fastfood *next;
}
Fastfood;

int switchboard(Fastfood **, int *);
int get_int(char *);
float get_float(char *);
char * get_string(char *);
void capitalize(char *);
int compare_names(char *s, char *t);
Fastfood * found_ff(Fastfood *, char *);
void add_ff(Fastfood **, int *, int);
void add_ff_head(Fastfood **, Fastfood *);
void add_ff_tail(Fastfood **, Fastfood *);
void view(Fastfood *, int);
void view_all(Fastfood *);
void view_ff(Fastfood *);
Food_item * found_item(Fastfood *, char *);
void add_item(Fastfood *, int);
void add_item_head(Fastfood *, Food_item *);
void add_item_tail(Fastfood *, Food_item *);
void rm_ff(Fastfood **, int *, int);
void rm_ff_head(Fastfood **);
void rm_ff_tail(Fastfood **);
void rm_item(Fastfood *, int);
void rm_item_head(Fastfood *);
void rm_item_tail(Fastfood *);
void rm_items(Fastfood *);
void deallocate(Fastfood **);
void save(Fastfood *, int);
void load(Fastfood **, int *);

int switchboard(Fastfood ** first, int *count)
{
    printf("[1] Add a Fastfood to Head\n");
    printf("[2] Add a Fastfood to Tail\n");
    printf("[3] View All Fastfood Chains\n");
    printf("[4] View a Fastfood Chain\n");
    printf("[5] Add an Item from Head\n");
    printf("[6] Add an Item to Tail\n");
    printf("[7] Remove a Fastfood from Head\n");
    printf("[8] Remove a Fastfood from Tail\n");
    printf("[9] Remove an Item from Head\n");
    printf("[10] Remove an Item from Tail\n");
    printf("[11] Exit\n");
    int choice = get_int("Choice: ");
    switch(choice)
	{
		case 1:
			add_ff(first, count, 1);
			break;
		case 2:
			add_ff(first, count, 0);
			break;
		case 3:
			view(*first, 1);
			break;
		case 4:
			view(*first, 0);
			break;
		case 5:
			add_item(*first, 1);
			break;
		case 6:
			add_item(*first, 0);
			break;
		case 7:
			rm_ff(first, count, 1);
			break;
		case 8:
			rm_ff(first, count, 0);
			break;
		case 9:
			rm_item(*first, 1);
			break;
		case 10:
			rm_item(*first, 0);
			break;
		case 11:
			break;
		default:
			printf("1 - 11 only.\n");
	}

	if(choice == 11)
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
/* prompts user for positive float */
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

char * get_string(char * prompt)
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
// returns a positive int if s comes alphabetically before t or zero if strings are the same word
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

void add_ff(Fastfood **first, int * count, int option)
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
		if(option)
		{
			// add fastfood to front of linked list
			add_ff_head(first, new);
		}
		else
		{
			// add fastfood to end of linked list
			add_ff_tail(first, new);
		}
		printf("\nFastfood added successfully\n\n");
		(*count)++;
	}
	else
	{
		printf("\nFastfood already in list.\n\n");
	}

	free(name);
}

void add_ff_head(Fastfood **first, Fastfood *new)
/* adds node to front of linked list */
{
	new -> next = *first;
	*first = new;
}

void add_ff_tail(Fastfood **first, Fastfood *new)
/*
	adds node to end of linked list if there are
	1> nodes in list; else add to front
*/
{
	if(*first)
	{
		for(Fastfood *ptr = *first; ptr; ptr = ptr -> next)
		{
			if(!(ptr -> next))
			{
				new -> next = NULL;
				ptr -> next = new;
				break;
			}
		}
	}
	else
	{
		add_ff_head(first, new);
	}
}

void view(Fastfood *first, int option)
/*
	checks if a list exists; prints fastfood info if list exists
*/
{
	if(first)
	{
		if(option)
		{
			view_all(first);
		}
		else
		{char *name = get_string("Enter name of fastfood: ");
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
	returns a food item pointer if it is found in list
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

void add_item(Fastfood *first, int option)
/*
	gets name of fastfood to which user will add item and checks
	if it exists; gets name of food item and checks if already in list
	and allocs new food item if food item is not found in list
*/
{
	if(first)
	{
		char *name = get_string("Enter name of fastfood: ");
		Fastfood *ff = found_ff(first, name);
		if(ff)
		{
			char *item_name = get_string("Enter name of food item: ");
			if(!found_item(ff, item_name))
			{
				// allocate space for new food item node
				Food_item *new = malloc(sizeof(Food_item));
				strcpy(new -> name, item_name);
				new -> price = get_float("Enter price: ");
				if(option)
				{
					// add food item to front of item linked list
					add_item_head(ff, new);
				}
				else
				{
					// add food item to end of item linked list
					add_item_tail(ff, new);
				}

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

void add_item_head(Fastfood *ff, Food_item *new)
/* adds node to front of linked list */
{
	new -> next = ff -> first;
	ff -> first = new;
}

void add_item_tail(Fastfood *ff, Food_item *new)
/*
	adds node to end of linked list if there
	are 1> nodes in list; else adds to front
*/
{
	if(ff -> first)
	{
		for(Food_item *tmp = ff -> first; tmp; tmp = tmp -> next)
		{
			if(!(tmp -> next))
			{
				tmp -> next = new;
				new -> next = NULL;
				break;
			}
		}
	}
	else
	{
		add_item_head(ff, new);
	}
}

void rm_ff(Fastfood ** first, int * count, int option)
/*
	removes fastfood from front or end of linked list and decrements
	the fastfood counter
*/
{
	if(*first)
	{
		if(option)
		{
			rm_ff_head(first);
		}
		else
		{
			rm_ff_tail(first);
		}

		printf("\nFastfood removed successfully.\n\n");
		(*count)--;
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
	rm_items(ptr);
	*first = ptr -> next;
	free(ptr);
}

void rm_ff_tail(Fastfood **first)
/*
	deallocates linked list of food items and removes
	fastfood node from end of list if there are 1>
	nodes in list, else removes from front
*/

{
	if(!((*first) -> next))
	{
		rm_ff_head(first);
	}
	else
	{
		for(Fastfood *ptr = *first; ptr -> next; ptr = ptr -> next)
		{
			if(!(ptr -> next -> next))
			{
				rm_items(ptr -> next);
				free(ptr -> next);
				ptr -> next = NULL;
				break;
			}
		}
	}
}

void rm_item(Fastfood *first, int option)
/* gets name of fastfood from which an item will be removed */
{
	if(first)
	{
		char *name = get_string("Enter name of fastfood: ");
		Fastfood *ff = found_ff(first, name);
		if(ff)
		{
			if(ff -> first)
			{
				if(option)
				{
					// remove item from front of list
					rm_item_head(ff);
				}
				else
				{
					// remove item from end of list
					rm_item_tail(ff);
				}

				printf("\nItem removed successfully.\n\n");
				(ff -> count)--;
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

void rm_item_tail(Fastfood *ff)
/*
	removes food item node from end of list if there are
	1> nodes in list; else removes from front
*/
{
	if(!(ff -> first -> next))
	{
		rm_item_head(ff);
	}
	else
	{
		for(Food_item *tmp = ff -> first; tmp -> next; tmp = tmp -> next)
		{
			if(!(tmp -> next -> next))
			{
				free(tmp -> next);
				tmp -> next = NULL;
				break;
			}
		}
	}
}

void rm_items(Fastfood *ff)
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
	{
		rm_ff_head(first);
	}
}

void save(Fastfood *first, int count)
/* saves data to a text file */
{
	FILE *file = fopen("fastfoods.txt", "w");
	if(file)
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
	{
		fscanf(file, "%d\n", count);
		for(int i = 0; i < (*count); i++)
		{
			Fastfood *new_ff = malloc(sizeof(Fastfood));
			fscanf(file, "%s %d\n", new_ff -> name, &(new_ff -> count));
			for(int j = 0; j < (new_ff -> count); j++)
			{
				Food_item *new_item = malloc(sizeof(Food_item));
				fscanf(file, "%s %f\n", new_item -> name, &(new_item -> price));
				add_item_tail(new_ff, new_item);
			}
			add_ff_tail(first, new_ff);
		}
		fclose(file);
	}
}