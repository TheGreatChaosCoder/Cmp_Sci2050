#include "lab3.h"

void printArray(int *array, int size) {
	printf("[ ");
	for(int i = 0; i < size; ++i) {
		printf("%d", array[i]);
		if((i + 1) == size) {
			printf(" ]\n");
		} else {
			printf(", ");
		}
	}
}

int main() {
	srand(time(NULL));
	int size = 5;
	int * arr = makeArray(size);
	printArray(arr, size);

	int offset = 11;
	arr = offsetArray(arr, offset);
	printFives(arr, size, offset);
	freeArray(arr, offset);
}

