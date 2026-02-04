#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern size_t j;
extern size_t incY;
extern size_t lenY;
extern double *Y;
extern size_t jy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    double *y_ptr = Y;
    for (j = 0; j < lenY; ++j) {
        *y_ptr *= beta;
        y_ptr += incY; // Stride is still applied, but we use pointer arithmetic
    }
}
