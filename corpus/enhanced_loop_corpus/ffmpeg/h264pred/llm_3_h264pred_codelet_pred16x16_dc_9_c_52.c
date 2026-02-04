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
    // Variant 2: Strided access with increased stride factor (double the original stride)
    // Simulates accessing every 2*stride element, increasing spatial sparsity
    for (i = 0; i < 16; i++) {
        dc += src[-1 + i * (2 * stride)];
    }
}
