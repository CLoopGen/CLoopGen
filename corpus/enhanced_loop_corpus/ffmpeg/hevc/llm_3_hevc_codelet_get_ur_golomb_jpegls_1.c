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
    unsigned int* index_ptr = &re_index;
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        re_cache <<= 1;
        (*index_ptr)++; // Indirect memory access via pointer
        if (*index_ptr > re_size_plus8) {
            *index_ptr = re_size_plus8;
        }
    }
}
