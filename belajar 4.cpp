#include <stdio.h>
#include <windows.h>

int main ()
{
	int i, x;
	scanf ("%d", &x);
	system ("cls");
	for (i=1; i<=x; i++)
	{
		printf ("Nilai i sekarang : %d\n", i);
	}

	return 0;	
}
