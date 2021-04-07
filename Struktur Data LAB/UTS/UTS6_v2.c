#include <stdio.h>
#define MAX 5

int enQueue(int *front, int *rear){
	if(*rear == MAX-1)
		return 1;
	else if(*front == -1 && *rear == -1)
		*front = *rear = 0;
	else
		(*rear)++;
	return 0;
}

int deQueue(){
	return 0;
}

int main(){
	int Queue[MAX], total=0, front=-1, rear=-1;
	printf("Masukkan angka :\n");
	while(!enQueue(&front, &rear)){
		scanf("%d", &Queue[rear]);
		if(Queue[rear]%2 != 1)
			Queue[rear] = deQueue();
		total += Queue[rear];
	}
	printf("\nTotal: %d", total);
	getchar();
	return 0;
}