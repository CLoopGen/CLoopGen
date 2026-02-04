#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of processing one element at a time with bit manipulation,
    // we restructure the loop to process multiple consecutive elements in bulk.
    // This improves spatial locality and enables potential vectorization.

    uint8_t *p = (uint8_t *)reg_dense;
    for (int i = 0; i < (1 << 14); i += 4) {
        // Process 4 consecutive indices: i, i+1, i+2, i+3
        for (int j = 0; j < 4 && (i + j) < (1 << 14); j++) {
            int idx = i + j;
            unsigned long byte_offset = idx * 6 / 8;
            unsigned long first_bit = idx * 6 & 7;
            unsigned long shift_adj = 8 - first_bit;
            unsigned long value = reg_raw[idx];

            // Update current byte
            p[byte_offset] &= ~(((1UL << 6) - 1) << first_bit);
            p[byte_offset] |= (value << first_bit);

            // Update next byte if needed (cross-byte write)
            if (shift_adj < 6) {
                p[byte_offset + 1] &= ~(((1UL << 6) - 1) >> shift_adj);
                p[byte_offset + 1] |= (value >> shift_adj);
            }
        }
    }
}
