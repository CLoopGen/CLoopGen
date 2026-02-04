#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < size - 1; i++) {
    double vi = vector[i];
    for (int j = i + 1; j < size; j++) {
        vector[j] -= matrix[j + i * size] * vi;
    }
}
}
