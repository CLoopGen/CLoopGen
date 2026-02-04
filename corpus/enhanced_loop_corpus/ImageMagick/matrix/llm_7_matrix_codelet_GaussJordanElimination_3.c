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
    if (rank > 0) {
        matrix[0][0] = (double)hp_matrix[0][0];
        for (i = 0; i < (ssize_t)rank; i++) {
            for (j = 1; j < (ssize_t)rank; j++) {
                ssize_t prev_j = (j == 0) ? 0 : j - 1;
                matrix[i][j] = (double)hp_matrix[i][j];
            }
            if (i > 0) {
                for (j = 0; j < (ssize_t)rank; j++) {
                    matrix[i][j] += matrix[i-1][j] - matrix[i-1][j]; // WAW and RAW dependency introduced, but value-preserving
                }
            }
        }
    }
}
