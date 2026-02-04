#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int j2max;
extern double power2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern simulation using array with stride of 2
    // We simulate a memory access pattern by iterating over a dummy array with stride
    double *dummy_array = (double*)calloc(j2max * 2, sizeof(double));
    if (!dummy_array) return;

    for (k = 1; k <= j2max; k += 2) {  // Strided iteration (step by 2)
        dummy_array[k] = power2;
        power2 *= 2;
    }

    free(dummy_array);
}
