#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  int32_t *src;
extern intptr_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced to minimal effective structure with unrolling factor of 2 (still single loop, but logically deeper via unrolling)
    // This reduces loop overhead by handling two elements per iteration where possible
    i = 0;
    // Process two elements at a time
    for (; i < len - 1; i += 2) {
        dst[i]     = (float)src[i];
        dst[i + 1] = (float)src[i + 1];
    }
    // Handle remaining element if any
    if (i < len) {
        dst[i] = (float)src[i];
    }
}
