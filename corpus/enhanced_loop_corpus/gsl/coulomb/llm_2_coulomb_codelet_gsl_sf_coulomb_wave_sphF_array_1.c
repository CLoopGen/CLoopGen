#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int kmax;
extern double *fc_array;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    for (k = 0; k <= kmax; k += stride) {
        fc_array[k] = 0.;
    }
    for (k = 1; k <= kmax; k += stride) {
        fc_array[k] = 0.;
    }
}
