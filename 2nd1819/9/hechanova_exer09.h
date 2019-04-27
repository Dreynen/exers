char * get_string()
/* gets a string from the user */
{
	char s[100];
	printf("Enter name: ");
	scanf("%s", s);
	char * t = malloc(sizeof(char) * strlen(s) + 1);
	strcpy(t, s);
	return t;
}

void filter(char * s)
/* filters the string to contain only alphabetical characters */
{
	for(int i = 0, n = strlen(s); i < n; i++)
	{
		s[i] = isalpha(s[i]) ? tolower(s[i]) : ' ';
	}
}

int get_flames(char * s, char * t)
/* gets the number of common letters in the two filtered names */
{
	for(int i = 0; i < strlen(s); i++)
	{
		char c = s[i];
		for(int j = 0; j < strlen(t); j++)
		{
			if(c != ' ' && t[j] == c)
			{
				for(int k = 0; k < strlen(s); k++)
				{
					if(s[k] == c)
					{
						s[k] = '*';
					}
				}
				t[j] = '*';
			}
		}
	}

	int count = 0;
	for(int i = 0, n = strlen(s); i < n; i++)
	{
		if(s[i] == '*')
		{
			count++;
		}
	}

	for(int i = 0, n = strlen(t); i < n; i++)
	{
		if(t[i] == '*')
		{
			count++;
		}
	}

	return count;
}

void FLAMES(int count)
/* outputs any of the corresponding word in FLAMES */
{
	printf("Count: %d\n", count);
	if(count)
	{
		switch(count % 6)
		{
			case 1:
				printf("Friends! :)\n");
				break;
			case 2:
				printf("Lovers! <3\n");
				break;
			case 3:
				printf("Affectionate! <3\n");
				break;
			case 4:
				printf("Marriage! <3\n");
				break;
			case 5:
				printf("Enemies! :(\n");
				break;
			case 6:
				printf("Sweethearts! <3\n");
				break;
		}
	}
	else
	{
		printf("None! :<\n");
	}
}