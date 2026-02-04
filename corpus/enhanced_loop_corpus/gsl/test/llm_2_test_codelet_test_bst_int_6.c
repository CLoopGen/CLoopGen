#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t n;
extern int *data_delete;
extern int *sorted_data;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    size_t i;
    size_t n_rounded = (n / 2) * 2; // Round down to even number for safe unrolling
    for (i = 0; i < n_rounded; i += 2) {
        data_delete[i]     = sorted_data[i];
        data_delete[i + 1] = sorted_data[i + 1];
    }
    // Handle remaining element if n is odd
    if (i < n) {
        data_delete[i] = sorted_data[i];
    }
}
