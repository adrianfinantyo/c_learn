#include <stdio.h>

int main ()
{
	int n,i,j;
	
	scanf("%d",&n);
	i = n;
	while (i>=1)
	{
		j = 1;
		do
		{
			printf("%d",i);
			j = j+1;
		
		} while (j<i);
		printf(" ");
		i = i-1;
	}

	return 0;
}
