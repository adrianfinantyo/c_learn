#include <stdio.h>

int main ()
{
	int studentid;
	char studentname[100];
	
	scanf("%[^#]%*c", &studentname);
	scanf("%d", &studentid);
	printf("ID\t: %d\n", studentid);
	printf("Name\t: %s", studentname);	
	
	return 0;
}
