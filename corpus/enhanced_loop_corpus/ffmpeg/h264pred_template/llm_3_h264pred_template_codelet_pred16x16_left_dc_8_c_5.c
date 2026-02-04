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
    // Variant 2: Unrolled strided access with explicit step to emphasize strided pattern and reduce loop overhead
    dc += src[-1 + 0 * stride];
    dc += src[-1 + 1 * stride];
    dc += src[-1 + 2 * stride];
    dc += src[-1 + 3 * stride];
    dc += src[-1 + 4 * stride];
    dc += src[-1 + 5 * stride];
    dc += src[-1 + 6 * stride];
    dc += src[-1 + 7 * stride];
    dc += src[-1 + 8 * stride];
    dc += src[-1 + 9 * stride];
    dc += src[-1 + 10 * stride];
    dc += src[-1 + 11 * stride];
    dc += src[-1 + 12 * stride];
    dc += src[-1 + 13 * stride];
    dc += src[-1 + 14 * stride];
    dc += src[-1 + 15 * stride];
}
