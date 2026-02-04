#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = size - 2; i >= 0; i--) {
        double d = vector[i];
        double update = 0.0;
        for (int j = i + 1; j < size; j++) {
            update += matrix[i + j * size] * vector[j];
        }
        d -= update;
        vector[i] = d / matrix[i + i * size];
    }
}
