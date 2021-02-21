#include <stdio.h>

int kecil (int a);
int besar (int a);
int panjang (char *str);

int main ()
{
	int i;
	char str[255];
	scanf ("%[^\n]s", str);
	for (i=0; i <= panjang(str)-1; i++)
	{
		if (i == 0 || str[i-2] == 33 || str[i-2] == 46 || str[i-2] == 63)
			str[i] = besar (str[i]);
		else 
			str[i] = kecil (str[i]);
		printf ("%c", str[i]);
	}	
	return 0;
}

int kecil (int a)
{
	if (a >= 65 && a <= 90)
		a += 32;
	return a;
}

int besar (int a)
{
	if (a >= 97 && a <= 122)
		a -= 32;
	return a;
}

int panjang (char *str)
{
    int len = 0;
    int i;
    
    for (i=0; str[i] != 0; i++) 
    {
        len++;
    }
    return(len);
}
