#include <stdio.h>
#include <malloc.h>

struct tnode{
	int data;
	struct tnode *next;
};

void addFromHead(struct tnode **head_ref, struct tnode *new_node){
	if ((*head_ref) != NULL)
		new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void deleteList(struct tnode **head_ref){
	struct tnode *temp;
	while((*head_ref) != NULL){
		temp = (*head_ref);
		(*head_ref) = temp->next;
		free(temp);
	}
}

int main(){
	struct tnode *head, *node;
	int i, num;
	head = NULL;
	for(i=0; i<10; i++){
 		scanf("%d", &num);
 		node = (struct tnode*) malloc(sizeof(struct tnode));
 		node->data = num;
		node->next = NULL;
 		addFromHead(&head, node);
	}
	deleteList(&head);
	return 0;
}
