#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Nama: Bonifasius Ariesto Adrian Finantyo
NIM: 00000042580
Kelas: A
*/

struct negara{
	char nama[20];
	struct negara *next;
};

struct negara *Q1Front, *Q1Rear, *Q1Node;
struct negara *Q2Front, *Q2Rear, *Q2Node;
struct negara *QFront, *QRear, *QNode;

void enQueue1(char negara[]){
	Q1Node = (struct negara*)malloc(sizeof(struct negara));
	strcpy(Q1Node->nama, negara);
	if(Q1Front == NULL)
    	Q1Front = Q1Rear = Q1Node;
    else{
		Q1Rear->next = Q1Node;
        Q1Rear = Q1Node; 	
	}
	Q1Rear->next = NULL;
}

void enQueue2(char negara[]){
	Q2Node = (struct negara*)malloc(sizeof(struct negara));
	strcpy(Q2Node->nama, negara);
	if(Q2Front == NULL)
    	Q2Front = Q2Rear = Q2Node;
    else{
		Q2Rear->next = Q2Node;
        Q2Rear = Q2Node; 	
	}
	Q2Rear->next = NULL;
}

void enQueue(char negara[]){
	QNode = (struct negara*)malloc(sizeof(struct negara));
	strcpy(QNode->nama, negara);
	if(QFront == NULL)
    	QFront = QRear = QNode;
    else{
		QRear->next = QNode;
        QRear = QNode; 	
	}
	QRear->next = NULL;
}

void compare(){
	Q2Node = Q2Front;
	while(Q2Node != NULL){
		Q1Node = Q1Front;
		while(Q1Node != NULL){
			if(!strcmp(Q2Node->nama, Q1Node->nama))
				enQueue(Q2Node->nama);
			Q1Node = Q1Node->next;
		}
		Q2Node = Q2Node->next;
	}
}

int main(){
	int i;
	
	// Memasukkan nama negara ke Queue 1 Linked list
	enQueue1("Afrika");
	enQueue1("Amerika");
	enQueue1("Belanda");
	enQueue1("Perancis");
	enQueue1("Italia");
	enQueue1("Spanyol");
	enQueue1("Portugal");
	enQueue1("Swiss");
	enQueue1("Denmark");
	enQueue1("Jerman");
	// Memasukkan nama negara ke Queue 2 Linked list
	enQueue2("Jepang");
	enQueue2("Swiss");
	enQueue2("Afrika");
	enQueue2("Belgia");
	enQueue2("Jerman");
	enQueue2("Swedia");
	enQueue2("Korea");
	enQueue2("Australia");
	// Compare Q1 dengan Q2
	compare();
	QNode = QFront;
	if(QFront == NULL)
		printf("Tidak ada yang sama\n");
	else{
		printf("\n   Negara yang sama dari 2 buah queue:\n");
		while(QNode != NULL){
			++i;
			printf("   %d). %s\n", i, QNode->nama);
			QNode = QNode->next;
		}
		printf("   Sehingga total ada %d negara yang sama\n", i);
	}
	printf("\n\n   ---------------------------------------------\n");
	printf("   Tekan apa saja untuk keluar...");
	getchar();
	return 0;
}
