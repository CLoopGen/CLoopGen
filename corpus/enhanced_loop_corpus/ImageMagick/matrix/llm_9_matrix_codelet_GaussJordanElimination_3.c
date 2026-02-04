#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double **matrix;
extern  size_t rank;
extern long double **hp_matrix;
extern ssize_t i;
extern ssize_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)rank; i++) {
        for (j = i; j < (ssize_t)rank; j++) {
            matrix[i][j] = (double)(hp_matrix[i][j] + hp_matrix[j][i]) * 0.5L;
            if (i != j) {
                matrix[j][i] = (double)matrix[i][j];
            }
        }
    }
}
