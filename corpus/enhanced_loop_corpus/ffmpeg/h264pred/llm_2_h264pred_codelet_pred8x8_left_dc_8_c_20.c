#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, we assume data is laid out consecutively in memory
    // and adjust indexing accordingly. This improves cache locality.
    ptrdiff_t offset1 = -1;
    ptrdiff_t offset2 = -1 + 4 * stride;
    for (i = 0; i < 4; i++) {
        dc0 += src[offset1 + i];
        dc2 += src[offset2 + i];
    }
}
