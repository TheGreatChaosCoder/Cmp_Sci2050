#include "lab0.h"

//The following loops over each array element and see if it is equal to num
//If it is, it will increase count until all elements are checked
//Returns count after the loop
int countOccurrences(int size, int* arr, int num){
    int count=0, i; 

    for(i=0; i<size; i++){
        if(arr[i] == num) {count++;}
    }

    return count;
}