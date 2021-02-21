#include <stdio.h>

int cek_matriks (int matriks[11][11], int n);

int main()
{
	int matriks[11][11]={0}, n, i, j;
	// Menerima input ukuran
	scanf ("%d", &n);
	// Mengecek syarat ukuran
	if (n>= 1 && n<= 10)
	{
		// Melakukan input nilai matriks
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf ("%d", &matriks[i][j]);
			}
		}
		if (cek_matriks(matriks, n))
			printf ("magic square");
		else
			printf ("bukan magic square");
	}
	return 0;
}

int cek_matriks (int matriks[11][11], int n)
{
	int diagonal[2]={0}, i, j;
	// Menghitung jumlah setiap diagonal
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (j==i)
			{
				diagonal[0] = diagonal[0] + matriks[i][j];
			}
			if (j==n-i-1)
			{
				diagonal[1] = diagonal[1] + matriks[i][j];
			}
		}
	}
	// Cek jumlah diagonal
	if (diagonal[0] != diagonal [1])
		return false;
	// Menghitung jumlah setiap baris dan kolom
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			matriks[i][n] += matriks[i][j];
			matriks[n][j] += 1;//matriks[j][i];
		}
		printf ("jumlah baris %d : %d\n", i, matriks[i][n]);
		if (matriks[i][n] != diagonal[0] && matriks[n][i] != diagonal[0])
			return false;
	}
	printf ("sum dg 1 : %d\n", diagonal[0]);
	printf ("sum dg 2 : %d\n", diagonal[1]);
	
	// !!! TEST PRINT MATRIKS !!!!
	printf ("\n");
	for (i=0; i<11; i++)
	{
		for (j=0; j<11; j++)
		{
			printf ("%3d ", matriks[i][j]);
		}
		printf ("\n");
	}
	return true;
}
