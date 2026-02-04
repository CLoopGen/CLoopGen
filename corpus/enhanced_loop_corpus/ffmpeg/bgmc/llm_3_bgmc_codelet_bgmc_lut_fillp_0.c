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
    // Variant 2: Strided memory access pattern on cf_table with indirect addressing simulation
    // Access every 2nd entry in cf_table[sx] starting from offset, creating strided reads
    const unsigned int stride = 2;
    const unsigned int max_symbol = 1 << 14;
    const unsigned int inner_iters = 1 << (14 - 8);

    for (sx = 0; sx < 16; sx++) {
        uint16_t *table_base = cf_table[sx];
        for (i = 0; i < inner_iters; i++) {
            unsigned int target = (i + 1) << 8;
            unsigned int found = 0;
            // Use for-loop to simulate search without while, using strided access
            for (unsigned int symbol = 1 << delta; symbol < max_symbol && !found; symbol += (1 << delta) * stride) {
                if (table_base[symbol] <= target) {
                    *lut++ = symbol >> delta;
                    found = 1;
                }
            }
            // Fallback in case strided skipped the valid element
            if (!found) {
                unsigned int symbol = 1 << delta;
                for (; symbol < max_symbol; symbol += 1 << delta) {
                    if (table_base[symbol] <= target) {
                        *lut++ = symbol >> delta;
                        break;
                    }
                }
            }
        }
    }
}
