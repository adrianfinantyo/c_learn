#include <stdio.h>

typedef struct
{
	char name[50];
	char major[50];
	float gpa;
}Student;

int main()
{
	// Penulisan struct di depan dapat dihilangkan
	Student waldo = {"Waldo", "Informatika", 3.98};
	
	printf("Nama  : %s\n", waldo.name);
	printf("Major : %s\n", waldo.major);
	printf("GPA   : %.2f\n", waldo.gpa);
	
	return 0;
}
