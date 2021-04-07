#include <stdio.h>

struct buku{
	int ISBN;
	char judul[50];
	char pengarang[50];
	char penerbit[50];
	float harga;
	int stok;
};

int main(){
	struct buku dataBuku = {1234567890, "Halo Dunia", "Adrian", "Kompas", 60500.250, 50};
	printf("ISBN           : %d\n", dataBuku.ISBN);
	printf("Judul          : %s\n", dataBuku.judul);
	printf("Pengarang      : %s\n", dataBuku.pengarang);
	printf("Penerbit       : %s\n", dataBuku.penerbit);
	printf("Harga buku     : Rp. %.3f\n", dataBuku.harga);
	printf("Stok buku      : %d\n", dataBuku.stok);
	getchar();
	return 0;
}