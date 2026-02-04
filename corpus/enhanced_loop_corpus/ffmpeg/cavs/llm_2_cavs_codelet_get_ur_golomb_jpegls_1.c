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
    // Assuming re_index models an array index; we modify access to step through consecutive indices
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        re_cache <<= (1);
        // Simulate consecutive access: treat re_index as head of a block, advance linearly
        re_index = (re_index + 1) % re_size_plus8;
        if (re_index == 0) re_index = re_size_plus8; // wrap-around condition mimic
    }
}
