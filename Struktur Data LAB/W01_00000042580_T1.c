#include <stdio.h>
#include <windows.h>

void show_menus();
void uppercase(char x[]);
void lowercase(char x[]);
void switching(char x[]);

int main ()
{
	char kalimat[500];
	int i, menu;
	
	// Menu Program
	do
	{
		show_menus();
		scanf ("%d", &menu);
	} while (menu != 1 && menu != 2 && menu != 3 && menu != 4);
	scanf ("%*c%[^\n]s", kalimat);
	// Pemanggilan Fungsi
	if (menu == 1)
		uppercase(kalimat);
	else if (menu == 2)
		lowercase(kalimat);
	else if (menu == 3)
		switching(kalimat);
	else if (menu == 4)
		return 0;
	// Print Hasil
	for (i=0; kalimat[i] != 0; i++)
		printf ("%c", kalimat[i]);
	return 0;
}

void show_menus()
{
	system("cls");
	printf ("1. Uppercase\n");
	printf ("2. Lowercase\n");
	printf ("3. Switching\n");
	printf ("4. Keluar\n");
	printf ("Pilihan : ");
}

void uppercase(char x[])
{
	int i;
	for (i=0; x[i] != 0; i++)
	{
		if (x[i] >= 97 && x[i] <= 122)
			x[i] -= 32;
	}
}

void lowercase(char x[])
{
	int i;
	for (i=0; x[i] != 0; i++)
	{
		if (x[i] >= 65 && x[i] <= 90)
			x[i] += 32;
	}
}

void switching(char x[])
{
	int i;
	for (i=0; x[i] != 0; i++)
	{
		if (x[i] >= 97 && x[i] <= 122)
			x[i] -= 32;
		else if (x[i] >= 65 && x[i] <= 90)
			x[i] += 32;
	}
}
