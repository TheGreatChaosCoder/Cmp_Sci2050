#include "lab3.h"

/**
 * @brief It take an integer representing the size of the array to allocate. It will then allocate
 * an integer array, and if successful, initialize it with a random int from 0 to 9 inclusive in each index. 
 * If the array was successfully allocated, the function will return a pointer to it, otherwise the function 
 * will return NULL.
 * @param size the integer that the array will be the size of
 * @return The pointer to the array
 */
int * makeArray(int size){
    int *p = malloc(size*sizeof(int));
    
    //checking if malloc worked
    if(!p) return NULL;
    
    //srand(time(NULL)) is called here incase it is not called elsewhere
    srand ( time(NULL) );

    for(int i=0; i<size; i++){
        p[i] = rand()%10;
    }

    return p;
}

/**
 * @brief Given an integer array, it will offset the pointer such that array[offset] represents the first element.
 * The function will return the offsetted pointer. Note that the array in the parameter will not be offsetted in
 * the function itself, however it can be by setting the array to be the pointer returned by the function.
 * @param array The array that will be offsetted
 * @param offset The amount the pointer will be offsetted by
 * @return The offsetted pointer to the array
 */
int * offsetArray(int *array, int offset){
    return array - offset;
}

/**
 * @brief Given an array and its offset, it will print out all of the indexes where the element at that index
 * is equal to 5. ie. With not offset and the array {5, 0 5}, "0, 2" will be printed. However, with an offset
 * eqaul to 2, the same array will print out {2,4}.
 * @param array The array that will be checked for fives
 * @param size The size of the array
 * @param offset The offset of the pointer (the array can be offsetted by offsetArray(int *array, int offset))
 */
void printFives(int *array , int size , int offset){
    /*This int is used similarly to a boolean; it is only used for formatting purposes so the for loop knows when to
    start putting commas*/
    short int firstFive = 1;

    for(int i=offset; i<size+offset; i++){
        if(array[i]==5){
            if(firstFive){
                printf("\n%i", i);
                firstFive = 0;
            }
            else printf(", %i",i);
        }
    }
    printf("\n");
}

/**
 * @brief Frees the allocated array. If the array was offsetted by offsetArray(int *array, int offset),
 * the offset amount is required to free the array with no errors.
 * @param array The array that will be freed
 * @param offset The amount the array pointer has been offsetted by
 */
void freeArray(int *array, int offset){
    free(array+offset);
}




