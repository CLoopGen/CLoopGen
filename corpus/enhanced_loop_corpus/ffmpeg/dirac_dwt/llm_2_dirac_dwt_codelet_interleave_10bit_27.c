#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int32_t *src0;
extern int32_t *src1;
extern int w2;
extern int add;
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching Pattern
    // Instead of writing to dst[2*i] and dst[2*i+1], accumulate results in local variables
    // and write them consecutively to improve store coalescing and cache behavior.
    int32_t *d = dst;
    for (i = 0; i < w2; i++) {
        int val0 = ((int)(src0[i] + (unsigned int)add)) >> shift;
        int val1 = ((int)(src1[i] + (unsigned int)add)) >> shift;
        *d++ = val0;
        *d++ = val1;
    }
}
