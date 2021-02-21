// TES PROGRAM POINTER

#include <stdio.h>

void pointer (int x, int *y)
{
	*y = x;
}

int main ()
{
	int a, b;
	a = 10;
	pointer (a, &b);
	printf ("isi dari a adalah = %d\n", a);
	printf ("isi dari b adalah = %d\n", b);
	
	return 0;
}
