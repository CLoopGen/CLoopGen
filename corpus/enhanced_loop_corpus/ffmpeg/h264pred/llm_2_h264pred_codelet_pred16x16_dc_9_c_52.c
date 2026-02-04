#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unrolled stride into contiguous elements)
    // Assuming stride = 1 for consecutive access, accumulate 16 consecutive elements
    ptrdiff_t effective_index = -1;
    for (i = 0; i < 16; i++) {
        dc += src[effective_index + i];
    }
}
