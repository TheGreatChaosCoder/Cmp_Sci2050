#include <stdio.h>
#include <stdlib.h>

float * readFloatFileIntoArray(FILE *fptr, int *length){
    fscanf(fptr, "%i", length);

    float *array = malloc(*length * sizeof(float));

    if(!array){
        return NULL;
    }

    int i=0;
    while(!feof(fptr)){
        fscanf(fptr, "%f", &array[i]);

        printf("\n%.2f", array[i]);
        i++;
    }

    return array;
}

void freeFloatArray(float **array){
    free(*array);
    array = NULL;
}

int main(){
    FILE *fptr = fopen("data.txt", "r");
    float *array;
    int length;

    array = readFloatFileIntoArray(fptr, &length);
    fclose(fptr);
    printf("\n%i\n", length);

    freeFloatArray(&array);
}