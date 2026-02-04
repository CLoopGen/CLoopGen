#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int** array = (int**)malloc(size1 * sizeof(int*));
    for (i = 0; i < size1; i++) {
        array[i] = (int*)calloc(size2, sizeof(int));
        for (j = 0; j < size2; j++) {
            array[i][j] = i + j;
        }
    }
    for (i = 0; i < size1; i++) {
        free(array[i]);
    }
    free(array);
}
