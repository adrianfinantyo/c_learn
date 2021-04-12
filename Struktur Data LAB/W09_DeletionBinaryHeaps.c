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

void MinHeapify(MinHeap *mHeap, int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < mHeap->heapSize && mHeap->hArr[l] < mHeap->hArr[i]) smallest = 1;
    if(r < mHeap->heapSize && mHeap->hArr[r] < mHeap->hArr[smallest]) smallest = r;
    if(smallest != i){
        swap(&mHeap->hArr[i], &mHeap->hArr[smallest]);
        MinHeapify(mHeap, smallest);
    }
}

int extraction(MinHeap *mHeap){
    if(mHeap->heapSize <= 0) return INT_MAX;
    if(mHeap->heapSize == 1){
        mHeap->heapSize--;
        return mHeap->hArr[0];
    }

    // Simpan nilai minummnya dan hapus dari heap
    int root = mHeap->hArr[0];
    mHeap->hArr[0] = mHeap->hArr[mHeap->heapSize-1];
    mHeap->heapSize--;
    MinHeapify(mHeap, 0);
}

int getMin(MinHeap *mHeap){
    return mHeap->hArr[0];
}

void printHeap(MinHeap mHeap){
    printf("Current heap : ");
    for(int i=0; i<mHeap.hArr[i]; i++){
        printf("%d ", mHeap.hArr[i]);
    }
    printf("\n");
}

// Mengurangi nilai pada indeex i mnjadi newValue dengan asumsi
// nilai newValue lebih kecil dari hArr[i]
void decreaseKey(MinHeap *mHeap, int i, int newValue){
    mHeap->hArr[i] = newValue;
    while(i != 0 && mHeap->hArr[parent(i) > mHeap->hArr[i]]){
        swap(&mHeap->hArr[i], &mHeap->hArr[parent(i)]);
        i = parent(i);
    }
}

// Pertama-tama dengan mengurangi nilainya menjadi negatif tak terhingga
// Agar menjadi paling kecil
// Lalu memanggil extractMin() untuk menghapusnya
void deleteKey(MinHeap *mHeap, int i){
    printf("Current Heap size = %d\n\n", mHeap->heapSize);
    printf("Deleting index %d from heap\n", i);
    decreaseKey(mHeap, i, INT_MIN);
    extractMin(mHeap);
}

int main(){
    MinHeap mHeap;

    mHeap = createHeap(11);
    printHeap(mHeap);
    insertKey(&mHeap, 3);
    printHeap(mHeap);
    insertKey(&mHeap, 2);
    printHeap(mHeap);
    insertKey(&mHeap, 1);
    printHeap(mHeap);
    insertKey(&mHeap, 15);
    printHeap(mHeap);
    insertKey(&mHeap, 5);
    printHeap(mHeap);
    insertKey(&mHeap, 4);
    printHeap(mHeap);
    insertKey(&mHeap, 45);
    printHeap(mHeap);
    printf("Min Value in Heap: %d \n", getMin(&mHeap));

    extractMin(&mHeap);
    printHeap(mHeap);

    deleteKey(&mHeap, 1);
    printHeap(mHeap);

    return 0;
}