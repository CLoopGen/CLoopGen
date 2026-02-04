#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *matrix;
extern double *vector;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Introduce strided memory access with padding simulation
    // Assume matrix has a padded stride (e.g., leading dimension greater than size)
    const int stride = size + 8;  // Simulate padding of 8 doubles per column
    for (int i = size - 2; i >= 0; i--) {
        double d = vector[i];
        for (int j = i + 1; j < size; j++)
            d -= matrix[i + j * stride] * vector[j];  // Strided access using larger stride
        vector[i] = d / matrix[i + i * stride];
    }
}
