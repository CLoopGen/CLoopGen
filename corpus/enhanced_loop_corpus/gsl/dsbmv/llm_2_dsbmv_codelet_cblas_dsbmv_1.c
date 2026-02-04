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
    // Assume incY is positive and reset iy to base offset before loop
    ptrdiff_t base_iy = iy; // preserve initial offset
    for (i = 0; i < N; i++) {
        Y[base_iy + i] *= beta;
    }
}
