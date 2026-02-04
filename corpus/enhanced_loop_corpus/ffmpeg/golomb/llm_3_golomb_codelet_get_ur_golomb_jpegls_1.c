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
    // Variant 2: Strided access pattern with periodic updates (stride of 2 iterations)
    // Simulates irregular update intervals to re_index and shifted evaluation
    int local_i = i;
    
    for (; local_i + 1 < limit; local_i += 2) {
        // Process two iterations with conditional progression
        if (((uint32_t)(re_cache)) >> 31 == 0) {
            re_cache <<= 1;
            re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        } else {
            break;
        }

        if (((uint32_t)(re_cache)) >> 31 == 0) {
            re_cache <<= 1;
            re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        } else {
            local_i++;  // Account for early exit on second step
            break;
        }
    }

    // Handle possible final odd iteration
    if (local_i < limit && (((uint32_t)(re_cache)) >> 31) == 0) {
        re_cache <<= 1;
        re_index = (re_size_plus8 > re_index + 1) ? re_index + 1 : re_size_plus8;
        local_i++;
    }

    i = local_i;
}
