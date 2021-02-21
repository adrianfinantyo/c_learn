#include <stdio.h>
#include <stdlib.h>

void cekgg (int *a, int *oo, int *oe, int *eo, int *ee);

int main ()
{
	int a[50], i, oo, oe, eo, ee;
	oo=0; oe=0; oo=0; oe=0;
	for (i=0; i <= 50-1; i++)
	{
		a[i] = rand();
		printf ("%5d ", a[i]);
	}
	cekgg (a, &oo, &oe, &eo, &ee);
	// Mencetak nilai oo, oe, eo, ee
	printf ("\nIndex\\Isi\tGanjil\tGenap\tTotal");
	printf ("\nGanjil\t\t%6d\t%5d\t%5d", oo, oe, oo+oe);
	printf ("\nGenap\t\t%6d\t%5d\t%5d", eo, ee, eo+ee);
	printf ("\nTotal\t\t%6d\t%5d", oo+eo, oe+ee);
	
	return 0;
}

// Function untuk mengecek ganjil genap
void cekgg (int *a, int *oo, int *oe, int *eo, int *ee)
{
	int i;
	for (i=1; i <= 50-1; i+=2)
	{
		if (a[i]%2 == 1)
			*oo += 1;
		else
			*oe += 1;
	}
	for (i=0; i <= 50-1; i+=2)
	{
		if (a[i]%2 == 1)
			*eo += 1;
		else
			*ee += 1;
	}
}
