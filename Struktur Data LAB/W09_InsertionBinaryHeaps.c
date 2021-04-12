#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct MinHeap{
    int *hArr;
    int capacity;
    int heapSize;
}MinHeap;

MinHeap createHeap(int cap){
    MinHeap newHeap;
    newHeap.heapSize = 0;
    newHeap.capacity = cap;
    newHeap.hArr = malloc(sizeof(int) * cap);

    int i;
    for(i=0; i<cap; i++){
        newHeap.hArr[i] = 0;
    }

    return newHeap;
}

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return (2*i + 1);
}

int left(int i){
    return (2*i + 2);
}

// Function untuk menukar 2 buah angka
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function untuk memasukkan angka baru ke heeap
void insertKey(MinHeap *mHeap, int k){
    printf("Current Heap Size = %d\n\n", mHeap->heapSize);
    printf("Inserting %d to heap\n", k);
    if(mHeap->heapSize == mHeap->capacity){
        printf("\nOverflow: Could not insertKey\n");
        return;
    }

    // Pertama-tama, masukkan angka ke dalam index terakhir
    mHeap->heapSize++;
    int i = mHeap->heapSize - 1;
    mHeap->hArr[i] = k;

    // Memperbaiki properti dari min heap
    // Jika angka baru yang masuk tidak memenuhi kriteria min heap
    while(i != 0 && mHeap->hArr[parent(i)] > mHeap->hArr[i]){
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

int getMin