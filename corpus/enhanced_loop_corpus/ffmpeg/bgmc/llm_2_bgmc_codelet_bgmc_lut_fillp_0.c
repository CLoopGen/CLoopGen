#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t * cf_table[16];
extern uint8_t *lut;
extern int delta;
extern unsigned int sx;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with precomputed indices and unrolled inner loop (simulated via direct iteration)
    for (sx = 0; sx < 16; sx++) {
        uint16_t *cf_ptr = cf_table[sx];  // Base pointer for consecutive access
        unsigned int shift_val = 14 - 8;
        unsigned int scale = 1 << delta;
        for (i = 0; i < (1 << shift_val); i++) {
            unsigned int target = (i + 1) << 8;  // Simplified: (14 - (14-8)) = 8
            unsigned int symbol = scale;
            // Replace while with bounded for loop to find next valid symbol
            for (; symbol < (1U << 15); symbol += scale) {
                if (cf_ptr[symbol] <= target) {
                    *lut++ = symbol >> delta;
                    break;
                }
            }
        }
    }
}
