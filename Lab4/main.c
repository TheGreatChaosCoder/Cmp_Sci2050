#include "lab4.h"
#include <time.h>

int main(){
    short *array = createArray(6);
    printf("\nsize:%i", getSize(array));
    srand ( time(NULL) );

    for(int i=0; i<getSize(array); i++){
        short a = rand()%10+1;
        printf("\n%i", a);
        array[i] = a;
    }

    printf("\nthing: %i\n", countGreater(array, 5));

    freeArray(array);
}