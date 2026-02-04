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
    // Variant 2: Strided access pattern simulation — process every second iteration conditionally
    // Introduce strided progression by skipping alternate valid positions, mimicking irregular traversal

    uint32_t temp_cache = re_cache;
    int temp_i = i;
    unsigned int temp_index = re_index;
    int stride = 2; // Simulate strided behavior by advancing in non-uniform steps

    for (; temp_i < limit && ((temp_cache >> 31) == 0); ) {
        temp_cache <<= 1;
        temp_index = (re_size_plus8 > temp_index + 1) ? temp_index + 1 : re_size_plus8;
        temp_i += (temp_i % stride == 0) ? 1 : 2; // Alternate step size to mimic strided access effect
    }

    // Synchronize state back to global variables
    re_cache = temp_cache;
    i = temp_i;
    re_index = temp_index;
}
