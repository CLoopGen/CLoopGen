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
    // Introduce indirect access pattern using a small lookup table to simulate indirect indexing
    static const unsigned int offset_table[4] = {1, 2, 1, 3};
    int idx = i & 3;

    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        re_cache <<= (1);
        re_index = (re_index + offset_table[idx]) >= re_size_plus8 ? re_size_plus8 : (re_index + offset_table[idx]);
    }
}
