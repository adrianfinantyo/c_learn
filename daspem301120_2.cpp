#include <stdio.h>

/*	ISI DARI PEMBELAJARAN INI ADALAH
	# CALL BY REFERENCE #
	DENGAN DEMIKIAN FUNCTION DAPAT
	MENGUDPATE/,MENGUBAH NILAI VARIABEL
	BERDASARKAN ALAMATNYA
*/

void pengali (int *a, int *b, int *c);

int main()
{
	int a, b, c;
	a = 10; b = 20; c=a*b;
	printf ("a=%d b=%d c=%d\n", a, b, c);
	pengali (&a, &b, &c);
	printf ("a=%d b=%d c=%d", a, b, c);
}

void pengali (int *x, int *y, int *z)
{
	*y = *x + *z;
	printf ("b berada di %X\n", y);			//  y = alamat b semula (yang dikirim dari main)
	printf ("b di tampung di %X\n", &y);	// &y = alamat b di tampung di alamat lain yakni y
	printf ("nilai b adalah %d\n", *y);		// *y = isi dari alamat b
}
