#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float alpha;
extern void *X;
extern  int incX;
extern int i;
extern int ix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unrolled by 2 elements)
    // Instead of strided access via ix, we assume X is accessed consecutively
    // and process two floats at a time in sequence.
    float *x_ptr = (float *)X;
    for (i = 0; i < N; i++) {
        x_ptr[2*i]     *= alpha;
        x_ptr[2*i + 1] *= alpha;
    }
}
