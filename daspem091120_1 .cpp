#include <stdio.h>

int input ();
void jumlah (int x, int y);

int main()
{
	int a,b;
    a = input ();
    b = input ();
    jumlah (a,b);
    
    return 0;
}

int input ()
{
    int j,k;
    printf("Angka : ");
    scanf("%d", &j);

    return j;
}

void jumlah (int x, int y)
{
    int z;
    z = x+y;
    printf ("Jumlah = %d", z);
}
