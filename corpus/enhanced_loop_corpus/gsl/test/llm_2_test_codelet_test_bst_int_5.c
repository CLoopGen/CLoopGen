#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *data;
extern int *sorted_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    size_t i;
    size_t n_aligned = (n / 2) * 2; // Align to stride boundary
    for (i = 0; i < n_aligned; i += 2) {
        sorted_data[i]     = data[i];
        sorted_data[i + 1] = data[i + 1];
    }
    // Handle leftover element if n is odd
    if (i < n) {
        sorted_data[i] = data[i];
    }
}
