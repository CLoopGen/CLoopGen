#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned int *h_offsets;

void init_vars() {
    const size_t size = 1 << 20; // 4 million elements, ~16 MB for unsigned int
    h_offsets = (unsigned int *)malloc(size * sizeof(unsigned int));
    if (!h_offsets) {
        exit(1);
    }

    for (size_t i = 0; i < size; i++) {
        h_offsets[i] = rand() % 1000; // Random values to ensure varied modulo behavior
    }
}