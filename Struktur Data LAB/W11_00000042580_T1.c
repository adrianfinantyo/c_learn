#include <stdio.h>
#include <limits.h>
#define EMPTY INT_MAX

void arrInit(int Arr[26][26]){
    int i, j;
    for(i=0; i<26; i++){
        for(j=0; j<26; j++)
            Arr[i][j] = EMPTY;
    }
}

void printArr(int Arr[26][26], int counter){
    int i, j;
    for(i=0; i<counter; i++){
        for(j=0; j<counter; j++){
            printf("%2d  "), Arr[i][j];
        }
        printf("\n");
    }
}

int charToint(char c){
    printf("index --> %d\n", c-97);
    return c-97;
}

int main(){
    int src_index, dest_index;
    int weight, counter=0, Arr[26][26];

    arrInit(Arr);
    while(1){
        scanf("%c#%c#%d", &src_index, &dest_index, &weight); fflush(stdin);
        // Conditional break
        if(src_index == '-' || dest_index == '-') break;
        else if(src_index == '\0') continue;
        // Push data into Array
        Arr[charToint(src_index)][charToint(dest_index)] = weight;
        ++counter;
    }
    printArr(Arr, counter);
    // printf("\n\nsource: ");
    // scanf("%c", &src_index);


    getchar();
    return 0;
}