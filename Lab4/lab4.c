#include "lab4.h"

/**
 * @brief Using the size it's given, it will allocate a short array of that size. In addition,
 * the size of the array will be stored as an int, hidden before the array. If sucessful, the
 * function will return the pointer to the array with the size hidden behind it. If it's not 
 * sucessful, the function will return null.
 * 
 * @param size The size of the array
 * @return a short pointer to the array with the size hidden behind it
 */
short * createArray(int size){
    short *array = malloc(sizeof(int) + size*sizeof(short));

    //Checking if malloc worked
    if(!array) return NULL;

    *((int*) array) = size;

    return (short*) (((int*) array)+1);
}

/**
 * @brief Retrieve the size of a short array that has its size hidden before the array pointer
 * 
 * @param array The short array created by createArray(int size)
 * @return The size of the array
 */
int getSize(short *array){
    //The size is located one int space behind the parameter pointer
    return *(((int*) array) - 1);
}

/**
 * @brief The function will go through a short array and count how many elements
 * are greater than the query value. It will return how many elements are greater.
 * 
 * @param array A short array created by createArray(int size)
 * @param query The value each element is compared against
 * @return The number of elements greater than the query value
 */
int countGreater(short *array, int query){
    int count = 0, i;

    for(i=0; i<getSize(array); i++){
        if(array[i]>query) count++;
    }

    return count;
}

/**
 * @brief If a short array is created by createArray(int size), it must be freed using this function.
 * 
 * @param array The array that will be freed
 */
void freeArray(short *array){
    /*It frees the pointer one int space back from the parameter because the allocated array had an additional space
      for the size, which must also be freed*/
    free(((int*) array) - 1);
}
