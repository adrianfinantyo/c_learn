#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define bool int

struct stack{
    char exp[50];
    struct stack *next, *prev;
}*top, *bottom, *node;

void push(char str[]){
    node = (struct stack*)malloc(sizeof(struct stack));
    strcpy(node->exp, str);
    node = NULL;
    if(top == NULL)
        top = bottom = node;
    else{
        top->prev = top;
        top->next = node;
        top = node;
    }
    top->next = NULL;
}

void pop(){
    if(top == NULL)
        return;
    struct stack *temp = top;
    top = temp->prev;
    free(temp);
}

bool isOperator(char str){
    if(str == '+' || str == '-' || str == '*' || str == '/')
        return 1;
    return 0;
}

void PreToIn(char str[]){
    int i;
    char op1, op2, temp[50];
    
    top = bottom = NULL;
    for(i=strlen(str); i>=0; i--){
        if(isOperator(str[i])){
            op1 = top->exp; pop;
            op2 = top->exp; pop;
            strcat(temp, "(");
            strcat(temp, op1);
            strcat(temp, str[i]);
            strcat(temp, op2);
            strcat(temp, ")");
            push(temp);
        }
        else
            push(str[i]);
    }
    node = bottom;
    if(bottom != NULL){
        while(node != NULL){
            printf("%s", node->exp);
            node = node->next;
        }
    }
}

int main(){
    char str1[10] = {"*—+ab+cd"};

    PreToIn(str1);

    return 0;
}
