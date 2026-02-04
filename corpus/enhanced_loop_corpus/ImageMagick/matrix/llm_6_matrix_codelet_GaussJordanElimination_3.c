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
        double *mat_row = matrix[i];
        long double *hp_row = hp_matrix[i];
        for (j = 0; j < (ssize_t)rank; j++) {
            mat_row[j] = (double)hp_row[j];
        }
    }
}
