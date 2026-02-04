#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int32_t *src0;
extern int32_t *src1;
extern ptrdiff_t len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with stride-2 pattern
    // Instead of alternating between src0 and src1 with post-increments, 
    // process two elements from src1 followed by two from src0 in batches.
    for (i = 0; i < len; i += 2) {
        *dst++ = src1[i];
        *dst++ = src1[i + 1];
        *dst++ = src0[i];
        *dst++ = src0[i + 1];
    }
}
