#include <stdio.h>
#include <stdlib.h>

typedef struct {
	/* stores the result of the last
	 * calculation done on the array
	 */
	int lastCalculation;
	int size;
} ArrayInfo;

int * createArray(int size);
int getSize(int *array);
ArrayInfo * getInfo(int *array);
void printLastCalculation(int *array);

void sumThrees(int *array);

void freeArray(int *array);
