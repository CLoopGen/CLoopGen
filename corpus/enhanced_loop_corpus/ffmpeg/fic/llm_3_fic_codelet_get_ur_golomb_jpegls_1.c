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
    // Variant 2: Strided memory access pattern with non-unit stride
    // Simulate a strided progression in re_index using a fixed stride of 2,
    // modeling access patterns seen in optimized numerical codes.
    const unsigned int stride = 2;
    for (; i < limit && (((uint32_t)(re_cache)) >> 31) == 0; i++) {
        re_cache <<= 1;
        re_index += stride;
        if (re_index > re_size_plus8) {
            re_index = re_size_plus8;
        }
    }
}
