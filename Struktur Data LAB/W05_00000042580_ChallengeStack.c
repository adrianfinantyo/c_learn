#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
  
struct bracket{
	char data;
	struct bracket *next;
};

bool isMatchingPair(char char1, char char2){
	if(char1 == '(' && char2 == ')')
		return 1;
	else if(char1 == '{' && char2 == '}')
		return 1;
	else if(char1 == '[' && char2 == ']')
		return 1;
	else
		return 0;
}

void push(struct bracket **top_ref, int new_data){
	struct bracket *new_node = (struct bracket*)malloc(sizeof(struct bracket));
	
	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int pop(struct bracket **top_ref){
	char res;
	struct bracket *top;
	
	if(*top_ref == NULL){
		printf("Stack is empty...");
		getchar();
	}
	else{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

bool areBracketsBalanced(char str[]){
	int i=0;
	struct brackets *stack = NULL;
	
	while (str[i]){
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			push(&stack, str[i]);
		if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
			if(stack == NULL)
				return 0;
			else if(!isMatchingPair(pop(&stack), str[i]))
				return 0;
		}
	i++;
	}
	if(stack==NULL)
		return 1;
	else
		return 0;
}

int main(){
	char str[100];
	
	printf("Input string : ");
	scanf("%[^\n]", str);
	if(areBracketsBalanced(str))
		printf("Balanced\n");
	else
		printf("Not Balanced\n");
	return 0;
}
