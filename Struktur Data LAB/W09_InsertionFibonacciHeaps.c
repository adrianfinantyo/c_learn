#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct node {
    struct node* parent;
    struct node* child;
    struct node* left;
    struct node* right;
    int key;
}node;

// Function untuk memasukkan node keedalam Heap
void insertion(node* *mini, int val){
    struct node* new_node = (node*)malloc(sizeof(node));
    new_node->key = val;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if((*mini) != NULL){
        ((*mini)->left)->right = new_node;
        new_node->right = *mini;
        new_node->left = (*mini)->left;
        (*mini)->left = new_node;
        if(new_node->key < (*mini)->key)
            (*mini) = new_node;
    }
    else{
        (*mini) = new_node;
    }
}

// Function untuk menampilkan Heap
void display(struct node* mini, int no_of_nodes){
    node* ptr = mini;
    if(ptr == NULL) printf("The Heap is Empty\n");
    
    else{
        printf("The root nodes of Haep are: \n");
        do{
            printf("%d", ptr->key);
            ptr = ptr->right;
            if(ptr != mini){
                printf("-->");
            }
        } while (ptr != mini && ptr->right != NULL);
    printf("\nThe heap has %d nodes\n", no_of_nodes);
    }
}

// Function untuk mencari node minimum dalam Heap
void find_min(struct node* mini){
    printf("min of heap is: %d\n", mini->key);
}

int main(){
    // Membuat variable "mini" sebagai minimum pointer
    struct node* mini = NULL;

    int no_of_nodes = 0;
    no_of_nodes = 7;
    insertion(&mini, 4);
    insertion(&mini, 3);
    insertion(&mini, 7);
    insertion(&mini, 5);
    insertion(&mini, 2);
    insertion(&mini, 1);
    insertion(&mini, 10);

    display(mini, no_of_nodes);

    find_min(mini);

    return 0;
}