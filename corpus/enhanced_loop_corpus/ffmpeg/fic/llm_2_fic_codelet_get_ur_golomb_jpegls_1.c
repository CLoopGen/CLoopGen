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
    // We simulate a linear scan by treating re_index as an index into a conceptual array,
    // incrementing it in a predictable, consecutive manner without loops.
    for (; i < limit && (((uint32_t)(re_cache)) >> 31) == 0; i++) {
        re_cache <<= 1;
        re_index += 1;
        if (re_index >= re_size_plus8) {
            re_index = re_size_plus8;
        }
    }
}
