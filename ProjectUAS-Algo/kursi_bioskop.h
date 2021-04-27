#include <stdio.h>
#include <malloc.h>
#define MAX 100

struct Chair{
    int chair;
    struct Chair *next;
};

struct Chair *front, *rear;

void Enqueue(int data){
    struct Chair *node;

    node = (struct Chair*)malloc(sizeof(struct Chair));
    node->chair = data;
    node->next = NULL;
    if(front == NULL) front = rear = node;
    else{
        rear->next = node;
        rear = node;
    }
}

void Dequeue(){
    struct Chair *temp = front;
    free(front);
    front = temp->next;
}

void fetch(int *counter){
    int data;

    FILE *fp = fopen("./chair_db/chair.txt", "r");
    while(1){
        fscanf(fp, "%d\n", &data);
        Enqueue(data);
        (*counter)++;
        if(feof(fp)){
            fscanf(fp, "%d", &data);
            Enqueue(data);
            (*counter)++;
            break;
        }
        //printf("Enqueue --> %d\n", data);
    }
    fclose(fp);
}

void testQueue(int total){
    int i;

    struct Chair *node = front;
    for(i=0; i<total; i++){
        printf("Queue %d --> %d\n", i+1, node->chair);
        node = node->next;
    }
}

void printChair(){
    int chairArr[100] = {0}, i, counter = 0, row, col;
    
    fetch(&counter);
    struct Chair *node = front;
    while(node->next != NULL){
        chairArr[(node->chair)-1] = (node->chair);
        node = node->next;
    }
    // for(i=0; i<100; i++){
    //     printf("chairArr[%d] --> %d\n", i, chairArr[i]);
    // }
    printf("\t-----------------------------------------\n");
    for(row=0; row<10; row++){
        printf("\t");
        for(col=0; col<10; col++){
            if(chairArr[((row+1)*10)-(10-col)] != 0) printf("| X ");
            else printf("|%3d", ((row+1)*10)-(10-col)+1);
        }
        printf("|\n\t-----------------------------------------\n");
    }
    printf("\t-----------------------------------------\n\n");
}

void inputChair(){
    int inputUser;
    
    system("cls");
    printf("\n\n\t              MENU PILIH KURSI           \n\n");
    printChair();
    printf("\tPlease choose your seat: ");
    scanf("%d", &inputUser); fflush(stdin);
    FILE *fp = fopen("./chair_db/chair.txt", "a");
    fprintf(fp, "%d\n", inputUser);
    fclose(fp);
}