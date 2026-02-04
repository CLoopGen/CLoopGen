#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double **matrix;
extern double **vectors;
extern  double *terms;
extern  double *results;
extern  size_t rank;
extern  size_t number_vectors;
extern ssize_t i;
extern ssize_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < (ssize_t)rank; j++) {
        for (i = 0; i < (ssize_t)number_vectors; i++) {
            for (ssize_t k = 0; k < (ssize_t)rank; k++) {
                if (i == 0) {
                    matrix[k][j] += terms[k] * terms[j];
                }
            }
            vectors[i][j] += results[i] * terms[j];
        }
    }
}
