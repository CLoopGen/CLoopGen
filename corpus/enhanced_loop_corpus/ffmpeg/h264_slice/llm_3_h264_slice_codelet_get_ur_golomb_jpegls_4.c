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
    // Variant 2: Strided memory access pattern with stride of 2 (simulating non-unit progression)
    // This models a scenario where indices progress in steps, affecting how state evolves
    uint32_t cache = re_cache;
    int idx = re_index;
    int size = re_size_plus8;

    for (; i < limit && ((cache >> (32 - 1)) & 1) == 0; i++) {
        cache <<= 1;
        idx += 2; // Stride of 2 in index advancement
        if (idx >= size) {
            idx = size;
        }
    }

    // Synchronize state back to extern variables
    re_cache = cache;
    re_index = idx;
}
