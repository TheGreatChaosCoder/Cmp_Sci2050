#include "lab6.h"

/**
 * @brief Using the size it's given, it will allocate a Student array of that size. In addition,
 * the size of the array will be stored as an int, hidden before the array. If sucessful, the
 * function will return the pointer to the array with the size hidden behind it. If it's not 
 * sucessful, the function will return null.
 * 
 * @param size The size of the array
 * @return A Student pointer to the array with the size hidden behind it
 */
Student * createArray(int size){
    //Initially an int array so it is easier to store the size
    int *array = malloc(sizeof(int) + size*sizeof(Student));

    //Check if malloc worked
    if(!array) return NULL;

    array[0] = size;

    return (Student *) (array + 1);
}

/**
 * @brief Retrieve the size of a Student array that has its size hidden before the array pointer
 * 
 * @param array The Student array created by createArray(int size)
 * @return The size of the array
 */
int getSize(Student *array){
    return *(((int *)(array))-1);
}

/**
 * @brief Given a Student array, it will return a pointer to the Student
 * struct at a given index. If the index is out of bounds for the array,
 * it will return NULL.
 * Note: The array starts at index 0.
 * 
 * @param array A Student array created by createArray(int size)
 * @param index The index the Student struct is located at
 * @return A pointer to the Student struct
 */
Student * getStudent(Student *array, int index){
    if(index<0 || index>=getSize(array)) return NULL;
    return array + index;
}

/**
 * @brief Given a pointer to a Student struct, it will return
 * the GPA value stored within that struct. If the pointer is
 * NULL, then -1 will be returned.
 * 
 * @param s A pointer to the Student struct
 * @return The GPA value of the Student struct
 */
float getGPA(Student *s){
    if(!s) return -1;
    return s->gpa;
}

/**
 * @brief Given a pointer to a Student struct, it will return
 * the ID value stored within that struct. If the pointer is
 * NULL, then -1 will be returned.
 * 
 * @param s A pointer to the Student struct
 * @return The ID value of the Student struct
 */
int getID(Student *s){
    if(!s) return -1;
    return s->id;
}

/**
 * @brief Given an array of Students, it will return
 * a pointer to the Student in the array that has the highest
 * ID value. Will return NULL if the size of the array is zero.
 * 
 * @param array A Student array created by createArray(int size);
 * @return A pointer to the Student in the array with the highest ID value.
 */
Student * getMaxID(Student *array){
    if(getSize(array) <= 0) return NULL;

    int i, maxIndex = 0;

    //Loops start at one because if there is only one element,
    //then there is no need to compare values.
    for(i=1; i<getSize(array); i++){
        if(getStudent(array, maxIndex) -> id < getStudent(array,i) -> id){
            maxIndex = i;
        }
    }

    return getStudent(array, maxIndex);
}

/**
 * @brief If an Student array was created by createArray(int size),
 * this function must be used in order to free it.
 * 
 * @param array A Student array created by createArray(int size)
 */
void freeArray(Student *array){
    free(((int *)(array))-1);
}