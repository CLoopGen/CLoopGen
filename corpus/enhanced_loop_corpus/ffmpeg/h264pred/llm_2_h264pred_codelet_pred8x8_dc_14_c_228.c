#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Reorganize accesses to use consecutive indexing where possible, reducing stride dependency
    ptrdiff_t offset = -stride;
    for (i = 0; i < 4; i++) {
        ptrdiff_t idx1 = offset + i;
        ptrdiff_t idx2 = 4 + i - stride;
        ptrdiff_t idx3 = -1 + (i + 4) * stride;
        dc0 += src[idx1] + src[i * stride - 1];
        dc1 += src[idx2];
        dc2 += src[idx3];
    }
}
