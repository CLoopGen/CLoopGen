#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int limit;
extern unsigned int re_index;
extern __attribute__((unused)) unsigned int re_cache;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access pattern simulation using pointer arithmetic
    // We simulate a strided access by incrementing index in steps, mimicking traversal over a larger data structure
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i += 2) {
        re_cache <<= (1);
        re_index += (1);
        if (i + 1 < limit) {
            re_cache <<= (1);
            re_index += (1);
        }
    }
}
