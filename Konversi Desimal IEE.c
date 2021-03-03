#include <stdio.h>
#include <math.h>
#include <windows.h>

void decTobin(int n, int a[]){
	int i;   
	for(i=0;n>0;i++){   
		a[i]=n%2;    
		n=n/2;    
	}
}

void program(){
	float fractionA[23], fractionB[23];
	int binary[23], exponent[8], sign, i, power;

	system("cls");
	printf("Masukkan sign : ");
	scanf("%d", &sign); fflush(stdin);
	if(sign < 0 || sign > 1)
		program();
	printf("Masukkan power : ");
	scanf("%d", &power); fflush(stdin);
	printf("Masukkan fraction < 1 : ");
	scanf("%f", &fractionA[0]); fflush(stdin);
	if(fractionA[0] > 1)
		program();
	//Program Jalan
	//Mencari exponent
	decTobin(power+127, exponent);
	//Mencari fraction
	for(i=0; i<23; i++){
		if(fractionA[i] == 0)
			break;
		fractionB[i] = fractionA[i]*2;
		binary[i] = fractionB[i];
		if(fractionB[i] >= 1)
			fractionA[i+1] = fractionB[i]-1;
		else
			fractionA[i+1] = fractionB[i];
		printf("|%2d|%f x 2 = %f\n", i+1,fractionA[i], fractionB[i]);
	}
	printf("\n-------------------------------------------------------\n");
	printf("fraction : ");
	for(i=0; i<23; i++)
		printf("%d", binary[i]);
	printf("\n-------------------------------------------------------\n");
	
	//Print Hasil
	printf("Hasil konversi = ");
	printf("%d ", sign);
	for(i=7; i>=0; i--)
		printf("%d", exponent[i]);
	printf(" ");
	for(i=0; i<23; i++)
		printf("%d", binary[i]);
	printf("\n                 - -------- -----------------------\n");
	if(sign == 0)
		printf("               (+) exponent         fraction       \n");
	else
		printf("               (-) exponent         fraction       \n");
}

int main(){
	char menu;
	do{
		program();
		printf("-------------------------------------------------------\n");
		printf("Do you want to convert again? (Y/N) > ");
		scanf("%c", &menu); fflush(stdin);
		if(menu != 78 || menu != 110)
			break;
	}while(1);
}
