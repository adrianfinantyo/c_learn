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

    getchar();
    return 0;
}