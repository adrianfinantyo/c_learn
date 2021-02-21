#include <stdio.h>
#include <windows.h>

void show_menus();
void print_matriks(int arr[][3]);
void scan_matriks(int arr[][3]);
void transpose(int arr[][3], int arrHasil[][3]);

int main ()
{
	int matriks1[3][3], matriks2[3][3], hasil[3][3];
	int i, j, k, jumlah=0, menu;
	
	// Input Matriks I
	printf ("Masukkan Matrix Pertama(3 x 3)\n");
	scan_matriks(matriks1);
	// Input Matriks II
	printf ("\nMasukkan Matrix Kedua(3 x 3)\n");
	scan_matriks(matriks2);
	// Tampilan Menu
	do
	{
		show_menus();
		scanf ("%d", &menu);
	} while (menu != 1 && menu != 2 && menu != 3 && menu != 4);
	// Pemanggilan Fungsi
	if (menu == 1)
	{
		for (i=0; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				for (k=0; k<3; k++)
				{
					jumlah = jumlah + matriks1[i][k] * matriks2[k][j];
				}
				hasil[i][j] = jumlah;
				jumlah=0;
			}
		}
		print_matriks(hasil);
	}
	else if (menu == 2)
	{
		for (i=0; i<3; i++)
		{
			for (j=0; j<3; j++)
			{
				hasil[i][j] = matriks1[i][j] + matriks2[i][j];
			}
		}
		print_matriks(hasil);
	}
	else if (menu == 3)
	{
		printf ("Transpose Matrix Pertama\n");
		transpose(matriks1, hasil);
		print_matriks(hasil);
		printf ("Transpose Matrix Kedua\n");
		transpose(matriks2, hasil);
		print_matriks(hasil);
	}
	else if (menu == 4)
		return 0;	
	// ~ Program Selesai ~
	return 0;
}
// Function untuk menampilkan menu
void show_menus()
{
	system("cls");
	printf ("1. Perkalian Dua Buah Matrix\n");
	printf ("2. Penjumlahan Dua Buah Matrix\n");
	printf ("3. Transpose Dua Buah Matrix\n");
	printf ("4. Keluar\n");
	printf ("Pilihan : ");
}
// Function untuk menampilkan hasil operasi matriks
void print_matriks(int arr[][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{	
		for (j=0; j<3; j++)
		{
			printf ("%-2d ", arr[i][j]);
		}
		printf ("\n");
	}
}
// Function untuk melakukan input terhadap matriks
void scan_matriks(int arr[][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			scanf ("%d", &arr[i][j]);	
		}
	}
}
// Function untuk melakukan transpose matriks
void transpose(int arr[][3], int arrHasil[][3])
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			arrHasil[i][j] = arr[j][i];
		}
	}
}
