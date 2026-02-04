#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ptrdiff_t stride;
int y;
int size;
uint16_t *src;
uint16_t *left;
int dc;

void init_vars() {
    size = 65536;
    stride = size;
    dc = 42;

    src = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * size * size);
    left = (uint16_t*)aligned_alloc(32, sizeof(uint16_t) * size);

    if (!src || !left) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        left[i] = i * 3 + 1;
    }

    for (int i = 0; i < size * size; i++) {
        src[i] = 0;
    }
}