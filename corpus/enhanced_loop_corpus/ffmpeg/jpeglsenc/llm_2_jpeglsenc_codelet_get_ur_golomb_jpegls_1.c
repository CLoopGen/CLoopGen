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
    // Variant 1: Consecutive memory access pattern simulation
    // We simulate a consecutive load by unrolling the effect of shifts and index updates,
    // assuming re_cache and re_index evolve predictably with each iteration.
    int j = i;
    for (; j < limit && (((uint32_t)(re_cache)) >> 31) == 0; j++) {
        re_cache <<= 1;
        re_index = (re_index + 1 < re_size_plus8) ? re_index + 1 : re_size_plus8;
    }
    i = j;
}
