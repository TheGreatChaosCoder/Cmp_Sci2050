#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	float height;
	double kilometers;
} Runner;

void sortByAge(Runner *array, int size);

int getByAge(Runner *array, int size, int age);
