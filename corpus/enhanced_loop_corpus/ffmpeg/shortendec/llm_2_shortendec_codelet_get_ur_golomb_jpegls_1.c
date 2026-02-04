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
    // We simulate a buffer access that advances consecutively with each iteration
    volatile uint32_t* mem_base = (volatile uint32_t*)(&re_cache);
    for (; i < limit && (((uint32_t)(re_cache)) >> 31) == 0; i++) {
        re_cache <<= 1;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        // Simulate consecutive write to adjacent memory locations
        if (re_index < 1024) {  // Artificial bound to prevent overflow
            mem_base[re_index] = re_cache;
        }
    }
}
