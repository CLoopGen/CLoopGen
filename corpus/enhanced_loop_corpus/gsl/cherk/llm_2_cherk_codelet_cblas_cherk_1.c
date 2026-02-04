#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing elements in row-major order, traverse with a fixed stride
    // across the flattened array, updating every 2nd element in chunks.
    float *C_ptr = (float *)C;
    int total_elements = 2 * ldc * N;
    for (i = 0; i < total_elements; i += 2) {
        C_ptr[i] = 0.;
        C_ptr[i + 1] = 0.;
    }
}
