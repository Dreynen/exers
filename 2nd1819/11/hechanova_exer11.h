typedef struct Food_item
{
	char name[30];
	float price;
}Food_item;

typedef struct Fastfood
{
	char name[30];
	Food_item Menu[15];
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
	char * ff_name = get_string();

	if(check_ff(ff_chain, *ff_count, ff_name) == -1)
	{

		strcpy(new_ff.name, ff_name);
		new_ff.item_count = 0;
		ff_chain[(*ff_count)] = new_ff;
		(*ff_count)++;
	}
	else
	{
		printf("\nFastfood chain already exists!\n");
	}
	free(ff_name);
	printf("\n");
}

int check_menu(Fastfood ff_chain, char * item_name)
/*
	checks if an item already exists in a menu
	works by declaring 2 new strings and copying names into those strings
	then capitalizing them and finally checking them, then returns index
	if it exists or -1 if it doesn't
*/
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
		char * item_name = get_string();
		if(check_menu(ff_chain[index], item_name) == -1)
		{
			strcpy(item.name, item_name);
			printf("Enter price: ");
			item.price = get_price();
			ff_chain[index].Menu[ff_chain[index].item_count] = item;
			ff_chain[index].item_count++;
		}
		else
		{
			printf("\nFood item already exists.\n");
		}
		free(item_name);
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
	printf("\n");
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

void read_fastfoods(FILE * file, Fastfood ff_chain[50], int * ff_count)
/* assigns existing fastfoods and fastfood menu items to program variables */
{
	fscanf(file, "%d\n", ff_count);
	for(int i = 0; i < *ff_count; i++)
	{
		fscanf(file, "%s %d\n", ff_chain[i].name, &ff_chain[i].item_count);
		for(int j = 0; j < ff_chain[i].item_count; j++)
		{
			fscanf(file, "%s %f\n", ff_chain[i].Menu[j].name, &ff_chain[i].Menu[j].price);
		}
	}
}

void save_ff(Fastfood ff_chain[50], int ff_count)
/* writes current fastfoods and fastfood menu items to a text file */
{
	FILE * file = fopen("fastfoods.txt", "w");
	if(file)
	{
		fprintf(file, "%d\n", ff_count);
		for(int i = 0; i < ff_count; i++)
		{
			fprintf(file, "%s %d\n", ff_chain[i].name, ff_chain[i].item_count);
			for(int j = 0; j < ff_chain[i].item_count; j++)
			{
				fprintf(file, "%s %f\n", ff_chain[i].Menu[j].name, ff_chain[i].Menu[j].price);
			}
		}

		fclose(file);
	}
}