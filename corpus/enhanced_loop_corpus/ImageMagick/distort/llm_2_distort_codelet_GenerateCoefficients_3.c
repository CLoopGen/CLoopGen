#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t number_values;
extern double *coeff;
extern size_t i;
extern double **vectors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    double *base = coeff;
    for (i = 0; i < number_values; i++) {
        vectors[i] = base;
        base += 3; // Move to next group of 3 elements consecutively
    }
}
