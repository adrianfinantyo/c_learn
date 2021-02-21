#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

struct data{
	int angka;
	struct data *next;
}*head, *tail, *curr;

void menus()
{
	system("cls");
	printf("MENU SINGLE LINK LIST\n\n");
	printf("1. Push Data\n");
	printf("2. Pop Data\n");
	printf("3. View Data\n");
	printf("4. EXIT\n");
	printf("Choose >> ");
}

void pushTail(int angka)
{
	curr = (data*)malloc(sizeof(data));
	curr->angka = angka;
	curr->next = NULL;
	
	if(head==NULL)
		head = tail = curr;
	else
	{
		tail->next = curr;
		tail = curr;	
	}	
}

void view()
{
	curr = head;
	
	if(head != NULL)
	{
		while(curr != NULL)
		{
			printf("%d -> ", curr->angka);
			curr = curr->next;
		}
	}
	else
			printf("TIDAK ADA DATA!\n");
	getchar();
}

void pop()
{
	if(head == NULL)
	{
		printf("TIDAK ADA DATA!");
		getchar();
	}
	else
	{
		curr = head;
		head = curr->next;
		free(curr);
		printf("Data sudah di hapus\n");
		getchar();
	}
}

int main ()
{
	int menu, angka;
	do
	{
		menus();
		scanf("%d", &menu);	fflush(stdin);
		
		switch (menu)
		{
			case 1:
				printf("Masukkan Angka : ");
				scanf("%d", &angka); fflush(stdin);
				pushTail(angka);
				break;
			case 2:
				pop();
				break;
			case 3:
				view();
				break;
			case 4:
				return 0;
		}
	} while (menu != 4);
	

	
	return 0;	
}


