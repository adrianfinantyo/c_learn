#include <stdio.h>

int main () 
{
	char str[50];

	printf("Masukin dong : ");
	gets(str);

	printf("Anda menulis: %s", str);

	return(0);
}
