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
    // Variant 2: Strided memory access pattern simulation
    // Instead of processing one bit at a time, process in strides of 2 bits per iteration
    // This changes the access pattern to skip intermediate states, simulating a strided traversal

    for (; i < limit && (((uint32_t)(re_cache)) >> 30) == 0 && (i + 1) < limit; i += 2) {
        re_cache <<= 2;
        re_index = (re_size_plus8 > re_index + 2) ? re_index + 2 : re_size_plus8;
    }

    // Handle remaining single iteration if limit is odd and i reached just before limit
    if (i == limit - 1 && (((uint32_t)(re_cache)) >> 31) == 0) {
        re_cache <<= 1;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        i++;
    }
}
