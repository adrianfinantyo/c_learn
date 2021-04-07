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
	struct buku list[3];
	int i=0;

	FILE *fp = fopen("list_buku.txt", "r");
	while(!feof(fp)){
		fscanf(fp, "%d/%[^/]/%[^/]/%[^/]/%f/%d\n", &list[i].ISBN, list[i].judul,
												       list[i].pengarang, list[i].penerbit,
												       &list[i].harga, &list[i].stok);
		i++;
		getchar();
	}
	fclose(fp);
	return 0;
}
