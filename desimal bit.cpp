#include<stdio.h>
#include<stdlib.h>

long long int binary(int x){
	if(x != 0){
		return (x % 2 + 10 * binary(x / 2)); 
	}
}
int main(){
	printf("masukan nilai decimal yang ingin di convert 	: ");
	int x;
	scanf("%d", &x); 
	system("cls");
	printf("binary numbernya adalah 			: %lld\n", binary(x));
	return 0;
}
