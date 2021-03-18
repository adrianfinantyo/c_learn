#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left, *right;
}Node;

Node *newNode (int item){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key){
    if(node == NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

void PreOrder(Node *temp){
    if(temp == NULL)
        return;
    printf("%d ", temp->key);
    PreOrder(temp->left);
    PreOrder(temp->right);
}

void InOrder(Node *temp){
    if(temp == NULL)
        return;
    InOrder(temp->left);
    printf("%d ", temp->key);
    InOrder(temp->right);
}

void PostOrder(Node *temp){
    if(temp == NULL)
        return;
    PostOrder(temp->left);
    PostOrder(temp->right);
    printf("%d ", temp->key);
}

int main(){
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
	
    // Print Transversal
    printf("Binary Tree in PreOrder   : ");
    PreOrder(root);
    printf("\nBinary Tree in InOrder    : ");
    InOrder(root);
    printf("\nBinary Tree in PostOrder  : ");
    PostOrder(root);
    printf("\n"); getch();
    
    return 0;
}
