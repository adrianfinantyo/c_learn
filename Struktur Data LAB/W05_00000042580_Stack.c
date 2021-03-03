#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Mahasiswa{
    char nim[13];
    char nama[50];
    char jurusan[30];
    struct Mahasiswa *next;
}Mahasiswa;

int isEmpty(Mahasiswa *stack){
    if(stack == NULL)
        return 1;
    return 0;
}

void push(Mahasiswa **stack, char nim[], char nama[], char jurusan[]){
    Mahasiswa *data = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(data->nim, nim);
    strcpy(data->nama, nama);
    strcpy(data->jurusan, jurusan);
    data->next = NULL;

    if(!isEmpty(*stack))
        data->next = *stack;
    *stack = data;
    printf("Adding %s to Stack\n", nama);
}

void pop(Mahasiswa **stack){
    printf("Removing Stack's top element\n");
    if(*stack == NULL){
        printf("Noting to pop. Stack already empty\n");
        return;
    }
    Mahasiswa *trash = *stack;
    *stack = trash->next;
    free(trash);
    printf("Pooping Stack success\n");
}

Mahasiswa *top(Mahasiswa *stack){
    if(stack == NULL) return NULL;
    return stack;
}

int main(){
    printf("STACK TUTORIAL\n");
    printf("--------------\n\n");

    printf("Initializing Stack\n\n");
    Mahasiswa *stackMhs;
    stackMhs = NULL;

    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "Yes" : "No");
    printf("what is the name at the top? %s\n\n",
            top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama
    );
    
    push(&stackMhs, "14026", "James Christian Wira", "Informatika");
    printf("what is the name at the top? %s\n",
            top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama
    );
    printf("Is Stack empty? %s\n\n", isEmpty(stackMhs) ? "Yes" : "No");
    
    pop(&stackMhs);
    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "Yes" : "No");
    printf("what is the name at the top? %s\n\n",
            top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama
    );

    push(&stackMhs, "17492", "Matthew Evans", "Informatika");
    push(&stackMhs, "14045", "Michael Roni", "Informatika");
    push(&stackMhs, "10000", "Mario Alexander", "Informatika");
    printf("what is the name at the top? %s\n\n",
            top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama
    );

    pop(&stackMhs);
    printf("what is the name at the top? %s\n\n",
            top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama
    );

    pop(&stackMhs);
    printf("what is the name at the top? %s\n\n",
            top(stackMhs)==NULL ? "No one. Stack is empty" : top(stackMhs)->nama
    );

    pop(&stackMhs);
    printf("\n");
    pop(&stackMhs);

    return 0;
}