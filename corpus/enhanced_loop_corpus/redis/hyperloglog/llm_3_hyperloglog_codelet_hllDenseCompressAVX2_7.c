#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access using indirect addressing via pointer arithmetic with stride of 2
    uint8_t *p = reg_dense;
    const int start = (1 << 14) - 32;
    const int end = (1 << 14);
    const int stride = 2;

    // Strided iteration: process every 2nd index
    for (int i = start; i < end; i += stride) {
        unsigned long byte_offset = (i * 6) / 8;
        unsigned long bit_shift = (i * 6) & 7;
        unsigned long complement_shift = 8 - bit_shift;
        unsigned long value = reg_raw[i];

        uint8_t mask_low = ((1UL << 6) - 1) << bit_shift;
        uint8_t mask_high = ((1UL << 6) - 1) >> complement_shift;

        // Strided updates to dense array with scattered writes
        p[byte_offset] = (p[byte_offset] & ~mask_low) | ((value << bit_shift) & mask_low);
        if (complement_shift < 8) {
            p[byte_offset + 1] = (p[byte_offset + 1] & ~mask_high) | (value >> complement_shift);
        }
    }

    // Handle any remaining elements if stride skips them (cleanup pass)
    for (int i = (1 << 14) - 31; i < (1 << 14); i += 2) {
        unsigned long byte = i * 6 / 8;
        unsigned long fb = (i * 6) & 7;
        unsigned long fb8 = 8 - fb;
        unsigned long v = reg_raw[i];
        p[byte] &= ~(((1UL << 6) - 1) << fb);
        p[byte] |= (v << fb) & 0xFF;
        p[byte + 1] &= ~(((1UL << 6) - 1) >> fb8);
        p[byte + 1] |= (v >> fb8) & 0xFF;
    }
}
