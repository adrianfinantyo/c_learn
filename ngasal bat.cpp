#include <stdio.h>

int main ()
{
	int i,a;
	
	i = 1;
	printf("Masukan Angka : ");
	scanf("%d",&a);
	printf("\n\nBerhitung dimulai...\n\n");
	do
	{
		if(i%10 == 0)
		{
			printf("%d\n",i);
		}
		else
		{
			printf("%d ",i);
		}
		i = i+1;
	} while (i<=a);
	
	return 0;
}
