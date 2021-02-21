#include <stdio.h>

int main()
{
	int ph;
	scanf ("%d", &ph);
	if (ph>7)
	{
		if (ph<12)
			printf ("Alkaline");
		else
			printf ("Very Alkaline");
	}
	else
	{
		if (ph == 7)
			printf ("Neutral");
		else
		{
			if (ph>2)
			{
				printf ("Acid");
			}
			else
				printf ("Very Acid");
		}
	}
	return 0;
}
