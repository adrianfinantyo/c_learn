#include <stdio.h>
#include <windows.h>

struct book{
	char name[50];
	char category[50];
	int price;
};

struct book catalog[10];

void show_menus(){
	system("cls");
	printf("WELCOME TO LIBRARY\n\n");
	printf("1. Input Book Catalog\n");
	printf("2. Show Book Catalog\n");
	printf("3. EXIT\n");
	printf("Choose > ");
}

int main(){
	int i=0, menu, price;
	
	do{
		show_menus(); 
		scanf("%d", &menu); fflush(stdin);
		switch (menu)
		{
			case 1:
				printf ("Book name : "); scanf("%[^\n]s", catalog[i].name); fflush(stdin);
				printf ("Category  : "); scanf("%[^\n]s", catalog[i].category); fflush(stdin);
				printf ("Price IDR : "); scanf("%d", &price); fflush(stdin);
				catalog[i].price = price;
				printf ("Berhasil!"); getchar();
				i++;
				break;
			case 2:
				for (i=0; i<10 ; i++){
					printf("%s / %s / IDR %d\n", catalog[i].name, catalog[i].category, catalog[i].price);
				}
				getchar();
				break;
		}
	}while (menu != 3);
	
	return 0;
}
