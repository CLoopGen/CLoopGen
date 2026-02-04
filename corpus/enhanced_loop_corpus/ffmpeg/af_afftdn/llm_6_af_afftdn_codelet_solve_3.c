#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double *temp_vector = (double*)alloca(size * sizeof(double));
    for (int i = size - 1; i >= 0; i--) {
        double d = vector[i];
        for (int j = i + 1; j < size; j++) {
            d -= matrix[i + j * size] * temp_vector[j];
        }
        temp_vector[i] = d / matrix[i + i * size];
    }
    for (int i = 0; i < size; i++) {
        vector[i] = temp_vector[i];
    }
}
