#include <stdio.h>

int main(){
    char x[5];
    int i;
    for(i=0; i<5; i++){
        scanf("%c", &x[i]);
    }
    for(i=0; i<5; i++){
        printf("char [%d] = %c\n", i, x[i]);
    }
    printf("DONE!\n");
    getchar();
    return 0;
}
