#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int32_t stride;
extern uint32_t row;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array
    // Use an index lookup table to access memory in non-sequential order
    uint32_t indices[16];
    for (uint32_t i = 0; i < 16; i++) {
        indices[i] = (i * 3) % 16;  // Generate scrambled access pattern
    }
    uint8_t *base = dst;
    for (row = 16; row--;) {
        base[indices[15 - row] * stride] = 0;  // Indirect strided access
    }
}
