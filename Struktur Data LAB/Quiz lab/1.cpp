#include <stdio.h>

int main()
{
	int angka, i, j;
	
	scanf ("%d", &angka);
	printf("\n");
	if (angka%2 == 1)
	{
		for (i=0; i<angka; i++)
		{
			for (j=0; j<angka; j++)
			{
				if (i==0 || i==angka-1 || i==angka/2)
					printf ("* ");
				else if (j==0 || j==angka-1 || j==angka/2)
					printf ("* ");
				else
					printf ("  ");
			}
			printf("\n");
		}
	}
	return 0;
}