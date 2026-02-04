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
    int **matrix = (int**)malloc(size1 * sizeof(int*));
    for (i = 0; i < size1; i++) {
        matrix[i] = (int*)calloc(size2, sizeof(int));
        for (j = 0; j < size2; j++) {
            if (j > 0) {
                matrix[i][j] = matrix[i][j-1] + 1; // Introduce RAW dependency within inner loop
            } else {
                matrix[i][j] = 0;
            }
        }
    }
    for (i = 0; i < size1; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
