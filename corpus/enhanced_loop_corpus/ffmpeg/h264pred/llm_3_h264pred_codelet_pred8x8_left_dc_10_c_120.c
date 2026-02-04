#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc0;
extern int dc2;
extern uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with explicit pointer arithmetic
    // Use pointer arithmetic with scaled stride to emphasize memory access pattern
    // and potentially aid vectorization or manual unrolling in some contexts.
    uint16_t *base1 = src - 1;
    uint16_t *base2 = src - 1 + 4 * stride;
    for (i = 0; i < 4; i++) {
        dc0 += *(base1 + i * stride);
        dc2 += *(base2 + i * stride);
    }
}
