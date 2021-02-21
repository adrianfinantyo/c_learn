#include <stdio.h>
int main()
{
	int i , nim;
	printf("NIM (5 digit ahir) = ");
	scanf("%d",&nim);
	while(1)
 	{
		if(nim == 0) break;
		for(i = 0; i <= nim % 10; i++)
			printf("#");
		printf(" => %d\n", nim % 10);
		nim /= 10;
 	}
 	return 0;
}

