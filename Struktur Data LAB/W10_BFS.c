#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    int dest;
    struct Edge *next;
} Edge;

typedef struct Queue{
    int data;
    struct Queue *next;
} Queue;

void addEdge(Edge *adjlist[], int src, int dest){
    Edge *temp;

    temp=(Edge*)malloc(sizeof(Edge));
    temp->dest = dest;
    temp->next = NULL;

    if(adjlist[src] == NULL){
        adjlist[src] = temp;
    }
    else{
        Edge *ptr = adjlist[src];
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

int isEmpty(Queue *queue){
    if(queue == NULL) return 1;
    return 0;
}

void enqueue(Queue **queue, int start){
    Queue *data = (Queue*)malloc(sizeof(Queue));
    data->data = start;
    data->next = NULL;

    if(isEmpty(*queue)) *queue = data;
    else{
        Queue *temp = *queue;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = data;
    }
}

void dequeue(Queue **head){
    if(isEmpty(*head)){
        return;
    }

    Queue *trash = *head;
    *head = trash->next;
    free(trash);
}

int front(Queue *queue){
    if(queue == NULL) return 0;
    return queue->data;
}

void BFS(int start, int visited[], Edge *adjlist[]){
    Queue *queue = NULL;

    // Tandai vertex start-nya sudah dikunjungi, lalu masukkan ke queue
    visited[start] = 1;
    enqueue(&queue, start);

    while(!isEmpty(queue)){
        // Print lalu buang vertex dari queue
        int v = front(queue);
        printf("%d", v);
        dequeue(&queue);

        // Dapatkan semua adjacent vertex yang sudah di dequeue
        // Kalau belum di visit, tandai visited-nya dan di enqueue
        Edge *it;
        for(it=adjlist[v]; it!=NULL; it=it->next){
            if(!visited[it->dest]){
                visited[it->dest] = 1;
                enqueue(&queue, it->dest);
            }
        }
    }
}

int main(){
    int i;
    int src, dest;
    int start;

    int V; // Jumlah vertex dalam graph
    // Inisialisasi graph
    printf("Jumlah vertex = "); scanf("%d", &V);
    Edge *adjList[V];

    for(i=0; i<V; i++){
        adjList[i] = NULL;
    }

    i = 0;
    while(1){
        printf("Adjacency List ke-%d\n", ++i);
        printf("Source: "); scanf("%d", &src);
        printf("Destination: "); scanf("%d", &dest);
        printf("\n");
        
        if(src <= -1 || dest <= -1) break;
        else{
            addEdge(adjList, src, dest);
            addEdge(adjList, dest, src);
        }
    }

    // Inisialisasi nilai visited
    int visited[V+2];
    for(i=0; i<V+2; i++){
        visited[i] = 0;
    }

    // Mulai BFS
    printf("Starting node: "); scanf("%d", &start);
    BFS(start, visited, adjList);
	getchar();
	
    return 0;
}
