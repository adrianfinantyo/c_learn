#include <stdio.h>

int main()
{
	int n, i, j;
	do
	{
		printf ("n : ");
		scanf ("%d", &n);
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (j==i)
				{
					printf ("*");
				}
				else if (j==n-i+1)
				{
					printf ("*");
				}
				else
				{
					printf (" ");	
				}		
			}
			printf ("\n");
		}

	} while (n>0);

	return 0;
}
