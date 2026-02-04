#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double beta;
extern double *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    double *y_ptr = Y;
    for (i = 0; i < lenY; i++) {
        *y_ptr *= beta;
        y_ptr += incY;
    }
}
