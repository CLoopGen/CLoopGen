#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern u_int dim;
extern int i;
extern double *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then handle remaining index)
    for (i = (dim - 1) & ~1; i >= 0; i -= 2) {
        if (b_ve[i] != 0.)
            break;
    }
    // If loop ended at invalid index due to stride, check the last odd index
    if (i < 0 && (dim - 1) % 2 == 1) {
        i = dim - 1;
        if (b_ve[i] != 0.)
            return;
        i -= 2;
    }
}
