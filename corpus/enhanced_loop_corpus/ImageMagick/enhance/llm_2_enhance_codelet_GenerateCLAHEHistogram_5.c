#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t number_bins;
extern size_t *histogram;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to process two elements per iteration
    ssize_t limit = (ssize_t)number_bins;
    ssize_t i;
    // Handle even number of bins; if odd, last element will be handled separately
    for (i = 0; i < limit - 1; i += 2) {
        histogram[i] = 0L;
        histogram[i + 1] = 0L;
    }
    // Handle remaining element if number_bins is odd
    if (i == limit - 1) {
        histogram[i] = 0L;
    }
}
