#include <stdio.h>
#define MAX 5

int enQueue(){
	int temp;
	scanf("%d", &temp);
	return temp;
}

int deQueue(){
	return 0;
}

int main(){
	int Queue[MAX], i, total=0;
	printf("Masukkan angka :\n");
	for(i=0; i<MAX; i++){
		Queue[i] = enQueue();
		if(Queue[i]%2 != 1)
			Queue[i] = deQueue();
	}
	for(i=0; i<MAX; i++)
		total += Queue[i];
	printf("\nTotal: %d", total);
	getchar();
	return 0;
}