#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define bool int

struct queue{
	int data;
	struct queue *next;
}*front, *rear, *node;

int isEmpty(struct queue *stack){
    if(stack == NULL)
        return 1;
    return 0;
}

void enQueue(int data){
    node = (struct queue*)malloc(sizeof(struct queue));
    node->data = data;
    if(isEmpty(front))
    	front = rear = node;
    else{
		rear->next = node;
        rear = node; 	
	}
	rear->next = NULL;  
}

int deQueue(){
	struct queue *trash;
    trash = front;
    front = trash->next;
    free(trash);
	if(isEmpty(front)){
        printf("Nothing to dequeue. Queue already empty\n\n");
        return 1;
    }
    return 0;
}

void printQueue(){
	struct queue *temp;
	temp = front;
	if(temp != NULL){
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}		
	}
	printf("\n\n");
}

int main(){
	int data, i;
	bool flag=0;
	
	front = rear = node = NULL;
	do{
		printf("Input number : ");
		scanf("%d", &data); fflush(stdin);
		if(front == NULL || data >= front->data){
			for(i=0; i<data; i++)
				enQueue(data);
			printf("Succes enqueue numbers %dx --> ", data);
			printQueue();
		}
		else{
			for(i=0; i<data; i++)
				flag = deQueue(data);
			if(flag == 0){
				printf("Succes dequeue numbers %dx --> ", data);
				printQueue();								
			}
		}
	}while(flag == 0);
	printf("\aProgram terminated\n");
	getchar();
	return 0;
}
