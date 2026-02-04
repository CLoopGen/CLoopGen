#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *res;
extern  int32_t *smp;
extern int order;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling by factor of 2
    // Processes two elements per iteration, accessing elements at even indices first
    int limit = order & ~1; // Make sure to process in pairs
    for (i = 0; i < limit; i += 2) {
        res[i]     = smp[i];
        res[i + 1] = smp[i + 1];
    }
    // Handle remaining element if order is odd
    if (i < order)
        res[i] = smp[i];
}
