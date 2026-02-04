#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access with stride offset, access consecutive elements in two separate sequential blocks
    ptrdiff_t offset = -stride;
    for (i = 0; i < 4; i++) {
        dc0 += src[offset + i];
        dc1 += src[offset + 4 + i];
    }
}
