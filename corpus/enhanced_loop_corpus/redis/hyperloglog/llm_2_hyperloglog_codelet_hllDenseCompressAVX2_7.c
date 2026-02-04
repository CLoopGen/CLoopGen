#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with loop unrolling and direct indexing
    uint8_t *p = reg_dense;
    for (int i = (1 << 14) - 32; i < (1 << 14); i++) {
        unsigned long byte = i * 6 / 8;
        unsigned long fb = (i * 6) & 7;
        unsigned long fb8 = 8 - fb;
        unsigned long v = reg_raw[i];

        // Direct consecutive accesses to reg_dense[byte] and reg_dense[byte+1]
        p[byte] &= ~(((1UL << 6) - 1) << fb);
        p[byte] |= (v << fb) & 0xFF;
        p[byte + 1] &= ~(((1UL << 6) - 1) >> fb8);
        p[byte + 1] |= (v >> fb8) & 0xFF;
    }
}
