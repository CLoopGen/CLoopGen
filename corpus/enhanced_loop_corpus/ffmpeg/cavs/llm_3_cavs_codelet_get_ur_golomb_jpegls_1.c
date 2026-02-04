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
    // Variant 2: Strided memory access pattern
    // Modify re_index to advance with a fixed stride instead of +1, creating non-unit jumps
    const unsigned int stride = 3; // Stride value chosen to create sparse access
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        re_cache <<= (1);
        re_index += stride;
        if (re_index >= re_size_plus8) {
            re_index = re_size_plus8; // Clamp to boundary when exceeded
        }
    }
}
