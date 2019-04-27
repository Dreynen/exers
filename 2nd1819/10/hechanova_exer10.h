typedef struct Food_item
{
	char * name;
	float price;
}Food_item;

typedef struct Fastfood
{
	char * name;
	Food_item Menu[30];
	int item_count;
}Fastfood;

int get_int()
/* gets an int from the user */
{
	int n;
	do
	{
		scanf("%d", &n);
		if(n < 0 || n > 5)
		{
			printf("\n1 - 5 only.\n");
		}
	}
	while(n < 0 || n > 5);

	return n;
}

char * get_string()
/* gets a string from the user */
{
	char s[100];
	scanf("%s", s);
	char * t = malloc(strlen(s) + 1);
	strcpy(t, s);

	return t;
}

float get_price()
/* gets a float from the user */
{
	float f;
	do
	{
		scanf("%f", &f);
	}while(f < 0);

	return f;
}

char * capitalize(char * s)
/* capitalizes a string */
{
	for(int i = 0, n = strlen(s); i < n; i++)
	{
		s[i] = toupper(s[i]);
	}

	return s;
}

int check_ff(Fastfood ff_chain[50], int ff_count, char * ff_name)
/* checks if a fastfood already exists */
{
	char name1[50], name2[50];
	strcpy(name2, ff_name);
	strcpy(name2, capitalize(name2));

	for(int i = 0; i < ff_count; i++)
	{
		strcpy(name1, ff_chain[i].name);
		strcpy(name1, capitalize(name1));
		if(strcmp(name1, name2) == 0)
		{
			return i;
		}
	}
	return -1;
}

void add_ff(Fastfood ff_chain[50], int * ff_count)
/* adds a fastfood */
{
	Fastfood new_ff;
	printf("Enter fastfood name: ");
	new_ff.name = get_string();
	if(check_ff(ff_chain, *ff_count, new_ff.name) == -1)
	{
		new_ff.item_count = 0;
		ff_chain[(*ff_count)] = new_ff;
		(*ff_count)++;
	}
	else
	{
		printf("\nFastfood chain already exists!\n");
		free(new_ff.name);
	}
	printf("\n");
}

int check_menu(Fastfood ff_chain, char * item_name)
/* checks if an item already exists in a menu */
{
	char name1[50], name2[50];
	strcpy(name2, item_name);
	strcpy(name2, capitalize(name2));

	for(int i = 0; i < ff_chain.item_count; i++)
	{
		strcpy(name1, ff_chain.Menu[i].name);
		strcpy(name1, capitalize(name1));
		if(strcmp(name2, name1) == 0)
		{
			return i;
		}
	}
	return -1;
}

void add_item(Fastfood ff_chain[50], int ff_count)
/* adds an item to the menu of a chosen fastfood */
{
	printf("Enter fastfood chain: ");
	char * ff_name = get_string();
	int index = check_ff(ff_chain, ff_count, ff_name);

	if(index != -1)
	{
		Food_item item;
		printf("Enter item name: ");
		item.name = get_string();
		if(check_menu(ff_chain[index], item.name) == -1)
		{
			printf("Enter price: ");
			item.price = get_price();
			ff_chain[index].Menu[ff_chain[index].item_count] = item;
			ff_chain[index].item_count++;
		}
		else
		{
			printf("\nFood item already exists.\n");
			free(item.name);
		}
	}
	else
	{
		printf("\nFastfood does not exist.\n");
		free(ff_name);
	}
	printf("\n");
}

void view_menu(Fastfood ff_chain[50], int ff_count)
/* outputs a fastfood name and its menu */
{
	printf("Enter fastfood chain: ");
	char * ff_name = get_string();
	int index = check_ff(ff_chain, ff_count, ff_name);

	if(index != -1)
	{
		printf("%s\n", ff_chain[index].name);
		for(int i = 0; i < ff_chain[index].item_count; i++)
		{
			printf("%s\t%.2f\n", ff_chain[index].Menu[i].name, ff_chain[index].Menu[i].price);
		}
	}
	else
	{
		printf("\nFastfood does not exist.\n");
	}
	printf("\n");

	free(ff_name);
}

void view_ff(Fastfood ff_chain[50], int ff_count)
/* outputs all fastfoods and their menus */
{
	printf("\nCurrent fastfood chains:\n");
	for(int i = 0; i < ff_count; i++)
	{
		printf("%s\n", ff_chain[i].name);
		for(int j = 0; j < ff_chain[i].item_count; j++)
		{
			printf("%s\t%.2f\n", ff_chain[i].Menu[j].name, ff_chain[i].Menu[j].price);
		}
		printf("\n");
	}
}

void deallocate(Fastfood ff_chain[50], int ff_count)
{
	for(int i = 0; i < ff_count; i++)
	{
		for(int j = 0; j < ff_chain[i].item_count; j++)
		{
			free(ff_chain[i].Menu[j].name);
		}
		free(ff_chain[i].name);
	}
}

void menu_out()
/* prints main menu of program */
{
	printf("MENU---------\n");
	printf("[1] Add a Fastfood Chain\n");
	printf("[2] View All Fastfood Chains\n");
	printf("[3] View a Fastfood Chain Menu\n");
	printf("[4] Add an Item to a Fastfood Chain Menu\n");
	printf("[5] Exit\n");
}