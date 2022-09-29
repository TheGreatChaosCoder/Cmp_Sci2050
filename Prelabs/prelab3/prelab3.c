#include <stdio.h>

/* This function returns a double array that can be indexed 
   starting at minIndex and ending at maxIndex, i.e., minIndex 
   is the index of the first element of the array and maxIndex 
   is the index of the last element of the array. The function: 
   void freeDoubleArray(double * array, int minIndex) must be 
   called to free the allocated array. 
*/  
double * createDoubleArray(int minIndex, int maxIndex){
    double *array = malloc((maxIndex-minIndex) * sizeof(double));
    array -= minIndex;
    return array;
}

void freeDoubleArray(double * array, int minIndex){
    array += minIndex;
    free(array);
}