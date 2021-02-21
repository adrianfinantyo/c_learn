#include <stdio.h>
#include <string.h>

struct member
{
	char name[50];
	int number;
};

typedef struct member Member;

int main()
{
	char str[50];
	int num;
	
	Member Adrian;
	gets(str);
	scanf("%d", &num);
	strcpy(Adrian.name, str);
	Adrian.number = num;
	
	printf("Name\t: %s\n", Adrian.name);
	printf("ID\t: %d\n", Adrian.number);
	
	return 0;
}
