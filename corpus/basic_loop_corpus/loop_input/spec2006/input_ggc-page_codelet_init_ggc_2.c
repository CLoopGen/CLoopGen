#include <stdint.h>
#include <stddef.h>

size_t object_size_table[66];
unsigned int order;

void init_vars() {
    for (order = 0; order < 64; ++order) {
        object_size_table[order] = (size_t)1 << order;
    }
    // Ensure no out-of-bounds access: only fill valid indices [0,63]
    // The loop uses order < (8*8) => order < 64, so we stay within [0,63]
}