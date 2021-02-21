#include <stdio.h>

int main()
{
	int i;
    char huruf [26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	for (i=0; i <= 26-1; i++)
	{
		printf("Huruf ke-%d adalah: %c\n", i+1,huruf [i]);	
	}
	
    return 0;
}

/*
int main(){
    // membuat array kosong
    char huruf [25];

    // mengisi array
    huruf [25] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
    // mencetak isi array dengan perulangan
	for (int i = 0; i <= 25 ; i++){
	    printf("Huruf ke-%d adalah : %s\n", i, huruf [i]);
	}
}
*/
