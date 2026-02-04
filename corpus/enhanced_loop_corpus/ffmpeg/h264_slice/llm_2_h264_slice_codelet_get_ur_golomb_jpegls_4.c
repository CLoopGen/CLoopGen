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
    // Assuming re_cache represents a bitstream and re_index tracks position, we simulate consecutive reads
    uint32_t cache = re_cache;
    int idx = re_index;
    int size = re_size_plus8;

    for (; i < limit && ((cache >> (32 - 1)) & 1) == 0; i++) {
        cache <<= 1;
        idx = (idx + 1 < size) ? idx + 1 : size;
    }

    // Update the external variables after loop execution
    re_cache = cache;
    re_index = idx;
}
