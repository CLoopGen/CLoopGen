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
    // Variant 1: Consecutive memory access pattern simulation using array-like indexing
    // Assumption: re_cache and re_index behave as if part of a bitstream buffer.
    // We simulate consecutive bit consumption by unrolling the shift logic in steps.

    uint32_t temp_cache = re_cache;
    int temp_i = i;
    unsigned int temp_index = re_index;

    for (; temp_i < limit && ((temp_cache >> 31) == 0); temp_i++) {
        temp_cache <<= 1;
        temp_index = (re_size_plus8 > temp_index + 1) ? temp_index + 1 : re_size_plus8;
    }

    // Update shared extern variables after loop
    re_cache = temp_cache;
    i = temp_i;
    re_index = temp_index;
}
