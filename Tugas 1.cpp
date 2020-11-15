#include <stdio.h> 

int main() 
{ 
	int n, bil;
	
	printf ("Angka: ");
	scanf ("%d",&n);
	bil = n % 2 == 0 ? printf ("Genap") : printf ("Ganjil");
	
	return 0;
}
