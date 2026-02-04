#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // We modify the access pattern to use a fixed stride (e.g., every 4th element)
    // to simulate non-consecutive traversal, which may stress cache behavior differently.
    // The stride allows exploration of memory bandwidth and alignment effects.

    const int stride = 4;
    uint8_t *p = (uint8_t *)reg_dense;
    for (int base = 0; base < stride; base++) {
        for (int i = base; i < (1 << 14); i += stride) {
            unsigned long byte_offset = i * 6 / 8;
            unsigned long first_bit = i * 6 & 7;
            unsigned long shift_adj = 8 - first_bit;
            unsigned long value = reg_raw[i];

            // Apply bitfield update to two bytes
            p[byte_offset] &= ~(((1UL << 6) - 1) << first_bit);
            p[byte_offset] |= (value << first_bit);

            p[byte_offset + 1] &= ~(((1UL << 6) - 1) >> shift_adj);
            p[byte_offset + 1] |= (value >> shift_adj);
        }
    }
}
