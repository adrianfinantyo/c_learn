#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>

struct mahasiswa{
    char nama[50];
    char nim[11];
    struct mahasiswa *next;
};

struct mahasiswa HashT[26][26][26];

void hash(char source[], int index[3]){
    int i;
    for(i=0; i<3; i++){
        if(source[i] >= 65 && source[i]<= 90)
            source[i] += 32;
        index[i] = source[i] - 97;
    }
}

void insertToChain(struct mahasiswa *head, struct mahasiswa **temp){
    struct mahasiswa *ptr = head;
    if(head == NULL){
        head = *temp;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = *temp;
    }
}

void fetch(){
	int i,j,k;
	struct mahasiswa x = {0};
	for(i=0; i<26; i++)
		for(j=0; j<26; j++)
			for(k=0; k<26; k++)
				HashT[i][j][k] = x;
	
    FILE *fp = fopen("datamhs.txt", "r");
    while(!feof(fp)){
        int index[3];
        struct mahasiswa *node = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));
        fscanf(fp, "%[^-]-%[^\n]\n", node->nim, node->nama);
        node->next = NULL;
        hash(node->nama, index);
        insertToChain(&HashT[index[0]][index[1]][index[2]], &node);
    }
    fclose(fp);
}

void menu(){
    system("cls");
    printf("======================================================\n");
    printf("                  Daftar Mahasiswa\n");
    printf("======================================================\n");
    printf("(1). Cari Mahasiswa (berdasarkan 3 huruf pertama)\n");
    printf("(2). Delete Mahasiswa\n");
    printf("(3). Tambah Mahasiswa\n");
    printf("(0). Exit\n");
    printf("Pilih : ");
}

void printSearch(){
    char temp, search[3];
    int i, index[3];
    struct mahasiswa *ptr;

    system("cls");
    printf("======================================================\n");
    printf("                  Cari Mahasiswa\n");
    printf("======================================================\n");
    printf("Masukkan 3 huruf inisial nama yang ingin dicari:\n");
    for(i=0; i<3; i++)
        scanf("%c", &search[i]); fflush(stdin);
    hash(search, index);
    ptr = &HashT[index[0]][index[1]][index[2]];
    i = 0;
    if(ptr == NULL)
    	printf("Anak berinisial %s tidak ditemukan!\n", search);
    else
	    while(ptr != NULL){
	        printf("Mahasiswa #%d\n", i+1);
	        printf("Nama  : %s\n", ptr->nama);
	        printf("NIM   : %s\n", ptr->nim);
	        printf("------------------------------------------\n");
	        ptr = ptr->next;
	        i++;
	    }
    printf("Tekan tombol apapun untuk melanjutkan..."); getchar();
}

void inputMahasiswa(){
    struct mahasiswa temp;
    system("cls");
    printf("======================================================\n");
    printf("                  Tambah Mahasiswa\n");
    printf("======================================================\n");
    printf("Masukkan nama mahasiswa baru : ");
    scanf("%[^\n]", temp.nama); fflush(stdin);
    printf("Masukkan NIM mahasiswa baru : ");
    scanf("%s", temp.nim); fflush(stdin);
    FILE *fin = fopen("datamhs.txt", "a");
    fprintf(fin, "%s-%s\n", temp.nim, temp.nama);
    fclose(fin);
}

// Delete mahasiswa masih nge bug, terhapus di hash table tapi di notepad masih ada jadi ke fetch lagi.
void deleteMahasiswa(){
	char nama[50];
	int index[3];
	struct mahasiswa *ptr, *trash;
	
	system("cls");
    printf("======================================================\n");
    printf("                   Hapus Mahasiswa\n");
    printf("======================================================\n");
    printf("Masukkan nama mahasiswa : ");
    scanf("%[^\n]", nama); fflush(stdin);
    hash(nama, index);
    ptr = &HashT[index[0]][index[1]][index[2]];
    if(ptr == NULL)
    	printf("Anak berinisial %s tidak ditemukan!\n", index);
    else
    	while(ptr != NULL){
			if(!strcmp(ptr->nama, nama)){
				trash = ptr;
                ptr = trash->next;
                free(ptr);
				break;	
			}
	        ptr = ptr->next;
	    }
    printf("Tekan tombol apapun untuk melanjutkan..."); getchar();
}

int main(){
    int inputKey;

    while(1){
        fetch();
        menu();
        scanf("%d", &inputKey); fflush(stdin);
        switch (inputKey)
        {
            case 1:
                printSearch();
                break;
            case 2:
                deleteMahasiswa();    
                break;
            case 3:
                inputMahasiswa();
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
