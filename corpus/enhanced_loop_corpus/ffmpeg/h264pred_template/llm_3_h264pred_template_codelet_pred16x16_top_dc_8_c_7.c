#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increased stride step, traversing every (stride/4)th element
    ptrdiff_t effective_stride = stride / 4;
    if (effective_stride == 0) effective_stride = 1;
    for (i = 0; i < 16; i++) {
        dc += src[i * effective_stride];  // Use scaled index for strided access pattern
    }
}
