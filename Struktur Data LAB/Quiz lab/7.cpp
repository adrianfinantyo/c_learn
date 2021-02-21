#include <stdio.h>

int main()
{
	int arr[5], i;
	for (i=0; i<5; i++)
		scanf("%d", &arr[i]);
	printf("\nIndex\t: ");
	scanf("%d", &i);
	printf("Nilai\t: %d", arr[i]);
	
	return 0;
}
