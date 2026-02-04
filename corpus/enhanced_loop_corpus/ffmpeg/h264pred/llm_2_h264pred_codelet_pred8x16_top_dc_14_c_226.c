#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc1;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access with stride offset, access consecutive elements
    // by adjusting base pointer and accessing in sequence.
    ptrdiff_t adjusted_index = -stride;
    dc0 += src[adjusted_index + 0] + src[adjusted_index + 1] +
           src[adjusted_index + 2] + src[adjusted_index + 3];
    dc1 += src[adjusted_index + 4] + src[adjusted_index + 5] +
           src[adjusted_index + 6] + src[adjusted_index + 7];
}
