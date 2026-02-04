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
    // We simulate a buffer access with consecutive reads, replacing bit manipulation with indexed access
    unsigned int *simulated_buffer = (unsigned int*)&re_cache; // Treat re_cache as start of a logical buffer
    for (; i < limit && simulated_buffer[0] != 0; i++) {
        simulated_buffer[0] <<= 1;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        simulated_buffer++; // Move to next "memory location" — consecutive access
    }
}
