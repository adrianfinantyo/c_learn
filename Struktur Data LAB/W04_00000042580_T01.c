#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Mahasiswa{
    char nama[100];
    char jurusan[30];
    int nim;
    struct Mahasiswa *next, *prev;
} Mahasiswa;

Mahasiswa *createNewNode(int nim, char *nama, char *jurusan){
    Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    newNode->nim = nim;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next = NULL;
    return newNode;
}

/*void printLinkedList(Mahasiswa *head){
    Mahasiswa *temp;

    temp = head;
    int i=1;
    while(temp != NULL){
        printf("Data ke %d\n", i);
        printf("NIM     : %d\n", temp->nim);
        printf("Nama    : %s\n", temp->nama);
        printf("Jurusan : %s\n", temp->jurusan);
        temp = temp->next;
        i++;
    }
}*/
void printLinkedList(Mahasiswa *head){
    Mahasiswa *temp;

    temp = head;
    int i=1;
    while(i<=6){
    	if(temp != NULL){
    		printf("Data ke %d\n", i);
        	printf("NIM     : %d\n", temp->nim);
        	printf("Nama    : %s\n", temp->nama);
        	printf("Jurusan : %s\n\n", temp->jurusan);
		}else{
			printf("data ke-%d = NULL\n", i);
			break;	
		}
		temp = temp->next;
        i++;
    }
}

int main(){
    Mahasiswa *head, *node, *tail;
    
    head = NULL;
    node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    
    node = createNewNode(14026, "James Christian Wira", "Informatika");
    head = tail = node;
    
    node = createNewNode(17492, "Matthew Evans", "Informatika");
    tail->prev = tail;
	tail->next = node;
    tail = node;

    node = createNewNode(1366, "Justin Susanto", "Informatika");
    tail->prev = tail;
	tail->next = node;
    tail = node;
    
    head->prev = tail;
    tail->next = head;    
	
    printf("Data Yang Terbaca\n\n");
    printLinkedList(head);
    return 0;
}
