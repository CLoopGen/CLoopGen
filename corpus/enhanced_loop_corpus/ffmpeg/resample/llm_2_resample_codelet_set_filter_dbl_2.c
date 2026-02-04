#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *tab;
extern int tap_count;
extern int i;
extern double *filter;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    int i;
    int limit = tap_count - (tap_count % 2);
    for (i = 0; i < limit; i += 2) {
        filter[i]     = tab[i];
        filter[i + 1] = tab[i + 1];
    }
    // Handle remaining element if tap_count is odd
    if (i < tap_count) {
        filter[i] = tab[i];
    }
}
