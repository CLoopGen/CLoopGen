#include <stdlib.h>
#include <stdint.h>

unsigned int *h_offsets;

void init_vars() {
    size_t size = 1 << 10;
    h_offsets = aligned_alloc(32, size * sizeof(unsigned int));
    for (size_t i = 0; i < size; i++) {
        h_offsets[i] = 1 + (i % 100);
    }
}