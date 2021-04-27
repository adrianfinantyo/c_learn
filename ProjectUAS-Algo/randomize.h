#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int length){
    int number = 0, i;
    srand(time(0));
    for(i=0; i<length; i++){
        number = number + rand() % 9;
        if(i != length-1)
            number *= 10;
    }
    printf("\nini random number : %d\n\n", number);
    return number;
}