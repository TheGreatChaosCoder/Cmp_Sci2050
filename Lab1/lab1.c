#include "lab1.h"
/* getMin:
*  Takes in the size of the array, an integer array, and a integer pointer
*  to represent the smallest value in the array
*
*  The function will return 0 if no errors occur, or -1 if a error occurs, 
*  either a null array or a size less than 1 is inputted. The smallest number 
*  in the array will be stored in the integer pointer called 'result'.
*/
int getMin(int size , int *array , int *result){
    //Checks for NULL array and size<-1
    if(array==NULL || size<1) return -1;

    int i, min=array[0];

    /*
    loops through the array to find the minimum
    if size==1, it will not go through the loop as the minimum is already found
    since min is already set to array[0]
    */
    for(i=1; i<size; i++){
        min = array[i]<min ? array[i] : min;
    }

    *result = min;
    return 0;
}

