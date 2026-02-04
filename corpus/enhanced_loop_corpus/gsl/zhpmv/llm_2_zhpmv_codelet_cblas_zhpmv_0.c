#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access via iy and incY, we rewrite to access consecutive double elements
    // We assume incY was originally a stride; now we collapse it into sequential indices.
    double *y_ptr = (double *)Y;
    for (i = 0; i < N; i++) {
        int idx = 2 * i;  // Now writing to consecutive locations
        y_ptr[idx] = 0.;
        y_ptr[idx + 1] = 0.;
    }
}
