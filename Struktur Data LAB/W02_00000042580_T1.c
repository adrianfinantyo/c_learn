#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int show_menu(int dataTotal)
{
	int menu;
	
	system("cls");
	printf("Welcome to simple student database (%d/20)\n", dataTotal);
	printf("1. Show all students\n");
	printf("2. Input new students\n");
	printf("3. Exit\n");
	printf("Choose : ");
	scanf("%d", &menu); fflush(stdin);
	
	return menu;
}

struct student{
	char name[50];
	char major[50];
	float gpa;
	struct student *next;
}*head, *tail, *curr;

void show_student()
{
	int i=0;
	curr = head;
	
	system("cls");
	printf("                       List of Student Information\n");
	printf("-------------------------------------------------------------------------------\n");
	printf("|No.|                   Name                   |        Major        |   GPA  |\n");
	printf("-------------------------------------------------------------------------------\n");
	
	if(head != NULL)
	{
		while(curr != NULL)
		{
			i++;
			printf("|%2d | %-40s | %-19s |  %.2f  |\n", i, curr->name, curr->major, curr->gpa);
			curr = curr->next;
		}
	}
	else
	{
		printf("                                  TIDAK ADA DATA!\n");
		printf("-------------------------------------------------------------------------------");
	}
}

void insert_student()
{
	float gpa;
	
	system("cls");
	curr = (struct student*)malloc(sizeof(struct student));
	curr->next = NULL;
	
	printf("   Insert Student Information\n");
	printf("--------------------------------\n");
	printf("Name   : "); gets(curr->name);
	printf("Major  : "); gets(curr->major);
	printf("GPA    : "); scanf("%f", &gpa); fflush(stdin);
	curr->gpa = gpa;
	if(head==NULL)
		head = tail = curr;
	else
	{
		tail->next = curr;
		tail = curr;	
	}	
}

int main()
{
	int menu, stdTotal=0;
	
	do
	{
		menu = show_menu(stdTotal);	
		if (menu == 1)
		{
			show_student();
			printf("\n");
			getchar();
		}
		else if (menu == 2)
			if (stdTotal <= 20)
			{
				stdTotal++;
				insert_student();
				printf("Inserting data\nNew students added\nPress any key to continue");
				getchar();
			}
			else
			{
				printf("Database is full\nPress any key to continue");
				getchar();
			}
				
	}while (menu != 3); 
	
	return 0;	
}
