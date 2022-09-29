#include "lab2.h"

/* makeArray:
   It take an integer representing the size of the array to allocate. It will then allocate
   the array, and if successful, initialize it with 0 in each index. If the array was successfully allocated
   the function will return a pointer to it, otherwise the function will return NULL.

   int size - the integer that the array will be the size of
*/

int * makeArray(int size){
    int *p = malloc(size*sizeof(int));
    
    //checking if malloc worked
    if(!p) return NULL;

    for(int i=0; i<size; i++){
        p[i] = 0;
    }

    return p;
}

/* fillTwos:
   Given an array and its size, it will fill the array with mulitiples of
   two starting at zero.

   int *array - the array to be used
   int size - the size of the array
*/
void fillTwos(int *array, int size){
    for(int i=0; i<size; i++){
        array[i] = i*2;
    }
}

/* freeArray:
   Given the address to an int array, it will free the memory allocated to
   the array. In addition, it will set the array pointer to NULL.

   int **array - the address to the array that will be freed
*/
void freeArray(int **array){
    free(*array);
    *array = NULL;
}

