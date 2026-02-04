#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;
extern int j;
extern  int dim;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed traversal order
    // Instead of accessing out[i + j] in increasing i and j, we traverse backwards
    // to create a different memory access pattern while maintaining correctness.
    for (i = size - 1; i >= 0; i -= dim)
        for (j = dim - 1; j >= 0; j--)
            out[i - dim + 1 + j] = 0.F;
}
