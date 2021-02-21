#include <stdio.h>

int main()
{
	char str1[100], str2[100], str3[100];
	int i;
	
	gets(str1);
	gets(str2);
	while (str1[i] == str2[i])
	{
		str3[i] = str1[i];
		i++;
	}
	for (i=0; str3[i] != 0; i++)
		printf ("%c", str3[i]);
	
	return 0;
}
