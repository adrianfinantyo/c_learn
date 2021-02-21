#include <stdio.h>

int main(){
    // membuat variabel score
    int score = 0;

    // membuat pointer dan referensikan dengan alamat
    // dari variabel score
    int *p_score = &score;

    // meanmpilkan isi dari variabel pointer dan alamat score
    printf("isi dari p_score memuat alamat = %X\n", p_score);
    printf("var score berada di  = %X\n", &score);

    // mengakses data variabel score dari pointer
    printf("isi score awal = %d\n", score);
	printf("isi *p_score = %d\n", *p_score);

    // mengubah data variabel score dari pointer
    *p_score = 5;

    // melihat isi variabel score
    printf("isi score setelah diubah = %d\n", score);
    
    return 0;
}
