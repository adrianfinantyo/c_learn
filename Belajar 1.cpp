#include <stdio.h>

/*
	Format untuk menampilkan bilangan :
	%d --> integer
	%s --> string
	%f --> float
	%c --> char
*/

int main () 
{
	int a, b, hasil;

	printf("Masukan angka I : ");
	scanf ("%d",&a);					//  "&" selalu digunakan dalam scanf, berfungsi untuk menaruh input di alamat variable
	printf("Masukan angka II : ");
	scanf ("%d",&b);					//	"&" selalu digunakan dalam scanf, berfungsi untuk menaruh input di alamat variable
	hasil= a + b;
	printf("Hasil : %d", hasil);

	return 0;
}


