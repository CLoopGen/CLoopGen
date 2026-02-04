#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double alpha;
extern double *x;
extern double *y;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access by 4*i, we process elements consecutively in chunks of 4
    for (i = 0; i < len4; i++) {
        int base_idx = 4 * i;
        y[base_idx]     += alpha * x[base_idx];
        y[base_idx + 1] += alpha * x[base_idx + 1];
        y[base_idx + 2] += alpha * x[base_idx + 2];
        y[base_idx + 3] += alpha * x[base_idx + 3];
    }
}
