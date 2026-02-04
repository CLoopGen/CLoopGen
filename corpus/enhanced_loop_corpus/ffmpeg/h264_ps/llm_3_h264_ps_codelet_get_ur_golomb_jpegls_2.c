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
    unsigned int* index_array = &re_index; // Simulate indirect memory access via pointer
    for (; i < limit && (((uint32_t)(re_cache)) >> (32 - (1))) == 0; i++) {
        re_cache <<= (1);
        *index_array = (*index_array + 1) % re_size_plus8; // Indirect update using dereferenced pointer (cyclic access)
        if (*index_array == 0) {
            *index_array = re_size_plus8;
        }
    }
}
