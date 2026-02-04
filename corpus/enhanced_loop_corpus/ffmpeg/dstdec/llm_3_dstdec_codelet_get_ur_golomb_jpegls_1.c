#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int limit;
extern unsigned int re_index;
extern __attribute__((unused)) unsigned int re_cache;
extern unsigned int re_size_plus8;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided memory access with fixed stride > 1
    // Instead of incrementing re_index by 1, access every 2nd position.
    // This creates a strided access pattern, skipping elements.
    // The loop condition still respects limit and cache high-bit check.

    for (; i < limit && (((uint32_t)(re_cache)) >> 31) == 0; i++) {
        re_cache <<= 1;
        re_index = (re_index + 2 < re_size_plus8 ? re_index + 2 : re_size_plus8);
    }
}
