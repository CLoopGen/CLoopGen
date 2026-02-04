#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int width;
extern uint8_t mask;
extern uint8_t color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step through pointer arithmetic in a single pass
    uint8_t *base = dst;
    int stride = width;
    uint8_t m = mask;
    uint8_t c = color;

    // Unroll the logic into two separate sequential loops to create strided access pattern
    for (i = 0; i < 4; i++) {
        // First set of writes: base + i (contiguous)
        if (m & (1 << (7 - i))) {
            *(base + i) = c;
        }
    }
    for (i = 0; i < 4; i++) {
        // Second set of writes: base + stride + i (strided relative to first loop)
        if (m & (1 << (3 - i))) {
            *(base + stride + i) = c;
        }
    }
}
