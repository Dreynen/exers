#include <stdio.h>
#include "hechanova_exer04.h"

int main()
{
	int N;
	while (N!=0)
	{
		// ask for positive integer
		do
		{
			scanf("%d", &N);
			if (N<0)
			{
				printf("Invalid!\n");
			}
		}
		while(N<0);

		// stop program if N==0
		if (N==0)
		{
			break;
		}

		if (N == perfect(N, 1))
		{
			printf("Perfect!!\n");
		}
		else
		{
			printf("Not perfect.\n");
		}
	}
	printf("Goodbye!\n");

	return 0;
}