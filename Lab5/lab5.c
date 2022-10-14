#include "lab5.h"

/**
 * @brief With the size given, it will malloc an int array of that size. In addition,
 * it will hide an ArrayInfo struct behind the pointer returned by the function that
 * will store the given size and set lastCalculation to -1. If an array is created 
 * using this function, the freeArray function must be used to free the array.
 * 
 * @param size The size of the int array
 * @return The pointer to the array with the ArrayInfo struct behind it if malloc
 * succeeds, NULL otherwise.
 */
int * createArray(int size){
    int *array = malloc(sizeof(ArrayInfo) + size*sizeof(int));

    //Check if malloc worked
    if(!array) return NULL;

    ((ArrayInfo*) (array))->size = size;
    ((ArrayInfo*) (array))->lastCalculation = -1;

    return (int*) (((ArrayInfo*) (array)) + 1);
}

/**
 * @brief Get the size of the int array if the array was
 * created by createArray(int size).
 * 
 * @param array The int array created by createArray(int size).
 * @return The size of the array.
 */
int getSize(int *array){
    return getInfo(array)->size;
}

/**
 * @brief Get the lastCalculation value from the ArrayInfo
 * struct before the array. This only applies if the array
 * is created using createArray(int size).
 * 
 * @param array An int array created by createArray(int size)
 * @return The value for the last calcuation done to the array
 */
int getLastCalculation(int *array){
    return getInfo(array)->lastCalculation;
}

/**
 * @brief Gets a pointer to the ArrayInfo struct that is located 
 * before the int array. This only applies if the array is created 
 * using createArray(int size).
 * 
 * @param array An int array created by createArray(int size)
 * @return The pointer to the ArrayInfo struct before the array
 */
ArrayInfo * getInfo(int *array){
    return (((ArrayInfo*) (array)) - 1);
}

/**
 * @brief Prints the last calculation done onto the array.
 * This is done by accessing the ArrayInfo struct located
 * before the array. If a previous calculation was done, it
 * will print out the result of that. It will print out -1
 * if no previous calculations were made. (By default,
 * lastCalculation is set to -1).
 * 
 * @param array An int array created by createArray(int size)
 */
void printLastCalculation(int *array){
    printf("\nLast Calculation Value: %i", getLastCalculation(array));
}

/**
 * @brief Given an int array created by createArray(int size), it will
 * sum every element of the array that is equal to three. The sum will be
 * stored in the ArrayInfo struct behind the array.
 * 
 * @param array An int array created by createArray(int size)
 */
void sumThrees(int *array){
    int sum=0, i;

    for(i=0; i<getSize(array); i++){
        if(array[i]==3) sum += 3;
    }

    getInfo(array)->lastCalculation = sum;
}

/**
 * @brief If an int array was created by createArray(int size), this
 * function must be used in order to free it.
 * 
 * @param array An int array created by createArray(int size)
 */
void freeArray(int *array){
    //Utilizing the getInfo function since that returns what is the first part of the malloced array
    free(getInfo(array));
}