#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

/*
Nama: Bonifasius Ariesto Adrian Finantyo
NIM: 00000042580
Kelas: A
*/

struct lagu{
	char judul[30];
	char penyanyi[20];
	char durasi [10];
	struct lagu *prev, *next;
};

struct lagu *Qfront, *Qrear, *Qnode;

void show_menu(){
	system("cls");
	printf("  ================================\n");
	printf("               Dotify\n");
	printf("  ================================\n");
	printf("  1. List Lagu\n");
	printf("  2. Tambah Lagu\n");
	printf("  3. My Playlist\n");
	printf("  4. Keluar\n");
	printf("  Pilihan menu: ");
}

void enQueue(struct lagu **temp){
    Qnode = (struct lagu*)malloc(sizeof(struct lagu));
    strcpy(Qnode->judul, (*temp)->judul);
    strcpy(Qnode->penyanyi, (*temp)->penyanyi);
    strcpy(Qnode->durasi, (*temp)->durasi);
    if(Qfront == NULL)
    	Qfront = Qrear = Qnode;
    else{
		Qrear->next = Qnode;
        Qrear = Qnode; 	
	}
	Qrear->next = Qfront;
	Qfront->prev = Qrear;  
}

void listLagu(){
	int i=0, input, lagu;
	struct lagu *head, *tail, *node;
	
	system("cls");
	head = tail = NULL;
	FILE *fp = fopen("musik.txt", "r");
	while(!feof(fp)){
		node = (struct lagu*)malloc(sizeof(struct lagu));
		fscanf(fp, "%[^#]#%[^#]#%[^\n]\n", node->judul, node->penyanyi, node->durasi);
		if(head==NULL)
			head = tail = node;
		else{
			tail->prev = tail;
			tail->next = node;
			tail = node;
		}
	}
	fclose(fp);
	node->next = NULL;
	
	printf("\n  ------------------------------------------------------------------------\n");
	printf("  | No |            Judul              |       Penyanyi      |  Durasi   |\n");
	printf("  ------------------------------------------------------------------------\n");
	node = head;
	if(head != NULL){
		while(node != NULL){
			++i;
			printf("  | %-3d| %-30s| %-20s|%10s |\n", i, node->judul, node->penyanyi, node->durasi);
			node = node->next;
		}
		printf("  ------------------------------------------------------------------------\n\n");
		do{
			printf("  Tekan [1] untuk menambahkan lagu pada playlist\n");
			printf("  Tekan [0] untuk kembali ke menu\n");
			printf("  Input: ");
			scanf("%d", &input); fflush(stdin);
			if(input == 1){
				printf("\n  Tambah Playlist\n");
				printf("  ---------------\n");
				printf("  Masukkan nomor urut lagu: ");
				scanf("%d", &lagu); fflush(stdin);
				// Pop lagu ke Queue
				node = head;
				i=0;
				while(node != NULL){
					++i;
					if(i == lagu){
						enQueue(&node);
						printf("  Berhasil menambahkan playlist!"); getchar();
						return;
					}	
					node = node->next;
				}
				printf("  Nomor lagu tidak tersedia."); getchar();
				break;
			}
			else if(input == 0)
				break;
			else{
				printf("  Angka yang Anda masukkan salah!"); getchar();
				break;	
			}
		}while(1);
	}
	else{
		printf("  |                              NO DATA!                                |\n");
		printf("  ------------------------------------------------------------------------\n");
		printf("  Tekan apa saja untuk kembali ke menu..."); getchar();
	}	
}

void tambahLagu(){
	struct lagu temp;
	
	printf("\n  Tambah Lagu\n");
	printf("  -----------\n");
	printf("  Judul Lagu : "); gets(temp.judul);
	printf("  Penyanyi   : "); gets(temp.penyanyi);
	printf("  Durasi     : "); gets(temp.durasi);
	FILE *fp = fopen("musik.txt", "a");
	fprintf(fp, "%s#%s#%s\n", temp.judul, temp.penyanyi, temp.durasi);
	fclose(fp);
	printf("\n  Lagu berhasil ditambahkan!"); getchar();
}

void plistLagu(){
	int i=0;
	
	system("cls");
	printf("\n  ------------------------------------------------------------------------\n");
	printf("  |                             My Playlist                              |\n");
	printf("  ------------------------------------------------------------------------\n");
	printf("  | No |            Judul              |       Penyanyi      |  Durasi   |\n");
	printf("  ------------------------------------------------------------------------\n");
	Qnode = Qfront;
	if(Qnode != NULL){
		while(Qnode != NULL){
			++i;
			printf("  | %-3d| %-30s| %-20s|%10s |\n", i, Qnode->judul, Qnode->penyanyi, Qnode->durasi);
			Qnode = Qnode->next;
			if(i>=15)
				break;
		}
		printf("  | .. | ............................  | ................... | ......... |\n");
		printf("  ------------------------------------------------------------------------\n");
		printf("  |               Playlist ini akan otomatis men-looping                 |\n");
		printf("  ------------------------------------------------------------------------\n");
		printf("  Tekan apa saja untuk kembali ke menu..."); getchar();	
	}
	else{
		printf("  |                              NO DATA!                                |\n");
		printf("  ------------------------------------------------------------------------\n");
		printf("  Tekan apa saja untuk kembali ke menu..."); getchar();	
	}
}

int main(){
	int inMenu;
	do{
		show_menu();
		scanf("%d", &inMenu); fflush(stdin);
		if(inMenu == 1)
			listLagu();
		else if(inMenu == 2)
			tambahLagu();
		else if(inMenu == 3)
			plistLagu();
		else if(inMenu == 4)
			break;
		else{
			printf("  Menu tidak dikenali. Mohon masukkan nomor menu kembali");
			getchar();
		}
	}while(1);
	return 0; 
}
