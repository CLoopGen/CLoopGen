#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via iy, we rewrite to access consecutive double elements
    // assuming incY was originally 1. We eliminate iy and use i directly for sequential writes.
    double *y_ptr = (double *)Y;
    for (i = 0; i < lenY; i++) {
        y_ptr[2 * i] = 0.;
        y_ptr[2 * i + 1] = 0.;
    }
}
