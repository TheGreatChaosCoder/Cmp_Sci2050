#include "lab1.h"

int main() {
	int size = 9, error,
			array[] = { 1, 2, 3, 4, 5, 6, 7, -8, 9 };

	int iResult;

	error = getMin(size, array, &iResult);
	printf("getMin() returned %d, result = %d\n", error, iResult);
	puts("Testing NULL checking");
	error = getMin(size, NULL, &iResult);
	printf("getMin() returned %d, result = %d\n", error, iResult);
	puts("Testing zero size checking");
	error = getMin(0, array, &iResult);
	printf("getMin() returned %d, result = %d\n", error, iResult);
	puts("Testing both");
	error = getMin(0, NULL, &iResult);
	printf("getMin() returned %d, result = %d\n", error, iResult);
}
