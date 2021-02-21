#include <stdio.h>

void hitung (int *p50k, int *p20k, int *p10k, int *p1k, int *p500, int *p100, int *p50, int *p25, int *saldo);
int bulat(int kembalian);

int main()
{
	int p50k=0, p20k=0, p10k=0, p1k=0, p500=0, p100=0, p50=0, p25=0, kembalian;
	hitung (&p50k, &p20k, &p10k, &p1k, &p500, &p100, &p50, &p25, &kembalian);
	printf ("%d\n", kembalian); 
	if (p50k>0)
		printf ("%d 50000\n", p50k);
	if (p20k>0)
		printf ("%d 20000\n", p20k);
	if (p10k>0)
		printf ("%d 10000\n", p10k);
	if (p1k>0)
		printf ("%d 1000\n", p1k);
	if (p500>0)
		printf ("%d 500\n", p500);
	if (p100>0)
		printf ("%d 100\n", p100);
	if (p50>0)
		printf ("%d 50\n", p50);
	if (p25>0)
		printf ("%d 25\n", p25);
	return 0;
}

void hitung (int *p50k, int *p20k, int *p10k, int *p1k, int *p500, int *p100, int *p50, int *p25, int *saldo)
{
	int harga, bayar, kembalian, x;
	scanf ("%d %d", &harga, &bayar); 
	x = bayar-harga;
	printf ("x : %d\n", x); // Aneh sih ini, kalo printf x dihilangkan program menjadi salah!!!
	kembalian = bulat (x);
	*saldo = kembalian;
	while (kembalian >= 50000)
	{
		kembalian -= 50000;
		++(*p50k);		
	}
	while (kembalian >= 20000)
	{
		kembalian -= 20000;
		++(*p20k);		
	}
	while (kembalian >= 10000)
	{
		kembalian -= 10000;
		++(*p10k);		
	}	
	while (kembalian >= 1000)
	{
		kembalian -= 1000;
		++(*p1k);		
	}	
	while (kembalian >= 500)
	{
		kembalian -= 500;
		++(*p500);		
	}	
	while (kembalian >= 100)
	{
		kembalian -= 100;
		++(*p100);		
	}
	while (kembalian >= 50)
	{
		kembalian -= 50;
		++(*p50);		
	}	
	while (kembalian >= 25)
	{
		kembalian -= 25;
		++(*p25);		
	}
}

int bulat(int kembalian)
{
	int x;
	if (kembalian % 25 != 0)
		x = 25 - kembalian % 25;
		kembalian = kembalian + x;
		printf ("func bulat : %d\n", kembalian);

	return kembalian;
}	
