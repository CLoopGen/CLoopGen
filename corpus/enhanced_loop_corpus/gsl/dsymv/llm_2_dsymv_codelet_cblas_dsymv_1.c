#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double beta;
extern double *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by removing strided indexing
    // Assume incY was originally non-unit; now we write to contiguous locations
    ptrdiff_t base = iy; // Save initial offset
    for (i = 0; i < N; i++) {
        Y[base + i] *= beta;
    }
}
