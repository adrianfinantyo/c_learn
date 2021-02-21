#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Mahasiswa{
    char nama[100];
    char jurusan[30];
    int nim;
    struct Mahasiswa *next;
} Mahasiswa;

int main(){
    Mahasiswa *head, *node;
    
    head = NULL;
    node = (Mahasiswa*) malloc(sizeof(Mahasiswa));
    
    node->nim = 14026;
    strcpy(node->nama, "James Chirstian Wira");
    strcpy(node->jurusan, "Informatika");

    node->next = NULL;
    head = node;

    return 0;
}
