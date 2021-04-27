#include <stdio.h>
#include <limits.h>

/*
    Judul   : W11_00000042580_T1 (Dijsktra)
    Nama    : Bonifasius Ariesto Adrian Finantyo
    NIM     : 00000042580
*/

void arrInit(int Arr[28][28]){
    int i, j;
    for (i = 0; i < 28; i++){
        for (j = 0; j < 28; j++)
            Arr[i][j] = INT_MAX;
    }
}

void printArr(int Arr[28][28], int counter){
    int i, j;
    for (i = 0; i < counter-1; i++){
        for (j = 0; j < counter+2; j++){
            if(Arr[i][j] == INT_MAX) printf(" XX ");
            else printf("%2d  ", Arr[i][j]);
        }
        printf("\n");
    }
}

void correctingArr(int Arr[28][28], int counter, int source){
    int i, j, min;
    for (i = 0; i < counter-1; i++){
        min = INT_MAX;
        for (j = 0; j < counter; j++){ 
            if(i > 0 && Arr[i][j] != INT_MAX)
                Arr[i][j] += Arr[i-1][counter];
            if(j == source) Arr[i][j] = INT_MAX;
            if(i > 0 && j == Arr[i-1][counter+1]) Arr[i][j] = INT_MAX;
            if(Arr[i][j] < min){
                min = Arr[i][j];
                Arr[i][counter] = min;
                Arr[i][counter+1] = j;
            }
            if(i == counter-2){
              Arr[i][counter] = INT_MIN;
              if(Arr[i-1][j] != INT_MAX && Arr[i-1][j] > Arr[i-1][counter]){
                Arr[i][counter] = Arr[i-1][j];
                Arr[i][counter+1] = j;
              }
            }
        }
        printf("\n");
    }
}

void printOutput(int Arr[28][28], int counter, char source){
    int i;
    printf("Untuk mencapai kota %c dari kota %c membutuhkan jarak terpendek 0\n", source, source);
    for (i = 0; i < counter-1; i++){
        printf("Untuk mencapai kota %c dari kota %c membutuhkan jarak terpendek %d\n",
        Arr[i][counter+1]+97, source, Arr[i][counter]);
    }
}

int charToint(char c){
    return c - 97;
}

int main(){
    char src_index, dest_index, source;
    int weight, counter = INT_MIN, Arr[28][28];

    arrInit(Arr);
    while (1){
        scanf("%c#%c#%d", &src_index, &dest_index, &weight);
        fflush(stdin);
        // Conditional break
        if (src_index == '-' || dest_index == '-')
            break;
        else if (src_index == '\n')
            continue;
        // Push data into Array
        Arr[charToint(src_index)][charToint(dest_index)] = weight;
        // Control counter
        if (charToint(src_index) > counter)
            counter = charToint(src_index) + 1;
        if (charToint(dest_index) > counter)
            counter = charToint(dest_index) + 1;

    }
    getchar();
    printf("\nsource: ");
    scanf("%c", &source); fflush(stdin);

    correctingArr(Arr, counter, charToint(source));

    printArr(Arr, counter);
    printOutput(Arr, counter, source);

    getchar();
    return 0;
}