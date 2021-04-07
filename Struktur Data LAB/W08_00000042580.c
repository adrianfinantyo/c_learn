#include <stdio.h>

void menu(){
    printf("=====================================\n");
    printf("         Daftar Mahasiswa\n");
    printf("=====================================\n");
    printf("(1). Cari Mahasiswa (berdasarkan 3 huruf pertama)\n");
    printf("(2). Delete Mahasiswa\n");
    printf("(3). Tambah Mahasiswa\n");
    printf("(0). Exit\n");
    printf("Pilih : ");
}

int main(){
    int inputKey;

    menu();
    scanf("%d", inputKey);
    switch (inputKey)
    {
    case 1:
        //code here    
        break;
    case 2:
        //code here    
        break;
    case 3:
        //code here    
        break;

    return 0;
}