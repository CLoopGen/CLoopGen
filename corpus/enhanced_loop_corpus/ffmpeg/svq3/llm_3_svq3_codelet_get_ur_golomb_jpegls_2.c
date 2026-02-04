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
    // Instead of single-bit shifts, process multiple bits per iteration (stride of 2)
    // This changes the access frequency and control flow progression
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - 2)) == 0; i += 2) {
        re_cache <<= 2;  // Stride of 2 bits
        re_index = (re_size_plus8 > re_index + 2) ? re_index + 2 : re_size_plus8;
        // Adjust i to prevent overshoot
        if (i + 1 >= limit) break;
    }
    // Handle remaining element if needed
    if (i == limit - 1 && (((uint32_t)(re_cache)) >> (32 - 1)) == 0) {
        re_cache <<= 1;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        i++;
    }
}
