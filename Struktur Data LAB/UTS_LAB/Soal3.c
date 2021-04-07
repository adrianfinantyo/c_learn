#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

/*
Nama: Bonifasius Ariesto Adrian Finantyo
NIM: 00000042580
Kelas: A
*/

struct Node{
    char key;
    struct Node *left, *right;
} Node;

struct Node *newNode (char item) {
    struct Node *temp = (struct Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insert(struct Node *node, int key) {
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void printInorder (struct Node *node) {
    if (node == NULL) return;
    printInorder (node->left);
    printf("%c ", node->key);
    printInorder(node->right);
}

void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%c ", node->key);
    printPreorder(node->left);
    printPreorder(node->right);
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder (node->left);
    printPostorder(node->right) ;
    printf("%c ", node->key);
}

int toUpper(char key){
	if(key >= 97 && key <= 122)
		key -= 32;
	return key;
}

int isValid(char key){
	if(key >= 65 && key <= 90 || key == 35)
		return 0;
	printf("   Invalid input, ulangi lagi\n");
	return 1;
}

int main() {
    struct Node *root = NULL;
	char key, temp;
	
	printf("\n   Program Tree Huruf\n");
	printf("   ----------------------\n");
	do{
		printf("   Masukkan huruf: ");
		scanf("%c", &temp); fflush(stdin);
		temp = toUpper(temp);
		if(!isValid(temp))
			key = temp;
		if(key == '#')
			break;
		root = insert(root, key);
	}while(key != '#');
	printf("   ----------------------\n\n");
    printf("   Urutan traversal dari tree :\n");
    printf("   Preorder  : "); printPreorder(root); printf("\n");
    printf("   Inorder   : "); printInorder(root); printf("\n");
    printf("   Postorder : "); printPostorder(root); printf("\n\n");
    printf("   Tekan apa saja untuk keluar....");
	getchar();
    
    return 0;
}
