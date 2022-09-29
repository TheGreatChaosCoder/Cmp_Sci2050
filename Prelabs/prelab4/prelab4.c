#include <stdio.h>
#include <stdlib.h>

void * createArray(int size, int dataSize){
    void* array = malloc(sizeof(int) + size*dataSize);
    *((int*) array) = size;
    return (void *) (((int*) array)+1);
}

int getSize(void * array){
    return *(((int*)array)-1);
}

void freeArray(void * array){
    free(((int*)array)-1);
}

int main(){
    float* array = createArray(9, sizeof(float));
    printf("\n%i", getSize(array));
    array[8] = 6.0;
    printf("\n%f", array[8]);

    freeArray(array);
}