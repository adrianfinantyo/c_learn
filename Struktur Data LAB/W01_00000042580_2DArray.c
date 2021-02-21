#include <stdio.h>

void printArray(int arr[][3])
{
	// Indeks untuk baris dan kolom
	int row, col;
	
	printf ("isi dari array:\n");
	for(row=0; row<3; row++)
	{
		for(col=0; col<3; col++)
		{
			printf ("%d", arr[row][col]);
		}
		printf ("\n");
	}
}

int main()
{
	// Inisialisasi langsung
	int randomNumbers[3][3] = 
	{
		{1, 2, 3},
		{6, 5, 4},
		{7, 8, 9},
	};
	printArray(randomNumbers);
		
	return 0;
}
