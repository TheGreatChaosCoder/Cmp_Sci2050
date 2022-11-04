#include "lab9.h"

/**
 * @brief A helper function to swap two Runner pointers. Used for sorting
 * an array of Runners.
 * 
 * @param a Pointer to a Runner variable
 * @param b Pointer to another Runner variable
 */
void swap(Runner *a, Runner *b){
    Runner temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Given an array of Runner structs and the size of that array, the
 * function will sort the array in ascending order by age. The function uses
 * bubble sort to sort the array and therefore will take O(n^2) time complexity
 * where n is the size of the array.
 * 
 * @param array An Array of Runner structs
 * @param size The size of the array
 */
void sortByAge(Runner *array, int size){
    int i, j;

    /*j loops through the array, i is to make sure that the end of the array
    is not checked constantly every loop*/
    for(i=0; i<size-1; i++){
        for(j=0; j<size-i-1; j++){
            if(array[j].age>array[j+1].age)
                swap(array+j, array+j+1);
        }
    }
}

/**
 * @brief Given an array of Runner structs, sorted by age, and the size of
 * the array, the function will return the index of the Runner element with
 * the specified age. If none of the Runner structs have the given age, the
 * function will return -1. The fuction uses binary search and therefore will
 * have a time complexity of O(log(n)), where n is the size of the array. If 
 * there are multiple Runners with the samegiven age, the function will return 
 * the index of the first one it finds.
 * 
 * @param array An array of Runner structs, sorted by age
 * @param size The size of the array
 * @param age An age that one of the Runner structs might have
 * @return The index to the Runner struct that has the given age,
 *         -1 if none of the Runner structs have that age. 
 */
int getByAge(Runner *array, int size, int age){
    int low = 0, high=size-1, mid;

    while(low<=high){
        mid = (low+high)/2;

        if(array[mid].age<age) low=mid+1;
        else if(array[mid].age>age) high=mid-1;
        else return mid;
    }

    return -1;
}