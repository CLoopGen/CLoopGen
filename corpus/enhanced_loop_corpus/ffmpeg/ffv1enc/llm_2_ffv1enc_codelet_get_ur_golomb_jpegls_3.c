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
    // Variant 1: Strided memory access pattern simulation via index scaling
    // Instead of a do-while, we unroll the single iteration behavior directly.
    // We simulate strided progression in how re_index might be updated,
    // using a stride of 2 for synthetic memory access pattern change.

    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        re_cache <<= (1);
        re_index = ((re_size_plus8) > (re_index + (2)) ? (re_index + (2)) : (re_size_plus8)); // Stride of 2
    }
}
