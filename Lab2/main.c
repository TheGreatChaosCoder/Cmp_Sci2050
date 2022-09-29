#include "lab2.h"

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
	int size = 10;
	int *array = makeArray(size);

	if(!array) {
		puts("ERROR: makeArray unexpectedly returned NULL");
		return -1;
	}

	puts("Printing all 0s");
	printArray(array, size);

	fillTwos(array, size);
	puts("Printing multiples of 2");
	printArray(array, size);

	printf("Array before free: %p\n", array);
	freeArray(&array);
	printf("Array after free: %p\n", array);
}
