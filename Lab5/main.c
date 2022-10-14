#include "lab5.h"
#include <stdlib.h>
#include <time.h>

int main(){
    int *array = createArray(5);

    printf("\nsize:%i", getSize(array));
    srand ( time(NULL) );

    for(int i=0; i<getSize(array); i++){
        int a = rand()%10+1;
        array[i] = a;
        printf("\n%i", array[i]);
    }

    printLastCalculation(array);
    sumThrees(array);
    printLastCalculation(array);
    printf("\n");

    freeArray(array);
}