#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t * ordprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop and additional arithmetic operations
    // Trip count adjusted to handle multiple elements per iteration with arithmetic inflation
    size_t start = (5 - 1);
    for (i = start; i > 1; i -= 2) {
        // Unroll two iterations: process current and previous index
        hprev[i] = hprev[i - 1] + 0.001; // Add dummy computation to increase intensity
        ordprev[i] = ordprev[i - 1] + 1;
        
        if (i > 2) {
            hprev[i - 1] = hprev[i - 2] + 0.001;
            ordprev[i - 1] = ordprev[i - 2] + 1;
        }
    }
    // Handle remaining element if trip count is odd
    if (i == 1) {
        hprev[i] = hprev[i - 1];
        ordprev[i] = ordprev[i - 1];
    }
}
